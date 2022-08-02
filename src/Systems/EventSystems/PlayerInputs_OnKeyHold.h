/******************************************************************************
filename:	PlayerInputs_OnKeyHold.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles any key hold events for player inputs.

******************************************************************************/
#pragma once

struct PlayerInputs_OnKeyHold : xecs::system::instance
{
    constexpr static auto typedef_v =
    xecs::system::type::global_event< OnKeyDown >
    {
        .m_pName = "PlayerInputs_OnKeyDown"
    };

    using query = std::tuple
    < 
        xecs::query::must< Player >
    >;

    void OnStart()
    {
        m_playerInputQuery.m_Must.AddFromComponents< Player >();
    }

    void OnEvent(const unsigned char _key) noexcept
    {
        // Seach for entities with Player component to update movement state
        std::cout << "listened to key down event ... updating event" << std::endl;
        Foreach
        (
            Search(m_playerInputQuery),
            [&](Player& _player)
            {
                // Update 
                switch (_key)
                {
                case 'w':
                    std::cout << "Triggered W" << std::endl;
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::UP)] = true;
                    break;
                case 's':
                    std::cout << "Triggered S" << std::endl;
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::DOWN)] = true;
                    break;
                case 'a':
                    std::cout << "Triggered A" << std::endl;
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::LEFT)] = true;
                    break;
                case 'd':
                    std::cout << "Triggered D" << std::endl;
                    _player.m_moveStates[static_cast<std::uint8_t>(Player::MOVE_STATE::RIGHT)] = true;
                    break;
                }
            }
        );
    }

    xecs::query::instance m_playerInputQuery;
};
