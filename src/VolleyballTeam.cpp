// Standard includes
#include <string>
#include <vector>

// Custom includes
#include "../include/VolleyballTeam.h"
#include "../include/Player.h"
#include "../include/Positions.h"


// Constructors
VolleyballTeam::VolleyballTeam() {
    std::vector<Player> team {};
}

VolleyballTeam::VolleyballTeam(std::vector<Player> new_team)
    : team{new_team} {
}


// Getters
std::vector<Player> VolleyballTeam::get_team() {
    return team;
}

Player VolleyballTeam::get_player(int i) {
    return team.at(i);
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
