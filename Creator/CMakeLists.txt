cmake_minimum_required(VERSION 3.8)

# Название подпроекта
project(Creator)

# Добавляем исполняемый файл подпроекта
add_executable(Creator creator.cpp)



# Установка стандарта C++
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Creator PROPERTY CXX_STANDARD 20)
endif()