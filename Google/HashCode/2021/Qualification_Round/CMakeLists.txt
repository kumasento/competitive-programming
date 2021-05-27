cmake_minimum_required(VERSION 3.16)

project(TrafficLight LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(
  DocTest
  GIT_REPOSITORY "https://github.com/onqtam/doctest"
  GIT_TAG "2.4.6"
)
FetchContent_MakeAvailable(DocTest)

add_executable(${PROJECT_NAME} main.cc)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} doctest)


