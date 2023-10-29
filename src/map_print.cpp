#include <ros/ros.h>
#include <iostream>
#include <nav_msgs/Path.h>
#include <cmath>
#include <nav_msgs/OccupancyGrid.h>
using namespace std;

nav_msgs::OccupancyGrid old_map;
nav_msgs::OccupancyGrid cur_map;


void mapCB(const nav_msgs::OccupancyGridConstPtr& msg){
    cur_map = *msg;
    if(cur_map!= old_map){
        std::cout << cur_map.info.width << "," << cur_map.info.height << std::endl;
        for(int i=0;i<cur_map.data.size();i++){
            if(i==cur_map.data.size()-1){
                std::cout << int(cur_map.data[i]) << std::endl;
            }
            else{
                std::cout << int(cur_map.data[i]) << ",";
            }
        }
        old_map = cur_map;
    }
}

int main(int argc, char **argv){
    ros::init(argc,argv,"map_print");
    ros::NodeHandle nh;
    ros::Subscriber path_sub = nh.subscribe("map",10,mapCB);
    ros::Rate r(1);
    while (ros::ok())
    {
        ros::spinOnce();
    }
    

    return 0;
}