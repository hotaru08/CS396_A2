/******************************************************************************
filename:	Velocity.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding rotation around the z - axis.

******************************************************************************/
#pragma once

struct Velocity
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Velocity"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Direction" , m_value.m_X, m_value.m_Y).clear();
        return { };
    }

    xcore::vector2 m_value; //<! Velocity Move Speed
};

property_begin(Velocity)
{
    property_var(m_value)
}
property_end()