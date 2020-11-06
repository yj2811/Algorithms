#include<iostream>

using namespace std;

void QuickSort(int arr[], int l, int h);
int Partition(int arr[], int a, int b);
void Swap(int *c, int *d);

void QuickSort(int arr[], int l, int h) {
    int j;
// Spent 2 hours only to realise that this if statement was missing.
    if(l < h) {
        j = Partition(arr, l, h);
        QuickSort(arr, l, j);
        QuickSort(arr, j+1, h);
    }
}

int Partition(int arr[], int a, int b){
    int i, j;
    int pivot = arr[a];

    i = a;
    j = b;
    while(i<j){
        do{
            i++;
        }while(arr[i] <= pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i<j){
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[a], &arr[j]);
    return j;
}

void Swap(int *c, int *d){

    int temp = *c;
    *c = *d;
    *d = temp;
}

int main(){
    int n, i, x, y;

    cout << "Enter length of array:" << endl;
    cin >> n;

    int arr[n];

    cout << "Enter array elements:" << endl;
    for(i=0; i<n; i++){
        cin >> arr[i];
    }

    x = 0;
    y = n;

    QuickSort(arr, x, y);

    cout << "Sorted array elements:";

    for(i=0; i<n; i++){
        cout << arr[i] << endl;
    }

}
