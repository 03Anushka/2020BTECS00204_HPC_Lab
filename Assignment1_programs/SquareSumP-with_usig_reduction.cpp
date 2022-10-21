#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

static long long sum =0;
int main()
{
    double itime, ftime, exec_time;
	itime = omp_get_wtime();
	
    omp_set_num_threads(4);
    int sum=0;
    #pragma omp parallel 
     {
       int id=omp_get_thread_num();
       #pragma omp for reduction(+:sum)
        for(long long i=1; i<=100;i++)
        { 
         printf("\nThread No. %d Number : %d Square : %d", omp_get_thread_num(), i, i * i);  
		   sum+=i*i;
        }
      }

        printf("\nSum is %d  ", sum);
    
        ftime = omp_get_wtime();
        exec_time = (ftime - itime);
        printf("\nTime taken is %f\n", exec_time);
        return 0;
	
        
}