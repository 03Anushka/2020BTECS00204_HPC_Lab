#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

static long long sum =0;
int main()
{
    double itime, ftime, exec_time;
	itime = omp_get_wtime();
    int a[10],b[10],c[10];
    for(long long i=0;i<10;i++)
		  	{
		  		cin>>a[i]>>b[i];
			  }
          #pragma omp parallel 
     omp_set_num_threads(4);
          #pragma omp for                                                            
        {
		
		for(long long i=0; i<1000;i++)
        { 
		    c[i]=a[i] + b[i];
        }
    }
        for(int i=0;i<4;i++)
        {
        	printf("\nSum is %f ",c[i] ;
		}
        
    
        ftime = omp_get_wtime();
        exec_time = (ftime - itime);
        printf("\nTime taken is %f\n", exec_time);
        return 0;
}