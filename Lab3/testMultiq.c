/*testMultiq.c*/

#include "multiq.h"
#include <sys/time.h>		//for gettimeofday() 

MultiQ loadData(FILE* f){
	MultiQ mq = createMQ(10);
	Task t;

	while(!feof(f)){

		fscanf(f,"%d,%d",&(t.tid),&(t.p));
		mq = addMQ(mq,t);
	};

	return mq;
}

MultiQ testDel(MultiQ mq, int num){
	for(int i=0;i<num;i++)
	{
		delNextMQ(mq);
	}
	return mq;
}

int main(){

	struct timeval t1, t2;
	double elapsedTime;
	int deleteNo=10000;
	
	// start timer
	gettimeofday(&t1, NULL);
	
	FILE* f = fopen("input10000.txt","r");
	MultiQ mq = loadData(f);
	fclose(f);

	// stop timer
	gettimeofday(&t2, NULL);
	
	// compute and print the elapsed time in millisec
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;			//sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;		//us to ms
	printf("Total time for loading is %f ms.\n",elapsedTime);

	// start timer
	gettimeofday(&t1, NULL);

	mq = testDel(mq,deleteNo);

	// stop timer
	gettimeofday(&t2, NULL);

	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;			//sec to ms
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;		//us to ms
	printf("Total time for %d deletions is %f ms.\n",deleteNo,elapsedTime);

	return 0;
}