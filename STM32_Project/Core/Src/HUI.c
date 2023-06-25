/*
 * HUImsg.c
 *
 *  Created on: Oct 7, 2021
 *      Author: Electric Canary
 */

#include "HUI.h"
#include "protocol.h"
#include "USB/usbd_midi_if.h"

//-----Sending HUI Messages to DAW

void HUI_Ping(void)
{
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0x90, 0, 0x7F);
	USBD_SendMidiMessages();
}

void HUI_ButtonPush(uint8_t zone, uint8_t port)
{
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xB0, 0x0F, zone);
	USBD_SendMidiMessages();
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xB0, 0x2F, 0x40 + port);
	USBD_SendMidiMessages();
}

void HUI_ButtonRelease(uint8_t zone, uint8_t port)
{
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xB0, 0x0F, zone);
	USBD_SendMidiMessages();
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xB0, 0x2F, port);
	USBD_SendMidiMessages();
}

void HUI_FaderMove(uint8_t channel_zone, uint16_t pos)
{
	uint16_t position = pos << 2;
	uint8_t hi = (uint8_t)(position >> 7);
	uint8_t lo = (uint8_t)(position & 0x7F);

	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xB0, channel_zone, hi);
	USBD_SendMidiMessages();
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xB0, 0x20 + channel_zone, lo);
	USBD_SendMidiMessages();
}

void HUI_VPotMove(uint8_t pot, uint8_t delta)
{
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xB0, 0x40 + pot, delta);
	USBD_SendMidiMessages();
}


//----Receiving HUI Messages from DAW

uint8_t HUI_DetectPing(uint8_t* msg)
{
	if (msg[0] == 0x90 && msg[1] == 0 && msg[2] == 0){return(1);}
	else {return(0);}
}

uint8_t HUI_DetectHdr(uint8_t* msg)
{
	if (msg[0] == 0xF0 && msg[1] == 0 && msg[2] == 0 && msg[3] == 0x66 && msg[4] == 5 && msg[5] == 0) {
		return(1);}
	else {return(0);}
}

uint8_t HUI_DetectZone(uint8_t* msg)
{
	if ((msg[0] == 0xB0) && (msg[1] == 0x0C)) {return(msg[2] & 0x1F);}
	else{return(0xFF);}
}

void HUI_DetectButton(uint8_t* msg)
{
	uint8_t state = 0xFF;
	static uint8_t zone;
	if(HUI_DetectZone(msg) != 0xFF) {zone = HUI_DetectZone(msg);}

	if ((msg[0] == 0xB0) && (msg[1] == 0x2C))
	{
		switch (msg[2] & 0xF0)
		{
			case 0x40:
				state = 1;
				break;
			case 0:
				state = 0;
				break;
			default:
				break;
		}
		if (state != 0xFF && zone <= 0x07)
		{
			switch (msg[2] & 0x0F)
			{
				case HUI_PORT_CHANNEL_SELECT:
					SelectBank[zone] = state;
					break;
				case HUI_PORT_CHANNEL_MUTE:
					MuteBank[zone] = state;
					break;
				case HUI_PORT_CHANNEL_SOLO:
					SoloBank[zone] = state;
					break;
				default:
					break;
			}
		}
	}
}

void HUI_DetectFaderPosition(uint8_t* msg)
{
	static uint8_t hi;

	if(msg[0] == 0xB0 && msg[1] <= HUI_ZONE_CHANNEL8 && msg[1] >= HUI_ZONE_CHANNEL1)
	{
		hi = msg[2];
	}
	if(msg[0] == 0xB0 && ((msg[1]&0xF0) == 0x20) && ((msg[1] & 0x0F) <= HUI_ZONE_CHANNEL8) && ((msg[1] & 0x0F) >= HUI_ZONE_CHANNEL1))
	{
		FaderPositions[msg[1] & 0x0F] = (hi<<7) + msg[2];
	}
}

void HUI_DetectVULevel(uint8_t* msg)
{
	if(msg[0] == 0xA0){VULevel[msg[1] + (8*(msg[2] & 0xF0)>>4)] = msg[2] & 0x0F;}
}

/*	Original set of characters, simplified in next array
    char HUI_SmallDisplay[] = {
	"ì","↑","→","↓","←","¿","à","Ø","ø","ò","ù","Ň","Ç","ê","É","é",
	"è","Æ","æ","Å","å","Ä","ä","Ö","ö","Ü","ü","°","°","ß","£","¥",
	" ","!","\"","#","$","%","&","'","(",")","*","+",",","-",".","/",
	"0","1","2","3","4","5","6","7","8","9",":",";","<","=",">","\?",
	"@","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O",
	"P","Q","R","S","T","U","V","W","X","Y","Z","[","\\","]","^","_",
	"`","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o",
	"p","q","r","s","t","u","v","w","x","y","z","{","|","}","~","░"};*/

void HUI_DetectSmallDisplay(uint8_t* msg)
{
	uint8_t i;
	const char HUI_SmallDisplay[] = {
		0x20,'^','>','v','<','\?','a','O','o','o','u','N','C','e','E','e',
		'e','E','e','A','a','A','a','O','o','U','u','C','F','B','L','Y',
		' ','!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/',
		'0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','\?',
		'@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
		'P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_',
		'`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o',
		'p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',' '};

	if (HUI_DetectHdr(msg))
	{
		if((msg[6] == 0x10) && (msg[7] <= 7) && (msg[12] == 0xF7))
		{
			for (i = 0; i < 4; i++)
			{
				DisplayBank[msg[7]][i] = HUI_SmallDisplay[msg[8+i] & 0x7F];
			}
		}
	}
}

void HUI_Rx(uint8_t* msg)
{
	//if Ping found respond with Ping
	if (HUI_DetectPing(msg)){HUI_Ping();}
	HUI_DetectVULevel(msg);
	HUI_DetectButton(msg);
	HUI_DetectFaderPosition(msg);
	HUI_DetectSmallDisplay(msg);
}
