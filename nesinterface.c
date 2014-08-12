
#include "nesinterface.h"


static int latchPin;
static int pulsePin;
static int dataPin;

static boolean buttonDown[8];
static boolean buttonLatch[8];


void nes_init( int nesPulsePin, int nesLatchPin, int nesDataPin )
{
    latchPin = nesLatchPin;
    pulsePin = nesPulsePin;
    dataPin  = nesDataPin;

    pinMode( latchPin, OUTPUT );
    pinMode( pulsePin, OUTPUT );
    pinMode( dataPin,  INPUT  );
}

void nes_update()
{
    unsigned char i;
    boolean newButtonValue;

    digitalWrite( latchPin, HIGH );
    digitalWrite( latchPin, LOW  );

    for( i = 0 ; i < 8 ; ++i )
    {
        newButtonValue = digitalRead( dataPin ) == LOW;

        digitalWrite( pulsePin, HIGH );
        digitalWrite( pulsePin, LOW  );

        if( !buttonDown[i] && newButtonValue ) {// When the button goes from up to pressed:
            buttonLatch[i] = true;				// Set the latch
        }

        buttonDown[i]  = newButtonValue;
    }
}

boolean nes_buttonDown( unsigned char button )
{
    return buttonDown[ button & 7 ];
}

boolean nes_buttonLatch( unsigned char button )
{
    return buttonLatch[ button & 7 ];
}

void nes_resetButtonLatches()
{
    unsigned char i;
    for( i = 0 ; i < 8 ; ++i ) buttonLatch[i] = false;
}


