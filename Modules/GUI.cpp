#include "GUI.h"
#include "Timer.h"

GUI::GUI() : timer(std::make_unique<Timer>()) {}
