#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void bubbleSort(int a[], int n)
{
    int temp, flag, i, j;
    for(i=0; i<n-1; i++)
    {
        flag=0;
        for(j=0; j<n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
}
int main()
{
    int a[100000], n, i;
    long int t1, t2;
    // clock_t t1, t2;
    struct timeval ts, tz;
    printf("Enter the length: ");
    scanf("%d", &n);
    // srand(time(0));
    for(i=0; i<n; i++)
    {
        // a[i] = rand() % 1000;
        // a[i] = i;
        a[i] = n-i;
    }
    printf("\n");
    gettimeofday(&ts, &tz);
    // t1 = current_timestamp();
    t1 = ts.tv_usec;
    // t1 = clock();
    bubbleSort(a, n);
    // t2 = clock();
    gettimeofday(&ts, &tz);
    t2 = ts.tv_usec;
    // t2 = current_timestamp();
    for(i=0; i<n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\nTime: %ld", t2-t1);
    // float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000; 
    // printf("\nTime: %f", diff);
    return 0;
}