#include <ros/ros.h>
#include <std_msgs/Int16.h>
#include <iostream>

ros::Publisher test_pub;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "test_node");
    ros::NodeHandle nh;

    ros::Rate rate(5);

    test_pub = nh.advertise<std_msgs::Int16>("test_topic", 10);

    std_msgs::Int16 msg;

    msg.data = 0;

    while (ros::ok())
    {
        msg.data += 1;
        test_pub.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}