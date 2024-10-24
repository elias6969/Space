#include <iostream>
#include <raylib.h>
#include <Header.h>
#include <vector>
#include <algorithm>
#include <minmax.h>
#include <math.h>
#include <cmath>

std::vector<Planets> planets = {
    //  Position     Diameter    Speed      Name
    {{30.0f, 30.0f}, 20.0f, 0.0001f, "Mercury", GRAY, 0.0f},          // Closest to the Sun
    {{30.0f, 30.0f}, 49.0f, 0.00004f, "Venus", ORANGE, 0.0f},         // Second planet
    {{30.0f, 30.0f}, 50.0f, 0.00003f, "Earth", BROWN, 0.0f},          // Our home
    {{30.0f, 30.0f}, 26.0f, 0.000025f, "Mars", RED, 0.0f},            // The red planet
    {{30.0f, 30.0f}, 110.0f, 0.000013f, "Jupiter", DARKPURPLE, 0.0f}, // The biggest planet
    {{30.0f, 30.0f}, 94.0f, 0.000010f, "Saturn", DARKBROWN, 0.0f},    // Famous for its rings
    {{30.0f, 30.0f}, 40.0f, 0.000007f, "Uranus", BLUE, 0.0f},         // Icy gas giant
    {{30.0f, 30.0f}, 39.0f, 0.000005f, "Neptune", MAGENTA, 0.0f},     // Farthest planet
};

void init()
{
}

void SolarSystemLogic()
{
    Vector2 SunPosition = {(float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f};
    // Calculate Earth's position using polar coordinates converted to Cartesian

    for (auto &Planetes : planets)
    {
        Planetes.angle += Planetes.planetOrbitSpeed;

        if (Planetes.PlanetName == "Mercury")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 150.0f,
                                 SunPosition.y + sin(Planetes.angle) * 150.0f};
        }
        else if (Planetes.PlanetName == "Venus")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 300.0f,
                                 SunPosition.y + sin(Planetes.angle) * 300.0f};
        }
        else if (Planetes.PlanetName == "Earth")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 450.0f,
                                 SunPosition.y + sin(Planetes.angle) * 450.0f};
        }
        else if (Planetes.PlanetName == "Mars")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 600.0f,
                                 SunPosition.y + sin(Planetes.angle) * 600.0f};
        }
        else if (Planetes.PlanetName == "Jupiter")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 750.0f,
                                 SunPosition.y + sin(Planetes.angle) * 750.0f};
        }
        else if (Planetes.PlanetName == "Saturn")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 900.0f,
                                 SunPosition.y + sin(Planetes.angle) * 900.0f};
        }
        else if (Planetes.PlanetName == "Uranus")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 1050.0f,
                                 SunPosition.y + sin(Planetes.angle) * 1050.0f};
        }
        else if (Planetes.PlanetName == "Neptune")
        {
            Planetes.position = {SunPosition.x + cos(Planetes.angle) * 1200.0f,
                                 SunPosition.y + sin(Planetes.angle) * 1200.0f};
        }
        DrawCircleV(Planetes.position, Planetes.Planetradius, Planetes.planetColor);
    }
    DrawCircle(SunPosition.x, SunPosition.y, 60.0f, YELLOW);
}