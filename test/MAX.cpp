#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main()
{
    int T = 0;
    cin>>T;
    int a = 0;
    for(int i = 0; i<T; i++)
    {
        
        int M = 0;
        for(int j = 0; j<10; j++)
        {         
            cin>>a;
            if(M < a){
                M = a;
            }
        }
        q.push(M);
    }
    cout<<q.size();
    while(!q.empty()){
        int r = q.front();
        q.pop();
        cout<<"#"<<i<<" "<<r<<endl;
    }
    
    return 0;
}