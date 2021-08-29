#pragma once
#include "../Structs/Helper.h"

inline Vector3 Subtract(Vector3 src, Vector3 dst)
{
    Vector3 diff;
    diff.x = src.x - dst.x;
    diff.y = src.y - dst.y;
    diff.z = src.z - dst.z;
    return diff;
}

inline float DotProduct(Vector3 src, Vector3 dst)
{
    return src.x * dst.x + src.y * dst.y + src.z * dst.z;
}

inline bool WorldToScreen(Vector3 world, Vector2& screen)
{
    auto Position = Subtract(world, refdef->origin);
    Vector3 Transform;

    // get our dot products from viewAxis
    Transform.x = DotProduct(Position, refdef->Matrix[1]);
    Transform.y = DotProduct(Position, refdef->Matrix[2]);
    Transform.z = DotProduct(Position, refdef->Matrix[0]);

    // make sure it is in front of us
    if (Transform.z < 0.1f)
        return false;

    // get the center of the screen
    Vector2 Center;
    Center.x = (float)(refdef->width * 0.5f);
    Center.y = (float)(refdef->height * 0.5f);

    screen.x = Center.x * (1 - (Transform.x / refdef->FOV.x / Transform.z));
    screen.y = Center.y * (1 - (Transform.y / refdef->FOV.y / Transform.z));
    return true;
}