include(FetchContent)

# Download GoogleTest
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

# ----------------------------
# factor_tests executable
# ----------------------------
add_executable(factor_tests
    test_factor.cpp
)

target_link_libraries(factor_tests
    pygmod_lib
    gtest_main
)

gtest_discover_tests(factor_tests)

# ----------------------------
# variable_tests executable
# ----------------------------
add_executable(variable_tests
    test_variable.cpp
)

target_link_libraries(variable_tests
    pygmod_lib
    gtest_main
)

gtest_discover_tests(variable_tests)