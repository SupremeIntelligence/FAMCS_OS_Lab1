cmake_minimum_required(VERSION 3.8)

# �������� ����������
project(Creator)

# ��������� ����������� ���� ����������
add_executable(Creator creator.cpp)

# ��������� ��������� C++
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Creator PROPERTY CXX_STANDARD 20)
endif()