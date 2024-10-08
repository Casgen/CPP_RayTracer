﻿#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "../math/Ray.h"
using namespace glm;

class Camera
{
    vec3 eyePosition, viewDirection, upVector, sideVector;
    mat4x4 viewMat;

    ivec4 viewPort;
    mat4x4 projectionMatPersp;
    mat4x4 ProjectionMatOrtho;

    float Azimuth, Zenith;

public:
    //Constructors
    /**
     * Construct a camera with a default position of vec3(0,0,0) and default view direction
     * (calculates view matrix, up vector and view vector)
     * @param width - Width of a viewport in pixels.
     * @param height - Height of a viewport in pixels.
     * @param f - Aperture of the lens.
     * @param focusDist - A Distance from the position of the camera to the desired point in the space.
     */
    Camera(const float& width, const float& height) : eyePosition(vec3(0.f, 0.f, 0.f)),
                                                          viewPort(ivec4(0, 0, width, height)),
                                                          projectionMatPersp(glm::perspective(
                                                              radians<float>(45.0f), width / height, 0.1f, 100.f)),
                                                          ProjectionMatOrtho(
                                                              ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f)),
                                                          Azimuth(0), Zenith(0)
    {
        CalculateAndSetUpVectors();
        CalculateAndSetViewTransformation();
    }


    /**
     * Constructs a camera with a default position of vec3(0,0,0) and a input view direction
     * @param width - Width of a viewport in pixels.
     * @param height - Height of a viewport in pixels.
     * @param lookAt - A vector which steers the camera to a given position
     * @param f - Aperture of the lens.
     * @param focusDist - A Distance from the position of the camera to the desired point in the space.
     */
    Camera(const float& width, const float& height, const vec3& lookAt)
        : eyePosition(vec3(0.f, 0.f, 0.f)), viewPort(ivec4(0, 0, width, height)),
          projectionMatPersp(glm::perspective(radians<float>(45.0f), width / height, 0.1f, 100.f)),
          ProjectionMatOrtho(ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f)), 
          Azimuth(0), Zenith(0)
    {
        viewDirection = normalize(lookAt);
        upVector = cross(cross(viewDirection, vec3(0.f, 0.f, 1.f)), viewDirection);
        sideVector = cross(viewDirection, upVector);
        CalculateAndSetViewTransformation();
    }


    /**
     * Creates a Camera with a position (calculates view matrix, up vector and view vector)
     * @param pos Position of the Camera
     * @param width - Width of a viewport in pixels;
     * @param height - Height of a viewport in pixels
     */
    template <typename NumType>
    Camera(vec3 const& pos, const NumType& width, const NumType& height)
        : eyePosition(pos), projectionMatPersp(perspective(radians<float>(45.0f), width / height, 0.1f, 100.f)),
          viewPort(0, 0, width, height), ProjectionMatOrtho(ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f)),
          Azimuth(0), Zenith(0)
    {
        CalculateAndSetUpVectors();
        CalculateAndSetViewTransformation();
    }

    //Getters
    vec3 GetEyePosition() const { return eyePosition; }
    vec3 GetViewDirection() const { return viewDirection; }
    vec3 GetUpVector() const { return upVector; }
    mat4x4 GetViewMat() const { return viewMat; }
    mat4x4 GetProjectionMatPersp() const { return projectionMatPersp; }
    mat4x4 GetProjectionMatOrtho() const { return ProjectionMatOrtho; }

    //Transformations

    /**
     * Rotates the camera around the Z-axis
     */
    template <typename NumType>
    void Yaw(NumType azimuth);

    /**
     * Rotates the camera around the Y-axis
     */
    template <typename NumType>
    void Pitch(NumType zenith);

    //Unique Funcs

    /**
     * Generates a ray at given coordinates
     * @param x - X coordinate on a viewport
     * @param y - Y coordinate on a viewport
     * @param modelMat - Model Matrix that is eventually multipled with the view matrix to create Model-View
     * transformation matrix
     */
    template <typename NumType>
    Ray CreateARay(const NumType& x, const NumType& y, const mat4x4& modelMat = mat4x4(1.f));

private:
    //Transformations

    /**
     * Calculates the up and View vector for the camera and stores them.
     */
    void CalculateAndSetUpVectors();

    /**
     * Calculates the view transformation matrix and stores it.
     */
    void CalculateAndSetViewTransformation();
};
