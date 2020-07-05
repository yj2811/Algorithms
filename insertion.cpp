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
        for(i=1; i<size; i++){
            temp = arr[i];
            j = i-1;
            while(j>=0 && arr[j]>temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }

    } else{
        for(i=1; i<size; i++){
            temp = arr[i];
            j = i-1;
            while(j>=0 && arr[j]<temp){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }

    }
    cout<<"\nThe sorted array is:\n";
    for(i=0; i<size; i++){
        cout<<arr[i];
        cout<<"\n";
    }
}
