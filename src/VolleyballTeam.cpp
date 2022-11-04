// Standard includes
#include <string>
#include <vector>
#include <map>
#include <iostream>

// Custom includes
#include "../include/VolleyballTeam.h"
#include "../include/Player.h"
#include "../include/Positions.h"


// Constructors
VolleyballTeam::VolleyballTeam() {
    std::vector<Player> team {};
	std::map<Position, std::vector<Player>> team_by_position {};
}

VolleyballTeam::VolleyballTeam(std::vector<Player> new_team)
    : team{new_team} {
	VolleyballTeam::transpose_team();
}

// Private functions

void VolleyballTeam::transpose_team() {
	for(auto & player: team) {
		for(auto pos : player.get_positions()){
			// Check if the key exists
			// If it does, simply add player to the existing vector
			// Otherwise insert new player vector into the map at new position
			if(team_by_position.count(pos)){
				team_by_position[pos].push_back(player);
			} else {
				std::vector<Player> temp {};
				temp.push_back(player);
				team_by_position.insert({pos, temp});
			}
		}
	}
}

std::string VolleyballTeam::position_as_str(Position p){
	std::string position = "";
	switch (p) {
		case Position::Setter:
			position = "Setter";
			break;
		case Position::Libero:
			position = "Libero";
			break;
		case Position::Middle:
			position = "Middle";
			break;
		case Position::Outside:
			position = "Outside";
			break;
		case Position::Opposite:
			position = "Opposite";
			break;
		default:
			position = "";
			break;
	}
	return position;
}

// Getters
std::vector<Player> VolleyballTeam::get_team() {
    return team;
}

Player VolleyballTeam::get_player(int i) {
    return team.at(i);
}

void VolleyballTeam::show_team() {
	for (Player player : team) {
		std::cout << player.get_name() << std::endl;
	}
}

void VolleyballTeam::show_team_by_position() {
	for (auto const& [pos, players] : team_by_position) {
		std::cout << "Position: " << position_as_str(pos) << " is preferred by: " << std::endl;
		for (auto player : players) {
			std::cout << "\t" << player.get_name() << std::endl;
		}
	}
}

// Setters

void VolleyballTeam::add_team_member(Player player) {
    team.push_back(player);
}

void VolleyballTeam::remove_team_member(Player player) {
    
    for (size_t i = 0; i < team.size(); i++ ) {
        if (team.at(i).get_name() == player.get_name()) {
            team.erase(team.begin() + i);
            return;
        }
    }
}

void VolleyballTeam::remove_team_member(int i) {
    team.erase(team.begin() + i);
}
