#include <omp.h>
#include <iostream>
using namespace std;

void printarray(int arr[], int len){
    cout<<"Array: ";
    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void minOperation(int arr[], int len){
    int minValue = arr[0];

    # pragma omp parallel for reduction(min: minValue)
        for(int i=0; i<len; i++){
            minValue = min(minValue, arr[i]);
        }

        cout<<"Min value: "<<minValue<<endl;
}

void maxOperation(int arr[], int len){
    int maxValue = arr[0];

    # pragma omp parallel for reduction(max : maxValue)
        for(int i=0; i<len; i++){
            maxValue = max(maxValue, arr[i]);
        }

        cout<<"Max value: "<<maxValue<<endl;
}

void sumOperation(int arr[], int len){
    int sum = 0;

    # pragma omp parallel for reduction(+ : sum)
        for(int i=0; i<len; i++){
            sum += arr[i];
        }
    cout<<"Sum: "<<sum<<endl;
}

void avgOperation(int arr[], int len){
    float sum = 0;

    # pragma omp parallel for reduction(+ : sum)
    for(int i=0; i<len; i++){
        sum += arr[i];
    }

    cout<<"Average: "<<sum/len<<endl;
}

int main(){
    int arr[50];
    
    for(int i=0; i<50; i++){
        arr[i] = rand()%100;
    }

    printarray(arr, 50);

    minOperation(arr, 50);
    maxOperation(arr, 50);
    sumOperation(arr, 50);
    avgOperation(arr, 50);

    return 0;
}