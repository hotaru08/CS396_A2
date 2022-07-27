/******************************************************************************
filename:	includes.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Header including other files.

******************************************************************************/
#pragma once

// STL libraries -------------------------------------------------------------
#include <xecs.h>
#include <limits>
#include <random>
#include <bitset>
#include <iostream>
#include <cstdint>

//#define FREEGLUT_STATIC
#include <GL\freeglut.h>

// Misc ----------------------------------------------------------------------
#include <Misc\Vector2D.h>
#include <Misc\Inputs.h>
#include <Misc\Window.h>

// Components ----------------------------------------------------------------
#include <Components\Timer.h>
#include <Components\Position.h>
#include <Components\Scale.h>
#include <Components\Rotation.h>
#include <Components\Velocity.h>

// Systems -------------------------------------------------------------------
#include <Systems\RenderingSystem.h>
#include <Systems\RenderTowerSystem.h>
