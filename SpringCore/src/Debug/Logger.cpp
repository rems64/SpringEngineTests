#include <Spring/SpringCore/Debug/Logger.hpp>

namespace SE
{
	Shared<spdlog::logger> Logger::m_coreLogger;
	void Logger::init(LoggerInfos infos)
	{
		spdlog::set_level(spdlog::level::trace);
		if (infos.async)
		{
			if (infos.preventDuplicates)
			{
				auto coreConsoleSink = makeShared<spdlog::sinks::dup_filter_sink_mt>(std::chrono::seconds(3));
				coreConsoleSink->add_sink(makeShared<spdlog::sinks::stdout_color_sink_mt>());
				coreConsoleSink->set_pattern("[%=n] [%=T] %^%v%$");
				m_coreLogger = makeShared<spdlog::logger>("CORE", coreConsoleSink);
			}
			else
			{
				auto coreConsoleSink = makeShared<spdlog::sinks::stdout_color_sink_mt>();
				coreConsoleSink->set_pattern("[%=n] [%=T] %^%v%$");
				m_coreLogger = makeShared<spdlog::logger>("CORE", coreConsoleSink);
			}
		}
		else
		{
			if (infos.preventDuplicates)
			{
				auto coreConsoleSink = makeShared<spdlog::sinks::dup_filter_sink_st>(std::chrono::seconds(3));
				coreConsoleSink->add_sink(makeShared<spdlog::sinks::stdout_color_sink_st>());
				coreConsoleSink->set_pattern("[%=n] [%=T] %^%v%$");
				m_coreLogger = makeShared<spdlog::logger>("CORE", coreConsoleSink);
			}
			else
			{
				auto coreConsoleSink = makeShared<spdlog::sinks::stdout_color_sink_st>();
				coreConsoleSink->set_pattern("[%=n] [%=T] %^%v%$");
				m_coreLogger = makeShared<spdlog::logger>("CORE", coreConsoleSink);
			}
		}

		m_coreLogger->set_level(spdlog::level::trace);
		spdlog::register_logger(m_coreLogger);
		auto logger = spdlog::get("CORE");
	}

	void Logger::setCoreLogLevel(SE::LOG_LVL logLevel)
	{
		m_coreLogger->set_level((spdlog::level::level_enum)logLevel);
	}
}