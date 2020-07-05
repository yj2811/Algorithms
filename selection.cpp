#include<iostream>

using namespace std;

int main(){
    int arr[100],size, i, j, min, max, pos, temp;
    string k;
    cout<<"\nEnter the size of the array:\n";
    cin>>size;

    cout<<"\nEnter the elements of the array:\n";
    for(i=0; i<size; i++){
        cin>>arr[i];
    }


    cout<<"\nEnter A for ascending sort and D for descending sort:\n";
    cin>>k;

    if(k == "A"){

    for(i=0; i<size-1; i++){

        min = arr[i];
        pos = i;
        for(j=i+1; j<size; j++){
            if (arr[j]<min){
                min = arr[j];
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
} else {
    for(i=0; i<size-1; i++){

        max = arr[i];
        pos = i;
        for(j=i+1; j<size; j++){
            if (arr[j]>max){
                max = arr[j];
                pos = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

    cout<<"\nThe sorted array is:\n";
    for(i=0; i<size; i++){
        cout<<arr[i];
        cout<<"\n";
    }
}
