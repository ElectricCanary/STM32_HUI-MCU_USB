/*
 * protocol.h
 *
 *  Created on: 12 oct. 2021
 *  Author: Electric Canary
 *
 *  Protocol join the different protocols used (HUI, MCU & MIDI) for general use functions
 *  When sending a message it's better to use these functions
 */

#ifndef INC_PROTOCOL_H_
#define INC_PROTOCOL_H_

#include <stdint.h>

//Different protocols that can be used
typedef enum {HUI,MCU,MIDI,NO}Protocol;

//The currently used protocol
extern Protocol ProtocolUsed;

//Function to detect protocol when first plugged in
void DetectProtocol(uint8_t* msg);

//Returns the maximum number of characters that can be displayed (4 for HUI & 6 for MCU)
uint8_t MaxDisplayChar(void);

//Array for solo status of the 8 tracks (1 is soloed, 0 not solo)
extern uint8_t SoloBank[8];

//Array for mute status of the 8 tracks (1 is muted, 0 not muted)
extern uint8_t MuteBank[8];

//Array for select status of the 8 tracks (1 is selected, 0 not selected)
extern uint8_t SelectBank[8];

//Array for the fader 14 bit positions of the 8 tracks
extern uint16_t FaderPositions[8];

//Array for the name display of the 8 tracks
extern uint8_t DisplayBank[8][7];

//Array of VU-Levels on 8 Channels (L1 to L8 then R1 to R8)
extern uint8_t VULevel[16];



//Selects the correct protocol receive function
void Protocol_Rx(uint8_t* msg);

//Moves the fader
void FaderMove(uint8_t fader, uint16_t position);

//Sends a fader touch signal
void FaderTouch(uint8_t fader);

//Sends a fader release signal
void FaderRelease(uint8_t fader);

//Moves 8 tracks up
void MoveBankUp(void);

//Moves 8 tracks down
void MoveBankDown(void);

//Moves 1 track up
void MoveChannelUp(void);

//Moves 1 track down
void MoveChannelDown(void);

#endif /* INC_PROTOCOL_H_ */
