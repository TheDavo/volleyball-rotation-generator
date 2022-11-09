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
	Team::transpose_team();
}

Team::Team()
	: team{}{
}

// Private functions

void Team::transpose_team() {
	for(auto & player: team) {
		for(auto pos : player.get_positions()){
			team_by_position[pos].push_back(player);
		}
	}
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

std::map<Position, std::vector<Player>> Team::create_empty_team(){
	std::map<Position, std::vector<Player>> new_team{
		{Position::Setter, std::vector<Player>{}},
		{Position::Middle, std::vector<Player>{}},
		{Position::Outside, std::vector<Player>{}},
		{Position::Opposite, std::vector<Player>{}},
		{Position::Libero, std::vector<Player>{}},
	};
	return new_team;
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