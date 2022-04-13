#include "Renderer.h"

#include <iostream>
#include <memory>

void Renderer::Render()
{
   for (int y = 0; y < Height; y++)
   {
      for (int x = 0; x < Width; x++)
      {
         //Viewport is used here as follows {x = 0, y = 0, z = 800, w = 600} {starting.x, starting.y, width, height}
         vec3 position3d = unProject(vec3(x,y,0.1f),ModelMat*scene.GetCamera().GetViewMat(),ProjectionMatPersp,ViewPort); 
         std::shared_ptr<Ray> ray = std::make_shared<Ray>(scene.GetCamera().GetEyePosition(),position3d);
         Color color = Color(position3d.x,position3d.y,0);
         ImageBuffer.setPixel(position3d.x,position3d.y,color.AsSFColor());
      }
   }
}
