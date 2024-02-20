#pragma once
#include <vector>
#include <memory>

class Road;

class Map {
public:
    Map();
private:
    std::vector<std::shared_ptr<Road> > roads;
};
