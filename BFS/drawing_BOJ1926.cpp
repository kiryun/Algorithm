#include <bits/stdc++.h>

using namespace std;

int n, m = 0;
bool** visit;
int** arr;

int cnt = 0; // 갯수
int s = 0; //넓이
int M = 0; //가장큰 넓이

//bfs를 위한 queue
queue<pair<int, int> > q;

//상화좌우 네방향
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs()
{
    //전체를 돈다.
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            //시작점을 찾는다. i, j가 방문한 곳이거나 0이면 그냥 넘어감
            if(visit[i][j] or arr[i][j] == 0){
                continue;
            }
            //i, j를 시작점으로 하는 bfs탐색 시작
            //넓이 초기화
            //갯수 1증가
            s = 0;
            cnt++;
            
            //방문 표시, q에다 넣기
            visit[i][j] = true;
            q.push(make_pair(i, j));

            while(!q.empty()){
                pair<int, int> temp = q.front();
                q.pop();
                //넓이 증가
                s++;
                //4방향을 검사한다.(top, bottom, left, right)
                for(int k = 0; k<4; k++){
                    int x  = temp.first;
                    int y = temp.second;
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    
                    //범위 검사
                    if(nx < 0 or nx >=n or ny < 0 or ny >= m){
                        continue;
                    }
                    if(arr[nx][ny] != 1 or visit[nx][ny]){
                        continue;
                    }
                    visit[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }

            if(s > M){
                M = s;
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    int a = 0;
    arr = new int*[n];
    visit = new bool*[n];

    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
        visit[i] = new bool[m];
        for(int j = 0; j< m; j++){

            cin>>arr[i][j];
        }
    }
    // cout<<endl;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout<<arr[i][j];
    //     }
    //     cout<<endl;

    // }
    bfs();
    cout<<cnt<<"\n";
    cout<<M<<"\n";
    
    return 0;
}