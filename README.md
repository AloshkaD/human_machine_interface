# Human Machine Interface 


The Human Machine Interface allows operators or users of the system to bi-directionally communicate with each aerial robotic agent. Both communication directions are equally important because:


* The communication from the robotic agent to the operator is needed to monitor its state and the performance of the requested mission. This will allow the operator to actuate in case of a need to redefine or abort the mission. 


* The communication from the operator to the robotic agent is needed if a non-rigid behavior is needed to accomplish the goal, making it possible to redefine the mission and also to start, stop and abort the mission.


## User's Guide

This user guide covers a general description of the application. This user guide could be found in: ```./Documentation/UserGuide```

## Developer’s Guide

###Obtaining source code and libraries
* Source code project:
git clone <https://yolanda_de_la_hoz_simon@bitbucket.org/yolanda_de_la_hoz_simon/groundcontrolsystem.git>

The Human Machine Interface depends on ROS, Qt and OpenSceneGraph.

* ROS framework: 
<http://wiki.ros.org/indigo/Installation/Ubuntu>

* Qt 4.8.6:
<http://download.qt.io/official_releases/qt/4.8/4.8.6/>

* OpenSceneGraph 3.2.2:
Installation tutorial in Ubuntu 14.04: 
<https://bhattigurjot.wordpress.com/2013/12/27/openscenegraph-on-linux/>

You should add this line at the end of your ~/.bashrc or write it each time that you want to use the HMI:
export OSG_DIR="/home/<my_account>/<my_OpenSceneGraph_Dir>/"


###Simple Installation 

```
cd ~/worskspace
git clone https://bitbucket.org/yolanda_de_la_hoz_simon/hmi_cvg_stack.git ./hmi_cvg_stack/src
cd /hmi_cvg_stack/src
catkin_init_workspace
./installation/set_environmental_variables.sh
cd ..
catkin_make
```

###Installation in a catkin previous project

```
cd <my_worskspace>/src/<workspace_path>     => Example: cd ~/workspace/ros/quadrotor_stack_catkin/src/quadrotor_stack/stack
git clone https://bitbucket.org/yolanda_de_la_hoz_simon/hmi_cvg_stack.git 
cd hmi_cvg_stack
./installation/set_environmental_variables.sh
cd ~/<my_workspace>
catkin_make
```

This software has been tested on: Ubuntu 14.04 and open source drivers.


###Project organization

The project organization use a model/view architecture that manages the relationship between data and the way it is presented to the user.

```
Project /
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

1. Create and initialize a catkin workspace.
2. Erase symlink of CMakeLists.txt and make a hard copy instead.
3. Load CMakeLists and run build option with Qt IDE.


```
cd ./hmi_cvg_stack/human_machine_interface
rm CMakeLists.txt
cp /opt/ros/indigo/share/catkin/cmake/toplevel.cmake CMakeLists.txt
cd ..
source devel/setup.bash
```
####Netbeans
Netbeans is a software development platform written in Java. The NetBeans Platform allows applications to be developed from a set of modular software components called modules. 

This IDE presents more functionalities for software development and project organization. It is recommended use it only if you are already familiar with it.

For more information:
<http://wiki.ros.org/IDEs>




