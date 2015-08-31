# Human Machine Interface 


The Human Machine Interface allows operators or users of the system to bi-directionally communicate with each aerial robotic agent. Both communication directions are equally important because:


* The communication from the robotic agent to the operator is needed to monitor its state and the performance of the requested mission. This will allow the operator to actuate in case of a need to redefine or abort the mission. 


* The communication from the operator to the robotic agent is needed if a non-rigid behavior is needed to accomplish the goal, making it possible to redefine the mission and also to start, stop and abort the mission.


## User's Guide

This user guide covers a general description of the application. This user guide could be found in: ```./Documentation/UserGuide```

## Developer's Guide

###Obtaining source code and libraries
* Source code project:
git clone <https://yolanda_de_la_hoz_simon@bitbucket.org/yolanda_de_la_hoz_simon/groundcontrolsystem.git>

The Human Machine Interface depends on ROS, Qt and OpenSceneGraph.

* ROS framework: 
<http://wiki.ros.org/indigo/Installation/Ubuntu>

* Qt IDE:
<http://download.qt.io/official_releases/qt/4.8/4.8.6/>

* OpenSceneGraph 3.2.2. 
Installation tutorial in Ubuntu 14.04: 
<https://bhattigurjot.wordpress.com/2013/12/27/openscenegraph-on-linux/>

###Installation



###Project organization

The project organization use a model/view architecture that manages the relationship between data and the way it is presented to the user.

```
MyProject /
    CMakeList.txt
    package.xml
    README.md
    src /             
        Controller /     
            source /
            include /
        View / 
            ui /
            resource /
              images.qrc
              images /
              osg_dataset /
            
    libraries /
    main.cpp
    
    test /
       Component1 /
                main.cpp
       Component2 /
                main.cpp
       ...
        
```

###Recommended IDEs

####Qt Creator
Qt Creator is a cross-platform C++, JavaScript and QML integrated development environment which is part of the SDK for the Qt GUI Application development framework.

Qt IDE: <http://www.qt.io/download/>

Create and initialize a catkin workspace.
Erase symlink of CMakeLists.txt and make a hard copy instead.
Load CMakeLists and run build option with Qt IDE.


```
cd ./hmi_cvg_stack/human_machine_interface
rm CMakeLists.txt
cp /opt/ros/indigo/share/catkin/cmake/toplevel.cmake CMakeLists.txt
cd ..
source devel/setup.bash
```


###Project contribution

