from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='bal_ca0_kisbeadando',
            executable='main',
        ),

        Node(
            package='bal_ca0_kisbeadando',
            executable='ossz',
        ),
        
    ])