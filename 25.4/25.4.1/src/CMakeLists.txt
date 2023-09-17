set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES func.cpp main.cpp)

add_executable(main ${SOURCES})

target_include_directories(main PUBLIC include)
