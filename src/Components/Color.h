/******************************************************************************
filename:	Color.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding color.

******************************************************************************/
#pragma once

struct Color
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Color"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value.m_X, m_value.m_Y, m_value.m_Z).clear();
        return{};
    }

    xcore::vector3 m_value;
};

//property_begin(Color)
//{
//    property_var(m_value)
//}
//property_end()
