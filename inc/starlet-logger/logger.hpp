#pragma once

#include <string>

namespace Starlet::Logger {
  enum class Level {
    Debug,
    Info,
    Warning,
    Error
  };

  void log(Level level, const char* caller, const char* function, const std::string& msg);

  bool error(const char* caller, const char* function, const std::string& msg);
  bool debugLog(const char* caller, const char* function, const std::string& msg, bool returnValue = true);
}
