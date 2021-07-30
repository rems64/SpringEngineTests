#pragma once

#include <SpringEngine/Core/Application.hpp>

extern std::shared_ptr<SE::Application> SE::buildApp();

int main(int argc, char** argv)
{
	std::shared_ptr<SE::Application> application = SE::buildApp();
	return 0;
}