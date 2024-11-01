cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)

# Collect all .cpp files in ./test/list
file(GLOB test_list_sources "./test/list/*.cpp")

# Add executable with all source files in ./test/list
add_executable(test_list ${test_list_sources})

# target_include_directories(list PRIVATE ./include)

target_link_libraries(
  test_list
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_list)

