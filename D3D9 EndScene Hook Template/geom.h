#pragma once
#include "stdafx.h"
#include <algorithm>

const float PI = 3.1415927f;

//vector and matrix classes modified from AC source
struct vec3
{
	float x, y, z;

	vec3() { x = y = z = 0; }
	vec3(float a, float b, float c) : x(a), y(b), z(c) {}
	vec3(float a, float b) : x(a), y(b), z(0) {}

	vec3(float *v) : x(v[0]), y(v[1]), z(v[2]) {}

	vec3 scaleFixedPoint(float scalex, float scaley, vec3 fixedPoint)
	{
		vec3 newvec;
		newvec.x = x * scalex + fixedPoint.x*(1 - scalex);
		newvec.y = y * scaley + fixedPoint.y*(1 - scaley);
		return newvec;
	}
};

struct vec4
{
	union
	{
		struct { float x, y, z, w; };
		float v[4];
	};
	vec4() {}
	explicit vec4(const vec3 &p, float w = 0) : x(p.x), y(p.y), z(p.z), w(w) {}
	vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
	float &operator[](int i) { return v[i]; }
	float  operator[](int i) const { return v[i]; }
};

vec3 Add(vec3 src, vec3 dst);

vec3 Subtract(vec3 src, vec3 dst);

float Magnitude(vec3 vec);

float Distance(vec3 src, vec3 dst);

vec3 Normalize(vec3 src);

vec3 CalcAngle(vec3 src, vec3 dst);

bool WorldToScreen(vec3 pos, vec3 &screen, float v[16], int windowWidth, int windowHeight);

float RadianToDegree(float radian);

float DegreeToRadian(float degree);

vec3 RadianToDegree(vec3 radians);

vec3 DegreeToRadian(vec3 degrees);

float DotProduct(vec3 src, vec3 dst);