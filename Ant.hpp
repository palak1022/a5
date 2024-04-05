#ifndef ANT_HPP
#define ANT_HPP

#include "Organism.hpp"

class Ant : public Organism {
public:
    virtual void move(std::vector<std::vector<Organism*>>& grid) override;
    virtual void breed(std::vector<std::vector<Organism*>>& grid) override;
    virtual void starve(int time_steps) override;
    virtual char getSymbol() const override = 0;
    virtual ~Ant() {}
};

#endif
