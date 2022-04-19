#include "Renderer.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <memory>
#include <memory>
#include <random>

static std::mt19937_64 rng;

void Renderer::Render()
{
    for (int y = 0; y < Height; y++)
    {
        for (int x = 0; x < Width; x++)
        {
            std::vector<Color> colors;
            Color num;

            for (int s = 0; s < sampling; s++)
            {
                std::uniform_real_distribution<float> randX(0.0, 1.0);
                std::uniform_real_distribution<float> randY(0.0, 1.0);

                float offsetX = randX(rng);
                float offsetY = randY(rng);

                Ray ray;
                HitRecord hitRecord;

                //Viewport is used here as follows {x = 0, y = 0, z = 800, w = 600} {starting.x, starting.y, width, height}
                if (scene.SendARay<float>(ray, static_cast<float>(x) + offsetX, static_cast<float>(y) + offsetY,
                                          hitRecord))
                {
                    vec3 N = hitRecord.normal;
                    colors.emplace_back(Color((N.x + 1) * 0.5, (N.y + 1) * 0.5, (N.z + 1) * 0.5));
                    continue;
                }

                colors.emplace_back(Color(x/Width,0,1-x/Width));
            }

            for (auto value : colors)
                num += value;

            ImageBuffer.setPixel(x, y, (num / sampling).AsSFColor());
        }
    }
}
