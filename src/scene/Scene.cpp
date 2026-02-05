#include "Scene.hpp"
#include "renderer/Renderer2D.hpp"
#include "renderer/DebugRenderer2D.hpp"
#include <glm/glm.hpp>

namespace SolarSystem2D
{

    Scene::Scene()
    {
        // Entities
        m_SceneRoot = std::make_unique<Entity>("SceneRoot");
        m_SunEntity = std::make_unique<Entity>("Sun");
        m_EarthOrbitEntity = std::make_unique<Entity>("EarthOrbit");
        m_EarthVisualEntity = std::make_unique<Entity>("EarthVisual");
        m_MoonOrbitEntity = std::make_unique<Entity>("MoonOrbit");
        m_MoonVisualEntity = std::make_unique<Entity>("MoonVisual");

        // Hierarchy
        m_SunEntity->getTransform().setParent(&m_SceneRoot->getTransform());
        m_EarthOrbitEntity->getTransform().setParent(&m_SceneRoot->getTransform());
        m_EarthVisualEntity->getTransform().setParent(&m_EarthOrbitEntity->getTransform());
        m_MoonOrbitEntity->getTransform().setParent(&m_EarthOrbitEntity->getTransform());
        m_MoonVisualEntity->getTransform().setParent(&m_MoonOrbitEntity->getTransform());

        // Planets
        m_Sun   = std::make_unique<Planet>(*m_SunEntity, *m_SunEntity, 0.0f, 0.0f, 0.4f);
        m_Earth = std::make_unique<Planet>(*m_EarthOrbitEntity, *m_EarthVisualEntity, 1.0f, 1.0f, 0.15f);
        m_Moon  = std::make_unique<Planet>(*m_MoonOrbitEntity, *m_MoonVisualEntity, 0.25f, 3.0f, 0.07f);

        m_VisualEntities.push_back(m_SunEntity.get());
        m_VisualEntities.push_back(m_EarthVisualEntity.get());
        m_VisualEntities.push_back(m_MoonVisualEntity.get());
    }

    Scene::~Scene() = default;

    void Scene::update(float dt)
    {
        m_Earth->update(dt);
        m_Moon->update(dt);
    }

    void Scene::render(const OrthographicCamera& camera)
    {
        Renderer2D::beginScene(camera);

        for (auto entity : m_VisualEntities)
        {
            glm::vec4 color(1.0f);
            if (entity->getName() == "Sun") color = {1.0f, 0.9f, 0.0f, 1.0f};
            else if (entity->getName() == "EarthVisual") color = {0.2f, 0.5f, 1.0f, 1.0f};
            else if (entity->getName() == "MoonVisual") color = {0.8f, 0.8f, 0.8f, 1.0f};

            Renderer2D::drawQuad(entity->getTransform().getWorldMatrix(), color);
        }

        DebugRenderer2D::beginScene(camera);

        // Earth orbit
        DebugRenderer2D::drawCircle(glm::vec2(0.0f), 1.0f, {0.4f,0.4f,0.4f,0.3f});

        glm::vec3 earthPos = glm::vec3(m_EarthOrbitEntity->getTransform().getWorldMatrix()[3]);
        DebugRenderer2D::drawCircle({earthPos.x, earthPos.y}, 0.25f, {0.6f,0.6f,0.6f,0.3f});
    }

}
