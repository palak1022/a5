#include "Male.hpp"
#include "World.hpp"
#include <algorithm>
#include <random>

void Male::move(std::vector<std::vector<Organism*>>& grid) {
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

void Male::starve(int time_steps) {
    if (time_steps >= 5) {
        // Male ant starves and dies
    }
}
