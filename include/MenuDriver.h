#ifndef _MENUDRIVER_H_
#define _MENUDRIVER_H_

#include <vector>

#include "./VolleyballTeam.h"

class MenuDriver {
private:
	enum class State {
		Intro,
		Overview,
		ShowRotations,
		Exit,
	};
	
	std::map<State, std::vector<char>> valid_inputs {
		{State::Intro, {'i', 'o', 's', 'q'}},
		{State::Overview, {'i', 'o', 's', 'q'}},
		{State::ShowRotations, {'i', 'o', 'a', 's', 'n', 'N', 'q'}},
		{State::Exit, {'q'}},
	};
	
	Team team;
	std::vector<Team> rotations;
	std::map<int, Position> team_style;
	State cur_state {State::Intro};
	
	std::vector<Team> get_slice(size_t from, size_t to);
		
	// Print functions
	void print_menu();
	void print_intro();
	void print_overview();
	void print_rotations();
	void print_rotations(bool paginated, unsigned int page_size); //TODO
	
	// Input functions
	bool is_valid_input(char input);
	void handle_input();
	void perform_input_action(char input);
	
public:
	void run();

	// Constructors
	MenuDriver(Team team, std::vector<Team> rotations, std::map<int, Position> team_style);
};

#endif