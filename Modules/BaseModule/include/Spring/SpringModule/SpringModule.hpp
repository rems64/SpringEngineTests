#pragma once

#ifdef SPRING_EXPORT_MODULE
#define SPRING_MODULE __declspec(dllexport)
#else
#define SPRING_MODULE __declspec(dllimport)
#endif

// To move in precompiled header
#include <vector>
#include <Spring/SpringCore.hpp>

namespace SE
{
	struct SPRING_MODULE SpringModuleLinkInfos
	{
	};
	class SPRING_MODULE SpringModule
	{
	public:
		SpringModule();
		~SpringModule();

		bool setupLink(SpringModuleLinkInfos infos);
	private:
	};
}
