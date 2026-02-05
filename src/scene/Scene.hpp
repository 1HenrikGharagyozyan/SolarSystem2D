#pragma once

#include "Entity.hpp"
#include "Planet.hpp"
#include "renderer/OrthographicCamera.hpp"

#include <memory>
#include <vector>

namespace SolarSystem2D
{

    class Scene
    {
    public:
        Scene();
        ~Scene();

        void update(float dt);
        void render(const OrthographicCamera& camera);

        Entity& getRoot() { return *m_SceneRoot; }

    private:
        std::unique_ptr<Entity> m_SceneRoot;

        std::unique_ptr<Entity> m_SunEntity;
        std::unique_ptr<Entity> m_EarthOrbitEntity;
        std::unique_ptr<Entity> m_EarthVisualEntity;
        std::unique_ptr<Entity> m_MoonOrbitEntity;
        std::unique_ptr<Entity> m_MoonVisualEntity;

        std::unique_ptr<Planet> m_Sun;
        std::unique_ptr<Planet> m_Earth;
        std::unique_ptr<Planet> m_Moon;

        std::vector<Entity*> m_VisualEntities;
    };

}
