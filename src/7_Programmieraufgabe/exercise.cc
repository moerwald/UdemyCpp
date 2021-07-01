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
    if (str.length() < sub_string.length())
        return false;

    auto end = str.end() - sub_string.length() + 1;
    for (auto it = str.cbegin(); it != end; ++it)
    {
        auto &&str_to_check = std::string(it, it + sub_string.length());

        if (sub_string == str_to_check)
            return true;
    }

    return false;
}
