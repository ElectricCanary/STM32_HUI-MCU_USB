/*
 * MCU.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Electric Canary
 */

#include "MCU.h"
#include "../Inc/USB/usbd_midi_if.h"
#include "protocol.h"

uint8_t MCU_Connected;

void MCU_Init(uint8_t* msg)
{
	if(MCU_DetectDeviceQuery(msg))
	{
		MCU_HostConnectionQuery();
			if(MCU_DetectHostConnectionReply(msg)){
				MCU_Connected = 1;
				MCU_HostConnectionConfirmation();
			}
			else{
				MCU_Connected = 0;
				MCU_HostConnectionError();
			}
	}
}

//-----Sending MIDI to DAW

void MCU_HostConnectionQuery(void)
{
	uint8_t msg[] = {0xF0,0,0,0x66,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0,0,0,0,0xF7};

	USBD_AddSysExMessage(MIDI_CABLE, msg, 18);
	USBD_SendMidiMessages();
}

void MCU_HostConnectionConfirmation(void)
{
	uint8_t msg[] = {0xF0, 0, 0, 0x66, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7};

	USBD_AddSysExMessage(MIDI_CABLE, msg, 14);
	USBD_SendMidiMessages();
}

void MCU_HostConnectionError(void)
{
	uint8_t msg[] = {0xF0, 0, 0, 0x66, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF7};

	USBD_AddSysExMessage(MIDI_CABLE, msg, 14);
	USBD_SendMidiMessages();
}

void MCU_ButtonPush(uint8_t id)
{
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0x90, id, 0x7F);
	USBD_SendMidiMessages();
}

void MCU_ButtonRelease(uint8_t id)
{
	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0x90, id, 0);
	USBD_SendMidiMessages();
}

void MCU_FaderMove(uint8_t channel, uint16_t pos)
{
	uint16_t position = pos << 2;
	uint8_t hi = (uint8_t)(position >> 7);
	uint8_t lo = (uint8_t)(position & 0x7F);

	USBD_MidiMessage(MIDI_CABLE, MIDI_CHANNEL, 0xE0 + channel, lo, hi);
	USBD_SendMidiMessages();
}

//----Receiving HUI Messages from DAW

uint8_t MCU_DetectOffline(uint8_t* msg)
{
	if(MCU_DetectHdr(msg) && msg[5]==0x0F && msg[6] == 0x7F && msg[7] == 0xF7){return(1);}
	else{return(0);}
}

uint8_t MCU_DetectDeviceQuery(uint8_t* msg)
{
	if(MCU_DetectHdr(msg) && msg[5] == 0 && msg[6] == 0xF7)
	{
		return(1);
	}
	else {return(0);}
}

uint8_t MCU_DetectHostConnectionReply(uint8_t* msg)
{
	uint16_t i;
	//uint8_t j;
	//uint8_t expected[] = {0xF0,0,0,0x66,0x00,2,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0,0,0,1,0xF7};

	for(i = 0; i<300; i++){
			if(MCU_DetectHdr(msg)){
				if(msg[5]==2 && msg[6]==0x00 && msg[7]==0x00 && msg[8]==0x00 && msg[9]==0x00 && msg[10]==0x00 && msg[11]==0x00 && msg[12]==0x00 && msg[13]==0 && msg[14]==0 && msg[15]==0 && msg[16]==1 && msg[17]==0xF7){
					return(1);
				}
			}
			HAL_Delay(1);
		}
	return(0);
}

uint8_t MCU_DetectHdr(uint8_t* msg)
{
	if (msg[0] == 0xF0 && msg[1] == 0 && msg[2] == 0 && msg[3] == 0x66) {return(1);}
	else {return(0);}
}

void MCU_DetectButton(uint8_t* msg)
{
	uint8_t state = 0xFF;

	if (msg[0] == 0x90)
	{
		switch (msg[2])
		{
			case 0x7F:
				state = 1;
				break;
			case 0x01:		//Probably shouldn't be here be makes it work with Reaper
				state = 1;
				break;
			case 0:
				state = 0;
				break;
			default:
				break;
		}
		if (state != 0xFF)
		{
			if((msg[1]>= MCU_ID_SELECT1) && (msg[1] <= MCU_ID_SELECT8))
			{
				SelectBank[msg[1] - MCU_ID_SELECT1] = state;
			}
			if((msg[1]>= MCU_ID_MUTE1) && (msg[1] <= MCU_ID_MUTE8))
			{
				MuteBank[msg[1] - MCU_ID_MUTE1] = state;
			}
			if((msg[1]>= MCU_ID_SOLO1) && (msg[1] <= MCU_ID_SOLO8))
			{
				SoloBank[msg[1] - MCU_ID_SOLO1] = state;
			}
		}
	}
}

void MCU_DetectFaderPosition(uint8_t* msg)
{
	if(((msg[0] & 0xF0) == 0xE0) && ((msg[0] & 0x0F) >= 0) && ((msg[0] & 0x0F) <= 7))
	{
		FaderPositions[msg[0] & 0x0F] = (msg[2]<<7) + msg[1];
	}
}

void MCU_DetectVULevel(uint8_t* msg)
{
	if(msg[0] == 0xD0)
	{
		VULevel[msg[1] & 0xF0] = msg[1] & 0x0F;
		VULevel[(msg[1] & 0xF0)+7] = msg[1] & 0x0F; //Duplicate Level for Right
	}
}

void MCU_DetectDisplay(uint8_t* msg)
{
	uint8_t i;

	if(MCU_DetectHdr(msg))
	{
		if (msg[5] == 0x12 && msg[14] == 0xF7)
		{
			for(i = 0; i < 7; i++)
			{
				DisplayBank[(msg[6]/7)][i] = msg[i+7];
			}
		}
	}
}

void MCU_Rx(uint8_t* msg)
{
	//if(!MCU_Connected){MCU_Init(msg);}
	if(MCU_DetectOffline(msg)){MCU_Connected = 0;}
	MCU_DetectButton(msg);
	MCU_DetectFaderPosition(msg);
	MCU_DetectVULevel(msg);
	MCU_DetectDisplay(msg);
}
