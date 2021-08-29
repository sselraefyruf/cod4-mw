#pragma once
#include "math/Vector.h"

class c_entity
{
public:
    char pad_0000[28]; //0x0000
    Vector3 origin; //0x001C
    char pad_0028[32]; //0x0028
}; //Size: 0x0048
