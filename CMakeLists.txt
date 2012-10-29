cmake_minimum_required(VERSION 2.6)


#IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    # Mac OS X specific code
#    SET(OperatingSystem "Mac OS X")

#    IF(${CMAKE_SYSTEM_PROCESSOR } MATCHES "Intel")
        # Intel Mac OS X specific code
#        SET(Processor "Intel")
#    ENDIF(${CMAKE_SYSTEM_PROCESSOR } MATCHES "Intel")

#ENDIF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
MESSAGE("CMAKE_SYSTEM is ${CMAKE_SYSTEM} ${CMAKE_SYSTEM_NAME} ${CMAKE_SYSTEM_VERSION}") 




project(JASTERSE)
include(CMakeForceCompiler)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_SYSTEM_NAME Linux)
set(H5X_TOOLCHAIN arm-generic-linux-gnueabi-)

#when you complie to ARM, do free this comment.
#CMAKE_FORCE_C_COMPILER(${H5X_TOOLCHAIN}-gcc GNU)
#CMAKE_FORCE_CXX_COMPILER(${H5X_TOOLCHAIN}g++ GNU)
CMAKE_FORCE_CXX_COMPILER(g++ GNU)

set(CMAKE_STRIP ${H5X_TOOLCHAIN}strip)

#set(CMAKE_C_FLAGS "-O3 -g -Wall -c -fmessage-length=0 -MMD -MP -D_GNU_SOURCE -DVERSION=\"0.0.0.5\"")
# -C do commpile without linking
# -DTEST :: defined flag this will use in this source form USER 
set(CMAKE_CXX_FLAGS "-std=c++0x -g -D_REENTRANT -Wall -MMD- -DLOCALTEST=1 -D_GNU_SOURCE -DVERSION=\"0.0.0.5\"")
#set(CMAKE_CXX_FLAGS "-g -Wall -c -MMD- -D_GNU_SOURCE -DVERSION=\"0.0.0.5\"")

#set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "")

ADD_SUBDIRECTORY(tmp)

ADD_SUBDIRECTORY(network)
ADD_SUBDIRECTORY(main)

#http://www.cmake.org/Wiki/CMake_Useful_Variables

