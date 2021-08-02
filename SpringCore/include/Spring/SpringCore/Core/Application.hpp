#pragma once

#include <Spring/SpringCore/Core/Core.hpp>
#include <Spring/SpringCore/Debug/Logger.hpp>

namespace SE
{
	class ModulesManager;

	/// <summary>
	/// Main application class, responsible of managing the program during its lifetime
	/// </summary>
	class Application
	{
	public:
		Application();
		~Application();

		static Application* get() { return m_instance; };
		void log();

	private:
		static Application* m_instance;
		//Unique<ModulesManager> m_modulesManager;
	};

	/// <summary>
	/// Main function responsible of the app creation. Should be implemented by the client.
	/// </summary>
	/// <returns>Shared pointer to the app</returns>
	Shared<Application> buildApp();
}