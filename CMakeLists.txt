cmake_minimum_required( VERSION 3.10)
project(shell_with_C)

set(CMAKE_C_STANDARD 99)

# put the executable in out/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

include_directories(${CMAKE_SOURCE_DIR}/builtins)

set(
  SOURCES
  src/shell.c
  builtins/cd.c
  builtins/builtins.c)

# executables
add_executable(shell ${SOURCES})
