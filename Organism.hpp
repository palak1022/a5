#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <vector>

class Organism {
public:
    virtual void move(std::vector<std::vector<Organism*> > &grid) = 0;
    virtual void breed(std::vector<std::vector<Organism*> > &grid) = 0;
    virtual void starve(int time_steps) = 0;
    virtual char getSymbol() const = 0;
    virtual ~Organism() {}
};

#endif

