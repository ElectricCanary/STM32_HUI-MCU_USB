/*
 * HUImsg.h
 *
 *  Created on: Oct 7, 2021
 *      Author: Electric Canary
 */

#ifndef INC_HUI_H_
#define INC_HUI_H_

#include "USB/usbd_midi.h"

//Channels Ports & Zones
#define HUI_ZONE_CHANNEL1 0
#define HUI_ZONE_CHANNEL2 1
#define HUI_ZONE_CHANNEL3 2
#define HUI_ZONE_CHANNEL4 3
#define HUI_ZONE_CHANNEL5 4
#define HUI_ZONE_CHANNEL6 5
#define HUI_ZONE_CHANNEL7 6
#define HUI_ZONE_CHANNEL8 7
#define HUI_PORT_CHANNEL_FADER 0
#define HUI_PORT_CHANNEL_SELECT 1
#define HUI_PORT_CHANNEL_MUTE 2
#define HUI_PORT_CHANNEL_SOLO 3
#define HUI_PORT_CHANNEL_AUTO 4
#define HUI_PORT_CHANNEL_VSEL 5
#define HUI_PORT_CHANNEL_INSERT 6
#define HUI_PORT_CHANNEL_RECRDY 7

//Keyboard Shortcuts Ports & Zone
#define HUI_ZONE_KEYBOARD 8
#define HUI_PORT_KEYBOARD_CTRL 0
#define HUI_PORT_KEYBOARD_SHIFT 1
#define HUI_PORT_KEYBOARD_EDITMODE 2
#define HUI_PORT_KEYBOARD_UNDO 3
#define HUI_PORT_KEYBOARD_ALT 4
#define HUI_PORT_KEYBOARD_OPTION 5
#define HUI_PORT_KEYBOARD_EDITTOOL 6
#define HUI_PORT_KEYBOARD_SAVE 7

//Window Ports & Zone
#define HUI_ZONE_WINDOW 9
#define HUI_PORT_WINDOW_MIX 0
#define HUI_PORT_WINDOW_EDIT 1
#define HUI_PORT_WINDOW_TRANSPORT 2
#define HUI_PORT_WINDOW_MEMLOC 3
#define HUI_PORT_WINDOW_STATUS 4
#define HUI_PORT_WINDOW_ALTER 5

//Channels & Bank Moves Ports & Zone
#define HUI_ZONE_MOVE 0x0A
#define HUI_PORT_MOVE_CHANNELDOWN 0
#define HUI_PORT_MOVE_BANKDOWN 1
#define HUI_PORT_MOVE_CHANNELUP 2
#define HUI_PORT_MOVE_BANKUP 3

//Assignment 1 Ports & Zone
#define HUI_ZONE_ASSIGN1 0x0B
#define HUI_PORT_ASSIGN1_OUTPUT 0
#define HUI_PORT_ASSIGN1_INPUT 1
#define HUI_PORT_ASSIGN1_PAN 2
#define HUI_PORT_ASSIGN1_SENDE 3
#define HUI_PORT_ASSIGN1_SENDD 4
#define HUI_PORT_ASSIGN1_SENDC 5
#define HUI_PORT_ASSIGN1_SENDB 6
#define HUI_PORT_ASSIGN1_SENDA 7

//Assignment 2 Ports & Zone
#define HUI_ZONE_ASSIGN2 0x0C
#define HUI_PORT_ASSIGN2_ASSIGN 0
#define HUI_PORT_ASSIGN2_DEFAULT 1
#define HUI_PORT_ASSIGN2_SUSPEND 2
#define HUI_PORT_ASSIGN2_SHIFT 3
#define HUI_PORT_ASSIGN2_MUTE 4
#define HUI_PORT_ASSIGN2_BYPASS 5
#define HUI_PORT_ASSIGN2_RECRDYAL 6

//Cursor Movement Ports & Zone
#define HUI_ZONE_CURSOR 0x0D
#define HUI_PORT_CURSOR_DOWN 0
#define HUI_PORT_CURSOR_LEFT 1
#define HUI_PORT_CURSOR_MODE 2
#define HUI_PORT_CURSOR_RIGHT 3
#define HUI_PORT_CURSOR_UP 4
#define HUI_PORT_CURSOR_SCRUB 5
#define HUI_PORT_CURSOR_SHUTTLE 6

