#pragma once

#include <Spring/SpringModule/SpringModule.hpp>
#include <Spring/SpringCore.hpp>

namespace SE
{
	namespace Audio
	{
		class SPRING_MODULE AudioModule : public SpringModule
		{
		public:
			AudioModule();
			~AudioModule();
		};
	}
}

extern "C" SPRING_MODULE SE::SpringModule * createModule(void);
extern "C" SPRING_MODULE void destroyModule(void);