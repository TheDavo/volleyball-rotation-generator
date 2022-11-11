#ifndef _MENUDRIVER_H_
#define _MENUDRIVER_H_

#include <vector>


#include "./VolleyballTeam.h"



class MenuDriver {
private:
	enum class State {
		Intro,
		Overview,
		ShowTeams,
		Exit,
	};
	
	
	Team team;
	std::vector<Team> rotations;
	std::map<int, Position> team_style;
	State cur_state {State::Intro};
	
	
	void move_to_state(State state);
	std::vector<Team> get_slice(size_t from, size_t to);
		
	// Print functions
	void print_menu();
	void print_intro();
	void print_overview();
	
	// Input functions
	void handle_input();
	
public:
	void run();

	// Constructors
	MenuDriver(Team team, std::vector<Team> rotations, std::map<int, Position> team_style);
};

#endif