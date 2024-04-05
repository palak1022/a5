#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "Ant.hpp"

class Queen : public Ant {
private:
    bool mated;
    int breedingTime;
    int x; // Adding x-coordinate as a member variable
    int y; // Adding y-coordinate as a member variable

public:
    Queen(int initialX, int initialY); // Constructor to initialize coordinates
    virtual void move(std::vector<std::vector<Organism*>>& grid) override;
    virtual void breed(std::vector<std::vector<Organism*>>& grid) override;
    virtual void starve(int time_steps) override;
    virtual char getSymbol() const override { return 'Q'; }
    ~Queen() {}
};

#endif // QUEEN_HPP

