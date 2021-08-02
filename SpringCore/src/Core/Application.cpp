#include <Spring/SpringCore/Core/Application.hpp>

#include <Spring/SpringCore/Debug/Logger.hpp>

namespace SE
{
	Application* Application::m_instance;
	Application::Application()
	{
		if (m_instance)
		{
			throw std::runtime_error("Only one application instance is allowed");
		}

		m_instance = this;

		Logger::init({ true, true });

		SE_CORE_WARN("Application constructor");
		
		//m_modulesManager = makeUnique<ModulesManager>();
		//m_modulesManager->load(L"AudioModule");
	}

	Application::~Application()
	{

	}

	void Application::log()
	{
		std::cout << "Pre-log..." << std::endl;
		SE_CORE_TRACE("LOG");
	}
}