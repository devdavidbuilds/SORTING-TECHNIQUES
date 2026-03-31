#include <iostream>
using namespace std;
int main(){

    int arr[] = {5,3,6,8,7};
    int i,j;
    int n=5;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"";
    }

    
}