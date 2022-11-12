#include <vector>
#include <algorithm>

#include "../include/MenuDriver.h"
#include "../include/VolleyballTeam.h"
#include "../include/Player.h"
#include "../include/Positions.h"



MenuDriver::MenuDriver(Team team, std::vector<Team> rotations, std::map<int, Position> team_style)
	: team{team}, rotations{rotations}, team_style{team_style}{
	
}


void MenuDriver::print_intro() {
	std::cout << "=-=-=-=-=-=-=- Welcome to the Volleyball Rotation Viewer! =-=-=-=-=-=-=- " << std::endl;
	std::cout << "|\tThis tool demonstrates what kind of rotations are available with" << std::endl;
	std::cout << "|\ta volleyball team and its wanted team composition!" << std::endl;
}

void MenuDriver::print_overview() {
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=- Team Overview =-=-=-=-=-=-=-=-=-=-=-=-=-=- " << std::endl;
	
	std::cout << "The volleyball team is currently composed of these players and their preferences: " << std::endl;
	for(Player player : team.get_team()) {
		std::cout << player.get_name() << ": ";
		for (Position pos : player.get_positions()){
			std::cout << position_as_str(pos) << " ";
		}
		std::cout << std::endl;
	}
}

void MenuDriver::print_rotations() {
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=- Team Rotations =-=-=-=-=-=-=-=-=-=-=-=-=- " << std::endl;
	
	for(size_t i = 0; i < rotations.size(); i++) {
		std::cout << "----- Rotation # " << i+1 << "-----" << std::endl;
		rotations.at(i).show_team();
		std::cout << "-----------------------------------" << std::endl;
	}
}

void print_rotations(bool paginated, unsigned int page_size) {
		std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=- Team Rotations =-=-=-=-=-=-=-=-=-=-=-=-=- " << std::endl;
}

void MenuDriver::run() {
	cur_state = State::Intro;
	print_intro();
	print_menu();
	handle_input();
}

bool MenuDriver::is_valid_input(char input){
	std::vector<char> inputs = valid_inputs[cur_state];
	return std::count(inputs.begin(), inputs.end(), input);
}

void MenuDriver::perform_input_action(char input) {
	switch (input) {
		case 'i':
			cur_state = State::Intro;
			print_intro();
			break;
		case 'o':
			cur_state = State::Overview;
			print_overview();
			break;
		case 'a':
			cur_state = State::ShowRotations;
			print_rotations();
			break;
		case 's':
			cur_state = State::ShowRotations;
			break;
		case 'q':
			cur_state = State::Exit;
			return;
	}
	
	print_menu();
	handle_input();
}


void MenuDriver::handle_input() {
	char input {};

	while(cur_state != State::Exit) {
		std::cout << "Please enter an action: ";
		std::cin >> input;
		if(is_valid_input(input)){
			perform_input_action(input);
		} else {
			std::cout << "Invalid input! \n" << std::endl;
		}
	}
	
}

void MenuDriver::print_menu() {
	// TODO
	switch (cur_state) {
		case State::Intro:
		case State::Overview:
			std:: cout << "\n\n>>| i: intro, o: overview, s: showteams, q: exit" << std::endl;
			break;
		case State::ShowRotations:
			std:: cout << "\n\n>>| i: intro, o: overview, a: print all rotations, s: set number of rotations to show, n: next rotations, N: previous rotations q: exit" << std::endl;
			break;
		default:
			break;
	}
}


