#pragma once

#include <SpringEngine/Core/Core.hpp>

namespace SE
{
	/// <summary>
	/// Main application class, responsible of managing the program during its lifetime
	/// </summary>
	class Application
	{
	public:
		Application();
		~Application();

	private:
		static Application* m_instance;
	};

	/// <summary>
	/// Main function responsible of the app creation. Should be implemented by the client.
	/// </summary>
	/// <returns>Shared pointer to the app</returns>
	Shared<Application> buildApp();
}