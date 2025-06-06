cmake_minimum_required(VERSION 3.29) # FetchContent is available in 3.11+
project(VoiceActivatedChess)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
include(FetchContent)
FetchContent_Declare(
raylib
DOWNLOAD_EXTRACT_TIMESTAMP OFF
URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)
FetchContent_GetProperties(raylib)
if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
set(FETCHCONTENT_QUIET NO)
FetchContent_Populate(raylib)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(ENV{SUPPORT_FILEFORMAT_SVG} 1)
add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
endif()
endif()

#Web Configurations
if (${PLATFORM} STREQUAL "Web")
# Tell Emscripten to build an example.html file.
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

#Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
target_link_libraries(${PROJECT_NAME} "-framework IOKit")
target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

#Our Project
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/textures
        ${CMAKE_CURRENT_BINARY_DIR}/textures
        COMMENT "Copying directory textures"
)