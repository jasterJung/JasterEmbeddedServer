#include <stdio.h>
#include <string.h>
#include "thread/TaskManager.h"


int main(int argc, char *argv[])
{
	printf("Starting..\n");

	//Need to Context struct.
	TaskManager* work = TaskManager::getInstance();
	work->openingPreparation(100);
	work->open();

	//pthread_cond_signal(&mycond[mi->second.index_num]);


	int key = 0;
	while(1)
	{
		Task job;
		printf("input the key\n");
		scanf("%d", &key);
		if(key == 9)
		{

			goto exit;

		}
		else //action someting
		{
			job.testTest = 1;
			work->doTesk(job);
		}
	}


exit:
	printf("End..\n");

	//add Thread 

	delete work;

	return 0;
}
