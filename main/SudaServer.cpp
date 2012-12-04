#include <stdio.h>
#include <string.h>
#include "thread/TaskManager.h"
#include "INIReader.h"


int main(int argc, char *argv[])
{
	printf("Get_Config..\n");
	INIReader cfg("server.cfg");
	int _port = cfg.GetInteger("udp_server","port",0);

	printf("Starting..%d\n" , _port);


	//Need to Context struct.
	jThread::TaskManager* work = jThread::TaskManager::getInstance();
	work->openingPreparation(10);
	work->open();

	//pthread_cond_signal(&mycond[mi->second.index_num]);


	int key = 0;
	while(1)
	{
		jThread::Task job;
		printf("input the key\n");
		scanf("%d", &key);
		if(key == 9)
		{

			goto exit;

		}
		else //action someting
		{
			work->doTesk(job);
		}
	}

exit:
	printf("End..\n");

	//add Thread 

	delete work;

	return 0;
}

