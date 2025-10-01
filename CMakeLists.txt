cmake_minimum_required(VERSION 3.8)
project(bal_ca0_kisbeadando)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(ament_dependencies
  rclcpp
  std_msgs
  geometry_msgs
)
add_executable(main src/main.cpp)
ament_target_dependencies(main rclcpp std_msgs)

add_executable(ossz src/ossz.cpp)
ament_target_dependencies(ossz rclcpp std_msgs)

install(TARGETS
  main
  ossz
  DESTINATION lib/${PROJECT_NAME})

ament_package()