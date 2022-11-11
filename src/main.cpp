// Standard includes
#include <iostream>
#include <vector>
#include <algorithm>

// Custom includes
#include "../include/Player.h"
#include "../include/Positions.h"
#include "../include/VolleyballTeam.h"
#include "../include/MenuDriver.h"
// Namespaces
using namespace std;


/*
 The team_style int input maps to the position on the court 
 */
vector<Team> possible_teams(Team team, map<int, Position> team_style);
bool can_run_team(Team team, map<int, Position> team_style);

int main() {
//    vector<Position> davit_pref {Position::Outside, Position::Middle, Position::Setter};
	vector<Position> davit_pref {Position::Middle, Position::Outside};
    Player davit {"Davit", davit_pref};
	
//	vector<Position> selma_pref {Position::Setter,Position::Libero};
    vector<Position> selma_pref {Position::Setter};
    Player selma {"Selma", selma_pref};
	
//	vector<Position> thinh_pref {Position::Outside, Position::Setter,Position::Opposite};
    vector<Position> thinh_pref {Position::Opposite};
    Player thinh {"Thinh", thinh_pref};
	
    vector<Position> dan_pref {Position::Middle};
    Player dan {"Dan", dan_pref};
	
    vector<Position> lauren_pref {Position::Outside};
    Player lauren {"Lauren", lauren_pref};
	
//	vector<Position> scott_pref {Position::Outside,Position::Middle};
    vector<Position> scott_pref {Position::Outside, Position::Middle};
    Player scott {"Scott", scott_pref};
	
//	vector<Position> jose_pref {Position::Setter,Position::Outside};
    vector<Position> jose_pref {Position::Outside};
    Player jose {"Jose", jose_pref};


	std::vector<Player> my_team {};

	my_team.push_back(selma);
	my_team.push_back(lauren);
	my_team.push_back(davit);
	my_team.push_back(thinh);
	my_team.push_back(jose);
	my_team.push_back(dan);
	my_team.push_back(scott);
	
	Team team {my_team};
	
	map<int, Position> team_5_1 {
		{1, Position::Setter},
		{2, Position::Outside},
		{3, Position::Middle},
		{4, Position::Opposite},
		{5, Position::Outside},
		{6, Position::Middle},
	};
    team.show_team();
	cout << endl;
	
	vector<Team> rotations = possible_teams(team, team_5_1);
	MenuDriver menu {my_team, rotations, team_5_1};
	menu.run();
    return 0;
}


void print_perm(vector<int> perm) {
	for (auto i : perm) {
		cout << i;
	}
	cout << endl;
}

int f()
{ 
    static int i;
    return ++i;
}

vector<Team> possible_teams(Team team, map<int, Position> team_style) {
	Team new_team = Team();
	vector<Team> ret {};
	vector<int> ordered_positions(team.get_team().size());
	
	// Simply generates a range of the size of the team
	generate(ordered_positions.begin(), ordered_positions.end(), f);
	
	// Early exit if team size is smaller than the required number of positions
	if (team.get_team().size() < team_style.size()){
		return {};
	}
	
	do {
		for(size_t i = 1; i <= team_style.size(); i++){
			vector<Position> cur_positions = team.get_player(ordered_positions[i - 1] - 1).get_positions();
			Player selected_player = Player(team.get_player(ordered_positions[i - 1] - 1).get_name(), {team_style.at(i)});
			// Check if current player's preferred positions is needed at current court position
			if(count(cur_positions.begin(), cur_positions.end(), team_style.at(i))){
				new_team.add_team_member(selected_player);
			}
		}
		if(can_run_team(new_team, team_style)){
			ret.push_back(new_team);
		}
		
		new_team.empty_team();
	} while(next_permutation(ordered_positions.begin(), ordered_positions.end()));
	
	return ret;
}

bool can_run_team(Team team, map<int, Position> team_style) {
	
	if (team.get_team().size() != team_style.size()){
		return false;
	}
	
	for(auto court_pos : team_style) {
		// Subtract one, since getting a player is zero-indexed, but the court positions are not
		Player cur_player = team.get_player(court_pos.first - 1);
		vector<Position> player_pref = cur_player.get_positions();
		
		// Player pref not found for this court position, early return false
		if(!count(player_pref.begin(), player_pref.end(), court_pos.second)){
			return false;
		}
	}
	
	// All players pass the vibe check!
	return true;
}