/******************************************************************************
filename:	Game.h
author:		Jolyn Wong Kaiyi, wong.k@digipen.edu
Project:	CS396 Assignment 02

Description:

    Defines the data related to a Game instance.

******************************************************************************/
#pragma once

namespace Text
{
    template < typename... TArgs >
    void PrintText(const int _x, const int _y, const char* const _str, TArgs&&... _args)
    {

        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluOrtho2D(0, m_W, 0, m_H);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glRasterPos2i(x, m_H - (y + 20));
        for (int i = 0; i < Length; ++i)
        {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, String[i]);
        }
        glPopMatrix();

        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glMatrixMode(GL_MODELVIEW);
    }
}

