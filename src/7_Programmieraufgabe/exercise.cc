#include "exercise.h"

string get_oldest_friend(const Friends& friends)
{
    auto nameToAge = pair<string, int>("", 0);
    for (auto &kvp : friends)
    {
        auto name = kvp.first;
        auto age = kvp.second.first;
        if (age > nameToAge.second )
        {
            nameToAge.first = name;
            nameToAge.second = age;
        }
    }

    return nameToAge.first;
}

string get_heaviest_friend(const Friends& friends)
{
    auto nameToWeigth = pair<string, int>("", 0);
    for (auto &kvp : friends)
    {
        auto name = kvp.first;
        auto age = kvp.second.second;
        if (age > nameToWeigth.second )
        {
            nameToWeigth.first = name;
            nameToWeigth.second = age;
        }
    }

    return nameToWeigth.first;
}
