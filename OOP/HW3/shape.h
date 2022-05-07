#ifndef HW3_SHAPE_H
#define HW3_SHAPE_H

const double pi = 3.141592654;
class shape
{
public:
    shape(double nn, double ll);
    ~shape() = default;
    double getarea() const; // get the area of the shape
    double getcir() const;  // get the circumference of the shape

private:
    double side_length;
    int n;                  // number of sides, 5 for circle
};


#endif //HW3_SHAPE_H
