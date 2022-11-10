#ifndef _MENUDRIVER_H_
#define _MENUDRIVER_H_

#include <vector>


#include "./VolleyballTeam.h"

enum class State {
	Intro,
	Overview,
	ShowTeams,
	Exit,
};

class MenuDriver {
private:

	std::vector<Team> teams;
	State cur_state {Intro};
	void move_to_state(State state);
	void print_instructions();
	std::vector<Team> get_slice(size_t from, size_t to);

public:
	void run();

	// Constructors
	MenuDriver(std::vector<Team> teams);
};

#endif