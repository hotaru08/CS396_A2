/******************************************************************************
filename:	FireBullet.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Data regarding the firing of a bullet

******************************************************************************/
#pragma once

struct FireBullet
{
    constexpr static auto typedef_v = xecs::component::type::data
    {
        .m_pName = "FireBullet"
    };

    xcore::err Serialize(xecs::serializer::stream& TextFile, bool) noexcept
    {
        TextFile.Field("Value", m_value).clear();
        return { };
    }

    bool m_value;
};

property_begin(FireBullet)
{
    property_var(m_value)
}
property_end()