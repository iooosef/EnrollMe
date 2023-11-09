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

find_package(Crow CONFIG REQUIRED)

# Add source to this project's executable.
add_executable (EnrollMe "EnrollMe.cpp" "EnrollMe.h")

target_link_libraries(EnrollMe PRIVATE Crow::Crow)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EnrollMe PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
list(REMOVE_ITEM _CROW_ICD "_CROW_ICD-NOTFOUND")
set_target_properties(Crow::Crow PROPERTIES INTERFACE_COMPILE_DEFINITIONS "${_CROW_ICD}")