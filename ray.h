#ifndef RAYH
#define RAYH
#include "vec3.h"

class ray
{
    public:
        ray() {}
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        point3 origin() const { return orig; }
        vec3 direction() const { return dir; }

        point3 at(float t) const 
        {
            return orig + t*dir; // will utilize the +moperator ebtween two vector as well as the * operator for a vector and a float
        }
    
    public:
        point3 orig;
        vec3 dir;
};

#endif