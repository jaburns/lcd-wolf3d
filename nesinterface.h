
#ifndef __NESINTERFACE_H
#define __NESINTERFACE_H

#include <WProgram.h>

#define NES_A      0
#define NES_B      1
#define NES_SELECT 2
#define NES_START  3
#define NES_UP     4
#define NES_DOWN   5
#define NES_LEFT   6
#define NES_RIGHT  7

#ifdef __cplusplus
extern "C" {
#endif



void nes_init( int nesPulsePin, int nesLatchPin, int nesDataPin );

void nes_update();

boolean nes_buttonDown(  unsigned char button );	// True when the button is currently depressed. False otherwise.
boolean nes_buttonLatch( unsigned char button );	// True from when a button is depressed until resetButtonLatches is called.

void nes_resetButtonLatches(); // After a button latch is reset, the button must be released and depressed for its latch to be true again.



#ifdef __cplusplus
}
#endif

#endif//__NESINTERFACE_H


