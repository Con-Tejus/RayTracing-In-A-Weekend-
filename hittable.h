#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "rtweekend.h"

class material;
struct hit_record
{
    point3 p;
    vec3 normal;
    double t;
    bool front_face;
    shared_ptr<material> mat_ptr;

    inline void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        // if the dot product between the direction of the ray and the outward normal of the sphere is less than 0 than we know it is front facing or outside the sphere
        front_face = (dot(r.direction(), outward_normal)) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
    public:
        // virtual function is a member function that is defined within base class in this case the hittable class and is redefined by a derived class ie sphere
        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};

#endif