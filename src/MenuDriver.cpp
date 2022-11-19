#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "../include/MenuDriver.h"
#include "../include/VolleyballTeam.h"
#include "../include/Player.h"
#include "../include/Positions.h"



MenuDriver::MenuDriver(Team team, std::vector<Team> rotations, std::map<int, Position> team_style)
	: team{team}, rotations{rotations}, team_style{team_style} {

}

void MenuDriver::run() {
	cur_state = State::MainMenu;
	print_intro();
	print_menu();
	handle_input();
}

void MenuDriver::print_intro() {
	system("cls");
	std::cout << "=-=-=-=-=-=-=- Welcome to the Volleyball Rotation Viewer! =-=-=-=-=-=-=- " << std::endl;
	std::cout << "|\tThis tool demonstrates what kind of rotations are available with" << std::endl;
	std::cout << "|\ta volleyball team and its wanted team composition!" << std::endl;
}

void MenuDriver::print_overview() {
	system("cls");
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=- Team Overview =-=-=-=-=-=-=-=-=-=-=-=-=-=- " << std::endl;

	std::cout << "The volleyball team is currently composed of these players and their preferences: " << std::endl;

	team.show_team();
}

void MenuDriver::print_rotations_intro() {
	system("cls");
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=- Team Rotations =-=-=-=-=-=-=-=-=-=-=-=-=- " << std::endl;
	std::cout << "|\tThe team provided is capable of running " << rotations.size() << " rotations" << std::endl;
	std::cout << "|\twith the team composition of:" << std::endl;
	for (auto comp  : team_style) {
		std::cout << "Position: " << comp.first << " " << position_as_str(comp.second) << std::endl;
	}
}

bool MenuDriver::is_valid_input(char input) {
	std::vector<char> inputs = valid_inputs[cur_state];
	return std::count(inputs.begin(), inputs.end(), input);
}

void MenuDriver::perform_input_action(char input) {
	switch (cur_state) {
		case State::MainMenu:
			handle_input_MainMenu(input);
			break;
		case State::ShowRotations:
			handle_input_ShowRotations(input);
			break;
		case State::Exit:
			handle_input_Exit(input);
			break;
		default:
			break;
	}
}

void MenuDriver::handle_input_MainMenu(char input) {
	switch (input) {
		case 'i':
			print_intro();
			break;
		case 'o':
			print_overview();
			break;
		case 's':
			cur_state = State::ShowRotations;
			print_rotations_intro();
			break;
		case 'q':
			cur_state = State::Exit;
			return;
	}

	print_menu();
	handle_input();
}

void MenuDriver::handle_input_ShowRotations(char input) {
	switch (input) {
		case 'i':
			cur_state = State::MainMenu;
			print_intro();
			break;
		case 'o':
			cur_state = State::MainMenu;
			print_overview();
			break;
		case 'a':
			print_all_rotations();
			break;
		case 's':
			change_pagination_size();
			break;
		case 'n':
			print_rotations(true);
			break;
		case 'N':
			print_rotations(false);
			break;
		case 'q':
			cur_state = State::Exit;
			return;
	}

	print_menu();
	handle_input();
}

void MenuDriver::change_pagination_size() {
	std::cout << "Input new pagination size: ";
	std::cin >> pagination_size;
	if (pagination_size > rotations.size()) {
		pagination_size = rotations.size();
	} else if (pagination_size <= 0 ) {
		pagination_size = 1;
	}
}

void MenuDriver::handle_input_Exit(char input) {
	return;
}

void MenuDriver::handle_input() {
	char input {};

	while(cur_state != State::Exit) {
		std::cout << "Please enter an action: ";
		std::cin >> input;
		if(is_valid_input(input)) {
			perform_input_action(input);
		} else {
			std::cout << "Invalid input! \n" << std::endl;
		}
	}
}


void MenuDriver::print_rotations(bool direction) {
	// true -> next, false -> prev
	static bool first_call {true};
	size_t to {};
	if(!first_call) {
		if (direction) { // next rotations
			if(pagination_size >= rotations.size()) {
				// Since the pagination size is greater than the entire vector
				// set the starting point to zero, showing the entire vector
				start_rotation_display = 0;
			} else if(!(start_rotation_display + pagination_size >= rotations.size())) {
				start_rotation_display += pagination_size;
			}
		} else { // previous rotations
			// Clamp the start to the zero index if going backwords would be negative
			// Even though size_t is unsigned, good to check in case of underflow
			if(start_rotation_display < pagination_size) {
				start_rotation_display = 0;
			} else {
				start_rotation_display -= pagination_size;
			}
		}
	}
	first_call = false;

	to = start_rotation_display + pagination_size;
	if (to >= rotations.size()) {
		to = rotations.size();
	}
	system("cls");
	for(size_t i = start_rotation_display; i < to; i++) {
		std::cout << "--------- Rotation # " << i + 1 << " of " << rotations.size() << std::endl;
		rotations.at(i).show_team();
		std::cout << "-----------------------------------" << std::endl;
	}
}

void MenuDriver::print_all_rotations() {
	std::cout << "=-=-=-=-=-=-=-=-=-=-=-=-=- Team Rotations =-=-=-=-=-=-=-=-=-=-=-=-=- " << std::endl;

	for(size_t i = 0; i < rotations.size(); i++) {
		std::cout << "--------- Rotation # " << i + 1 << " of " << rotations.size() << std::endl;
		rotations.at(i).show_team();
		std::cout << "-----------------------------------" << std::endl;
	}
}

void MenuDriver::print_menu() {
	// TODO
	switch (cur_state) {
		case State::MainMenu:
			std:: cout << "\n\n>>| i: intro, o: overview, s: showteams, q: exit" << std::endl;
			break;
		case State::ShowRotations:
			std:: cout << "\n\n>>| i: intro, o: overview, a: print all rotations, s: set number of rotations to show\nn: next rotations, N: previous rotations q: exit" << std::endl;
			break;
		default:
			break;
	}
}
