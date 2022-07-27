#include <includes.h>

static struct Game
{
    // Window instance
    Window m_windowInst;
    
    // ECS instance
    std::unique_ptr<xecs::game_mgr::instance> m_gameMgr;

	void Initialize() noexcept
	{
		xcore::Init("TowerDefense");

		m_gameMgr = std::make_unique< xecs::game_mgr::instance >();
		RenderingSystem::m_windowPtr = &m_windowInst;
	}

	void CleanUp() noexcept
	{
		xcore::Kill();
	}

} sg_game;

// ----------------------------------------------------------------------------
void RegisterElements()
{
	sg_game.m_gameMgr->RegisterComponents
	<
		  Position
		, Rotation
		, Scale
		, Timer
		, Velocity
	>();

	sg_game.m_gameMgr->RegisterSystems
	<
		  RenderingSystem
		, RenderTowerSystem

	>();

    //
        // Initialize global elements
        //
    std::srand(101);

	sg_game.m_gameMgr->getOrCreateArchetype< Position, Velocity, Timer>()
		.CreateEntities(1, [&](Position& position, Velocity& velocity, Timer& timer) noexcept
		{
				position.m_value = xcore::vector2
				{
					/*static_cast<float>(std::rand() % sg_game.m_windowInst.m_width),
				    static_cast<float>(std::rand() % sg_game.m_windowInst.m_height)*/
					100, 100
				};

				velocity.m_value.m_X = std::rand() / static_cast<float>(RAND_MAX) - 0.5f;
				velocity.m_value.m_Y = std::rand() / static_cast<float>(RAND_MAX) - 0.5f;
				velocity.m_value.Normalize();

				timer.m_value = std::rand() / static_cast<float>(RAND_MAX) * 8;
		}
	);
	
}

void RefreshUpdate(int value)
{
    // Post re-paint request to activate display()
    glutPostRedisplay();

    // next timer call milliseconds later
    glutTimerFunc(15, RefreshUpdate, 0);
}

int main(int argc, char** argv)
{
    // Enable run-time memory check for debug builds.
#if defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	sg_game.Initialize();
	RegisterElements();

	// Setup Window Instance, Graphics and GameLoop
	{
		glutInitWindowSize(sg_game.m_windowInst.m_width, sg_game.m_windowInst.m_height);
		glutInitWindowPosition(sg_game.m_windowInst.m_posX, sg_game.m_windowInst.m_posY);

		glutInit(&argc, argv);
		glutCreateWindow(xcore::get().m_pAppName);

		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
		glutReshapeFunc
		(
			[](int w, int h) noexcept
			{
				sg_game.m_windowInst.m_width = w;
				sg_game.m_windowInst.m_height = h;
			}
		);
		glutDisplayFunc
		(
			[]()
			{
				sg_game.m_gameMgr->Run();
				sg_game.m_windowInst.m_inputs.m_keys.FrameUpdate();
			}
		);

		glutTimerFunc(0, RefreshUpdate, 0);

        glutKeyboardFunc([](unsigned char Key, int MouseX, int MouseY) noexcept
        {
			sg_game.m_windowInst.m_inputs.m_keys.setKeyState(Key, true);
			sg_game.m_windowInst.m_inputs.m_mouseX = MouseX;
			sg_game.m_windowInst.m_inputs.m_mouseY = MouseY;
        });
        glutKeyboardUpFunc([](unsigned char Key, int MouseX, int MouseY) noexcept
        {
			sg_game.m_windowInst.m_inputs.m_keys.setKeyState(Key, false);
            sg_game.m_windowInst.m_inputs.m_mouseX = MouseX;
            sg_game.m_windowInst.m_inputs.m_mouseY = MouseY;
        });
        glutMouseFunc([](int Button, int State, int MouseX, int MouseY) noexcept
        {
            sg_game.m_windowInst.m_inputs.m_mouseX = MouseX;
            sg_game.m_windowInst.m_inputs.m_mouseY = MouseY;

            if (Button == GLUT_LEFT_BUTTON )
				sg_game.m_windowInst.m_inputs.m_mouseLeftBtn  = (State == GLUT_DOWN);
            else if (Button == GLUT_RIGHT_BUTTON)
                sg_game.m_windowInst.m_inputs.m_mouseRightBtn = (State == GLUT_DOWN);
        });

		glutMainLoop();
	}

	sg_game.CleanUp();
}