# - Set (make requirements then declare project
cmake_minimum_required(VERSION 3.18)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
# Do this to begin with so it's easy to see wat compiler command/flags
# are used. This can also be done by removing the 'set'command and running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Set the C++ Standard directly
set(CMAKE_CXX_STANDARD 14)

# - Declare the build of the mpags-cipher main program
add_executable(mpags-cipher
    mpags-cipher.cpp
    MPAGSCipher/TransformChar.cpp
    MPAGSCipher/processCommandLine.cpp
    )

target_include_directories(mpags-cipher
    PRIVATE MPAGSCipher
    )

#- Don't allow C++ compiler vendor extensions
set(CMAKE_CXX_EXTENSIONS OFF)
# - Use our standard set of flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher 
    PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
)