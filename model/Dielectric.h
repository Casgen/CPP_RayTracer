#pragma once
#include "HitRecord.h"
#include "Material.h"
#include "../math/MathUtils.h"

class Dielectric : public Material
{
public:
    float indexOfRefraction;

    /**
     *  Creates a dielectric material with an index of refraction
     *  @param etai - an Index of refraction (
     */
    Dielectric(const float& etai) : indexOfRefraction(etai) {}

    bool Scatter(const Ray& rayIn, const HitRecord& record, Color& attenuation, Ray& scattered) const override
    {
        attenuation = Color(1.f);
        float refractionRatio = record.frontFace ? 1.0f / indexOfRefraction : indexOfRefraction;

        vec3 unitDirection = normalize(rayIn.direction);
        float cosTheta = fmin(dot(-unitDirection, record.normal), 1.0);
        float sinTheta = sqrt(1.0f - cosTheta*cosTheta);

        bool cannotRefract = refractionRatio * sinTheta > 1.0f;
        vec3 direction;

        if (cannotRefract || reflectance(cosTheta, refractionRatio) > MathUtils::RandomFloat())
            direction = MathUtils::Reflect(unitDirection, record.normal);
        else
            direction = MathUtils::Refract(unitDirection, record.normal, refractionRatio);

        scattered = Ray(record.point, direction);
        return true;
    }

    private:
        float reflectance(float cos, float refIdx) const
        {
            float r0 = (1-refIdx)/(1+refIdx);
            r0 = r0*r0;
            return r0 + (1.f-r0)*pow(1-cos,5);
        }
};

