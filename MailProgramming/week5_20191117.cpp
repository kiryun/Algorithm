#include <bits/stdc++.h>

using namespace std;

// 정수 배열과 타겟 숫자가 주어지면, 합이 타겟값이 되는 두 원소의 인덱스를 찾으시오.
// 단, 시간복잡도 O(n) 여야 합니다.
// Given an array of integers and a target integer, find two indexes of the array element that sums to the target number.

// 예제)
// Input: [2, 5, 6, 1, 10], 타겟 8
// Output: [0, 2] // 배열[0] + 배열[2] = 8

int N = 0;
int* arr;
int t = 0;

map<int, int> m;
vector<int> result;

int main()
{
    cin>>N;

    arr = new int[N];

    for(int i = 0; i<N; i++){
        cin>>arr[i];
        m.insert(make_pair(arr[i], i)); // hash map 생성
    }

    cin>>t;

    // for(int i = 0; i<N; i++){
    //     cout<<m[arr[i]]<<": "<<arr[i]<<" ";
    // }
    // cout<<endl;
    // cout<<t<<endl;

    for(int i = 0; i<N; i++){
        if(arr[i] > t){
            continue;
        }
        int temp = t - arr[i];
        
        map<int, int>::iterator it;
        it = m.find(temp);
        if( it == m.end() ){
            cout<<"cant not find "<<temp<<endl;
        }else{
            result.push_back(i);
            result.push_back(m[temp]);
            break;
        }
    }

    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}