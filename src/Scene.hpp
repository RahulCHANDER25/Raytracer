/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Scene
*/

#pragma once

#include "Camera.hpp"
#include "Lights.hpp"
#include "Shapes/IShape.hpp"

#include <memory>
#include <vector>

namespace RayTracer {
class Camera;
class Scene {
public:
    std::vector<std::unique_ptr<IShape>> shapes;
    std::vector<std::unique_ptr<ILight>> lights;
    std::unique_ptr<Camera> camera;
    int width, height;

    Scene(int w, int h);
    Scene(const Scene &) = delete;
    Scene &operator=(const Scene &) = delete;

    void addShape(std::unique_ptr<IShape> shape);
    void addLight(std::unique_ptr<ILight> light);
    void setCamera(const RayTracer::Camera &cam);

    void generateImage(std::ostream &out) const;
};
} // namespace RayTracer
