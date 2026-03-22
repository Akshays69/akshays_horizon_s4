# 🤖 ROS2 Distance Publisher–Subscriber System + Bonus Enhancements

## 📌 Overview

This project implements a **ROS2-based communication system** simulating a rover sensor.

The system consists of:

* A **Publisher Node** that generates random distance values
* A **Subscriber Node** that receives and displays those values

Additionally, the **Bonus Task** extends the system with enhanced logic such as warnings and data processing.

---

## 🧾 What the System Does

The program performs the following:

1. Publishes simulated **distance values (0–100)** every second
2. Transmits data through a **ROS2 topic (`distance`)**
3. Receives and displays the values in another node
4. Applies additional logic (bonus task) such as:

   * Threshold warnings
   * Filtering values
   * Data monitoring

---

## 📁 Project Structure

```id="2p8k4m"
ros2_ws/
  src/
    my_package/
      my_package/
        publisher.c
        subscriber.c
  install/
  build/
  log/
  output/
```

---

## 🧠 Core Concept

ROS2 follows a **Publisher–Subscriber model**:

```id="9v4k1x"
Publisher → Topic → Subscriber
```

* Publisher sends data
* Topic acts as communication channel
* Subscriber receives data

---

## 💻 Source Code

---

### 🔹 Publisher Node (`publisher.c`)

```python id="6f2n8k"
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
import random

class DistancePublisher(Node):
    def __init__(self):
        super().__init__('distance_publisher')
        self.publisher_ = self.create_publisher(Int32, 'distance', 10)
        self.timer = self.create_timer(1.0, self.publish_distance)

    def publish_distance(self):
        msg = Int32()
        msg.data = random.randint(0, 100)
        self.publisher_.publish(msg)
        self.get_logger().info(f'Publishing: {msg.data}')

def main(args=None):
    rclpy.init(args=args)
    node = DistancePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
```

---

### 🔹 Subscriber Node (`subscriber.c`)

#include <stdio.h>

#include "rcl/rcl.h"
#include "std_msgs/msg/float32.h"

int main(int argc, char * argv[])
{
    
    rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
    rcl_init_options_init(&init_options, rcl_get_default_allocator());

    rcl_context_t context = rcl_get_zero_initialized_context();
    rcl_init(argc, argv, &init_options, &context);

    
    rcl_node_t node = rcl_get_zero_initialized_node();
    rcl_node_options_t node_ops = rcl_node_get_default_options();
    rcl_node_init(&node, "distance_subscriber", "", &context, &node_ops);

    rcl_subscription_t subscriber = rcl_get_zero_initialized_subscription();
    rcl_subscription_options_t sub_ops = rcl_subscription_get_default_options();

    rcl_subscription_init(
        &subscriber,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
        "distance",
        &sub_ops
    );

    std_msgs__msg__Float32 msg;

    while (1)
    {
        if (rcl_take(&subscriber, &msg, NULL, NULL) == RCL_RET_OK)
        {
            printf("Received: %.2f\n", msg.data);
        }
    }

    return 0;
}

---

## ⚙️ Build and Execution

---

### 1️⃣ Create Workspace

```bash id="x8v3lp"
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws
colcon build
```

---

### 2️⃣ Source Environment

```bash id="q4z7ht"
source /opt/ros/humble/setup.bash
source install/setup.bash
```

---

### 3️⃣ Create Package

```bash id="z7t2kp"
cd ~/ros2_ws/src
ros2 pkg create --build-type ament_python my_package
```

---

### 4️⃣ Build Package

```bash id="p6r1mx"
cd ~/ros2_ws
colcon build
```

---

### 5️⃣ Run Publisher

```bash id="k3v9za"
ros2 run my_package publisher
```

---

### 6️⃣ Run Subscriber (New Terminal)

```bash id="y1f8xb"
source ~/ros2_ws/install/setup.bash
ros2 run my_package subscriber
```

---

## 🧪 Example Output

---

### 📤 Publisher Output

```id="8k2fmp"
Publishing: 23
Publishing: 67
Publishing: 12
```

---

### 📥 Subscriber Output

```id="3p7zld"
Received: 23
Received: 67
Received: 12
```

---

## 📸 Output Proof

All proof files are stored in:

```id="r6x1nb"
output/
```

Includes:

* Ubuntu installation screenshot
* ROS2 installation verification
* Publisher node output
* Subscriber node output

---

## 🎬 Demo

```id="f2q7yc"
output/ros2_demo.mp4
```

---

# 🚀 BONUS TASK

## 📌 Description

The bonus task enhances the ROS2 system by adding **intelligent processing and safety logic** to the subscriber node.

---

## 🔧 Enhancements Implemented

* 🚨 Threshold warning system
* 📊 Data filtering
* 📈 Monitoring incoming values
* 🧠 Improved decision-making

---

## 💡 Bonus Logic

Example enhancement:

```python id="t4k9vp"
if msg.data > 70:
    print("Warning: Distance exceeds safe limit")
```

---

## 🧪 Enhanced Subscriber Example

```python id="h7m2rz"
def listener_callback(self, msg):
    value = msg.data

    if value > 70:
        self.get_logger().warn(f'Warning! High distance: {value}')
    else:
        self.get_logger().info(f'Received: {value}')
```

---

## 🎯 Bonus Output Example

```id="j9r3xp"
Received: 45
Received: 60
Warning! High distance: 85
```

---

## 🧠 Concepts Used

* ROS2 Node Architecture
* Publisher–Subscriber Communication
* Topic-based Messaging
* Python Programming
* Real-time Data Processing
* Conditional Logic and Safety Checks

---

## ⚠️ Input Constraints

* Distance values: 0–100
* Threshold (bonus): 70
* Data published every 1 second

---

## 🎯 Learning Outcomes

* Understand ROS2 communication model
* Implement real-time data exchange
* Apply safety constraints in robotics
* Extend basic systems with intelligent logic

---

## 🏁 Conclusion

This project demonstrates how ROS2 enables **modular, scalable communication** between components in robotics systems.

The bonus task adds **intelligence and safety awareness**, making the system more realistic for real-world rover applications.

---
