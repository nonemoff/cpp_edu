set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES main.cpp cpu.cpp ram.cpp disk.cpp gpu.cpp kbd.cpp)

add_executable(main ${SOURCES})

target_include_directories(main PUBLIC include)
