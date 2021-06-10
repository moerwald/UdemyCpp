#include "Struct2.h"
#include <iostream>

enum Lanes
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
        std::cout << "LANE: " << lane << std::endl;
        std::cout << "VELOCITY: " << velocity << std::endl;
    }
} TS_Vehicle;

void Print(TS_Vehicle v) {
    std::cout << "ID: " << v.id << std::endl;
    std::cout << "LANE: " << v.lane << std::endl;
    std::cout << "VELOCITY: " << v.velocity << std::endl;
}

int Struct2::Main()
{
    TS_Vehicle v1{ 1, Lanes::CENTER, 48.5 };
    v1.Print();
    Print(v1);

    return 0;
}
