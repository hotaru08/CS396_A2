/******************************************************************************
filename:	PlayerInputs_KeyEventsSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    

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
            [&](Direction& _direction)
            {
                // Update 
                switch (_key)
                {
                case 'w':
                    _direction.m_value.m_Y = -1.0f;
                    break;
                case 's':
                    _direction.m_value.m_Y = 1.0f;
                    break;
                case 'a':
                    _direction.m_value.m_X = -1.0f;
                    break;
                case 'd':
                    _direction.m_value.m_X = 1.0f;
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
            [&](Direction& _direction)
            {
                switch (_key)
                {
                case 'w':
                case 's':
                    _direction.m_value.m_Y = 0.0f;
                    break;
                case 'a':
                case 'd':
                    _direction.m_value.m_X = 0.0f;
                    break;
                }
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};
