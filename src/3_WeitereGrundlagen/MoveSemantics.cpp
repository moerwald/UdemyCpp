#include "MoveSemantics.h"
#include <iostream>
#include <random>
#include "OwnString.h"


class Entity
{
public:
    Entity(const OwnString& name)
        :m_Name(name)
    {
    }

    Entity(OwnString&& name)
        :m_Name(std::move(name))
    {
    }

    void PrintName()
    {
        m_Name.Print();
    }

private:
    OwnString m_Name;
};

int MoveSemantics::main()
{
    Entity entity(OwnString("Andy"));
    entity.PrintName();
    return 0;
}
