#ifndef WORKER_HPP
#define WORKER_HPP

#include "Ant.hpp"

class Worker : public Ant {
public:
    Worker(int x, int y); // Constructor declaration

    virtual void move(std::vector<std::vector<Organism*>>& grid) override;
    virtual void breed(std::vector<std::vector<Organism*>>& grid) override {}
    virtual void starve(int time_steps) override;
    virtual char getSymbol() const override { return 'w'; }
    ~Worker() {}
};

#endif // WORKER_HPP

