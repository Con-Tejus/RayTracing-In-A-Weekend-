#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

/*
shared_ptr<type> is a pointer to some allocated type, with reference-counting semantics.Every time you assign its 
value to another shared pointer (usually with a simple assignment), the reference count is incremented. As shared 
pointers go out of scope (like at the end of a block or function), the reference count is decremented. Once the count 
goes to zero, the object is deleted. 
*/
class hittable_list : public hittable
{
    public:
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) { add(object); }

        void clear() { objects.clear(); }
        void add(shared_ptr<hittable> object) { objects.push_back(object); }

        virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;
    
    public:
        std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
    hit_record temp_rec;
    bool hit_anything = false;
    auto closest_so_far = t_max;

    //const auto here allows us to observe the entry in objects without knowing the type
    for(const auto& object: objects)
    {
        if(object->hit(r,t_min, closest_so_far, temp_rec))
        {
            closest_so_far = temp_rec.t;
            hit_anything = true;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif