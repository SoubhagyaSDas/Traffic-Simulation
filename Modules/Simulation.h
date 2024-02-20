#pragma once
#include <vector>
#include <memory>

class GUI;
class DynamicRoadItem;

class Simulation {
public:
    Simulation();
private:
    std::vector<std::shared_ptr<DynamicRoadItem> > dynamicRoadItems;
    std::weak_ptr<GUI> gui;
};
