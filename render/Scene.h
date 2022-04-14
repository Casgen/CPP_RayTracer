#pragma once
#include <vector>

#include "Camera.h"
#include "../model/HittableObject.h"

class Scene
{
   Camera Cam;
   std::vector<HittableObject*> HittableObjects;

public:

   //------Constructors-------
   Scene(const Camera& cam, std::vector<HittableObject*> objects)
      : Cam(cam), HittableObjects(std::move(objects)) {}

   Scene(const Camera& cam) : Cam(cam) {}
   
   
   //---------Getters---------
   Camera GetCamera() const {return Cam;}
   std::vector<HittableObject*> GetObjects() const {return HittableObjects;}

   
   //---------Setters---------
   void SetCamera(Camera cam);
   void SetHittableObjects(std::vector<HittableObject> objects);

   
   //------Unique Funcs-------
   void AddHittableObject(HittableObject* obj) {HittableObjects.push_back(obj);}
   void SendARay();
    
};
