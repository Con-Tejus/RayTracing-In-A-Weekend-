#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"

class sphere : public hittable
{
    public:
        sphere() {}
        sphere(point3 cen, float r, shared_ptr<material> m) : center(cen), radius(r), mat_ptr(m) {};

        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override; 
        // this ovveride signifies that the virtual function will be redefined here in this class

    public:
        point3 center;
        float radius;
        shared_ptr<material> mat_ptr;
};

// specify sphere::hit because this is the derived class implementation of hit from the base class hittable
bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
    //center can be called directly here because it is public
    vec3 oc = r.origin() - center;
    auto a = r.direction().squared_length();
    auto half_b = dot(oc, r.direction());
    auto c = oc.squared_length() - radius*radius;

    auto discriminant = half_b*half_b - a*c;
    if(discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    //find the nearest root that lies in the acceptable range between tmin and tmax
    auto root = (-half_b - sqrtd) / a;

    if(root < t_min || root > t_max)
    {
        root = (-half_b + sqrtd) / a;
        if(root < t_min || root > t_max)
        {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outside_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outside_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}

#endif