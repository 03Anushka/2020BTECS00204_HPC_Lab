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
    int thread_id[4]; 
    #pragma omp parallel 
     {
       int id=omp_get_thread_num();
       thread_id[id]=0;
       #pragma omp for
        for(long long i=1; i<=100;i++)
        { 
         printf("\nThread No. %d Number : %d Square : %d", omp_get_thread_num(), i, i * i);  
		    thread_id[id] += i * i;
        }
      }
   for(int i=0;i<4;i++)
   {
   	sum+=thread_id[i];
   }
        printf("\nSum is %d  ", sum);
    
        ftime = omp_get_wtime();
        exec_time = (ftime - itime);
        printf("\nTime taken is %f\n", exec_time);
        return 0;
	
        
}