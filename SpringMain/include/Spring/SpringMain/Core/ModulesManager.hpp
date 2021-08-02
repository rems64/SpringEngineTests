#pragma once

#include <Spring/SpringCore/Debug/Logger.hpp>
#include <Spring/SpringModule/SpringModule.hpp>

namespace SE
{
	/// <summary>
	/// Class instanced in application, in charge of dynamically loading the modules
	/// </summary>
	class ModulesManager
	{
	public:
		ModulesManager();
		~ModulesManager();

		SpringModule* load(const std::wstring name);
		void unload(const std::wstring name);

	private:
		std::map<std::wstring, HMODULE> m_libraries;
		std::map<std::wstring, SpringModule*> m_modules;
	};
}