cmake_minimum_required(VERSION 3.0.2)
project(vorc_gazebo)

find_package(catkin REQUIRED COMPONENTS
  vrx_gazebo
  wamv_gazebo
  wave_gazebo
  xacro
)

catkin_package(
  CATKIN_DEPENDS
    vrx_gazebo
    wamv_gazebo
    wave_gazebo
    xacro
)

include_directories(
)

## Install ##

# Run xacro to generate world files
xacro_add_files(
  worlds/marina.world.xacro
  worlds/perception.world.xacro
  worlds/station_keeping.world.xacro
  worlds/wayfinding.world.xacro
  worlds/gymkhana.world.xacro
  INORDER INSTALL DESTINATION worlds
)

install(DIRECTORY worlds/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/worlds)

install(DIRECTORY models/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/models)

install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)

install(DIRECTORY config/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/config)

# Install all the executable nodes
catkin_install_python(
  PROGRAMS
    nodes/pinger_visualization.py
    nodes/set_pinger_position.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
