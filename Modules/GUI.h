#pragma once
#include <vector>
#include <memory>

class Timer;

class GUI {
public:
    GUI();
private:
    std::unique_ptr<Timer> timer;
    std::vector<std::shared_ptr<class Map> > maps;
};
