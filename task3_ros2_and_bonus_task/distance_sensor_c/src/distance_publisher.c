#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

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
    rcl_node_init(&node, "distance_publisher", "", &context, &node_ops);

    rcl_publisher_t publisher = rcl_get_zero_initialized_publisher();
    rcl_publisher_options_t pub_ops = rcl_publisher_get_default_options();

    rcl_publisher_init(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
        "distance",
        &pub_ops
    );

    std_msgs__msg__Float32 msg;
    srand(time(NULL));

    while (1)
    {
        msg.data = ((float)rand() / RAND_MAX) * 100;

        rcl_publish(&publisher, &msg, NULL);
        printf("Publishing: %.2f\n", msg.data);

        sleep(1);
    }

    return 0;
}
