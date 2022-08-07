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
        BULLET,
        
        TOWER_ATTACKING_AI,
        PLAYER_ATTACKING_AI,
        BOMBER_AI,

        SPAWNER,

        RENDER_MELEE,
        RENDER_HEALTH_BAR,

        TOTAL_NUM_PREFABS
    };

    void Initialize() noexcept
    {
        xcore::Init("TowerDefense");

        m_gameMgr = std::make_unique< xecs::game_mgr::instance >();

        m_gameMgr->RegisterComponents< ALL_COMPONENTS, ALL_TAGS >();
        m_gameMgr->RegisterGlobalEvents< ALL_EVENTS >();
        m_gameMgr->RegisterSystems< ALL_SYSTEMS >();
    }

    void InitializePrefabs() noexcept
    {
        // Create Tower Prefab
        m_prefabGUIDs[PREFAB_TYPES::TOWER] =
        m_gameMgr->CreatePrefab<Position, Scale, GridCell, Color, Health, Tower>
        (
            [&](Position& _towerPos, Scale& _scale, Color& _color, Health& _health) noexcept
            {
                _scale.m_value  = xcore::vector2{ 30.0f, 30.0f };
                _color.m_value  = xcore::vector3{ 0.45490f, 0.45490f, 0.81176f };
                _health.m_value = Definitions::TOWER_HEALTH;
            }
        );

        // Create Turrent Prefab
        m_prefabGUIDs[PREFAB_TYPES::TURRET] =
        m_gameMgr->CreatePrefab<Position, Scale, Rotation, GridCell, Timer, FireBullet, Color, Target>
        (
            [&](Scale& _scale, Color& _color, FireBullet& _fireBullet) noexcept
            {
                _scale.m_value  = xcore::vector2{ 30.0f, 30.0f };
                _color.m_value  = xcore::vector3{ 0.2f, 0.5f, 1.0f };
                _fireBullet.m_shootInterval = 0.15f;
            }
        );

        // Create Player Prefab
        m_prefabGUIDs[PREFAB_TYPES::PLAYER] =
        m_gameMgr->CreatePrefab<Position, Rotation, Scale, GridCell, Player, Velocity, Color, Health, Timer, MeleeAttack>
        (
            [&](Position& _playerPos, Scale& _scale, Color& _color, 
                Health& _health, Timer& _timer) noexcept
            {
                _scale.m_value      = xcore::vector2{ 20.0f, 20.0f };
                _color.m_value      = xcore::vector3{ 0.75f, 1.0f, 0.75f };
                _health.m_value     = Definitions::PLAYER_HEALTH;
            }
        );

        // Create Spawner Prefab, that spawn AIs
        m_prefabGUIDs[PREFAB_TYPES::SPAWNER] =
        m_gameMgr->CreatePrefab<Timer, Spawner>
        (
            [&](Timer& _timer) noexcept
            {
                _timer.m_value = 3.0f;
            }
        );

        // --------------------------------------------------------------------

        // Create Bullet Prefab
        m_prefabGUIDs[PREFAB_TYPES::BULLET] =
        m_gameMgr->CreatePrefab<Position, Scale, GridCell, Velocity, Color, Bullet>
        (
            [&](Scale& _scale, Color& _color) noexcept
            {
                _scale.m_value = xcore::vector2{ 3.0f, 3.0f };
                _color.m_value = xcore::vector3{ 0.2f, 0.7f, 1.0f };
            }
        );

        // Create Tower AI Prefab
        m_prefabGUIDs[PREFAB_TYPES::TOWER_ATTACKING_AI] =
        m_gameMgr->CreatePrefab<Position, Rotation, Scale, GridCell, Velocity, Timer, Color, Target, TowerAI>
        (
            [&](Scale& _scale, Color& _color, Velocity& _velocity) noexcept
            {
                _scale.m_value = xcore::vector2{ 20.0f, 20.0f };
                _color.m_value = xcore::vector3{ 1.0f, 0.57647f, 0.41961f };
                _velocity.m_value = xcore::vector2{ 3.0f, 3.0f };
            }
        );

        // Create Player AI Prefab
        m_prefabGUIDs[PREFAB_TYPES::PLAYER_ATTACKING_AI] =
        m_gameMgr->CreatePrefab<Position, Rotation, Scale, GridCell, Velocity, Timer, Color, Target, PlayerAI, MeleeAttack>
        (
            [&](Scale& _scale, Color& _color, Velocity& _velocity) noexcept
            {
                _scale.m_value = xcore::vector2{ 20.0f, 20.0f };
                _color.m_value = xcore::vector3{ 0.88627f, 0.36471f, 0.36078f };
                _velocity.m_value = xcore::vector2{ 3.0f, 3.0f };
            }
        );

        // Create Bomber AI Prefab
        m_prefabGUIDs[PREFAB_TYPES::BOMBER_AI] =
        m_gameMgr->CreatePrefab<Position, Rotation, Scale, GridCell, Velocity, Timer, Color, Target, BomberAI, FireBullet>
        (
            [&](Scale& _scale, Color& _color, Velocity& _velocity) noexcept
            {
                _scale.m_value = xcore::vector2{ 20.0f, 20.0f };
                _color.m_value = xcore::vector3{ 0.71569f, 0.20784f, 0.22353f };
                _velocity.m_value = xcore::vector2{ 1.5f, 1.5f };
            }
        );

        // Create Melee Attack Range Prefab
        m_prefabGUIDs[PREFAB_TYPES::RENDER_MELEE] =
        m_gameMgr->CreatePrefab<Position, Rotation, Scale, Color, Timer, RenderMelee>
        (
            [&](Position& _pos, Scale& _scale, Color& _color) noexcept
            {
                _scale.m_value = xcore::vector2{ 20.0f, 10.0f };
                _color.m_value = xcore::vector3{ 0.90980f, 0.90980f, 0.90980f };
            }
        );

        // Create Health Bar Prefab
        m_prefabGUIDs[PREFAB_TYPES::RENDER_HEALTH_BAR] =
        m_gameMgr->CreatePrefab<Position, Scale, Color, HealthBar>
        (
            [&](Position& _pos, Scale& _scale, Color& _color) noexcept
            {
                _scale.m_value = xcore::vector2{ 50.0f, 7.5f };
                _color.m_value = xcore::vector3{ 1.0f, 0.0f, 0.0f };
            }
        );
    }

    void InitializeInstances() noexcept
    {
        // Create Tower instances from prefabs
        m_gameMgr->CreatePrefabInstance
        (
            1, m_prefabGUIDs[PREFAB_TYPES::TOWER],
            [&](xecs::component::entity& _ent, Position& _position, GridCell& _cell) noexcept
            {
                _position.m_value = xcore::vector2{ m_windowInst.m_width * 0.5f, m_windowInst.m_height * 0.5f };
                _cell             = grid::ComputeGridCellFromWorldPosition(_position.m_value);

                // Create Health Bar for Tower
                m_gameMgr->CreatePrefabInstance
                (
                    1, m_prefabGUIDs[PREFAB_TYPES::RENDER_HEALTH_BAR],
                    [&](Position& _healthPos, HealthBar& _bar) noexcept
                    {
                        _healthPos.m_value = _position.m_value;
                        _bar.m_value = _ent;
                    }
                );

                // Create Turrent instances from prefabs, around the Main Tower
                unsigned totalTurrets = 4;
                float degBetweenTurrets = xcore::math::PI2.m_Value / totalTurrets;

                for (unsigned i = 0; i < totalTurrets; ++i)
                {
                    m_gameMgr->CreatePrefabInstance
                    (
                        1, m_prefabGUIDs[PREFAB_TYPES::TURRET],
                        [&](Position& _turrentPos, Rotation& _turretRot,
                            GridCell& _turretCell, Timer& _timer) noexcept
                        {
                            _turrentPos.m_value = xcore::vector2
                            {
                                _position.m_value.m_X + 100.0f * std::cosf(degBetweenTurrets * i),
                                _position.m_value.m_Y + 100.0f * -std::sinf(degBetweenTurrets * i)
                            };

                            _turretRot.m_value = xcore::math::RadToDeg(degBetweenTurrets * i);
                            _turretCell = grid::ComputeGridCellFromWorldPosition(_turrentPos.m_value);
                        }
                    );
                }
            }
        );

        // Create Player instances from prefabs
        m_gameMgr->CreatePrefabInstance
        (
            1, m_prefabGUIDs[PREFAB_TYPES::PLAYER],
            [&](Position& _position, GridCell& _cell) noexcept
            {
                _position.m_value   = xcore::vector2{ m_windowInst.m_width * 0.5f, m_windowInst.m_height * 0.5f + 300.0f };
                _cell               = grid::ComputeGridCellFromWorldPosition(_position.m_value);
            }
        );

        // Create Spawners
        m_gameMgr->CreatePrefabInstance
        (
            1, m_prefabGUIDs[PREFAB_TYPES::SPAWNER],
            [&]() noexcept
            { }
        );
    }

    void InitializeGame() noexcept
    {
        srand(time(NULL));

        InitializePrefabs();
        InitializeInstances();
    }

    void CleanUp() noexcept
    {
        m_gameMgr.reset();
        xcore::Kill();
    }

    // Data Members -----------------------------------------------------------
    
    // Container to store prefabs that is used in the game
    std::unordered_map< PREFAB_TYPES, xecs::prefab::guid > m_prefabGUIDs; 
    Window m_windowInst;
    std::unique_ptr<xecs::game_mgr::instance> m_gameMgr;
    bool m_gameOver = false;
    float m_elapsedTime;
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
