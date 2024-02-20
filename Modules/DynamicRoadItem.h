#pragma once
#include "RoadItem.h"
#include <vector>
#include <memory>

class Simulation;

class DynamicRoadItem : public RoadItem {
public:
    DynamicRoadItem();
private:
    std::vector<std::weak_ptr<Simulation> > simulations;
};
