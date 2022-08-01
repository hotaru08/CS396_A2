/******************************************************************************
filename:	Game.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines the data related to a Game instance.

******************************************************************************/
#pragma once

struct Game
{
    // Enum stating the different prefab types
    enum class PREFAB_TYPES : std::uint8_t
    {
        TOWER = 0,
        TURRET,

        PLAYER,

        TOWER_ATTACKING_AI,
        PLAYER_ATTACKING_AI,
        BOMBER_AI
    };

    void Initialize()
    {
        xcore::Init("TowerDefense");

        m_gameMgr = std::make_unique< xecs::game_mgr::instance >();
        RenderingSystem::m_windowPtr = &m_windowInst;

        m_gameMgr->RegisterComponents< ALL_COMPONENTS >();
        m_gameMgr->RegisterSystems< ALL_SYSTEMS >();
    }

    void InitializePrefabs()
    {
        // Create Tower Prefab
        m_prefabGUIDs[PREFAB_TYPES::TOWER] =
        m_gameMgr->CreatePrefab<Position, Scale, GridCell>
        (
            [&](Position& _position, Scale& _scale, GridCell& _cell) noexcept
            {
                _position.m_value = xcore::vector2{ 0.0f, 0.0f };
                _scale.m_value = xcore::vector2{ 1.0f, 1.0f };
                _cell.m_X = _cell.m_Y = 0;
            }
        );

    }

    void InitializeInstances()
    {
        // Create Tower instances from prefabs
        m_gameMgr->CreatePrefabInstance
        (
            1, m_prefabGUIDs[PREFAB_TYPES::TOWER],
            [&](Position& _position, Scale& _scale, GridCell& _cell) noexcept
            {
                _scale.m_value = xcore::vector2{ 10.0f, 10.0f };
                _position.m_value = xcore::vector2{ m_windowInst.m_width * 0.5f, m_windowInst.m_height * 0.5f };
                _cell = grid::ComputeGridCellFromWorldPosition(_position.m_value);
            }
        );
    }

    void InitializeGame() noexcept
    {
        InitializePrefabs();
        InitializeInstances();
    }

    void CleanUp() noexcept
    {
        m_gameMgr.reset();
        xcore::Kill();
    }

    // Data Members -----------------------------------------------------------
    Window m_windowInst;
    std::unique_ptr<xecs::game_mgr::instance> m_gameMgr;

    // Container to store prefabs that is used in the game
    std::unordered_map< PREFAB_TYPES, xecs::prefab::guid > m_prefabGUIDs; 
};
