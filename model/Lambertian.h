#pragma once
#include <glm/gtc/constants.hpp>

#include "HitRecord.h"
#include "Material.h"
#include "../math/MathUtils.h"

class Lambertian : public Material
{
public:

    Color Albedo;

    Lambertian(Color color) : Albedo(color) {}
    
    bool Scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const override
    {
        
        vec3 scatterDirection = record.normal + MathUtils::RandomUnitVector();

        if (MathUtils::IsNearlyZero(scatterDirection))
                scatterDirection = record.normal;
        
        scattered = Ray(record.point, scatterDirection);
        attenuation = Albedo;
        return true;
    }
};
