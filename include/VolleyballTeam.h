#ifndef _VOLLEYBALLTEAM_H_
#define _VOLLEYBALLTEAM_H_

// Standard includes
#include <vector>
#include <string>

// Custom includes
#include "./Positions.h"
#include "./Player.h"

class VolleyballTeam {
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

    // Constructors
    VolleyballTeam();
    VolleyballTeam(std::vector<Player> team);

};

#endif
