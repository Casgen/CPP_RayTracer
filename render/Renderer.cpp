#include "Renderer.h"

#include <iostream>
#include <memory>

void Renderer::Render()
{
    for (HittableObject* object : scene.GetObjects())
    {
        for (int y = 0; y < Height; y++)
        {
            for (int x = 0; x < Width; x++)
            {
                //Viewport is used here as follows {x = 0, y = 0, z = 800, w = 600} {starting.x, starting.y, width, height}
                vec3 position3d = unProject(vec3(x, y, 0.1f), ModelMat * scene.GetCamera().GetViewMat(),
                                            ProjectionMatPersp, ViewPort);
                Ray ray = Ray(scene.GetCamera().GetEyePosition(), position3d);


                float t;
                if ((t = object->TestIntersection(ray)) > 0.0)
                {
                    vec3 N = normalize(ray.At(t) - object->GetPosition());
                    Color color = Color((N.x+1)*0.5, (N.y+1)*0.5, (N.z+1)*0.5);
                    ImageBuffer.setPixel(x, y, color.AsSFColor());
                }
            }
        }
    }
}
