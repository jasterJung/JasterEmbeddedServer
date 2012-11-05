#include_directories(include)
#include_directories(../../../fmb_driver)
#include_directoraies(util)

include_directories(./)

set(_SRC 
TaskManager.cpp
CommonSocketThread.cpp
ScopeMutex.cpp
condition.cpp
Thread.cpp
)

ADD_LIBRARY( networkBase STATIC ThreadPool.cpp ${_SRC})
#USBEvent.h
#USBEvent.cpp
#util/Debug.c
#util/Utility.c
#util/Runnable.h
#util/Thread.h
#cmd/FmbCmd.c
#cmd/FmbCmdTbl.c
#com/FmbComDriver.c
#com/FmbComplayer.c
#com/FmbComStream.c
#com/FmbComRecv.c
#com/FmbComFile.c
#ControllerH58.cpp
#sce/FmbAp.c
#sce/FmbScenario.c
#sce/FmbSceWait.c
#)



