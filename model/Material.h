#pragma once
#include "../math/Color.h"
#include "../math/Ray.h"

struct HitRecord;

class Material
{
public:
    virtual bool Scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const = 0;
};
