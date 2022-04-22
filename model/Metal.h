#pragma once
#include "HitRecord.h"
#include "Material.h"
#include "../math/MathUtils.h"

class Metal : public Material
{
public:
    Color Albedo;
    float fuzz;

    /**
     *  A Material which totally reflects rays coming in
     *  @param a - A Color (Attenuation color)
     *  @param f - Amount of fuzz (bigger the value, the more is the scattered ray steered in a random direction)
     */
    Metal(const Color& a, const float& f = 0) : Albedo(a), fuzz(f) {}

    bool Scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const override
    {
        const vec3 reflectedRay = MathUtils::Reflect(normalize(rayIn.direction),record.normal);
        
        scattered = Ray(record.point, reflectedRay + fuzz*MathUtils::RandomInUnitSphere());
        attenuation = Albedo;
        return dot(scattered.direction,record.normal) > 0;
    }
};
