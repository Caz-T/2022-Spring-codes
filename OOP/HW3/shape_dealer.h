#ifndef HW3_SHAPE_DEALER_H
#define HW3_SHAPE_DEALER_H

#include <vector>
#include "shape.h"
class shape_dealer
{
public:
    shape_dealer();             // constructor, automatically triggering input function
    ~shape_dealer() = default;  // trivial destructor

private:
    std::vector<shape> shapes;  // stores all shapes
    bool push_shape(double command, double data);  // add a shape to (vector)shapes
    void report();              // displays total circumference and total area
};


#endif //HW3_SHAPE_DEALER_H

