#ifndef WORLD_HPP
#define WORLD_HPP

#include "Organism.hpp"
#include "Ant.hpp"
#include "Queen.hpp"
#include "Worker.hpp"
#include "Male.hpp"
#include "DoodleBug.hpp"
#include <iostream>
#include <vector>
#include <random>

class World {
private:
    int width;
    int height;
    int time_steps;
    std::vector<std::vector<Organism*>> grid;

    template<typename T>
    void placeOrganism(std::mt19937& gen);

public:
    World(int width, int height, int doodlebugs, int queen_ants, int male_ants, int worker_ants);
    ~World();

    void run();

    void simulateStep();
    void print();
};

#endif // WORLD_HPP

