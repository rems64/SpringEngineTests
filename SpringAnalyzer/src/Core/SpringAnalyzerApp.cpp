#include <SpringAnalyzer/Core/SpringAnalyzerApp.hpp>

#include <Spring/SpringMain/Core/EntryPoint.hpp>

namespace SA
{
	SpringAnalyzerApp::SpringAnalyzerApp()
	{
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