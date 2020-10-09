cmake_minimum_required(VERSION 3.0.2)
project(vorc_gazebo)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} ${GAZEBO_CXX_FLAGS}")

find_package(gazebo REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  gazebo_dev
  vrx_gazebo
  wamv_gazebo
  wave_gazebo
  xacro
)

catkin_package(
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS
    gazebo_dev
    vrx_gazebo
    wamv_gazebo
    wave_gazebo
    xacro
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(vorc_scoring_plugin src/scoring_plugin.cc)
target_link_libraries(vorc_scoring_plugin ${catkin_LIBRARIES})

add_library(vorc_perception_scoring_plugin
  SHARED src/perception_scoring_plugin.cc)
target_link_libraries(vorc_perception_scoring_plugin
  ${catkin_LIBRARIES} vorc_scoring_plugin)

## Install ##

# Run xacro to generate world files
xacro_add_files(
  worlds/marina.world.xacro
  worlds/perception_task.world.xacro
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

install(TARGETS vorc_scoring_plugin
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS vorc_perception_scoring_plugin
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
