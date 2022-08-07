/******************************************************************************
filename:	MeleeAttack.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding MeleeAttack

******************************************************************************/
#pragma once

struct MeleeAttack
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "MeleeAttack"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value).clear();
        return { };
    }

    bool m_value;
};

struct RenderMelee
{
    constexpr static auto typedef_v = xecs::component::type::tag
    {
        .m_pName = "RenderMelee"
    };
};
