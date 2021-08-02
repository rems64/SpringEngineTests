#include <Spring/SpringModule/SpringModule.hpp>

namespace SE
{
	SpringModule::SpringModule()
	{
		SE::Logger::init({ true, true });
	}

	SpringModule::~SpringModule()
	{

	}

	bool SpringModule::setupLink(SpringModuleLinkInfos infos)
	{
		SE_CORE_CRITICAL("WTF");
		return true;
	}
}