cmake_minimum_required(VERSION 3.8)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable (ReporterTest reporter_test.cpp)	

target_include_directories(ReporterTest PUBLIC ${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/Reporter ${CMAKE_SOURCE_DIR})

target_link_libraries(ReporterTest PRIVATE gtest gtest_main) #�������� ������� � ���� ������

add_test(ReporterTest ReporterTest)					#���������� ����� � CTest


