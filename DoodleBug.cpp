#include "DoodleBug.hpp"
#include "Ant.hpp"
#include "World.hpp"
#include <algorithm>
#include <random>

DoodleBug::DoodleBug(int initialX, int initialY) : x(initialX), y(initialY), breedingTime(0) {} // Constructor initialization

void DoodleBug::move(std::vector<std::vector<Organism*>>& grid) {
    std::vector<std::pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(directions.begin(), directions.end(), gen);

    for (const auto& dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;

        if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()) {
            if (grid[newX][newY] != nullptr && dynamic_cast<Ant*>(grid[newX][newY]) != nullptr) {
                grid[newX][newY] = this;
                grid[x][y] = nullptr;
                x = newX; // Update x-coordinate after move
                y = newY; // Update y-coordinate after move
                return;
            } else if (grid[newX][newY] == nullptr) {
                grid[newX][newY] = this;
                grid[x][y] = nullptr;
                x = newX; // Update x-coordinate after move
                y = newY; // Update y-coordinate after move
                return;
            }
        }
    }
}

void DoodleBug::breed(std::vector<std::vector<Organism*>>& grid) {
    if (breedingTime >= 10) {
        std::vector<std::pair<int, int>> positions;
        for (int i = x - 1; i <= x + 1; i++) {
            for (int j = y - 1; j <= y + 1; j++) {
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == nullptr) {
                    positions.emplace_back(i, j);
                }
            }
        }

        if (!positions.empty()) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::shuffle(positions.begin(), positions.end(), gen);

            grid[positions[0].first][positions[0].second] = new DoodleBug(positions[0].first, positions[0].second);
            breedingTime = 0;
        }
    } else {
        breedingTime++;
    }
}

void DoodleBug::starve(int time_steps) {
    if (time_steps >= 20) {
        // Doodlebug starves and dies
    }
}

