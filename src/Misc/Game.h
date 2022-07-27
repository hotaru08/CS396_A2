#pragma once

static struct Game
{
    Window m_windowInst;

    std::unique_ptr<xecs::game_mgr::instance> m_gameMgr = nullptr;
    int m_DisplayGridInfo = 0;


    void Initialize() noexcept
    {
        xcore::Init("TowerDefense");

        m_gameMgr = std::make_unique< xecs::game_mgr::instance >();
        RenderingSystem::m_windowPtr = &m_windowInst;

        m_gameMgr->RegisterComponents<Position, Scale, Velocity,Timer>();
        m_gameMgr->RegisterSystems<RenderingSystem, RenderTowerSystem>();
    }

    void CleanUp() noexcept
    {
        m_gameMgr.reset();
        xcore::Kill();
    }

} sg_game;
