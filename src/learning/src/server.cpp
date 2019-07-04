/*
 * server.cpp
 *
 *  Created on: 2019年7月4日
 *      Author: yinlei
 */
#include "ros/ros.h"
#include "learning/AddTwoInts.h"

bool add(learning::AddTwoInts::Request &req, learning::AddTwoInts::Response &res) {
	res.sum = req.a + req.b;
	ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
	ROS_INFO("sending back response: [%ld]", (long int)res.sum);
	return true;
}

int main(int argc, char **argv) {
	// 初始化ros节点，名称为add_two_ints_server
	ros::init(argc, argv, "add_two_ints_server");

	// 创建节点句柄，用来发布服务
	ros::NodeHandle n;

	// 创建一个名为add_two_ints的service，同时注册回调函数add
	ros::ServiceServer service = n.advertiseService("add_two_ints", add);

	ROS_INFO("Ready to add two ints.");
	// 循环等待回调函数
	ros::spin();
	return 0;
}


