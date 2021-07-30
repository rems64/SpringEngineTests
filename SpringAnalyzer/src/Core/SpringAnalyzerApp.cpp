#include <SpringAnalyzer/Core/SpringAnalyzerApp.hpp>

#include <SpringEngine/Core/EntryPoint.hpp>

namespace SA
{
	SpringAnalyzerApp::SpringAnalyzerApp()
	{
		std::cout << "[INFO] ALIVE" << std::endl;
	}

	SpringAnalyzerApp::~SpringAnalyzerApp()
	{

	}
}

namespace SE
{
	Shared<SE::Application> buildApp()
	{
		return makeShared<SA::SpringAnalyzerApp>();
	}
}