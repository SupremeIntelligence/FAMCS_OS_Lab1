﻿# CMakeList.txt: проект CMake для OS_Lab1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (OS_Lab1)

# Добавьте источник в исполняемый файл этого проекта.
add_subdirectory(Creator)
add_subdirectory(Reporter)
add_subdirectory(tests)

add_executable (OS_Lab1 main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(Creator PUBLIC include)
target_include_directories(Reporter PUBLIC include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OS_Lab1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
