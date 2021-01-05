cmake_minimum_required(VERSION 3.1)
project(where_is_the_logic)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include_directories(
  ${PROJECT_SOURCE_DIR}
  ${PROJECT_SOURCE_DIR}/contrib/mongo-c-driver/libbson/src
  ${PROJECT_SOURCE_DIR}/contrib/mongo-c-driver/libmongoc/src
)

add_subdirectory(contrib)
add_subdirectory(library)
add_subdirectory(sources)
add_subdirectory(util)
add_subdirectory(app)

add_executable(where_is_the_logic
  main.cpp
)

target_link_libraries(where_is_the_logic PUBLIC
  application
  generic
)
