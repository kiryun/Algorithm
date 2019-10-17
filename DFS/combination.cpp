//5개중에서 3개를 조합햇을 경우 나오는 경우의 수
#include <bits/stdc++.h>
#define MAX 5

using namespace std;

int arr[MAX];
bool select[MAX];

void Print()
{
    for(int i = 0; i < MAX; i++){
        if(select[i] == true){
            cout<<arr[i]<<" ";
        }
    }
    
    cout<<endl;
}

//idx: 시작점
//cnt: 현재 몇개 뽑았는지
void dfs(int idx, int cnt)
{
    if(cnt == 3){
        Print();
        return;
    }

    for(int i = idx; i < MAX; i++){
        if(select[i] == true){
            continue;
        }
        select[i] = true;
        dfs(i, cnt + 1);
        select[i] = false;
    }
}

int main(){
    for(int i = 0; i<5; i++){
        arr[i] = i+1;
    }
    dfs(0,0);
    return 0;
}