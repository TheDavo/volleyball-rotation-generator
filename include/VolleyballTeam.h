#ifndef _VOLLEYBALLTEAM_H_
#define _VOLLEYBALLTEAM_H_

// Standard includes
#include <vector>
#include <string>
#include <map>
// Custom includes
#include "./Positions.h"
#include "./Player.h"

class Team {
private:

    std::vector<Player> team;
	
public:

    // Getters
    std::vector<Player> get_team();
    Player get_player(int i);
	void show_team();
    
    // Setters
    void add_team_member(Player player);
    void remove_team_member(Player player);
    void remove_team_member(int i);
	void empty_team();

    // Constructors
    Team(std::vector<Player> team);
};
#endif