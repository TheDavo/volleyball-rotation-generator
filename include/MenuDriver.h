#ifndef _MENUDRIVER_H_
#define _MENUDRIVER_H_

#include <vector>

#include "./VolleyballTeam.h"

class MenuDriver {
	private:
		enum class State {
			MainMenu,
			ShowRotations,
			Exit,
		};

		std::map<State, std::vector<char>> valid_inputs {
			{State::MainMenu, {'i', 'o', 's', 'q'}},
			{State::ShowRotations, {'i', 'o', 'a', 's', 'n', 'N', 'q'}},
			{State::Exit, {'q'}},
		};

		Team team;
		std::vector<Team> rotations;
		std::map<int, Position> team_style;
		State cur_state {State::MainMenu};

		size_t pagination_size {3};
		size_t start_rotation_display {0};

		std::vector<Team> get_slice(size_t from, size_t to);

		// Print functions
		void print_menu();
		void print_intro();
		void print_overview();
		void print_rotations_intro();
		void print_all_rotations();
		void print_rotations(bool direction); // true -> next, false -> previous

		// Input functions
		bool is_valid_input(char input);
		void handle_input();
		void handle_input_MainMenu(char input);
		void handle_input_ShowRotations(char input);
		void handle_input_Exit(char input);
		void perform_input_action(char input);

		void change_pagination_size();

	public:
		void run();

		// Constructors
		MenuDriver(Team team, std::vector<Team> rotations, std::map<int, Position> team_style);
};

#endif
