// Standard Includes
#include <string>
#include <vector>

// Custom includes
#include "../include/Player.h"

// Constructors
Player::Player(std::string name, std::vector<Position> positions)
    : full_name{name}, positions{positions} {
}

// Getters
std::string Player::get_name() {
    return full_name;
}

std::string Player::position_as_str(Position p){
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


std::vector<Position> Player::get_positions() {
    return positions;
}

void Player::show_positions() {
	// TODO
}

// Setters
void Player::set_name(std::string name) {
    full_name = name;
}

void Player::set_positions(std::vector<Position> new_positions) {
    positions = new_positions;
}

void Player::add_position(Position position) {
    positions.push_back(position);
}
