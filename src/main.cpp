// Standard includes
#include <iostream>


// Custom includes
#include "../include/Player.h"
#include "../include/Positions.h"
#include "../include/VolleyballTeam.h"
// Namespaces
using namespace std;


int main() {
    vector<Position> davit_pref {Position::Outside, Position::Middle,Position::Setter};
    Player davit {"Davit", davit_pref};
	
    vector<Position> selma_pref {Position::Setter,Position::Libero};
    Player selma {"Selma", selma_pref};
	
    vector<Position> thinh_pref {Position::Outside, Position::Setter,Position::Opposite};
    Player thinh {"Thinh", thinh_pref};
	
    vector<Position> dan_pref {Position::Middle};
    Player dan {"Dan", dan_pref};
	
    vector<Position> lauren_pref {Position::Outside};
    Player lauren {"Lauren", lauren_pref};
	
    vector<Position> scott_pref {Position::Outside,Position::Middle};
    Player scott {"Scott", scott_pref};
	
    vector<Position> jose_pref {Position::Setter,Position::Outside};
    Player jose {"Jose", jose_pref};

	VolleyballTeam my_team {};
	my_team.add_team_member(davit);
	my_team.add_team_member(selma);
	my_team.add_team_member(thinh);
	my_team.add_team_member(dan);
	my_team.add_team_member(lauren);
	my_team.add_team_member(scott);
	my_team.add_team_member(jose);
	

    my_team.show_team();
    return 0;
}
