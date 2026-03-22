#include <stdio.h>
#include <string.h>

#include "rcl/rcl.h"
#include "std_msgs/msg/string.h"

int main(int argc, char * argv[])
{
    rcl_init_options_t init_options = rcl_get_zero_initialized_init_options();
    rcl_init_options_init(&init_options, rcl_get_default_allocator());

    rcl_context_t context = rcl_get_zero_initialized_context();
    rcl_init(argc, argv, &init_options, &context);

    rcl_node_t node = rcl_get_zero_initialized_node();
    rcl_node_options_t node_ops = rcl_node_get_default_options();
    rcl_node_init(&node, "command_listener", "", &context, &node_ops);

    rcl_subscription_t subscriber = rcl_get_zero_initialized_subscription();
    rcl_subscription_options_t sub_ops = rcl_subscription_get_default_options();

    rcl_subscription_init(
        &subscriber,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, String),
        "rover_command",
        &sub_ops
    );

    std_msgs__msg__String msg;

    while (1)
    {
        if (rcl_take(&subscriber, &msg, NULL, NULL) == RCL_RET_OK)
        {
            printf("Received command: %s\n", msg.data.data);

            if (strcmp(msg.data.data, "MOVE_FORWARD") == 0)
                printf("Rover moving...\n");
            else
                printf("Rover stopped!\n");
        }
    }

    return 0;
}
