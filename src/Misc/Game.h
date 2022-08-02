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

    void Initialize() noexcept
    {
        xcore::Init("TowerDefense");

        m_gameMgr = std::make_unique< xecs::game_mgr::instance >();
        RenderCameraSystem::m_windowPtr = &m_windowInst;

        m_gameMgr->RegisterComponents< ALL_COMPONENTS >();
        m_gameMgr->RegisterGlobalEvents< ALL_EVENTS >();
        m_gameMgr->RegisterSystems< ALL_SYSTEMS >();
    }

    void InitializePrefabs() noexcept
    {
        // Create Tower Prefab
        m_prefabGUIDs[PREFAB_TYPES::TOWER] =
        m_gameMgr->CreatePrefab<Position, Scale, GridCell, Timer>
        (
            [&](Position& _position, Scale& _scale, GridCell& _cell, Timer& _timer) noexcept
            {
                _position.m_value   = xcore::vector2{ 0.0f, 0.0f };
                _scale.m_value      = xcore::vector2{ 1.0f, 1.0f };
                _cell.m_X           = _cell.m_Y = 0;
                _timer.m_value      = 0.0f;
            }
        );

        // Create Tower Prefab
        m_prefabGUIDs[PREFAB_TYPES::TURRET] =
        m_gameMgr->CreatePrefabVariant
        (
            m_prefabGUIDs[PREFAB_TYPES::TOWER],
            [&](Timer& _timer) noexcept
            {
                _timer.m_value = 10.0f;
            }
        );

        // Create Player Prefab
        m_prefabGUIDs[PREFAB_TYPES::PLAYER] =
        m_gameMgr->CreatePrefab<Position, Scale, Rotation, GridCell, Player, Velocity>
        (
            [&](Position& _position, Scale& _scale, Rotation& _rotation, GridCell& _cell, Player& _player, Velocity& _velocity) noexcept
            {
                _position.m_value       = xcore::vector2{ 0.0f, 0.0f };
                _scale.m_value          = xcore::vector2{ 1.0f, 1.0f };
                _scale.m_value          = 0.0f;
                _cell.m_X = _cell.m_Y   = 0;

                _player.m_moveStates.reset();
                _velocity.m_value = xcore::vector2{ 0.0f, 0.0f };
            }
        );
    }

    void InitializeInstances() noexcept
    {
        // Create Tower instances from prefabs
        m_gameMgr->CreatePrefabInstance
        (
            1, m_prefabGUIDs[PREFAB_TYPES::TOWER],
            [&](Position& _position, Scale& _scale, GridCell& _cell) noexcept
            {
                _scale.m_value      = xcore::vector2{ 10.0f, 10.0f };
                _position.m_value   = xcore::vector2{ m_windowInst.m_width * 0.5f, m_windowInst.m_height * 0.5f };
                _cell               = grid::ComputeGridCellFromWorldPosition(_position.m_value);
            }
        );

        // Create Player instances from prefabs
        m_gameMgr->CreatePrefabInstance
        (
            1, m_prefabGUIDs[PREFAB_TYPES::PLAYER],
            [&](Position& _position, Scale& _scale, GridCell& _cell) noexcept
            {
                _scale.m_value      = xcore::vector2{ 30.0f, 30.0f };
                _position.m_value   = xcore::vector2{ m_windowInst.m_width * 0.5f, m_windowInst.m_height * 0.5f - 100.0f };
                _cell               = grid::ComputeGridCellFromWorldPosition(_position.m_value);
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
static Game sg_game;


// For printing text
namespace Text
{
    template < typename... TArgs >
    void PrintText(const int _x, const int _y, const char* const _str, TArgs&&... _args) noexcept
    {
        std::array<char, 256> finalString;
        const auto len = sprintf_s(finalString.data(), finalString.size(), _str, _args...);
        sg_game.m_windowInst.RenderText(_x, _y, finalString.data(), len);
    }
}
