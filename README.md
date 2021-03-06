[![Build Status](https://travis-ci.org/inani47/terrapinavigator.svg?branch=master)](https://travis-ci.org/inani47/terrapinavigator)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
# terrapinavigator - Navigation and Mapping with TurtleBot 

## Overview
This project is an implementation of a simulated robotic system capable of navigation and mapping of unknown environments. The project was immplemented on the TurtleBot platform using Gazebo, Rviz and ROS (and its various packages and libraries eg. gmapping).
The developed system is capable of:
* navigating unknown environments
* robust in avoiding obstacles 
* simultaneously mapping the environment and
* takes pictures at regular intervals or when desired by the user


Few applications of the projects include:
* Navigation of known environments like offices and factories.
* Explorer bot to aid rescue efforts during natural disasters.
* Remote Survaillence 

The project was programmed in the C++ programming language and uses with C++ 11/14 features with ephasis given to Object Oriented Programming principles. The code follows the Google C++ Styleguide with cpplint validation. Cppcheck was also used for static code analysis. This project followed Test-driven Development to guide implementation and uses unit tests to test the code coverage written using Google Test framework. The entire code was written and debugged using the Eclipse IDE. The code follows doxygen-formatted comments to aid doxygen documentation.

The project was completed in about three weeks time.  This project was implemented by following the Solo Iterative Process(SIP). This included the creation of a product backlog using the requirements and ordering them in the order of their priority. Finally, the software was developed over three sprints which were one week long in duration. The first week focused on the planning and design of the project inculding the initial UML diagrams. The second week involved the programming of the actual module. In the third week, the remainder of programming aspect of the project was completed and a video presentation was created (link in SIP & Sprint Logs section).

## Example outputs

### Final Map Example

![finalmap](https://user-images.githubusercontent.com/31521157/34059472-2dce52de-e1ad-11e7-9c35-8bc2ac10b1d1.jpg)

### Picture Service Example
![pictureServiceExample](https://raw.githubusercontent.com/inani47/terrapinavigator/master/outputs/pictures/turtleBotImage1512864439.161703.jpg)


## About the Developer

I am Pranav Inani. I am currently pursing my masters in Robotics at University of Maryland - College Park. I hold a Bachelors degree in Mechatronics from Mahatma Gandhi Institute of Technology, India. I have worked for a small start-up geared towards solving the self-driving car problem in India (a completely different challenge altogether). I wish to pursue a career in Robotics with a focus in Artificial Intelligence.
Few modest projects I was a part of:
* Lane Marker Detection Using DBScan Clustering Algorithm.
* AStar Path Planning Algorithm.
* Design and Fabrication of Quadcopter with Integrated End-Effector.
* Home automation Using Raspberry Pi and Arduino.

## Disclaimer

This software is released under the BSD-3 License.
```
BSD 3-Clause License

Copyright (c) 2017, Pranav Inani
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of the copyright holder nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```
## Dependencies

To run this program you need to have the following installed on your system:
* Ubuntu (Wily/Xenial) or Debian (Jessie)
* ROS Kinetic
* Gazebo 7.x (part of ros-kinetic-desktop-full package)
* Turtlebot simulation stack
* Gmapping
* map_server

To install ROS, use this [link](http://wiki.ros.org/kinetic/Installation)

To install turtlebot simulation stack. In a terminal:
```
sudo apt-get install ros-kinetic-turtlebot-gazebo ros-kinetic-turtlebot-apps ros-kinetic-turtlebot-rviz-launchers
source /opt/ros/kinetic/setup.bash
```
To install gmapping, In a terminal:
```
sudo apt-get install ros-kinetic-slam-gmapping
```
To install Map_server, In a terminal:
```
 sudo apt-get install ros-kinetic-map-server
```



## SIP & Sprint Logs

Link to SIP Planning: [SIP Logs](https://docs.google.com/spreadsheets/d/1yglRR3HuQ96tQThB4AsiW9a2gjR8kYN-1Wcj_BuyqH0/edit?usp=sharing)

Link to Sprint Planning Notes: [Sprint Notes](https://docs.google.com/document/d/1rXK6foPKe-qIE33yUQAk5DwvEb2_a-keuWt45c4f9LM/edit)

Link to the video presentation uploaded on youtube: [Presentation Video](https://youtu.be/ouJtWGgyxr0)



## Build Steps
If you do not have a catkin workspace, in a new terminal:
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
source devel/setup.bash
cd src/
git clone --recursive https://github.com/inani47/terrapinavigator.git
cd ..
catkin_make
```
If you wish to run this code in an existing catkin workspace:
```
cd ~/catkin_ws/
source devel/setup.bash
cd src/
git clone --recursive https://github.com/inani47/terrapinavigator.git
cd ..
catkin_make
```
## Running the Demo Using Launch File
To run the demo we need to run two launch files. First launch file loads the Gazebo environment and runs the terrapinavigator node to explore and map the environment. The seconds lauch file loads rviz (for visualization) and gmapping (for SLAM and Mapping).

After following the build instructions:

To run the demo, in a new terminal:
```
cd ~/catkin_ws/
source devel/setup.bash
roslaunch terrapinavigator terrapinavigator.launch 
```
This will load the turtlebot in the gazebo world and wait for 15 seconds. Now to run gmapping and Rviz, in a new terminal:
```
cd ~/catkin_ws/
source devel/setup.bash
roslaunch terrapinavigator demo.launch 
```

This will start the gmapping package and load rviz for visualization.

Note: You may close the gazebo window if your rig can't handle the load and continue to use rviz for visualization.

### Saving the Map
Once you are happy with the map created. To save a map, in a new terminal:
```
rosrun map_server map_saver -f <map_name>
```
To view the saved map. In a new terminal
```
eog <map_name>.pgm
```
### Running Picture Service From Command Line
The demo implementation is such that a picture is taken every 40 seconds and it gets stored in the ros folder with file name "termpImage" followed by the current time stamp at the time of takin the picture.

If you wish to manually click a picture while the demo is running at any desired time. In a new terminal:
```
cd ~/catkin_ws/
source devel/setup.bash
rosservice call /pictureService "reqImg: true" 
```
If the image was taken succesfully you will see the following output:
```
clickImg: True
```
The files will get saved in ./ros folder. To view the files. In a terminal:
```
gnome-open ~/.ros
```
This will open the ./ros folder using the GUI and you can see all the pictures taken manually as well as those autmatically taken every 40 seconds in the demo.

Note: If you do not have gnome-open installed. In a terminal:
```
sudo apt install libgnome2-bin
```

### Recording, Inspecting and Playing back bag files
To enable bag file recording of all topics except camera. While launching the demo, in a new terminal:
```
cd ~/catkin_ws/
source devel/setup.bash
roslaunch terrapinavigator terrpainavigator.launch rec:=1
```
This will save a bag file in the results folder of the package.

To inspect the bag file, In a new terminal:
```
cd ~/catkin_ws/
source devel/setup.bash
cd src/terrapinavigator/results
rosbag info recording.bag
```


To replay the bag file, first run rosmaster from a terminal:
```
roscore
```
Now, from the results folder run the following command in a new terminal:
```
cd ~/catkin_ws/
source devel/setup.bash
cd src/terrapinavigator/results
rosbag play recording.bag
```

## Running Rostest
To run rostest, in a new terminal:
```
cd ~/catkin_ws/
source devel/setup.bash
cd build/
make run_tests
```
### Code Coverage Output Using lcov
![Code Coverage](https://user-images.githubusercontent.com/31521157/34026729-fee76d8e-e125-11e7-8342-f9dcf03d3111.png)
## Known Issues/Bugs 
* Unable to show code coverage using coveralls. Added lcov output to the readme instead
* When gazebo initializes it  throws some errors of missing plugins and thi followin error:
  SpawnModel: Failure - model name mobile_base already exist.
  However, these make no difference to the demo. The latter error maybe resolved once ros answers is back online.

## API and other developer documentation

### Generating Doxygen Documentation

To install doxygen run the following command: 
```
sudo apt-get install doxygen
```

Now from your cloned directory, run the following command:

```
doxygen terpDocs
```

Doxygen files will be generated to /docs folder

To view them in a browser:
```
cd docs
cd html
firefox index.html
```


