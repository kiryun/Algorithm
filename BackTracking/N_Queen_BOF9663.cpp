#include <iostream>
#include <math.h>

using namespace std;

int N=0;
int arr[14]= {-1,}; // arr[i] = j는 i, j에 퀸을 놓는다 라는 것을 의미한다.
int cnt = 0;

//열과 대각선상에 존재하는지 여부를 판단
bool promise(int level){
    //이전에 놓았던 퀸들의 위치 ~ 현재 놓을 위치의 열까지 순회
    for(int i = 0; i<level; i++){
        //열에 존재한다면
        if(arr[i] == arr[level]){
            return false;
        }
        //대각선 상에서 같은 위치에 잇는지
        if(level-i == abs(arr[level] - arr[i])){
            return false;
        }
    }
    //모두다 통과하면 놓아도 되는 위치라는 의미로 true를 return한다.
    return true;
}

//현재 어디까지 왔는지(열의 위치)
void dfs(int level)
{
    //level이 N보다 크거나 같다는 것은 무사히 퀸을 잘 놓고 왔다는 뜻이다.
    //무사히 재귀를 다돌았으면 cnt++해준다.
    if(level >= N){
        cnt++;
        return;
    }

    //각 열마다 행을 돌면서 검사한다.
    for(int i = 0; i<N; i++){
        //현재 level에서 놓을 수 있는 곳이 있는가?
        if(!promise(level)){
            return;
        }
        arr[level+1] = i;
        dfs(level+1);
        arr[level+1] = -1;

    }
}

int main()
{
    int level = 0;
    cin>>N;

    dfs(level);
    cout<<cnt<<endl;
    return 0;
}