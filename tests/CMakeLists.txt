cmake_minimum_required(VERSION 3.8)

include(FetchContent)	#загрузка гугл тестов

FetchContent_Declare(
googletest
#GIT_REPOSITORY https://github.com/google/googletest.git
#GIT_TAG v1.15.2
URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)
add_library (GTest::GTest INTERFACE IMPORTED)

target_link_libraries(GTest::GTest INTERFACE gtest_main) #линковка проекта и гугл тестов

add_executable (Reporter_test reporter_test.cpp)	

target_include_directories(Reporter_test PUBLIC ../Reporter/include)

target_link_libraries(Reporter_test PUBLIC GTest::GTest ReporterLib)	#линковка проекта и тестов

add_test(ReporterTest Reporter_test)					#добавление теста в CTest