cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(MIKROE_PROJECT LANGUAGES CXX)
elseif(UNIX)
    project(MIKROE_PROJECT)
endif()

set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)

set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(HEADER_DIR "${CMAKE_SOURCE_DIR}/headers")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${HEADER_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${HEADER_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

if (WIN32)
    add_executable(MIKROE_PROJECT WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(MIKROE_PROJECT ${SOURCES})
endif()

target_include_directories(MIKROE_PROJECT PRIVATE ${FORMS_DIR})
target_include_directories(MIKROE_PROJECT PRIVATE ${HEADER_DIR})
target_include_directories(MIKROE_PROJECT PRIVATE ${SOURCE_DIR})
target_link_libraries(MIKROE_PROJECT PUBLIC Qt6::Widgets)