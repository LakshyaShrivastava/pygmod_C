# Define the core library
add_library(pygmod_lib
    Factor.cpp
    Variable.cpp
    np_utils.cpp
)

# Expose the 'src/' directory to anyone linking against this library
target_include_directories(pygmod_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})