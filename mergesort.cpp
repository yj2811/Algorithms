#include<iostream>

using namespace std;

void mergeSort(int arr[], int, int);
void merge(int arr[], int, int, int);

int main(){
    int arr[100],size, i, j, lb, ub, mid;

    cout<<"\nEnter the size of the array:\n";
    cin>>size;

    cout<<"\nEnter the elements of the array:\n";
    for(i=0; i<size; i++){
        cin>>arr[i];
    }


    lb = 0;
    ub = size-1;

    mergeSort(arr, lb, ub);

    cout<<"\nThe sorted array is:\n";
    for(i=0; i<size; i++){
        cout<<arr[i];
        cout<<"\n";
    }
}

void mergeSort(int arr[], int lb, int ub){
    int mid;
    if(lb<ub){
        mid = (lb + ub)/2;
        mergeSort(arr, lb, mid);
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }

}

void merge(int arr[], int lb, int mid, int ub){
    int b[100];
    int i = lb;
    int j = mid+1;
    int k = lb;

    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            b[k] = arr[i];
            i++;
        }else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        while(j<=ub){
            b[k] = arr[j];
            j++;
            k++;
        }
    }else{
        while(i<=mid){
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=lb; k<=ub; k++){
        arr[k] = b[k];
    }
}
