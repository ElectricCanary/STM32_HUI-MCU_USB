/*
 * protocol.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Electric Canary
 */

#include "protocol.h"
#include "HUI.h"
#include "MCU.h"

uint8_t SoloBank[8];
uint8_t SoloBank[8];
uint8_t MuteBank[8];
uint8_t SelectBank[8] = {[0 ... 7] = 0xFF};
uint16_t FaderPositions[8];
uint8_t DisplayBank[8][7] = {[0 ... 7][0 ... 6] = 0xFF};
uint8_t VULevel[16];

Protocol ProtocolUsed = NO;

void DetectProtocol(uint8_t* msg)
{
	if(HUI_DetectHdr(msg))
		{
			ProtocolUsed = HUI;
		}
	else if(MCU_DetectHdr(msg)){ProtocolUsed = MCU;}
}

uint8_t MaxDisplayChar(void)
{
	switch (ProtocolUsed) {
		case HUI:
			return(4);
			break;
		case MCU:
			return(7);
			break;
		default:
			return(4);
			break;
	}
}

void Protocol_Rx(uint8_t* msg)
{
	if(ProtocolUsed == NO)
	{
		DetectProtocol(msg);
	}
	switch (ProtocolUsed)
	{
		case HUI:
			HUI_Rx(msg);
			break;
		case MCU:
			MCU_Rx(msg);
			break;
		case MIDI:
			break;
		default:
			HUI_Rx(msg);
			break;
	}
}

void FaderTouch(uint8_t fader)
{
	switch (ProtocolUsed) {
			case HUI:
				HUI_ButtonPush(fader, HUI_PORT_CHANNEL_FADER);
				break;
			case MCU:
				MCU_ButtonPush(MCU_ID_FADERTOUCH1 + fader);
				break;
			case MIDI:
				break;
			default:
				break;
		}
}

void FaderRelease(uint8_t fader)
{
	switch (ProtocolUsed) {
			case HUI:
				HUI_ButtonRelease(fader, HUI_PORT_CHANNEL_FADER);
				break;
			case MCU:
				MCU_ButtonRelease(MCU_ID_FADERTOUCH1 + fader);
				break;
			case MIDI:
				break;
			default:
				break;
		}
}

void FaderMove(uint8_t fader, uint16_t position)
{
	switch (ProtocolUsed) {
			case HUI:
				HUI_FaderMove(fader, position);
				break;
			case MCU:
				MCU_FaderMove(fader, position);
				break;
			case MIDI:
				break;
			default:
				break;
		}
}

void MoveChannelUp(void)
{
	switch (ProtocolUsed) {
			case HUI:
				HUI_ButtonPush(HUI_ZONE_MOVE,HUI_PORT_MOVE_CHANNELUP);
				HUI_ButtonRelease(HUI_ZONE_MOVE,HUI_PORT_MOVE_CHANNELUP);
				break;
			case MCU:
				MCU_ButtonPush(MCU_ID_BANKS_CHANRIGHT);
				MCU_ButtonRelease(MCU_ID_BANKS_CHANRIGHT);
				break;
			case MIDI:
				break;
			default:
				break;
		}
}

void MoveChannelDown(void)
{
	switch (ProtocolUsed) {
			case HUI:
				HUI_ButtonPush(HUI_ZONE_MOVE,HUI_PORT_MOVE_CHANNELDOWN);
				HUI_ButtonRelease(HUI_ZONE_MOVE,HUI_PORT_MOVE_CHANNELDOWN);
				break;
			case MCU:
				MCU_ButtonPush(MCU_ID_BANKS_CHANLEFT);
				MCU_ButtonRelease(MCU_ID_BANKS_CHANLEFT);
				break;
			case MIDI:
				break;
			default:
				break;
		}
}

void MoveBankUp(void)
{
	switch (ProtocolUsed) {
			case HUI:
				HUI_ButtonPush(HUI_ZONE_MOVE,HUI_PORT_MOVE_BANKUP);
				HUI_ButtonRelease(HUI_ZONE_MOVE,HUI_PORT_MOVE_BANKUP);
				break;
			case MCU:
				MCU_ButtonPush(MCU_ID_BANKS_BANKRIGHT);
				MCU_ButtonRelease(MCU_ID_BANKS_BANKRIGHT);
				break;
			case MIDI:
				break;
			default:
				break;
		}
}

void MoveBankDown()
{
	switch (ProtocolUsed) {
			case HUI:
				HUI_ButtonPush(HUI_ZONE_MOVE,HUI_PORT_MOVE_BANKDOWN);
				HUI_ButtonRelease(HUI_ZONE_MOVE,HUI_PORT_MOVE_BANKDOWN);
				break;
			case MCU:
				MCU_ButtonPush(MCU_ID_BANKS_BANKLEFT);
				MCU_ButtonRelease(MCU_ID_BANKS_BANKLEFT);
				break;
			case MIDI:
				break;
			default:
				break;
		}
}
