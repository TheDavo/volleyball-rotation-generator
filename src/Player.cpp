// Standard Includes
#include <string>
#include <vector>

// Custom includes
#include "../include/Player.h"
#include "../include/Positions.h"

// Constructors
Player::Player(std::string name, std::vector<Position> positions)
    : full_name{name}, positions{positions} {
}

// Getters
std::string Player::get_name() {
    return full_name;
}

std::vector<Position> Player::get_positions() {
    return positions;
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
