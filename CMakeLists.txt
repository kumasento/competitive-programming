cmake_minimum_required(VERSION 3.11)

project(competitive-programming LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

# --------------- The only build target -----------------
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS *.cc)
foreach(src_name IN ITEMS ${SRC_FILES})
  get_filename_component(dir_name ${src_name} DIRECTORY)
  string(REPLACE "/" "-" target_prefix ${dir_name})
  get_filename_component(target_name ${src_name} NAME_WE)
  add_executable("${target_prefix}-${target_name}" ${src_name})
endforeach()
