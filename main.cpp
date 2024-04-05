#include "World.hpp"

int main() {
    int width = 100, height = 100;
    int doodlebugs = 15, queen_ants = 2, male_ants = 20, worker_ants = 30;

    World world(width, height, doodlebugs, queen_ants, male_ants, worker_ants);
    world.run();

    return 0;
}

