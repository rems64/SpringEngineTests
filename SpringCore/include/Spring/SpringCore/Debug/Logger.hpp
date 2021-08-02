#pragma once

#include <Spring/SpringCore/Core/Core.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/dup_filter_sink.h>
#include <spdlog/tweakme.h>

namespace SE
{
	struct SE_API LoggerInfos
	{
		bool async = true;
		bool preventDuplicates = true;
	};

	enum SE_API LOG_LVL
	{
		SE_LOGLVL_TRACE = SPDLOG_LEVEL_TRACE,
		SE_LOGLVL_INFO = SPDLOG_LEVEL_INFO,
		SE_LOGLVL_WARN = SPDLOG_LEVEL_WARN,
		SE_LOGLVL_ERROR = SPDLOG_LEVEL_ERROR,
		SE_LOGLVL_CRITICAL = SPDLOG_LEVEL_CRITICAL
	};


	class SE_API Logger
	{
	public:
		static void init(LoggerInfos infos);
		static void destroy();

		inline static Shared<spdlog::logger> getCoreLogger() { return m_coreLogger; };

		static void setCoreLogLevel(SE::LOG_LVL logLevel);

	private:
		static Shared<spdlog::logger> m_coreLogger;
	};
}

#if !defined(NDEBUG)
#define SE_CORE_TRACE(...) SE::Logger::getCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...) SE::Logger::getCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...) SE::Logger::getCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...) SE::Logger::getCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_CRITICAL(...) SE::Logger::getCoreLogger()->critical(__VA_ARGS__)
#define SE_CORE_SET_LEVEL(level) SE::Logger::setCoreLogLevel(level)
#else
#define SE_CORE_TRACE(...)
#define SE_CORE_INFO(...)
#define SE_CORE_WARN(...)
#define SE_CORE_ERROR(...)
#define SE_CORE_CRITICAL(...)
#define SE_CORE_SET_LEVEL(level)
#endif