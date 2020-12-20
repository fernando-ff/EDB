cmake_minimum_required(VERSION 3.5)
project (MyArray VERSION 1.0.0 LANGUAGES CXX )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#
# Compiling flags
set( GCC_COMPILE_FLAGS "-Wall" )

# Include dir
include_directories( "src" "lib" )

#=== Test target ===

add_executable(run_tests "test/run_tests.cpp"
                         "lib/test_manager.cpp")

target_compile_features( run_tests PUBLIC cxx_std_11 )

#=== Driver array target ===

add_executable( da "src/driver_vector.cpp" )

target_compile_features( da PUBLIC cxx_std_11 )
