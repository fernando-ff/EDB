cmake_minimum_required(VERSION 3.5)
project(SortingAlgorithms VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# set the include path
include_directories( include )


### [2] Test target
# set the include path
include_directories( lib )

# Add the test target
add_executable( run_tests
                src/sorting.cpp
                lib/test_manager.cpp
                test/run_tests.cpp )

# define C++11 standard
set_property(TARGET run_tests PROPERTY CXX_STANDARD 11)

### [3] The timing example app
# define the sources for the project
add_executable( timing_template
                src/sorting.cpp
                src/timing_template.cpp ) # This is the runtime measuring code. 

# define C++11 standard
set_property(TARGET timing_template PROPERTY CXX_STANDARD 11)


# The end
