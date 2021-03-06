cmake_minimum_required(VERSION 3.10)

project(SeAN)

# DEBUG flags include '-fprofile-arcs -ftest-coverage' options of g++, which are
# used to provide code coverage information to the tool 'gcov'.
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fprofile-arcs -ftest-coverage -fPIC -Wall -Wextra -Wshadow")
set(CMAKE_CXX_FLAGS "-O3 -march=native")

include_directories(include)
add_subdirectory(src)

add_executable(sean src/main.cc)

if(CMAKE_BUILD_TYPE MATCHES DEBUG)

    find_package(ROOT REQUIRED)

    enable_testing()

    add_executable(test_excited_state test/test_excited_state)
    
    add_executable(test_grid test/test_grid)
    target_link_libraries(test_grid lib_Grid)
    
    add_executable(test_integrator test/test_integrator)
    target_link_libraries(test_integrator lib_Integrator)

    add_executable(test_integrator_2d test/test_integrator_2d)
    target_link_libraries(test_integrator_2d lib_Integrator)
    target_link_libraries(test_integrator_2d ${ROOT_LIBRARIES})

    add_executable(test_nucleus test/test_nucleus)
    target_link_libraries(test_nucleus lib_ExcitedState)
    target_link_libraries(test_nucleus lib_Grid)
    target_link_libraries(test_nucleus lib_Nucleus)
    target_link_libraries(test_nucleus lib_Integrator)
    
    add_executable(test_target test/test_target)
    target_link_libraries(test_target lib_ExcitedState)
    target_link_libraries(test_target lib_Integrator)
    target_link_libraries(test_target lib_Nucleus)
    target_link_libraries(test_target lib_Target)

    add_executable(test_voigt_profile test/test_voigt_profile)
    target_link_libraries(test_voigt_profile lib_VoigtProfile)

    add_test(NAME Execution COMMAND sean)
    add_test(NAME ExcitedState COMMAND test_excited_state)
    add_test(NAME Grid COMMAND test_grid)
    add_test(NAME Integrator COMMAND test_integrator)
    add_test(NAME Integrator2D COMMAND test_integrator_2d)
    add_test(NAME Nucleus COMMAND test_nucleus)
    add_test(NAME Target COMMAND test_target)
    add_test(NAME VoigtProfile COMMAND test_voigt_profile)

    message(STATUS "Debug build activated.")
    message(STATUS "To run tests, execute\n\tmake test\nor\n\tctest")
    message(STATUS "To view code coverage after testing, execute, e.g.,\ngcovr -r ${CMAKE_SOURCE_DIR} --exclude ${CMAKE_SOURCE_DIR}/include/TestUtilities.h\n   if 'gcovr' is installed.")
endif()
