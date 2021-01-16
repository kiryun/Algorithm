// 정수 배열(int array)이 주어지면 두번째로 큰 값을 프린트하시오.
// Given an integer array, find the second largest element.

// 예제)
// Input: [10, 5, 4, 3, -1]
// Output: 5

// Input: [3, 3, 3]
// Output: Does not exist.

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int size = 0;
    int* arr;

    cin>>size;
    arr = new int[size];
    for(int i = 0; i<size; i++){
        cin>>arr[i];
    }

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }

    int max = arr[0];
    for(int i = 0; i<size; i++){
        if(i == size-1){
            
        }else{
            if(max < arr[i]){

            }
        }

    }

    return 0;
}