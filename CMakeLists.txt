cmake_minimum_required(VERSION 3.26)
project(Data_Structures)

set(CMAKE_CXX_STANDARD 14)
set(Foo "")      # 1 quoted arg -> value is ""

# Add the executable target
add_executable(Data_Structures
        Homeworks/Week11/frequency.cpp
)

# Pass arguments to the executable target
target_compile_definitions(Data_Structures PRIVATE FOO=${Foo})
