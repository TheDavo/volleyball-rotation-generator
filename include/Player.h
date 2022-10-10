#ifndef _PLAYER_H_
#define _PLAYER_H_
// Standard includes
#include <string>
#include <vector>

// Custom includes
#include "./Positions.h"

class Player {
private: 
    std::string full_name;
    std::vector<Position> positions;

public:
    // Getters
    std::string get_name();
    std::vector<Position> get_positions();


    // Setters
    void set_name(std::string name);
    void set_positions(std::vector<Position> positions);
    void add_position(Position position);
    

    // Constructors
    Player(std::string name, std::vector<Position> positions);
};

#endif
