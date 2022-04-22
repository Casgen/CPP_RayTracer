#include "Renderer.h"
#include "../math/MathUtils.h"

Color Renderer::ColorRay(int& x, int& y, Ray& ray, const int& depth)
{
    if (depth <= 0) return {0.f};

    HitRecord hitRecord = HitRecord();

    //Viewport is used here as follows {x = 0, y = 0, z = 800, w = 600} {starting.x, starting.y, width, height}
    if (scene.Hit<float>(ray, hitRecord))
    {
        Ray scattered;
        Color attenuation;
        if (hitRecord.material->Scatter(ray,hitRecord,attenuation,scattered))
            return attenuation * ColorRay(x, y, scattered, depth - 1);
        return {0.f};
    }

    vec3 unitDirection = normalize(ray.direction);
    float t = 0.5f * (unitDirection.y + 1.0f);
    return Color(1.f) * (1.0f - t) + Color(0.5f, 0.7f, 1.0f) * t;
}


void Renderer::Render()
{
    for (int y = 0; y < Height; y++)
    {
        for (int x = 0; x < Width; x++)
        {
            auto num = Color(0.f);
            for (int s = 0; s < sampling; s++)
            {
                Ray ray = scene.GetCamera().CreateARay<float>(x + MathUtils::RandomFloat(0.f, 1.f),
                                                              y + MathUtils::RandomFloat(0.f, 1.f));
                num += ColorRay(x, y, ray, rayRecursionDepth);
            }

            Color result = num / sampling;
            ImageBuffer.setPixel(x, y, result.AsSFColor());
        }
    }
}
