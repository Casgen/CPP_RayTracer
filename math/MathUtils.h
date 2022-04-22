#pragma once
#include <random>
#include <glm/glm.hpp>

using namespace glm;

class MathUtils
{
private:
    inline static std::mt19937_64 rng = std::mt19937_64(487);
    constexpr auto static zeroTolerance = 1e-8;

public:
    static float RandomFloat(const float& min, const float& max)
    {
        std::uniform_real_distribution randX(min, max);
        return randX(rng);
    }

    static bool IsNearlyZero(const vec4& vec)
    {
        return (vec.x < zeroTolerance && vec.x > -zeroTolerance) &&
            (vec.y < zeroTolerance && vec.y > -zeroTolerance) &&
            (vec.z < zeroTolerance && vec.z > -zeroTolerance) &&
            (vec.w < zeroTolerance && vec.w > -zeroTolerance);
    }

    static bool IsNearlyZero(const vec3& vec)
    {
        return (vec.x < zeroTolerance && vec.x > -zeroTolerance) &&
            (vec.y < zeroTolerance && vec.y > -zeroTolerance) &&
            (vec.z < zeroTolerance && vec.z > -zeroTolerance);
    }

    static vec3 Reflect(const vec3& v, const vec3& n)
    {
        return v - 2 * dot(v, n) * n;
    }


    static vec3 RandomVec3(const float& min, const float& max)
    {
        return {RandomFloat(min, max), RandomFloat(min, max), RandomFloat(min, max)};
    }

    static vec3 RandomInUnitSphere()
    {
        while (true)
        {
            const auto p = RandomVec3(-1, 1);
            if (pow(length(p), 2) >= 1) continue;
            return p;
        }
    }

    static vec3 RandomUnitVector() { return normalize(RandomInUnitSphere()); }

    static float VectorLengthSquared(const vec3& vec)
    {
        return vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
    }
};
