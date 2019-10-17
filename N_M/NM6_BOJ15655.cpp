#include <bits/stdc++.h>

using namespace std;

int n, m = 0;
int* arr;
bool* visit;

void Print()
{
    for(int i = 0; i<n; i++){
        if(visit[i]){
            cout<<arr[i]<<" ";
        }
    }
    cout<<"\n";
}

//idx: 배열 시작 위치, cnt: 현재 어디까지 왔는지
void nm(int idx, int cnt)
{  
    if(cnt == m){
        Print();
        return;
    }
    for(int i = idx; i<n; i++){
        if(visit[i]){
            continue;
        }else{
            visit[i] = true;
            nm(i, cnt+1);
            visit[i] = false;
        }
    }

}

int main()
{
    cin>>n>>m;

    arr = new int[n];
    visit = new bool[n];

    int a = 0;
    for(int i = 0; i<n; i++){
        cin>>a;
        arr[i] = a;
    }

    sort(arr, arr+n);

    nm(0, 0);


    return 0;
}