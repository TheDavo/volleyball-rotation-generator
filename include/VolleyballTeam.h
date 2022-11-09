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
	std::map<Position, std::vector<Player>> team_by_position{
		{Position::Setter, std::vector<Player>{}},
		{Position::Middle, std::vector<Player>{}},
		{Position::Outside, std::vector<Player>{}},
		{Position::Opposite, std::vector<Player>{}},
		{Position::Libero, std::vector<Player>{}},
	};
	
	void attempt_find_swap();
	
	
	/** 
	 * @brief | Changes team from being player oriented to position oriented.
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
	std::map<Position, std::vector<Player>> create_empty_team();
    
    // Setters
    void add_team_member(Player player);
    void remove_team_member(Player player);
    void remove_team_member(int i);
	void empty_team();

    // Constructors
    Team(std::vector<Player> team);
	Team();
};
#endif