cmake_minimum_required(VERSION 3.26)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(RAYLIB_5_0_INCLUDE_DIR "C:/Libraries/raylib/raylib-5.0_win64_msvc16/include")
set(RAYLIB_5_0_LIB_DIR "C:/Libraries/raylib/raylib-5.0_win64_msvc16/lib")

project(My_Text_Editor)

add_executable(
    My_Text_Editor
    src/main.c
)

target_include_directories(
    My_Text_Editor
    PUBLIC ${RAYLIB_5_0_INCLUDE_DIR}
)

target_link_directories(
    My_Text_Editor
    PUBLIC ${RAYLIB_5_0_LIB_DIR}
)

target_link_libraries(
    My_Text_Editor
    PRIVATE raylib
)

if (MSVC)
    target_link_libraries(
        My_Text_Editor
        PRIVATE winmm
    )
endif()
