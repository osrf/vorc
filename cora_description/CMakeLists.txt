cmake_minimum_required(VERSION 3.0.2)
project(cora_description)

find_package(catkin REQUIRED COMPONENTS
  wamv_gazebo
  xacro
)

catkin_package(
  CATKIN_DEPENDS xacro
)

xacro_add_files(
  urdf/cora.urdf.xacro
    INORDER INSTALL DESTINATION urdf
)

install(DIRECTORY models/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/models
)

install(DIRECTORY urdf/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/urdf
)
