#include "Ray.h"

void Ray::ToString()
{
    std::printf("Ray Origin: {%.2f,%.2f,%.2f} RayDirection: {%.2f,%.2f,%.2f}",origin.x,origin.y,origin.z, direction.x,direction.y,direction.z);
}
