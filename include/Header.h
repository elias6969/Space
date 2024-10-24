#ifndef HEADER_H
#define HEADER_H
#include <iostream>

struct Planets
{
    Vector2 position;
    float Planetradius;
    float planetOrbitSpeed;
    const char* PlanetName;
    Color planetColor;
    float angle;
};

void init();
void SolarSystemLogic();

#endif