/*
 * MCU.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Electric Canary
 */

#ifndef INC_MCU_H_
#define INC_MCU_H_

#include <stdint.h>

//MCU IDs
#define MCU_ID_RECRDY1 0x00
#define MCU_ID_RECRDY2 0x01
#define MCU_ID_RECRDY3 0x02
#define MCU_ID_RECRDY4 0x03
#define MCU_ID_RECRDY5 0x04
#define MCU_ID_RECRDY6 0x05
#define MCU_ID_RECRDY7 0x06
#define MCU_ID_RECRDY8 0x07
#define MCU_ID_SOLO1 0x08
#define MCU_ID_SOLO2 0x09
#define MCU_ID_SOLO3 0x0A
#define MCU_ID_SOLO4 0x0B
#define MCU_ID_SOLO5 0x0C
#define MCU_ID_SOLO6 0x0D
#define MCU_ID_SOLO7 0x0E
#define MCU_ID_SOLO8 0x0F
#define MCU_ID_MUTE1 0x10
#define MCU_ID_MUTE2 0x11
#define MCU_ID_MUTE3 0x12
#define MCU_ID_MUTE4 0x13
#define MCU_ID_MUTE5 0x14
#define MCU_ID_MUTE6 0x15
#define MCU_ID_MUTE7 0x16
#define MCU_ID_MUTE8 0x17
#define MCU_ID_SELECT1 0x18
#define MCU_ID_SELECT2 0x19
#define MCU_ID_SELECT3 0x1A
#define MCU_ID_SELECT4 0x1B
#define MCU_ID_SELECT5 0x1C
#define MCU_ID_SELECT6 0x1D
#define MCU_ID_SELECT7 0x1E
#define MCU_ID_SELECT8 0x1F
#define MCU_ID_VSELECT1 0x20
#define MCU_ID_VSELECT2 0x21
#define MCU_ID_VSELECT3 0x22
#define MCU_ID_VSELECT4 0x23
#define MCU_ID_VSELECT5 0x24
#define MCU_ID_VSELECT6 0x25
#define MCU_ID_VSELECT7 0x26
#define MCU_ID_VSELECT8 0x27
#define MCU_ID_ASSIGN_TRACK 0x28
#define MCU_ID_ASSIGN_SEND 0x29
#define MCU_ID_ASSIGN_PAN 0x2A
#define MCU_ID_ASSIGN_PLUGIN 0x2B
#define MCU_ID_ASSIGN_EQ 0x2C
#define MCU_ID_ASSIGN_DYN 0x2D
#define MCU_ID_BANKS_BANKLEFT 0x2E
#define MCU_ID_BANKS_BANKRIGHT 0x2F
#define MCU_ID_BANKS_CHANLEFT 0x30
#define MCU_ID_BANKS_CHANRIGHT 0x31
#define MCU_ID_FLIP 0x32
#define MCU_ID_EDIT 0x33
#define MCU_ID_NAME 0x34
#define MCU_ID_SMPTE 0x35
#define MCU_ID_F1 0x36
#define MCU_ID_F2 0x37
#define MCU_ID_F3 0x38
#define MCU_ID_F4 0x39
#define MCU_ID_F5 0x3A
#define MCU_ID_F6 0x3B
#define MCU_ID_F7 0x3C
#define MCU_ID_F8 0x3D
#define MCU_ID_VIEW_MIDI 0x3E
#define MCU_ID_VIEW_INPUTS 0x3F
#define MCU_ID_VIEW_TRACKS 0x40
#define MCU_ID_VIEW_INSTR 0x41
#define MCU_ID_VIEW_AUX 0x42
#define MCU_ID_VIEW_BUS 0x43
#define MCU_ID_VIEW_OUTPUTS 0x44
#define MCU_ID_VIEW_USER 0x45
#define MCU_ID_SHIFT 0x46
#define MCU_ID_OPTION 0x47
#define MCU_ID_CONTROL 0x48
#define MCU_ID_ALT 0x49
#define MCU_ID_AUTO_READ 0x4A
#define MCU_ID_AUTO_WRITE 0x4B
#define MCU_ID_AUTO_TRIM 0x4C
#define MCU_ID_AUTO_TOUCH 0x4D
#define MCU_ID_AUTO_LATCH 0x4E
#define MCU_ID_GROUP 0x4F
#define MCU_ID_UTIL_SAVE 0x50
#define MCU_ID_UTIL_UNDO 0x51
#define MCU_ID_UTIL_CANCEL 0x52
#define MCU_ID_UTIL_ENTER 0x53
#define MCU_ID_MARKER 0x54
#define MCU_ID_NUDGE 0x55
#define MCU_ID_CYCLE 0x56
#define MCU_ID_DROP 0x57
#define MCU_ID_REPLACE 0x58
#define MCU_ID_CLICK 0x59
#define MCU_ID_SOLO 0x5A
#define MCU_ID_REWIND 0x5B
#define MCU_ID_FASTFWD 0x5C
#define MCU_ID_STOP 0x5D
#define MCU_ID_PLAY 0x5E
#define MCU_ID_RECORD 0x5F
#define MCU_ID_CURSOR_UP 0x60
#define MCU_ID_CURSOR_DOWN 0x61
#define MCU_ID_CURSOR_LEFT 0x62
#define MCU_ID_CURSOR_RIGHT 0x63
#define MCU_ID_ZOOM 0x64
#define MCU_ID_SCRUB 0x65
#define MCU_ID_USERSWITCHA 0x66
#define MCU_ID_USERSWITCHB 0x67
#define MCU_ID_FADERTOUCH1 0x68
#define MCU_ID_FADERTOUCH2 0x69
#define MCU_ID_FADERTOUCH3 0x6A
#define MCU_ID_FADERTOUCH4 0x6B
#define MCU_ID_FADERTOUCH5 0x6C
#define MCU_ID_FADERTOUCH6 0x6D
#define MCU_ID_FADERTOUCH7 0x6E
#define MCU_ID_FADERTOUCH8 0x6F
#define MCU_ID_FADERTOUCHMASTER 0x70
#define MCU_ID_SMPTELED 0x71
#define MCU_ID_BEATSLED 0x72
#define MCU_ID_RUDESOLOLIGHT 0x73
#define MCU_ID_RELAY 0x76



