#pragma once
#include <vector>
#include "Camera.h"
#include "../model/HittableObject.h"

/**
 * @attention WATCH OUT FOR THE tMin value !! if set to high, it can show black spots, when objects are very close to each other.
 */
class Scene
{
private:
    Camera cam;
    mat4x4 modelMat;
    std::vector<HittableObject*> hittableObjects;
    float tMax, tMin;

public:
    //------Constructors-------
    Scene(const Camera& cam, std::vector<HittableObject*> objects)
        : cam(cam), modelMat(mat4x4()), hittableObjects(std::move(objects)), tMax(INFINITY), tMin(0.001f)
    {
    }

    /**
     * Creates a scene with a camera in it
     * @param cam - A camera
     */
    Scene(const Camera& cam) : cam(cam), modelMat(mat4x4()), tMax(INFINITY), tMin(0.001f)
    {
    }


    //---------Getters---------
    Camera GetCamera() const { return cam; }
    std::vector<HittableObject*> GetObjects() const { return hittableObjects; }


    //---------Setters---------
    void SetCamera(Camera cam);
    void SetHittableObjects(std::vector<HittableObject> objects);


    //------Unique Funcs-------

    /**
     * Adds a hittable object to the scene
     * @param obj - Hittable object to be added to the array
     */
    void AddHittableObject(HittableObject* obj) { hittableObjects.push_back(obj); }

    /**
     * Based on a given ray it calculates whether the ray hits any of the objects or not
     * @param ray - Input ray that calculates the intersection with.
     * @param hitRecord - a HitRecord which outputs a result if an intersection occured.
     */

    template <typename T>
    bool Hit(Ray& ray, HitRecord& hitRecord);
};
