#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sensor_msgs/JointState.h>


int main(int argc, char **argv){
    ros::init(argc, argv,"publisher");
    ros::NodeHandle nh;
    ros::Publisher chatterPublisher = nh.advertise<sensor_msgs::JointState>("chatter",1);
    ros::Rate loopRate(1);
    sensor_msgs::JointState message;
    message.position.resize(6);
    message.position[0]=0.0;
    message.position[1]=0.0;
    message.position[2]=0.0;
    message.position[3]=0.0;
    message.position[4]=0.0;
    message.position[5]=0.0;


    unsigned int count =1;
    while(ros::ok())
    {
        chatterPublisher.publish(message);

        ros::spinOnce();

        loopRate.sleep();
        message.position[0]+=1;
        message.position[1]+=1;
        message.position[2]+=1;
        message.position[3]+=1;
        message.position[4]+=1;
        message.position[5]+=1;

    }

    ros::shutdown();
    return 0;
}