#include <ros/ros.h>
#include <nav_msgs/Path.h>
#include <cmath>

nav_msgs::Path global_path;
double PathLength(std::vector<geometry_msgs::PoseStamped> &path){
    double length,section;
    // geometry_msgs::PoseStamped first = path[0];
    for(int i=0;i<path.size()-1;i++){
        section = sqrt(pow(path[i+1].pose.position.y-path[i].pose.position.y,2)+pow(path[i+1].pose.position.x-path[i].pose.position.x,2));
        length += section;
    }
    return length;
}
void pathCB(const nav_msgs::Path::ConstPtr &path){
    global_path.poses = path->poses;
    double path_length = PathLength(global_path.poses);
    std::cout << "Global path length: " << path_length << std::endl;
}
int main(int argc, char **argv){
    ros::init(argc,argv,"computePath");
    ros::NodeHandle nh;
    ros::Subscriber path_sub = nh.subscribe("move_base_node/GlobalPlanner/plan",10,pathCB);
    ros::Rate r(1);
    while (ros::ok())
    {
        ros::spinOnce();
    }
    

    return 0;
}