

#! /usr/bin/env python 

from std_msgs.msg  import String 
import rospy

def talker(): 

   print("")


def main(): 

    try: 

        talker()

    except rospy.ROSInterruptException:
       pass 

main()  # Call main function 