//Transporter Main Ports & Zone
#define HUI_ZONE_TRANSPORT 0x0E
#define HUI_PORT_TRANSPORT_TALKBACK 0
#define HUI_PORT_TRANSPORT_REWIND 1
#define HUI_PORT_TRANSPORT_FASTFWD 2
#define HUI_PORT_TRANSPORT_STOP 3
#define HUI_PORT_TRANSPORT_PLAY 4
#define HUI_PORT_TRANSPORT_RECORD 5

//Transporter Loop/Rtz/End Ports & Zone
#define HUI_ZONE_LOOP 0x0F
#define HUI_PORT_LOOP_RTZ 0
#define HUI_PORT_LOOP_END 1
#define HUI_PORT_LOOP_ONLINE 2
#define HUI_PORT_LOOP_LOOP 3
#define HUI_PORT_LOOP_QCKPNCH 4

//Transporter Punch Ports & Zone
#define HUI_ZONE_PUNCH 0x10
#define HUI_PORT_PUNCH_AUDITION 0
#define HUI_PORT_PUNCH_PRE 1
#define HUI_PORT_PUNCH_IN 2
#define HUI_PORT_PUNCH_OUT 3
#define HUI_PORT_PUNCH_POST 4

//Monitor Input Ports & Zone
#define HUI_ZONE_MONIN 0x11
#define HUI_PORT_MONIN_INPUT3 0
#define HUI_PORT_MONIN_INPUT2 1
#define HUI_PORT_MONIN_INPUT1 2
#define HUI_PORT_MONIN_MUTE 3
#define HUI_PORT_MONIN_DISCRETE 4

//Monitor Output Ports & Zone
#define HUI_ZONE_MONOUT 0x12
#define HUI_PORT_MONOUT_OUTPUT3 0
#define HUI_PORT_MONOUT_OUTPUT2 1
#define HUI_PORT_MONOUT_OUTPUT1 2
#define HUI_PORT_MONOUT_DIM 3
#define HUI_PORT_MONOUT_MONO 4

//NumPad 1 Ports & Zone
#define HUI_ZONE_NUM1 0x13
#define HUI_PORT_NUM1_0 0
#define HUI_PORT_NUM1_1 1
#define HUI_PORT_NUM1_4 2
#define HUI_PORT_NUM1_2 3
#define HUI_PORT_NUM1_5 4
#define HUI_PORT_NUM1_POINT 5
#define HUI_PORT_NUM1_3 6
#define HUI_PORT_NUM1_6 7

//NumPad 2 Ports & Zone
#define HUI_ZONE_NUM2 0x14
#define HUI_PORT_NUM2_ENTER 0
#define HUI_PORT_NUM2_PLUS 1

//NumPad 3 Ports & Zone
#define HUI_ZONE_NUM3 0x15
#define HUI_PORT_NUM3_7 0
#define HUI_PORT_NUM3_8 1
#define HUI_PORT_NUM3_9 2
#define HUI_PORT_NUM3_MINUS 3
#define HUI_PORT_NUM3_CLR 4
#define HUI_PORT_NUM3_EQUAL 5
#define HUI_PORT_NUM3_DIVIDE 6
#define HUI_PORT_NUM3_MULTIPLY 7

//Timecode LEDs Ports & Zone (No buttons Associated)
#define HUI_ZONE_TIMECODE 0x16
#define HUI_PORT_TIMECODE_TIMECODE 0
#define HUI_PORT_TIMECODE_FEET 1
#define HUI_PORT_TIMECODE_BEAT 2
#define HUI_PORT_TIMECODE_RUDESOLO 3

//Auto Enable Ports & Zone
#define HUI_ZONE_AUTOEN 0x17
#define HUI_PORT_AUTOEN_PLUGIN 0
#define HUI_PORT_AUTOEN_PAN 1
#define HUI_PORT_AUTOEN_FADER 2
#define HUI_PORT_AUTOEN_SENDMUTE 3
#define HUI_PORT_AUTOEN_SEND 4
#define HUI_PORT_AUTOEN_MUTEAUTO 5

