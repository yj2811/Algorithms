#include<iostream>

using namespace std;

int main(){
    int arr[100],size, i, j, min, max, pos, temp, swap;
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
            swap = 0;
            for(j=0; j<size-i-1; j++){
                if(arr[j+1]<arr[j]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    swap = 1;
                }
            }

            if (swap == 0){
                break;
            }

        }

    } else{
        for(i=0; i<size-1; i++){
            swap = 0;
            for(j=0; j<size-i-1; j++){
                if(arr[j+1]>arr[j]){
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;

                    swap = 1;
                }
            }

            if (swap == 0){
                break;
            }

        }
    }
    cout<<"\nThe sorted array is:\n";
    for(i=0; i<size; i++){
        cout<<arr[i];
        cout<<"\n";
    }
}
