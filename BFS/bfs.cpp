#include <bits/stdc++.h>

using namespace std;

//n: node의 갯수
//c: checked의 약자 방문했는지 확인용 변수
//a: node
int n = 7;
bool c[7];
vector<int> a[7];

void bfs(int start){
    queue<int> q;
    q.push(start);

    c[start] = true;
    //q가 비어있을 때 까지 반복
    while(!q.empty()){
        int x = q.front(); //q의 가장 앞부분을 리턴받는다.
        //q를 pop하고 이를 출력한다.
        q.pop();
        cout<<x;
        //현재 노드에서 인접한 부분이 방분했는지 검사한다.
        //x(q에서 pop한 노드)노드에 연결되어있는 노드 갯수만큼 반복문을 실행
        for(int i = 0; i<a[x].size(); i++){
            //y(연결되어있는 노드)중에 check가 안된(방문이 안된)노드가 있으면
            int y = a[x][i];
            if(!c[y]){
                //q에 삽입한다.
                q.push(y);
                //방문표시를 한다.
                c[y] = true;
            }
        }
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

    bfs(0);

    return 0;
}