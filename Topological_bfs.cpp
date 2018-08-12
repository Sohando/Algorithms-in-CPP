#include <iostream>
#include<queue>
using namespace std;

vector<int>V[100];
bool visited[100]={false};
int indegree[100]={0};

void topo( int so ) {

      priority_queue< int, vector< int >, greater<int> > q;
      q.push(so);

      while( !q.empty() ) {
          int u = q.top();
          q.pop();
          visited[u] = true;
          cout << u << " ";

          for( int i=0;i<V[u].size();i++ ) {
              indegree[ V[u][i] ]--;
              if( indegree[ V[u][i] ]==0 ) {
                  q.push( V[u][i] );
              }
          }
      }
}

int main() {
  int n,m;
  cin>>n>>m;

  while(m--) {
    int x,y;
    cin>>x>>y;
    V[x].push_back(y);
    indegree[y]=indegree[y]+1;
  }
// if not lexographically
  for(int i=1;i<=n;i++) {
    if(indegree[i]==0&&visited[i]==false) {
        topo(i);
    }
  }
// if lexographically 
/*
for(int i=1;i<=n;i++) {
  if(indegree[i]==0) {
      q.push(i);
  }
}
topo(number of element);
*/
  return 0;
}
