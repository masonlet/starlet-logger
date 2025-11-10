# Starlet Logger

A lightweight logging utility for C++ applications.

## Using as a Dependency

```cmake
include(FetchContent)

FetchContent_Declare(starlet_logger
  GIT_REPOSITORY https://github.com/masonlet/starlet-logger.git 
  GIT_TAG main
)
FetchContent_MakeAvailable(starlet_logger)

target_link_libraries(app_name PRIVATE starlet_logger)
```
