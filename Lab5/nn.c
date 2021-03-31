/*nn.c*/

#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(){
    struct timeval t1, t2;
	double elapsedTime;
    int n = 10;
    FILE *results = fopen("results_nn.txt", "w");

    for( int k = 0 ; k < 15 ; k++){

        gettimeofday(&t1, NULL);
        int in = 5;
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n; j++){
                in++;
            }
        }
        gettimeofday(&t2, NULL);

        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
        printf("Total time taken for general n^2 procedure for n = %d is %f ms.\n\n", n, elapsedTime);
        fprintf(results, "Total time taken for general n^2 procedure for n = %d is %f ms.\n\n", n, elapsedTime);
        
        if (n < 10000) 
        {
            n *= 10;
        }
        else if (n >= 30000)
        {
            return 0;
        }
        else 
        {
            n += 10000;
        } 
    }

    fclose(results);
    return 0;

}