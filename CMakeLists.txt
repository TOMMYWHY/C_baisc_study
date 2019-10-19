cmake_minimum_required(VERSION 3.14)
project(c002 C)

set(CMAKE_C_STANDARD 99)

add_executable(c002 main.c multFiles/includes/a.h)
add_executable(MainFuncArgs MainFuncArgs.c)
add_executable(functions functions.c)
add_executable(Define Define.c)
add_executable(multFiles multFiles/main.c multFiles/includes/hello.h multFiles/includes/a.h)

add_executable(pointer pointer/main.c)
add_executable(pointer_array pointer/pointer_array.c)
add_executable(pointer_test pointer/pointer_test.c)
add_executable(funcPointer funcPointer/main.c)
add_executable(array_pointer array_pointer/main.c)
add_executable(string string/main.c)

