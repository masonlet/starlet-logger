cmake_minimum_required(VERSION 3.20)

set(LOG_NAME StarletLogger)
SET(LOG_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LOG_INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/inc")

if(NOT TARGET ${LOG_NAME})
  add_library(${LOG_NAME} STATIC)

  file(GLOB_RECURSE LOG_SRC CONFIGURE_DEPENDS ${LOG_SRC_DIR}/*.cpp)
  file(GLOB_RECURSE LOG_HEADERS CONFIGURE_DEPENDS ${LOG_INC_DIR}/*.hpp)

  source_group(TREE ${LOG_SRC_DIR} PREFIX "Source Files" FILES ${LOG_SRC})
  source_group(TREE ${LOG_INC_DIR} PREFIX "Header Files" FILES ${LOG_HEADERS})

  target_sources(${LOG_NAME} PRIVATE ${LOG_SRC} ${LOG_HEADERS})
  target_include_directories(${LOG_NAME} PUBLIC 
    $<BUILD_INTERFACE:${SER_INC_DIR}> 
    $<INSTALL_INTERFACE:include>
  )
endif()
