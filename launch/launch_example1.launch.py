from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(package='bal_ca0_proba', executable='trig_publisher', name='trig_publisher', output='screen'),
        Node(package='bal_ca0_proba', executable='trig_subscriber', name='trig_subscriber', output='screen'),      
    ]) 