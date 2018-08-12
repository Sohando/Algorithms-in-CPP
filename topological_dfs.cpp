#include<bits/stdc++.h>
using namespace std;

vector< int > V[100];
bool visited[100] = {false};
stack< int > st;

void topo(  int s ) {
    visited[s] = true;

    for( int i=0;i<V[s].size();i++ ) {
        if( !visited[V[s][i]] ) {
            topo(V[s][i]);
        }
    }
    st.push(s);
}

int main() {

    int n,m;
    int x,y;

    cin >> n >> m;


    for( int i=0;i<m;i++ ) {
        cin >> x >> y;
        V[x].push_back(y);
    }



    for( int i=1;i<=n;i++ ) {
        if( !visited[i] ) {
            topo( i );
        }
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return 0;
}
