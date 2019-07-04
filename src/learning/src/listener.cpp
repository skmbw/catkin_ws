/*
 * listener.cpp
 *
 *  Created on: 2019年7月3日
 *      Author: yinlei
 */

#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg) {
	// 将接受的消息打印出来，ROS_INFO相当于printf或cout
	ROS_INFO("I heard: %s", msg->data.c_str());
}

int main(int argc, char **argv) {
	// 初始化ROS节点
	ros::init(argc, argv, "listener");

	// 创建节点句柄
	ros::NodeHandle n;

	// 创建订阅者，订阅名为chatter的话题，注册回调函数chatterCallback
	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

	// 循环等待回调
	ros::spin();

	return 0;
}

