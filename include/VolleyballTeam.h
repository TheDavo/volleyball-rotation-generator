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
	std::map<Position, std::vector<Player>> team_by_position{
		{Position::Setter, std::vector<Player>{}},
		{Position::Middle, std::vector<Player>{}},
		{Position::Outside, std::vector<Player>{}},
		{Position::Opposite, std::vector<Player>{}},
		{Position::Libero, std::vector<Player>{}},
	};
	std::string position_as_str(Position p);
	
	void attempt_find_swap();
	
	/** 
	 * @brief | Changes team from being player oriented to position oriented.
	 * This allows a player to be found by searching for a position
	 * rather than searching through players to find if they have a
	 * preferred position.
	*/ 
	void transpose_team();
public:

	// Constants
	
	std::map<Position, int> const team_5_1 {
		{Position::Setter, 1},
		{Position::Middle, 2},
		{Position::Outside, 2},
		{Position::Opposite, 1},
		{Position::Libero, 0},
	};
	
	std::map<Position, int> const team_6_2 {
		{Position::Setter, 2},
		{Position::Middle, 2},
		{Position::Outside, 2},
		{Position::Opposite, 0},
		{Position::Libero, 0},
	};
	// End Constants

    // Getters
    std::vector<Player> get_team();
    Player get_player(int i);
	void show_team();
	void show_team_by_position();
	std::map<Position, std::vector<Player>> create_empty_team();
    
    // Setters
    void add_team_member(Player player);
    void remove_team_member(Player player);
    void remove_team_member(int i);
	
	// Volleyball Functions
	
	// team_style's int input is to count how many of type Position are required
	// to make that type of team work
	bool can_run_team(std::map<Position, int> team_style);
	
	std::vector<std::map<Position, std::vector<Player>>> possible_teams(std::map<Position, int> team_style);

    // Constructors
    VolleyballTeam();
    VolleyballTeam(std::vector<Player> team);

};

#endif