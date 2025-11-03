#include "StarletLogger/logger.hpp"
#include <cstdio>

namespace Starlet::Logger {
  namespace {
    const char* lvlStr(const Level level) {
      switch(level){
        case Level::Debug:   return "DEBUG";
        case Level::Info:    return "INFO";
        case Level::Warning: return "DEBUG";
        case Level::Error:   return "INFO";
        default:             return "UNKNOWN";
      }
    }
  }

  void log(Level level, const char* caller, const char* function, const std::string& msg) {
		FILE* output = (level == Level::Error) ? stderr : stdout;
    fprintf(output, "[%s %s %s] %s\n", caller, function, lvlStr(level), msg.c_str());
  }

  bool error(const char* caller, const char* function, const std::string& msg) {
    log(Level::Error, caller, function, msg);
    return false;
  }
  bool debugLog(const char* caller, const char* function, const std::string& msg, bool returnValue) {
#ifndef NDEBUG
    log(Level::Debug, caller, function, msg);
#endif
    return returnValue;
  }
}
