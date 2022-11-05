// Standard includes
#include <iostream>


// Custom includes
#include "../include/Player.h"
#include "../include/Positions.h"
#include "../include/VolleyballTeam.h"
// Namespaces
using namespace std;


int main() {
    vector<Position> davit_pref {Position::Outside, Position::Middle, Position::Setter};
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


	std::vector<Player> my_team {};

	my_team.push_back(davit);
	my_team.push_back(selma);
	my_team.push_back(thinh);
	my_team.push_back(dan);
	my_team.push_back(lauren);
	my_team.push_back(scott);
	my_team.push_back(jose);
	
	VolleyballTeam team {my_team};
	

    team.show_team();
	cout << endl;
	team.show_team_by_position();
	cout << endl;
	cout << "Can team run a 5-1? " << team.can_run_team(team.team_5_1) << endl;
	
	cout << "Can team run a 6-2? " << team.can_run_team(team.team_6_2) << endl;
	
	team.possible_teams(team.team_5_1);
    return 0;
}
