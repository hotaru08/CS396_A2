/******************************************************************************
filename:	Scale.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding scale.

******************************************************************************/
#pragma once

struct Scale
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Scale"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value.m_X, m_value.m_Y).clear();
        return{};
    }

    xcore::vector2 m_value;
};

property_begin(Scale)
{
    property_var(m_value)
}
property_end()