//Auto Mode Ports & Zone
#define HUI_ZONE_AUTOMODE 0x18
#define HUI_PORT_AUTOMODE_TRIM 0
#define HUI_PORT_AUTOMODE_LATCH 1
#define HUI_PORT_AUTOMODE_READ 2
#define HUI_PORT_AUTOMODE_AUTOOFF 3
#define HUI_PORT_AUTOMODE_WRITE 4
#define HUI_PORT_AUTOMODE_TOUCH 5

//Status\Group Ports & Zone
#define HUI_ZONE_GROUP 0x19
#define HUI_PORT_GROUP_PHASE 0
#define HUI_PORT_GROUP_MONITOR 1
#define HUI_PORT_GROUP_AUTO 2
#define HUI_PORT_GROUP_SUSPEND 3
#define HUI_PORT_GROUP_CREATE 4
#define HUI_PORT_GROUP_GROUP 5

//Edit Ports & Zone
#define HUI_ZONE_EDIT 0x1A
#define HUI_PORT_EDIT_PASTE 0
#define HUI_PORT_EDIT_CUT 1
#define HUI_PORT_EDIT_CAPTURE 2
#define HUI_PORT_EDIT_DELETE 3
#define HUI_PORT_EDIT_COPY 4
#define HUI_PORT_EDIT_SEPARATE 5

//Function Keys Ports & Zone
#define HUI_ZONE_FUNCTION 0x1B
#define HUI_PORT_FUNCTION_F1 0
#define HUI_PORT_FUNCTION_F2 1
#define HUI_PORT_FUNCTION_F3 2
#define HUI_PORT_FUNCTION_F4 3
#define HUI_PORT_FUNCTION_F5 4
#define HUI_PORT_FUNCTION_F6 5
#define HUI_PORT_FUNCTION_F7 6
#define HUI_PORT_FUNCTION_F8 7

//Parameters Edit Ports & Zone
#define HUI_ZONE_PARAM 0x1C
#define HUI_PORT_PARAM_INSPARA 0
#define HUI_PORT_PARAM_ASSIGN 1
#define HUI_PORT_PARAM_SELECT1 2
#define HUI_PORT_PARAM_SELECT2 3
#define HUI_PORT_PARAM_SELECT3 4
#define HUI_PORT_PARAM_SELECT4 5
#define HUI_PORT_PARAM_BYPASS 6
#define HUI_PORT_PARAM_COMPARE 7

//Click/Beep/Relays/Footswitch Ports & Zone (no buttons associated or LEDs)
#define HUI_ZONE_CLICK 0x1D
#define HUI_PORT_CLICK_RELAY1 0
#define HUI_PORT_CLICK_RELAY2 1
#define HUI_PORT_CLICK_CLICK 2
#define HUI_PORT_CLICK_BEEP 3



//-----Sending MIDI to DAW

//Sends a Ping (note)
void HUI_Ping(void);

//Sends Button Push/Release signal corresponding to the zone and port
void HUI_ButtonPush(uint8_t zone, uint8_t port);
void HUI_ButtonRelease(uint8_t zone, uint8_t port);

//Sends fader position, 16-bit input, internal precision is 14-bit
void HUI_FaderMove(uint8_t channel_zone, uint16_t pos);

//Sends V-Pot Move, only works with delta
void HUI_VPotMove(uint8_t pot, uint8_t delta);



//-----Receiving MIDI from DAW

//Returns 1 when Ping from DAW is detected
uint8_t HUI_DetectPing(uint8_t* msg);

//Returns 1 when SysEx Header from DAW is detected
uint8_t HUI_DetectHdr(uint8_t* msg);

//Returns currently selected zone
uint8_t HUI_DetectZone(uint8_t* msg);

//Solo,Mute & Select state of the 8 current tracks
void HUI_DetectButton(uint8_t* msg);

//Update Fader Position Bank if moved in DAW
void HUI_DetectFaderPosition(uint8_t* msg);

//Detects Level for each stereo channel
void HUI_DetectVULevel(uint8_t* msg);

//Array of the names for each current track (8 times 4 char)
extern int HUI_SmallDisplayBank[8][4];
void HUI_DetectSmallDisplay(uint8_t* msg);

//Function for all HUI Detection
void HUI_Rx(uint8_t* msg);

#endif /* INC_HUI_H_ */
