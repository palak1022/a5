#include "Ant.hpp"
#include "World.hpp"
#include <algorithm>
#include <random>

void Ant::move(std::vector<std::vector<Organism*>>& grid) {
    int x = 0, y = 0;
    std::vector<std::pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(directions.begin(), directions.end(), gen);

    for (const auto& dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;

        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] == nullptr) {
            grid[newX][newY] = grid[x][y];
            grid[x][y] = nullptr;
            return;
        }
    }
}

void Ant::breed(std::vector<std::vector<Organism*>>& grid) {
    // Ants other than Queen cannot breed
}

void Ant::starve(int time_steps) {
    if (time_steps >= 5) {
        // Ant starves and dies
    }
}
