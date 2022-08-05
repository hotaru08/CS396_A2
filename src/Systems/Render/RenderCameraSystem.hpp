/******************************************************************************
filename:	RenderCameraSystem.hpp
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Base Rendering System that handles the buffer rendering.

******************************************************************************/
#pragma once

void RenderCameraSystem::OnUpdate() noexcept
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Setup viewport for rendering camera
    glViewport(0, 0, sg_game.m_windowInst.m_width, sg_game.m_windowInst.m_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, sg_game.m_windowInst.m_width, 0, sg_game.m_windowInst.m_height, -1, 1);
    glScalef(1, -1, 1);
    glTranslatef(0, -sg_game.m_windowInst.m_height, 0);

    SendEventFrom<update>(this);

    glutSwapBuffers();
}
