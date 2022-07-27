/******************************************************************************
filename:	Velocity.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding position.

******************************************************************************/
#pragma once

struct Velocity
{
    xcore::vector2 m_value;

    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Velocity"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value.m_X, m_value.m_Y).clear();
        return { };
    }
};

// Serialization - Property
property_begin(Velocity)
{
    property_var(m_value)
}
property_end()