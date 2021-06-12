#include "Struct3.h"
#include <iostream>

namespace NS_Struct3
{

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

    void Print(const TS_Vehicle* const v) {

        std::cout << "ID: " << v->id << std::endl;
        std::cout << "LANE: " << static_cast<int>(v->lane) << std::endl;
        std::cout << "VELOCITY: " << v->velocity << std::endl;
    }

    void Print(TS_Vehicle v) {
        Print(static_cast<TS_Vehicle*>(&v));
    }
}

constexpr int NrOfVehicles = 3;

int Struct3::Main()
{
    NS_Struct3::TS_Vehicle v1{ 1, NS_Struct3::Lanes::CENTER, 48.5f };
    NS_Struct3::TS_Vehicle v2{ 2, NS_Struct3::Lanes::RIGHT, 100.0f };
    NS_Struct3::TS_Vehicle v3{ 3, NS_Struct3::Lanes::LEFT, 42.0f };

    NS_Struct3::TS_Vehicle arr[NrOfVehicles]{ v1, v2, v3 };

    for (size_t i = 0; i < NrOfVehicles; i++)
    {
        arr[i].Print();
        Print(arr[i]);
        Print(&arr[i]);
    }

    return 0;
}
