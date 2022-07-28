/******************************************************************************
filename:	Rotation.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding rotation around the z - axis.

******************************************************************************/
#pragma once

struct Rotation
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "Rotation"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value).clear();
        return{};
    }

    float m_value;
};

property_begin(Rotation)
{
    property_var(m_value)
}
property_end()
