/******************************************************************************
filename:	TurretShootingSystem.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    System that handles turrent shooting logic.

******************************************************************************/
#pragma once

struct TurretShootingSystem : xecs::system::instance
{
    constexpr static auto typedef_v = xecs::system::type::update
    {
        .m_pName = "TurretShootingSystem"
    };

    TurretShootingSystem(xecs::game_mgr::instance& _inst)
        : xecs::system::instance{ _inst }
    { };

    void operator()(
        xecs::component::entity& _entity, FireBullet& _fireBullet,
        Target* _target, Timer& _timer, Position& _turrentPos, Rotation& _turretRot);

private:
    static constexpr float m_shootInterval = 0.5f;
    static constexpr float m_bulletSpeed   = 5.0f;
};
