# catkin_ws
学习ROS的项目

## ubuntu 执行Python脚本出现: /usr/bin/env: ‘python\r’: No such file or directory
这个可能是因为，文件是windows下的，要转成unix下的格式。
:set ff
输入:set ff=unix
再输入:wq 保存
如果还是不行，新建一个文件，gedit打开将内容放入

## cannot launch node of type [mrobot_teleop/mrobot_teleop.py]: can't locate node [mrobot_teleop.py] in package [mrobot_teleop]

是因为对文件没有权限，所以解决方式：
chmod +x mrobot_teleop.py
