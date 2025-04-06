cmake_minimum_required(VERSION 3.10)
project(GlOptUserTasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

file(GLOB SOURCES 
    src/*.cpp
)

add_library(GlOpt_user_tasks SHARED ${SOURCES})

target_include_directories(GlOpt_user_tasks
    PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

if(WIN32)
    target_compile_definitions(GlOpt_user_tasks 
        PRIVATE GLOPT_USER_TASKS_EXPORTS
    )
endif()
add_executable(TestApp src/main.cpp)

target_link_libraries(TestApp PRIVATE GlOpt_user_tasks)

target_include_directories(TestApp
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)