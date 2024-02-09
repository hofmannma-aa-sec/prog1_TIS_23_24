cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (commandblock
	VERSION 1.0
	DESCRIPTION "Eine Applikation die die Applikation Test erstellt")

# C++ Standart
set(CMAKE_CXX_STANDARD 20)

# Definition hinzufuegen
# add_definitions(-D....)

# Unterschiedliche Versionen für Debug und Release
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g3 -O0")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall -O3 -s -pipe")

# Astyle Option in make
add_custom_target (astyle
	COMMAND
	COMMAND astyle -r ${PROJECT_SOURCE_DIR}/*.h ${PROJECT_SOURCE_DIR}/*.cpp --exclude=build
	VERBATIM
)

# Exportdatei fuer die Einstellungen von CMake
configure_file(config.h.in ${PROJECT_SOURCE_DIR}/config.h)

# Includes
include_directories(${PROJECT_SOURCE_DIR})

# Hier wird die Zielapplikation erstellt
add_executable(${PROJECT_NAME} main.cpp)

