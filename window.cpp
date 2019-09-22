#include <iostream>
#include "ray.h"

vec3 color(const ray& r)
{
    // gives direction in terms of the Z axis in this case the
    // negative direction is facing into the screen
    vec3 unit_direction = unit_vector(r.direction());
    float t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*vec3(1.0,1.0,1.0) + t*vec3(0.5, 0.7, 1.0);
}

int main() 
{
    // window size of 200x100
    int nx = 200;
    int ny = 100;
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);
    
}