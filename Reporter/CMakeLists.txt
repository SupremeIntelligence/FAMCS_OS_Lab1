cmake_minimum_required(VERSION 3.8)

# Название подпроекта
project(Reporter)

# Добавляем исполняемый файл подпроекта
add_executable(Reporter reporter.cpp)

#target_include_directories(Reporter PUBLIC include/ReporterLib)

target_link_libraries (Reporter PUBLIC ReporterLib)

target_include_directories(Reporter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
# Установка стандарта C++
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Reporter PROPERTY CXX_STANDARD 20)
endif()