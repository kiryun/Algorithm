#include <bits/stdc++.h>

using namespace std;


// 정수 배열(int array)가 주어지면 가장 큰 이어지는 원소들의 합을 구하시오. 단, 시간복잡도는 O(n).
// Given an integer array, find the largest consecutive sum of elements.

// 예제)
// Input: [-1, 3, -1, 5]
// Output: 7 // 3 + (-1) + 5

// Input: [-5, -3, -1]
// Output: -1 // -1

// Input: [2, 4, -2, -3, 8]
// Output: 9 // 2 + 4 + (-2) + (-3) + 8


int n = 0;

int solution(int* arr, int n){
    int maxSum = arr[0];
    int currentSum = arr[0];


    for(int i = 0; i < n; i++){
        currentSum = max(currentSum+arr[i], arr[i]);
        maxSum = max(currentSum, maxSum);
    }

    return maxSum;

}

int main()
{
    int* arr;
    cin>>n;
    arr = new int[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    // for(int i = 0; i<n; i++){
    //     cout<<arr[i];
    // }
    cout<<solution(arr, n)<<endl;

    
    return 0;
}