#include <LTEngine/Game/Game.h>
#include <LTEngine/Window/Window.h>
ltengine::Game::Game()
{

	m_dispaly = new Window();
}

ltengine::Game::~Game()
{
	delete m_dispaly;
}


