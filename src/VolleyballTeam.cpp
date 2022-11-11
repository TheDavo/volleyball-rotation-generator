// Standard includes
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm> // for std::find
// Custom includes
#include "../include/VolleyballTeam.h"
#include "../include/Player.h"
#include "../include/Positions.h"


// Constructors
Team::Team(std::vector<Player> new_team)
	: team{new_team} {
}


// Getters
std::vector<Player> Team::get_team() {
	return team;
}

Player Team::get_player(int i) {
	return team.at(i);
}

void Team::show_team() {
	for (Player player : team) {
		std::cout << player.get_name() << std::endl;
	}
}
// Setters

void Team::add_team_member(Player player) {
    team.push_back(player);
}

void Team::remove_team_member(Player player) {
	for (size_t i = 0; i < team.size(); i++ ) {
		if (team.at(i).get_name() == player.get_name()) {
			team.erase(team.begin() + i);
			return;
		}
	}
}

void Team::remove_team_member(int i) {
	team.erase(team.begin() + i);
}

void Team::empty_team() {
	team = std::vector<Player> {};
}