
#include "exercise.h"
#include <iostream>

using std::cout;
using std::endl;


int main()
{

    Friends friends;

    friends["Jan"] = std::pair<int, int> (36, 82);
    friends["Ina"] = std::pair<int, int> (46, 52);

    auto oldest = get_oldest_friend(friends);
    cout << "Oldest friend: " << oldest << endl;

    auto heaviest = get_heaviest_friend(friends);
    cout << "Heaviest friend: " << heaviest << endl;


    cout << "is_palendrom(otto): " << is_palindrom("otto") << endl;
    cout << "is_palendrom(smith): " << is_palindrom("smith") << endl;

	return 0;
}
