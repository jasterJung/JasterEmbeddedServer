#INCLUDE_DIRECTORIES(../network)




include_directories (../network)
#libNetworkBase.a
#set 
#../network/ThreadPool.h 
#./SudaServer.cpp)

# Make sure the linker can find the Hello library once it is built. 
link_directories (../network) 


add_executable (tt SudaServer.cpp)

TARGET_LINK_LIBRARIES(
tt
networkBase
pthread
)

message("--Using these parameters : ${CMAKE_CXX_FLAGS}")


#set_target_properties(ControllerWrapper PROPERTIES LINK_FLAGS "-static")

