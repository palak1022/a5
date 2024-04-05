#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Organism.hpp"

class DoodleBug : public Organism {
private:
    int x; // Adding x-coordinate as a member variable
    int y; // Adding y-coordinate as a member variable
    int breedingTime;

public:
    DoodleBug(int initialX, int initialY); // Constructor to initialize coordinates
    virtual void move(std::vector<std::vector<Organism*>>& grid) override;
    virtual void breed(std::vector<std::vector<Organism*>>& grid) override;
    virtual void starve(int time_steps) override;
    virtual char getSymbol() const override { return 'D'; }
    ~DoodleBug() {}
};

#endif // DOODLEBUG_HPP

