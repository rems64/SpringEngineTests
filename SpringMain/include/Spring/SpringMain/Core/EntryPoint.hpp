#pragma once

#include <Spring/SpringCore/Core/Application.hpp>
#include <Spring/SpringMain/Core/ModulesManager.hpp>
#include <Spring/SpringCore/Core/Core.hpp>

extern std::shared_ptr<SE::Application> SE::buildApp();

int main(int argc, char** argv)
{
	std::shared_ptr<SE::Application> application = SE::buildApp();
	SE::Unique<SE::ModulesManager> modulesManager = SE::makeUnique<SE::ModulesManager>();
	modulesManager->load(L"AudioModule");
	system("PAUSE");
	return 0;
}