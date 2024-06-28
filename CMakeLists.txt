cmake_minimum_required(VERSION 3.10)

project(SupperMoment VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(COMPILE_COMMANDS_OUTPUT_DIR ${CMAKE_BINARY_DIR}/..)

include_directories(include modules/include 3rd/include)

file(GLOB_RECURSE SRC_FILES src/*.cpp modules/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

add_custom_target(copy_compile_commands ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
    ${CMAKE_BINARY_DIR}/compile_commands.json 
    ${COMPILE_COMMANDS_OUTPUT_DIR}/compile_commands.json
    DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
    COMMENT "Copying compile_commands.json to ${COMPILE_COMMANDS_OUTPUT_DIR}"
)
#target_link_libraries(${PROJECT_NAME} PRIVATE mylib)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)


set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
