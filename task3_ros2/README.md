# Task 3 – ROS2 Communication (C)

## Overview
This project demonstrates ROS2 node communication using C.

## Nodes
- Distance Publisher
- Distance Subscriber
- Decision Node (Bonus)
- Command Listener (Bonus)

## Topics
- /distance
- /rover_command

## Functionality
- Publisher sends random distance values
- Subscriber receives and prints
- Decision node sends STOP / MOVE_FORWARD
- Command node simulates rover movement

## How to Run
colcon build
source install/setup.bash

ros2 run distance_sensor_c distance_publisher
ros2 run distance_sensor_c decision_node
ros2 run distance_sensor_c command_listener


## Output
- Distance values displayed
- Rover commands displayed
