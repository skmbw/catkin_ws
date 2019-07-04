/*
 * talker.cpp
 *
 *  Created on: 2019年7月3日
 *      Author: yinlei
 */
#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char ** argv) {
	// 节点初始化，节点名为talker
	ros::init(argc, argv, "talker");

	// 创建节点句柄
	ros::NodeHandle n;

	// 发布话题chatter，消息类型是String，向节点管理其注册自己
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	// 设置循环的频率，一秒钟5次
	ros::Rate loop_rate(5);

	int count = 0;
	while(ros::ok()) {
		// 构建消息内容
		std_msgs::String msg;
		std::stringstream ss;
		ss << "hello world " << count;
		msg.data = ss.str();

		// 控制台中打印消息
		ROS_INFO("%s", msg.data.c_str());

		// 发布消息
		chatter_pub.publish(msg);

		// 循环等待回调
		ros::spinOnce();

		// 按频率休息200ms
		loop_rate.sleep();
		++count;
	}
}


