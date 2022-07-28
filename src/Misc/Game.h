#pragma once

struct Game
{
    void Initialize()
    {
        xcore::Init("TowerDefense");

        m_gameMgr = std::make_unique< xecs::game_mgr::instance >();
        RenderingSystem::m_windowPtr = &m_windowInst;

        m_gameMgr->RegisterComponents< ALL_COMPONENTS >();
        m_gameMgr->RegisterSystems< ALL_SYSTEMS >();
    }

    void InitializeGame() noexcept
    {
        // Create Tower Entity
        m_gameMgr->getOrCreateArchetype< Position, Scale >().CreateEntities
        (
            1,
            [&](Position& position, Scale& scale) noexcept
            {
                scale.m_value = xcore::vector2
                {
                    5.0f, 5.0f
                };

                position.m_value = xcore::vector2
                {
                    m_windowInst.m_width * 0.5f,
                    m_windowInst.m_height * 0.5f
                };
            }
        );

        // Create Main Tower Prefab
        auto PrefabGuid = m_gameMgr->CreatePrefab<Position, Scale>
        (
            [&](Position& position, Scale& scale) noexcept
            {
                position.m_value = xcore::vector2
                {
                    0.0f, 0.0f
                };

                scale.m_value = xcore::vector2
                {
                    1.0f, 1.0f
                };
            }
        );

        // Create Main Tower Prefab instance
        m_gameMgr->CreatePrefabInstance
        (
            1, PrefabGuid, 
            [&](Position& position, Scale& scale) noexcept
            {
                position.m_value = xcore::vector2
                { 
                    100.0f,100.0f
                };
            }
        );
    }

    void CleanUp() noexcept
    {
        m_gameMgr.reset();
        xcore::Kill();
    }

    Window m_windowInst;
    std::unique_ptr<xecs::game_mgr::instance> m_gameMgr;
};
