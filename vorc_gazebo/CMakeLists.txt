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

# Generate world files from xacro and install
xacro_add_files(
  worlds/marina.world.xacro
  worlds/perception_task.world.xacro
  INORDER INSTALL DESTINATION worlds
)

# Install all the world files
install(DIRECTORY worlds/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/worlds)

# Install all the model files
install(DIRECTORY models/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/models)

# Install all the launch files
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch)

# Install all the config files
install(DIRECTORY config/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/config)
