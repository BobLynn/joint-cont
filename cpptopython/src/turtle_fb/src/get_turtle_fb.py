#!/usr/bin/env python
# -*- coding: UTF-8 -*-
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist 
from turtlesim.msg import Pose 

def callback(data):
    rospy.loginfo("position = %f,%f", data.x, data.y) 
    rospy.loginfo("direction = %f", data.theta)

def listener():
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber("turtle1/pose", Pose, callback)
    rospy.spin()

if __name__ == '__main__':
listener()