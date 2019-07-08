#!/usr/bin/env python
# -*- coding: UTF-8 -*-
from std_msgs.msg  import String 
from geometry_msgs.msg import Twist
import rospy
import random

def talker():
    rospy.init_node('talker',anonymous=True)    
    pub =  rospy.Publisher("turtle1/cmd_vel", Twist, queue_size=10) 
    rate = rospy.Rate(2) # hz
    while not rospy.is_shutdown(): 
        move_cmd = Twist()
        move_cmd.linear.x = random.uniform(0,1)
        move_cmd.angular.z = 2 * random.uniform(0,1) - 1
        rospy.loginfo("linear=%f",move_cmd.linear.x)
        rospy.loginfo("angular=%f",move_cmd.angular.z)
        pub.publish(move_cmd)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass