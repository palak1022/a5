#ifndef MALE_HPP
#define MALE_HPP

#include "Ant.hpp"

class Male : public Ant {
public:
    Male(int x, int y); // Constructor declaration

    virtual void move(std::vector<std::vector<Organism*>>& grid) override;
    virtual void breed(std::vector<std::vector<Organism*>>& grid) override {}
    virtual void starve(int time_steps) override;
    virtual char getSymbol() const override { return 'o'; }
    ~Male() {}
};

#endif // MALE_HPP

