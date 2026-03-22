#include <stdio.h>
#include <string.h>

#include "rcl/rcl.h"
#include "std_msgs/msg/float32.h"
#include "std_msgs/msg/string.h"

int main(int argc, char * argv[])
{
    rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
    rcl_init_options_init(&init_options, rcl_get_default_allocator());

    rcl_context_t context = rcl_get_zero_initialized_context();
    rcl_init(argc, argv, &init_options, &context);

    rcl_node_t node = rcl_get_zero_initialized_node();
    rcl_node_options_t node_ops = rcl_node_get_default_options();
    rcl_node_init(&node, "decision_node", "", &context, &node_ops);

    rcl_subscription_t subscriber = rcl_get_zero_initialized_subscription();
    rcl_subscription_options_t sub_ops = rcl_subscription_get_default_options();

    rcl_subscription_init(
        &subscriber,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
        "distance",
        &sub_ops
    );

    rcl_publisher_t publisher = rcl_get_zero_initialized_publisher();
    rcl_publisher_options_t pub_ops = rcl_publisher_get_default_options();

    rcl_publisher_init(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
        "rover_command",
        &pub_ops
    );

    std_msgs__msg__Float32 dist_msg;
    std_msgs__msg__String cmd_msg;

    char buffer[50];

    while (1)
    {
        if (rcl_take(&subscriber, &dist_msg, NULL, NULL) == RCL_RET_OK)
        {
            printf("Distance: %.2f\n", dist_msg.data);

            if (dist_msg.data < 30)
                strcpy(buffer, "STOP");
            else
                strcpy(buffer, "MOVE_FORWARD");

            cmd_msg.data.data = buffer;
            cmd_msg.data.size = strlen(buffer);
            cmd_msg.data.capacity = 50;

            rcl_publish(&publisher, &cmd_msg, NULL);

            printf("Command: %s\n", buffer);
        }
    }

    return 0;
}
