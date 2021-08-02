#include <Spring/SpringMain/Core/ModulesManager.hpp>

typedef SE::SpringModule* (*fnCreateModule)(void);
typedef void (*fnDestroyModule)(void);

namespace SE
{
	ModulesManager::ModulesManager() : m_modules()
	{
	}

	ModulesManager::~ModulesManager()
	{
	}

	SpringModule* ModulesManager::load(const std::wstring name)
	{
		SpringModule* module = nullptr;
		std::map<std::wstring, SpringModule*>::iterator it = m_modules.find(name);
		if (it == m_modules.end())
		{
			HMODULE library = LoadLibraryW(name.c_str());
			if (library)
			{
				fnCreateModule createModuleFunction = (fnCreateModule)GetProcAddress(library, "createModule");
				if (createModuleFunction)
				{
					module = createModuleFunction();
					if (module)
					{
						m_modules.insert(std::map<std::wstring, SpringModule*>::value_type(name, module));
						m_libraries.insert(std::map<std::wstring, HMODULE>::value_type(name, library));
						module->setupLink({ });
					}
					else
					{
						SE_CORE_ERROR(L"Could not load module from {}, an error occured", name);
						FreeLibrary(library);
					}
				}
				else
				{
					SE_CORE_ERROR(L"Could not find symbol \"createModule\" in library {}, an error occured", name);
					FreeLibrary(library);
				}
			}
			else
			{
				SE_CORE_ERROR(L"Could not load library {}, an error occured", name);
			}
		}
		else
		{
			SE_CORE_WARN(L"Library {} is already loaded", name);
		}

		return module;
	}

	void ModulesManager::unload(const std::wstring name)
	{

	}
} // Namespace SE