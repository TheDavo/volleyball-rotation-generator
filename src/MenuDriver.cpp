#include <vector>


#include "../include/MenuDriver.h"
#include "../include/VolleyballTeam.h"
#include "../include/Player.h"
#include "../include/Positions.h"



MenuDriver::MenuDriver(Team team, std::vector<Team> rotations, std::map<int, Position> team_style)
	: team{team}, rotations{rotations}, team_style{team_style}{
	
}

void MenuDriver::move_to_state(State state){
	cur_state = state;
}

void MenuDriver::print_intro() {
	std::cout << "=-=-=-=-=-=-=- Welcome to the Volleyball Rotation Viewer! =-=-=-=-=-=-=- " << std::endl;
	std::cout << "|\tThis tool demonstrates what kind of rotations are available with" << std::endl;
	std::cout << "|\ta volleyball team and its wanted team composition!" << std::endl;
}

void MenuDriver::print_overview() {
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=- Team Overview =-=-=-=-=-=-=-=-=-=-=-=-=-=- " << std::endl;
	
	for(Player player : team.get_team()) {
		std::cout << player.get_name() << ": ";
		for (Position pos : player.get_positions()){
			std::cout << position_as_str(pos) << " ";
		}
		std::cout << std::endl;
	}
}

void MenuDriver::run() {
	cur_state = State::Intro;
	print_intro();
	print_menu();
	handle_input();
}

void MenuDriver::handle_input() {
	// TODO
	char input {};
	bool valid_input {false};
	
	do {
		std::cin >> input;
		
	} while(!valid_input);
	
}

void MenuDriver::print_menu() {
	// TODO
	switch (cur_state) {
		case State::Intro:
		case State::Overview:
			std:: cout << "\n\n>>| i: intro, o: overview, s: showteams, q: exit" << std::endl;
			break;
		case State::ShowTeams:
			std:: cout << "\n\n>>| i: intro, o: overview, s: set number of rotations to show, n: next rotations, N: previous rotations q: exit" << std::endl;
			break;
		default:
			break;
	}
}


