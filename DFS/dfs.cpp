#include <bits/stdc++.h>

using namespace std;

//n: node의 갯수
//c: checked의 약자 방문했는지 확인용 변수
//a: node
int n = 7;
bool c[7];
vector<int> a[7];

void dfs(int x){
    //x를 방문했는지 확인
    if(c[x]){
        //방문했다면 return
        return;
    }
    //방문처리해준다.
    c[x] = true;
    cout<<x<<" ";
    //x기준(최상단 노드)에서 인접노드 중 방문해본다.(재귀)
    for(int i = 0; i<a[x].size(); i++){
        int y = a[x][i];
        dfs(y);
    }

}

int main()
{
    //vector<int> a;
    //a[0].push_back(1): a의 0번째 index에 1을 추가하는 것
    //0->1,2
    a[0].push_back(1);
    a[0].push_back(2);
    
    //1->0,2,3,4
    a[1].push_back(0);
    a[1].push_back(2);
    a[1].push_back(3);
    a[1].push_back(4);

    a[2].push_back(0);
    a[2].push_back(1);
    a[2].push_back(5);
    a[2].push_back(6);

    a[3].push_back(1);
    a[3].push_back(4);

    a[4].push_back(1);
    a[4].push_back(3);

    a[5].push_back(2);
    a[5].push_back(6);

    a[6].push_back(2);
    a[6].push_back(5);

    dfs(0);
    
    return 0;
}