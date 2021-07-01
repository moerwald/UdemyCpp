#pragma once

#include <map>
#include <string>

using std::map;
using std::string;
using std::pair;


typedef map<string, pair<int, int>> Friends;

string get_oldest_friend(const Friends& friends);
string get_heaviest_friend(const Friends& friends);
