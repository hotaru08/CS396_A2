/******************************************************************************
filename:	Bullet.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding bullet.

******************************************************************************/
#pragma once

struct Bullet
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Bullet"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Owner", m_owner).clear();
        return{};
    }

    xecs::component::entity m_owner;
};

property_begin(Bullet)
{
    property_var(m_owner)
}
property_end()