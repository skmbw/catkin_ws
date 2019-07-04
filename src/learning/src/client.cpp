/*
 * client.cpp
 *
 *  Created on: 2019年7月4日
 *      Author: yinlei
 */
#include <cstdlib>
#include "ros/ros.h"
#include "learning/AddTwoInts.h"

int main(int argc, char **argv) {
	// 初始化ros客户端节点，名称add_two_ints_client
	ros::init(argc, argv, "add_two_ints_client");

	// 简单校验参数是否为三个
	if (argc != 3) {
		// ROS_INFO("USAGE: add_tow_ints_client X Y");
		ROS_INFO("USAGE: rosrun learning client X Y");
		return 1;
	}

	// 创建节点句柄，用来创建服务客户端
	ros::NodeHandle n;

	// 创建服务客户端，连接服务名为add_two_ints的服务
	ros::ServiceClient client = n.serviceClient<learning::AddTwoInts>("add_two_ints");

	// 实例化一个参数，这是C++的方式
	learning::AddTwoInts srv;
	// 对调用参数赋值
	srv.request.a = atoll(argv[1]);
	srv.request.b = atoll(argv[2]);

	// 发起调用
	if (client.call(srv)) {
		ROS_INFO("Sum: %ld", (long int)srv.response.sum);
	} else {
		ROS_ERROR("Failed to call service add_two_ints");
		return 1;
	}

	return 0;
}



