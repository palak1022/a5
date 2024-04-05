#include "Queen.hpp"
#include "Worker.hpp"
#include "Male.hpp"
#include "World.hpp"
#include <algorithm>
#include <random>

Queen::Queen(int initialX, int initialY) : mated(false), breedingTime(0), x(initialX), y(initialY) {} // Constructor initialization

void Queen::move(std::vector<std::vector<Organism*>>& grid) {
    if (!mated) {
        // Queen ant does not move until mated
        return;
    }

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
            x = newX; // Update x-coordinate after move
            y = newY; // Update y-coordinate after move
            return;
        }
    }
}

void Queen::breed(std::vector<std::vector<Organism*>>& grid) {
    // Implementation of breed method
}

void Queen::starve(int time_steps) {
    // Implementation of starve method
}

