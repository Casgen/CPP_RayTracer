#pragma once
#include <vector>
#include "Camera.h"
#include "../model/HittableObject.h"

class Scene
{
    Camera cam;
    mat4x4 modelMat;
    std::vector<HittableObject*> hittableObjects;

public:
    //------Constructors-------
    Scene(const Camera& cam, std::vector<HittableObject*> objects)
        : cam(cam), modelMat(mat4x4()), hittableObjects(std::move(objects))
    {
    }

    Scene(const Camera& cam) : cam(cam), modelMat(mat4x4(1.f))
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
     *
     */

    template <typename T>
    bool SendARay(Ray& ray, const T& x, const T& y, HitRecord& hitRecord);
};
