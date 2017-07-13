cmake_minimum_required(VERSION 2.8)
project( odewithcmake )

include_directories ("${PROJECT_SOURCE_DIR}/Include")
include_directories ("${PROJECT_SOURCE_DIR}/Utils/Include")
include_directories ("${PROJECT_SOURCE_DIR}/Utils/src")
include_directories ("${PROJECT_SOURCE_DIR}/eigen")
include_directories("/usr/local/include")
include_directories("/home/spacemaster09/ode-0.12/ode/src/joints")

link_directories ("${PROJECT_SOURCE_DIR}/Utils/src")


link_directories("/usr/local/lib")

add_library( main ControlPBP.cpp  UnityOde.cpp )


target_link_libraries( main ode lib )
