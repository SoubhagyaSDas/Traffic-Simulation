#pragma once
#include <vector>
#include <memory>

class RoadItem;

class Road {
public:
    Road();
private:
    std::vector<std::shared_ptr<RoadItem> > roadItems;
};
