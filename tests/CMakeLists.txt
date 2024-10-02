cmake_minimum_required (VERSION 3.8)

project(Tests)

enable_testing()

add_executable(Test_main test_main.cpp)
add_executable(Test_creator test_creator.cpp)
add_executable(Test_reporter test_reporter.cpp)

target_link_libraries(Test_main PRIVATE OS_Lab1)
target_link_libraries(Test_creator PRIVATE Creator)
target_link_libraries(Test_reporter PRIVATE Reporter)

add_test(NAME TestMain COMMAND Test_main)
add_test(NAME TestCreator COMMAND Test_creator)
add_test(NAME TestReporter COMMAND Test_reporter)
