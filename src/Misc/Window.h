/******************************************************************************
filename:	Window.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines a window instance

******************************************************************************/
#pragma once

// Defines a window instance to be displayed
struct Window
{
    // Window data members
    std::int32_t   m_width  = 1024;
    std::int32_t   m_height = 800;
    std::int32_t   m_posX   = 0;
    std::int32_t   m_posY   = 0;

    Input m_inputs;
    
    void RenderText(int _x, int _y, const char* const _str, unsigned _length)
    {
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, m_width, 0, m_height);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2i(_x, m_height - (_y + 20));

        for (unsigned i = 0; i < _length; ++i)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, _str[i]);
        }
        glPopMatrix();

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
};
