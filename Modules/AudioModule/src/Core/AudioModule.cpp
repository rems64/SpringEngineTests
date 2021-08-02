#include <Spring/AudioModule/Core/AudioModule.hpp>

#include <iostream>

namespace SE
{
	namespace Audio
	{
		AudioModule::AudioModule()
		{
		}

		AudioModule::~AudioModule()
		{
		}
	}
}

SE::Audio::AudioModule* gAudioModule = nullptr;

extern "C" SPRING_MODULE SE::SpringModule * createModule(void)
{
	//assert(gAudioModule == nullptr);
	gAudioModule = new SE::Audio::AudioModule();
	return gAudioModule;
}

extern "C" SPRING_MODULE void destroyModule(void)
{
	//assert(gAudioModule);
	delete gAudioModule;
	gAudioModule = nullptr;
}
