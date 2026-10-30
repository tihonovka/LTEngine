#pragma once
#include <LTEngine/Core/Base.h>
#include <LTEngine/Core/Core.h>
#include <LTEngine/Window/Window.h>

namespace ltengine
{
	class Game : public Base
	{
	public:
		Game();
		virtual ~Game();

		virtual void run() final;

	private:
		Window* m_dispaly{};
		bool m_isRunning{true};

	};
}