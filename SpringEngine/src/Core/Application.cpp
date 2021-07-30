#include <SpringEngine/Core/Application.hpp>

namespace SE
{
	Application* Application::m_instance;
	Application::Application()
	{
		if (m_instance)
		{
			throw std::runtime_error("Only one application instance is allowed");
		}
	}

	Application::~Application()
	{

	}
}