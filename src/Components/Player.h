/******************************************************************************
filename:	Player.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data relating to a player.

******************************************************************************/
#pragma once

struct Player
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Player"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        //TextFile.Field("MoveStates", m_moveStates[0]).clear();
        return{};
    }

    enum class MOVE_STATE : std::uint8_t
    {
        NONE = 0,
        UP,
        DOWN,
        LEFT,
        RIGHT,

        NUM_STATES
    };

    std::bitset<static_cast<std::uint8_t>(MOVE_STATE::NUM_STATES)> m_moveStates;
};

//property_begin(Player)
//{
//    property_var(m_value)
//}
//property_end()