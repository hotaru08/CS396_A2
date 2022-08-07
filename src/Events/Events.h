/******************************************************************************
filename:	Events.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Header including other event files.

******************************************************************************/
#pragma once

#include <Events\OnKeyUp.h>
#include <Events\OnKeyHold.h>
#include <Events\OnKeyDown.h>

#include <Events\OnMouseButtonDown.h>
#include <Events\OnMouseMoved.h>

#define ALL_EVENTS \
    OnKeyUp, OnKeyHold, OnKeyDown, OnMouseButtonDown, OnMouseMoved