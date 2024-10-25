#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <raylib.h>
#include <vector>
struct Sun
{
    Vector2 Position;
    float radius;
};

struct Planets {
    Vector2 position;
    float Planetradius;
    float planetOrbitSpeed;
    const char* PlanetName;
    Color planetColor;
    float angle;
    float semiMajorAxis;
    float eccentricity;
    std::vector<Vector2> trail;  // Make sure this is here
};

void init(Sun &PlanetSun);
void SolarSystemLogic(Sun &PlanetSun);
#endif