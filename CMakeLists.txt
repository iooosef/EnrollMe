# CMakeList.txt : CMake project for EnrollMe, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
CACHE STRING "Vcpkg toolchain file")

project ("EnrollMe")

include(FetchContent)

find_package(asio CONFIG REQUIRED)
find_package(unofficial-sqlite3 CONFIG REQUIRED)

#
# Crow project configuration variables
#
set(CROW_BUILD_EXAMPLES Off)
set(CROW_BUILD_TOOLS Off)
set(CROW_BUILD_TESTS Off)
set(CROW_BUILD_DOCS Off)

# add crow project to the build
FetchContent_Declare(crow
  		 GIT_REPOSITORY https://github.com/CrowCpp/Crow.git
		 GIT_TAG master
		 )

if(NOT crow_POPULATED)
  FetchContent_Populate(crow)
  add_subdirectory(${crow_SOURCE_DIR} ${crow_BINARY_DIR})
endif(NOT crow_POPULATED)

# Add source to this project's executable.
add_executable (EnrollMe "src/EnrollMe.h" "src/EnrollMe.cpp")

target_link_libraries(EnrollMe PRIVATE asio::asio)
target_link_libraries(EnrollMe PUBLIC Crow::Crow)
target_link_libraries(EnrollMe PRIVATE unofficial::sqlite3::sqlite3)

target_sources(EnrollMe PRIVATE "src/EnrollMe.cpp" "src/EnrollMe.h")
target_sources(EnrollMe PRIVATE "src/data/Database.cpp" "src/data/Database.h")
target_sources(EnrollMe PRIVATE "src/controllers/Home.cpp" "src/controllers/Home.h")
target_sources(EnrollMe PRIVATE "src/controllers/Enroll.cpp" "src/controllers/Enroll.h")
target_sources(EnrollMe PRIVATE "src/controllers/Logging.cpp" "src/controllers/Logging.h")

target_include_directories(EnrollMe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_custom_target(Templates
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/templates
	COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/templates
    ${CMAKE_BINARY_DIR}/templates
    )
add_custom_target(Static
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/static
	COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/src/static
    ${CMAKE_BINARY_DIR}/static
    )
add_custom_target(Data
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/data
	COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/src/data
            ${CMAKE_BINARY_DIR}/data
    COMMAND ${CMAKE_COMMAND} -E remove
            ${CMAKE_BINARY_DIR}/data/Database.cpp
            ${CMAKE_BINARY_DIR}/data/Database.h
    )

add_dependencies(EnrollMe Templates)
add_dependencies(EnrollMe Static)
add_dependencies(EnrollMe Data)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EnrollMe PROPERTY CXX_STANDARD 20)
endif()

#list(REMOVE_ITEM _CROW_ICD "_CROW_ICD-NOTFOUND")
#set_target_properties(Crow::Crow PROPERTIES INTERFACE_COMPILE_DEFINITIONS "${_CROW_ICD}")