#include "exercise.h"

string get_oldest_friend(const Friends& friends)
{
    auto nameToAge = pair<string, int>("", 0);
    for (auto& kvp : friends)
    {
        auto& name = kvp.first;
        auto age = kvp.second.first;

        if (age > nameToAge.second)
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
    for (auto& kvp : friends)
    {
        auto& name = kvp.first;
        auto weight = kvp.second.second;

        if (weight > nameToWeigth.second)
        {
            nameToWeigth.first = name;
            nameToWeigth.second = weight;
        }
    }

    return nameToWeigth.first;
}

bool is_palindrom(const string& str)
{
    const std::string str_reversed(str.crbegin(), str.crend());

    return str_reversed == str;
}

bool is_in_string(const string& str, const string& sub_string)
{
    auto it_str = str.cbegin();
    const auto& it_str_end = str.cend();

    while (it_str != it_str_end)
    {
        auto it_sub_string = sub_string.cbegin();

        while ((*it_str) == (*it_sub_string))
        {
            ++it_str;
            ++it_sub_string;

            if (it_sub_string == sub_string.cend())
            {
                // search succeeded
                return true;
            }

            if ((*it_str) != (*it_sub_string))
            {
                //No match reset orig string iterator
                --it_str;  
                break;
            }
        }

        ++it_str;
    }

    return false;
}
