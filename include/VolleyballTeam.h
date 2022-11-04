#ifndef _VOLLEYBALLTEAM_H_
#define _VOLLEYBALLTEAM_H_

// Standard includes
#include <vector>
#include <string>
#include <map>
// Custom includes
#include "./Positions.h"
#include "./Player.h"

class VolleyballTeam {
private:
    std::vector<Player> team;
	std::map<Position, std::vector<Player>> team_by_position;
	std::string position_as_str(Position p);
	
	/** 
	 * Changes team from being player oriented to position oriented.
	 * This allows a player to be found by searching for a position
	 * rather than searching through players to find if they have a
	 * preferred position.
	*/ 
	void transpose_team();
public:
    // Getters
    std::vector<Player> get_team();
    Player get_player(int i);
	void show_team();
	void show_team_by_position();
    
    // Setters
    void add_team_member(Player player);
    void remove_team_member(Player player);
    void remove_team_member(int i);

    // Constructors
    VolleyballTeam();
    VolleyballTeam(std::vector<Player> team);

};

#endif