//1 if the Init went correctly
extern uint8_t MCU_Connected;
//Checks Connection with Host
void MCU_Init(uint8_t* msg);
uint8_t MCU_DetectDeviceQuery(uint8_t* msg);
void MCU_HostConnectionQuery(void);
void MCU_HostConnectionConfirmation(void);
void MCU_HostConnectionError(void);
uint8_t MCU_DetectHostConnectionReply(uint8_t* msg);



//----- Sending MIDI to DAW

//Send Button Push/Release Signal
void MCU_ButtonPush(uint8_t id);
void MCU_ButtonRelease(uint8_t id);

//Send fader position, 16-bit input, internal precision is 14-bit
void MCU_FaderMove(uint8_t channel, uint16_t pos);



//----- Receiving MIDI from DAW

//Detects Offline Signal
uint8_t MCU_DetectOffline(uint8_t* msg);

//Detects ExSys Header
uint8_t MCU_DetectHdr(uint8_t* msg);

//Updates Solo/Mute/Select banks
void MCU_DetectButton(uint8_t* msg);

//Updates Fader Positions Bank
void MCU_DetectFaderPosition(uint8_t* msg);

//Updates VULevel Bank
void MCU_DetectVULevel(uint8_t* msg);

//Updates Display Bank
void MCU_DetectDisplay(uint8_t* msg);

//General Rx function for MCU Protocol
void MCU_Rx(uint8_t* msg);

#endif /* INC_MCU_H_ */
