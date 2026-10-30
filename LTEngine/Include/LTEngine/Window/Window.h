#pragma once
#include <LTEngine/Core/Base.h>

namespace ltengine {

	class Window: public Base
	{
	public:
		Window();
		virtual ~Window() override;
	
	private:
		void* m_handle{};
	};

}