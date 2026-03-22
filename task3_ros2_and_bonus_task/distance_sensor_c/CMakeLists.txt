cmake_minimum_required(VERSION 3.8)
project(distance_sensor_c)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# dependencies
find_package(ament_cmake REQUIRED)
find_package(rcl REQUIRED)
find_package(std_msgs REQUIRED)

# executables
add_executable(distance_publisher src/distance_publisher.c)
ament_target_dependencies(distance_publisher rcl std_msgs)

add_executable(distance_subscriber src/distance_subscriber.c)
ament_target_dependencies(distance_subscriber rcl std_msgs)

# install
add_executable(decision_node src/decision_node.c)
ament_target_dependencies(decision_node rcl std_msgs)

add_executable(command_listener src/command_listener.c)
ament_target_dependencies(command_listener rcl std_msgs)

install(TARGETS
  distance_publisher
  distance_subscriber
  decision_node
  command_listener
  DESTINATION lib/${PROJECT_NAME}
)

# testing (optional)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# MUST BE LAST
ament_package()
