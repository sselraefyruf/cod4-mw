#include <cstdint>
#include "math/Vector.h"

class Refdef
{
public:
    uint32_t x; //0x0000
    uint32_t y; //0x0004
    uint32_t width; //0x0008
    uint32_t height; //0x000C
    Vector2 FOV; //0x0010
    Vector3 origin; //0x0018
    Vector3 Matrix[3]; //0x0024
    char pad_0058[28]; //0x0058
}; //Size: 0x0074

inline Refdef* refdef = (Refdef*)0x00797600;