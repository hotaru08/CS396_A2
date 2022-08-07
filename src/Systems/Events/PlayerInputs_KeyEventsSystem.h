/******************************************************************************
filename:	PlayerInputs_KeyEventsSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Player Inputs.

******************************************************************************/
#pragma once

struct PlayerInputs_OnKeyDown : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::global_event< OnKeyDown >
    {
        .m_pName = "PlayerInputs_OnKeyDown"
    };

    void OnGameStart()
    {
        m_playerInputQuery.m_Must.AddFromComponents< Player >();
    }

    void OnEvent(const unsigned char _key) noexcept
    {
        // Seach for entities with Player component to update movement state
        Foreach
        (
            Search(m_playerInputQuery),
            [&](Velocity& _velocity)
            {
                // Update 
                switch (_key)
                {
                case 'w':
                    _velocity.m_value.m_Y = -3.0f;
                    break;
                case 's':
                    _velocity.m_value.m_Y = 3.0f;
                    break;
                case 'a':
                    _velocity.m_value.m_X = -3.0f;
                    break;
                case 'd':
                    _velocity.m_value.m_X = 3.0f;
                    break;

                case '~': // Set to render debug info
                    //SendGlobalEvent< RenderDebugInfo >(true);
                    break;
                }
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};

struct PlayerInputs_OnKeyUp : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::global_event< OnKeyUp >
    {
        .m_pName = "PlayerInputs_OnKeyUp"
    };

    void OnGameStart()
    {
        m_playerInputQuery.m_Must.AddFromComponents< Player >();
    }

    void OnEvent(const unsigned char _key) noexcept
    {
        // Seach for entities with Player component to update movement state
        Foreach
        (
            Search(m_playerInputQuery),
            [&](Velocity& _velocity)
            {
                switch (_key)
                {
                case 'w':
                case 's':
                    _velocity.m_value.m_Y = 0.0f;
                    break;
                case 'a':
                case 'd':
                    _velocity.m_value.m_X = 0.0f;
                    break;
                }
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};

struct PlayerInputs_OnMouseMoved : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::global_event< OnMouseMoved >
    {
        .m_pName = "PlayerInputs_OnMouseMoved"
    };

    void OnGameStart()
    {
        m_playerInputQuery.m_Must.AddFromComponents< Player >();
    } 

    void OnEvent(const xcore::vector2& _mousePos) noexcept
    {
        // Seach for entities with Player component to update movement state
        Foreach
        (
            Search(m_playerInputQuery),
            [&](Position& _pos, Rotation& _rotation, Velocity& _velocity)
            {
                xcore::vector2 dir = _mousePos - _pos.m_value;
                _rotation.m_value = -xcore::ATan2(dir.m_Y, dir.m_X).getDegrees().m_Value;
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};

struct PlayerInputs_OnMouseButtonDown : xecs::system::instance
{
    // Aliases
    using spawn_attack = xecs::event::instance< Position, Rotation>;
    using events = std::tuple< spawn_attack >;

    constexpr static auto typedef_v =
    xecs::system::type::global_event< OnMouseButtonDown >
    {
        .m_pName = "PlayerInputs_OnMouseButtonDown"
    };

    void OnGameStart()
    {
        m_playerInputQuery.m_Must.AddFromComponents< Player >();
    }

    void OnEvent(const unsigned char _btn) noexcept
    {
        // Seach for entities with Player component to update movement state
        Foreach
        (
            Search(m_playerInputQuery),
            [&](Timer& _timer, MeleeAttack& _meleeAttack)
            {
                // Left Mouse click, set player to be unable to attack
                if (_btn == 0 && _timer.m_value <= 0.0f)
                {
                    _meleeAttack.m_value = true;
                }
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};
