cmake_minimum_required(VERSION 2.8)
project( odewithcmake )


set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++0x  -fmessage-length=0 ")



find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)



subdirs(main Utils)

include_directories ("${PROJECT_SOURCE_DIR}/Include")
include_directories ("${PROJECT_SOURCE_DIR}/Utils/Include")
include_directories ("${PROJECT_SOURCE_DIR}/eigen")

link_directories("/home/spacemaster09/makewithode/main")
link_directories("/usr/local/lib")
link_directories("/home/spacemaster09/makewithode/Utils/Src")



add_executable(odemake unit.cpp)

generate_messages(DEPENDENCIES std_msgs)


target_link_libraries( odemake  ode lib main )



