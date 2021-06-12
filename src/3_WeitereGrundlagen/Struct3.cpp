#include "Struct3.h"
#include <iostream>

enum class Lanes : int
{
    RIGHT = 1,
    CENTER = 0,
    LEFT = -1,
};

typedef struct Vehicle
{
    int id;
    Lanes lane;
    float velocity;

    Vehicle(Vehicle& rhs)
    {
        id = rhs.id;
        lane = rhs.lane;
        velocity = rhs.velocity;
    }

    Vehicle(int id, Lanes lane, float velocity)
    {
        this->id = id;
        this->lane = lane;
        this->velocity = velocity;
    }

    void Print()
    {
        std::cout << "ID: " << id << std::endl;
        std::cout << "LANE: " << static_cast<int>(lane) << std::endl;
        std::cout << "VELOCITY: " << velocity << std::endl;
    }
} TS_Vehicle;

void Print(TS_Vehicle v) {
    std::cout << "ID: " << v.id << std::endl;
    std::cout << "LANE: " << static_cast<int>(v.lane) << std::endl;
    std::cout << "VELOCITY: " << v.velocity << std::endl;
}

int Struct3::Main()
{
    TS_Vehicle v1{ 1, Lanes::CENTER, 48.5f };
    TS_Vehicle v2{ 2, Lanes::RIGHT, 100.0f };
    TS_Vehicle v3{ 3, Lanes::LEFT, 42.0f };

    return 0;
}
