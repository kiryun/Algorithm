#include <queue>
#include <iostream>
#include <utility>


using namespace std;

int n, m = 0;
int maze[100][100] = {
    -1,

    };

//거리를 저장하는 변수
int dist[100][100] = {
    -1,
    };

queue<pair<int,int> > q;
// bool visit[100][100] = {
//     {false, },
//     };

//4방향
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs()
{   
    dist[0][0] = 1;
    q.push(make_pair(0, 0));

    while(!q.empty()){
        
        pair<int, int> temp = q.front();
        q.pop();

        //4방향 검사
        for(int i = 0; i<4; i++){
            int nx = temp.first + dx[i];
            int ny = temp.second + dy[i];
            // cout<<nx<<" "<<ny<<endl;

            //nx, ny가 범위를 넘어서거나 
            //dist[nx][ny]가 -1이 아니거나(이미 방문을 했다면) 
            //maze[nx][ny]가 1이 아니라면 넘어간다.
            if(nx < 0 or nx >= n or ny < 0 or ny >=m){
                continue;
            }
            if(dist[nx][ny] != -1 or maze[nx][ny] != 1){
                continue;
            }
            

            dist[nx][ny] = dist[temp.first][temp.second] + 1;
            if(nx == n and ny == m){
                return;
            }
            // cout<<dist[nx][ny]<<endl;
            q.push(make_pair(nx, ny));
        }


    }

}


int main()
{
    cin>>n>>m;
    string s;
    for(int i = 0; i<n; i++){
        cin>>s;
        for(int j = 0; j<m; j++){
            maze[i][j] = s[j]-48;
            dist[i][j] = -1;
        }
    }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<maze[i][j];
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<dist[i][j];
    //     }
    //     cout<<endl;
    // }

    bfs();
    // for(int i = 0; i<n; i++){
    //     for(int j = 0; j<m; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dist[n-1][m-1]<<endl;


    return 0;
}