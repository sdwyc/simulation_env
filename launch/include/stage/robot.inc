include "sensors.inc"

define agent position
(
    size [0.4 0.4 0.4]
    origin [0 0 0 0]
    color "red"
    gui_nose 0
    drive "diff"
    lidar(pose [ 0 0 0.3 0 ] color "blue")
    camera( 
        pose [ 0 0 0.3 0 ]
        range [ 0.2 8.0 ]
        resolution [ 640 480 ]
        fov [ 70 40 ]
        pantilt [ 0 0 ]
        alwayson 1
    )
)