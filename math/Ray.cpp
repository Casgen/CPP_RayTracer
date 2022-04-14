#include "Ray.h"

void Ray::ToString()
{
    std::printf("Ray Origin: {%.2f,%.2f,%.2f} RayDirection: {%.2f,%.2f,%.2f}",Origin.x,Origin.y,Origin.z, Direction.x,Direction.y,Direction.z);
}
