cmake_minimum_required(VERSION 3.8)

# �������� ����������
project(Reporter)

# ��������� ����������� ���� ����������
add_executable(Reporter reporter.cpp)


# ��������� ��������� C++
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Reporter PROPERTY CXX_STANDARD 20)
endif()