#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct Kitchen
{
    Kitchen();
    ~Kitchen();

    Dishwasher dishwasher;

    void start(Dishwasher* dishwasher);
    void stop(Dishwasher* dishwasher);

    JUCE_LEAK_DETECTOR(Kitchen)
};
