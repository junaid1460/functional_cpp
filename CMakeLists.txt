
cmake_minimum_required(VERSION 3.0.0)

set(EX_PROJECT_NAME
    ex_cpp
)
set(EX_SOURCE_DIR
    src
)
set(EX_SOURCE
    ${EX_SOURCE_DIR}/main.cpp
)
set(EX_LIBRARIES_DIR
    libs
)
set(EX_LIBRARIES 
    defmacro
)

project(${EX_PROJECT_NAME})

#########
# GTest #
#########
enable_testing()
add_subdirectory(libs/gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

###########
# Project #
###########
add_executable(${EX_PROJECT_NAME} ${EX_SOURCE})

foreach(LIBRARY ${EX_LIBRARIES})
    add_subdirectory("${EX_LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)
target_link_libraries(${EX_PROJECT_NAME} ${EX_LIBRARIES})

add_custom_target(run
    COMMAND ex_cpp
    DEPENDS ex_cpp
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)