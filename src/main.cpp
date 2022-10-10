// Standard includes
#include <iostream>


// Custom includes
#include "../include/Player.h"
#include "../include/Positions.h"
// Namespaces
using namespace std;


int main() {
    vector<Position> davit_pref {Position::Middle,Position::Setter};
    Player davit {"Davit", davit_pref};

    cout << davit.get_name() << endl;
    return 0;
}
