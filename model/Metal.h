#pragma once
#include "HitRecord.h"
#include "Material.h"
#include "../math/MathUtils.h"

class Metal : public Material
{
public:
    Color Albedo;

    Metal(const Color& a) : Albedo(a) {}

    bool Scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const override
    {
        const vec3 reflectedRay = MathUtils::Reflect(normalize(rayIn.direction),record.normal);
        scattered = Ray(record.point, reflectedRay);
        attenuation = Albedo;
        return dot(scattered.direction,record.normal) > 0;
    }
};
