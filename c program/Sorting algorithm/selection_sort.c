#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void selection_sort(int a[], int n)
{
    int i, j, max, temp;
    for(i=0; i<n-1; i++)
    {
        max = 0;
        for(j=0; j<n-i; j++)
        {
            if(a[max] < a[j])
            {
                max = j;
            }
        }
        if(max != j-1) 
        {
            temp = a[max];
            a[max] = a[j-1];
            a[j-1] = temp;
        }
    }
}

int main() 
{
    int a[100000], n, i, j, t1, t2;
    struct timeval tv;
    struct timeval tz;
    printf("Enter the length: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        a[i] = rand() % 1000;
    }   
    gettimeofday(&tv, &tz);
    t1 = tv.tv_usec;
    selection_sort(a, n);
    gettimeofday(&tv, &tz);
    t2 = tv.tv_usec;
    for(i=0; i<n; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("\nTime: ", t2-t1);
    return 0;
}