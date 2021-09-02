#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>


void chatterCallback(const sensor_msgs::JointState & msg);

int main(int argc, char **argv){
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle nh;

    ros::Subscriber subscriber = nh.subscribe("chatter",1,chatterCallback);
    ros::spin();
    return 0;
}
void chatterCallback(const sensor_msgs::JointState & msg){
    ROS_INFO(
        "Joint position:\n1:%.2f \n2:%.2f \n3:%.2f \n4:%.2f \n5:%.2f \n6:%.2f \n", msg.position[0], msg.position[1], msg.position[2], msg.position[3], msg.position[4], msg.position[5]
        );
}
