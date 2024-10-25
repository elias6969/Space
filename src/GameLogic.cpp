#include <iostream>
#include <raylib.h>
#include <Header.h>
#include <vector>
#include <algorithm>
#include <minmax.h>
#include <math.h>
#include <cmath>

std::vector<Planets> planets = {
    //  Position          Diameter    Speed       Name        Color      Angle     Semi-Major Axis    Eccentricity   Trail
    {{30.0f, 30.0f},    20.0f,     0.01f,   "Mercury",  GRAY,     0.0f,   107.91,   0.205,    {}},   // Mercury
    {{30.0f, 30.0f},    49.0f,     0.004f,  "Venus",    ORANGE,   45.0f,  108.21,  0.006,    {}},   // Venus
    {{30.0f, 30.0f},    50.0f,     0.003f,  "Earth",    BLUE,     90.0f,  149.60,  0.016,    {}},   // Earth
    {{30.0f, 30.0f},    26.0f,     0.0025f, "Mars",     RED,      135.0f, 227.92,  0.093,    {}},   // Mars
    {{30.0f, 30.0f},    110.0f,    0.0013f, "Jupiter",  DARKPURPLE, 180.0f, 778.57,  0.048,  {}},   // Jupiter
    {{30.0f, 30.0f},    94.0f,     0.0010f, "Saturn",   DARKBROWN, 225.0f, 1433.53, 0.056,   {}},   // Saturn
    {{30.0f, 30.0f},    40.0f,     0.0007f, "Uranus",   BLUE,     270.0f, 2872.46, 0.046,    {}},   // Uranus
    {{30.0f, 30.0f},    39.0f,     0.0005f, "Neptune",  MAGENTA,  315.0f, 4495.06, 0.010,    {}}    // Neptune
};

double orbitalSpeed(double mu, double r, double a)
{
    return std::sqrt(mu * ((2.0 / r) - (1.0 / a)));
}

void init(Sun &PlanetSun)
{
    double mu = 1.0;
    for (auto &planetesReference : planets)
    {
        double dx = PlanetSun.Position.x - planetesReference.position.x;
        double dy = PlanetSun.Position.y - planetesReference.position.y;
        double r = std::sqrt(dx * dx + dy * dy);

        planetesReference.angle = orbitalSpeed(mu, r, planetesReference.semiMajorAxis);
    }
}

void updateTrail(Planets &planet)
{
    if (planet.trail.empty() || 
        (planet.position.x != planet.trail.back().x || 
         planet.position.y != planet.trail.back().y)) 
    {
        planet.trail.push_back(planet.position);
    }
    
    if (planet.trail.size() > 1000)
    {
        planet.trail.erase(planet.trail.begin());
    }
}
void DrawPlanetTrail(Planets &planet) {
    for(size_t i = 0; i < planet.trail.size(); i++){
        float alpha = (float)i / (float)planet.trail.size();
        //DrawCircleV(planet.trail[i], planet.Planetradius, Fade(planet.planetColor, alpha));
        DrawLineEx(planet.trail[i], planet.trail[i + 1], 10.0f, Fade(planet.planetColor, alpha));
    }
}

void SolarSystemLogic(Sun &PlanetSun)
{
    PlanetSun.Position = {(float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f};
    for (auto &Planetes : planets)
    {
        Planetes.angle += Planetes.planetOrbitSpeed;
        if (Planetes.PlanetName == "Mercury")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + (float)r * cos((float)Planetes.angle),
                                 PlanetSun.Position.y + (float)r * sin((float)Planetes.angle)};
        }
        else if (Planetes.PlanetName == "Venus")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + cos((float)Planetes.angle) * 300.0f,
                                 PlanetSun.Position.y + sin((float)Planetes.angle) * 300.0f};
        }
        else if (Planetes.PlanetName == "Earth")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + cos((float)Planetes.angle) * 450.0f,
                                 PlanetSun.Position.y + sin((float)Planetes.angle) * 450.0f};
        }
        else if (Planetes.PlanetName == "Mars")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + cos((float)Planetes.angle) * 600.0f,
                                 PlanetSun.Position.y + sin((float)Planetes.angle) * 600.0f};
        }
        else if (Planetes.PlanetName == "Jupiter")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + cos((float)Planetes.angle) * 750.0f,
                                 PlanetSun.Position.y + sin((float)Planetes.angle) * 750.0f};
        }
        else if (Planetes.PlanetName == "Saturn")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + cos((float)Planetes.angle) * 900.0f,
                                 PlanetSun.Position.y + sin((float)Planetes.angle) * 900.0f};
        }
        else if (Planetes.PlanetName == "Uranus")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + cos((float)Planetes.angle) * 1050.0f,
                                 PlanetSun.Position.y + sin((float)Planetes.angle) * 1050.0f};
        }
        else if (Planetes.PlanetName == "Neptune")
        {
            double r = Planetes.semiMajorAxis * (1.0 - Planetes.eccentricity * Planetes.eccentricity) / (1.0 + Planetes.eccentricity * cos(Planetes.angle));
            Planetes.position = {PlanetSun.Position.x + cos((float)Planetes.angle) * 1200.0f,
                                 PlanetSun.Position.y + sin((float)Planetes.angle) * 1200.0f};
        }
        try
        {
        updateTrail(Planetes);
        DrawPlanetTrail(Planetes);
        DrawCircleV(Planetes.position, Planetes.Planetradius, Planetes.planetColor);
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error:" << e.what() << '\n';
        }
        

    }
    DrawCircle(PlanetSun.Position.x, PlanetSun.Position.y, 60.0f, YELLOW);
}