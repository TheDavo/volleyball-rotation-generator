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
			team_by_position[pos].push_back(player);
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

std::map<Position, std::vector<Player>> VolleyballTeam::create_empty_team(){
	std::map<Position, std::vector<Player>> new_team{
		{Position::Setter, std::vector<Player>{}},
		{Position::Middle, std::vector<Player>{}},
		{Position::Outside, std::vector<Player>{}},
		{Position::Opposite, std::vector<Player>{}},
		{Position::Libero, std::vector<Player>{}},
	};
	
	return new_team;
}

void VolleyballTeam::show_team_by_position() {
	for (auto const& [pos, players] : team_by_position) {
		std::cout << "Position: " << position_as_str(pos) << " is preferred by: " << std::endl;
		for (auto player : players) {
			std::cout << "\t" << player.get_name() << std::endl;
		}
	}
}

std::vector<std::map<Position, std::vector<Player>>> VolleyballTeam::possible_teams(std::map<Position, int> team_style){
	std::vector<std::map<Position, std::vector<Player>>> possible_teams {};
	
	std::map<Position, std::vector<Player>> cur_team = create_empty_team();
	std::vector<Player> unavailable_players {};
	
	for (auto const& [pos, amount] : team_style) {
		std::cout << "Looking for " << position_as_str(pos) << std::endl;
		for(int i = 0; i < amount; i++) {
			for(auto & player : team){
				std::vector<Position> player_pos = player.get_positions();
				// Ensure there is a free player available and can fit the position
				if (std::find(unavailable_players.begin(), unavailable_players.end(), player) == unavailable_players.end() && 
					std::find(player_pos.begin(), player_pos.end(), pos) != player_pos.end()){
					std::cout << "Player \t" << player.get_name() << std::endl;
					// Add player for the current position
					std::cout << "Player\t" << player.get_name() << " is a fit for " << position_as_str(pos) << std::endl;
					cur_team[pos].push_back(player);
					
					// Add to list of chosen players
					unavailable_players.push_back(player);
					
					// Found a player, break out of loop
					break;
				}
			}
		}
	}
	
	if (unavailable_players.size() != team.size()) {
		// TODO
		// Implement check of current team vs team (if the team can be made)
		// If not, attempt to find players to swap places to fill in the blanks
	}
	
	possible_teams.push_back(cur_team);
	return possible_teams;
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


// Volleyball Functions

bool VolleyballTeam::can_run_team(std::map<Position, int> team_style){
	for (auto requirement : team_style) {
		// Typecasting here as the type of .size() was long long unsigned int
		// Resulting in compiler warnings
		if(int(team_by_position[requirement.first].size()) < requirement.second){
			return false;
		}
	}
	return true;
}

void VolleyballTeam::attempt_find_swap() {
	
}