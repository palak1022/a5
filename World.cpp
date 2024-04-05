#include "World.hpp"

World::World(int width, int height, int doodlebugs, int queen_ants, int male_ants, int worker_ants) {
    this->width = width;
    this->height = height;
    this->time_steps = 0;

    grid.resize(width, std::vector<Organism*>(height, nullptr));

    std::random_device rd;
    std::mt19937 gen(rd());

    // Place doodlebugs
    for (int i = 0; i < doodlebugs; i++) {
        placeOrganism<DoodleBug>(gen);
    }

    // Place queen ants
    for (int i = 0; i < queen_ants; i++) {
        placeOrganism<Queen>(gen);
        // Assuming Queen is already mated
    }

    // Place male ants
    for (int i = 0; i < male_ants; i++) {
        placeOrganism<Male>(gen);
    }

    // Place worker ants
    for (int i = 0; i < worker_ants; i++) {
        placeOrganism<Worker>(gen);
    }
}

World::~World() {
    // Cleanup dynamically allocated memory
    for (auto& row : grid) {
        for (auto organism : row) {
            delete organism;
        }
    }
}

void World::run() {
    while (true) {
        simulateStep();
        print();
        time_steps++;
    }
}

void World::simulateStep() {
    // Implementation for simulating a step
}

void World::print() {
    // Implementation for printing the world state
}

template<typename T>
void World::placeOrganism(std::mt19937& gen) {
    int x, y;
    do {
        x = gen() % width;
        y = gen() % height;
    } while (grid[x][y] != nullptr);

    grid[x][y] = new T(x, y);
}

