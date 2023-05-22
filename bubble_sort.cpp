#include <iostream>
#include <omp.h>
using namespace std;
void printarr(int arr[],int len)
{
    for (int i=0;i<len; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[50];

    for(int i=0; i<50; i++){
        arr[i] = rand() % 100;
    }

    int N = sizeof(arr) / sizeof(arr[0]);
    printarr(arr,N);
    int first;
    double start_timer, end_timer;
    start_timer = omp_get_wtime();
    for (int i=0;i<N-1;i++)
    {
        first = i % 2;
        # pragma omp parallel for default(none),shared(arr,first,N)
        for (int j=first;j<N-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    end_timer = omp_get_wtime();

    cout<<endl;
    printarr(arr,N);
    cout<<"TotalTime: "<<(end_timer - start_timer);
    return 0;

}