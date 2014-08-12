#ifndef __LCDWOLF3D_H
#define __LCDWOLF3D_H

#include <WProgram.h>

#define UNSIGNED_DIFF( _a, _b ) ( (_a) < (_b) ? (_b) - (_a) : (_a) - (_b) )
#define SET_PIXEL( _x, _y ) ( screenBuffer.data[ (_x) + 128 * ((_y) / 8) ] |=  ( 1 << ( (_y) % 8 ) ) )
#define CLR_PIXEL( _x, _y ) ( screenBuffer.data[ (_x) + 128 * ((_y) / 8) ] &= ~( 1 << ( (_y) % 8 ) ) )
#define FLP_PIXEL( _x, _y ) ( screenBuffer.data[ (_x) + 128 * ((_y) / 8) ] ^=  ( 1 << ( (_y) % 8 ) ) )

#define GET_WALL_DOT( _z, _x, _y ) pgm_read_byte( &_z[ (_x) + ( ((_y) >> 3) << 6 ) ] ) & ( 1 << ( (_y) % 8 ) )

#define BLOCK_SIZE    20
#define BLOCK_SIZE_F  20.0f

#define HIT_WIDTH 5.0f

#define MAP_WIDTH   24
#define MAP_HEIGHT  24

#define VISPLANEDIST_TIMES_WALLHEIGHT  2000.0f

// Holds the result of a ray being cast.
struct SLICE
{
    uint8_t targetBlockX;
    uint8_t targetBlockY;
    uint8_t textureId;
    uint8_t textureOffset;
    uint8_t sliceHeight;
};

struct SCREENBUFFER
{
    uint8_t width;
    uint8_t height;
    uint8_t data[1024];
};

#endif//__LCDWOLF3D_H
