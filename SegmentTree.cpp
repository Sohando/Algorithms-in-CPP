#include<bits/stdc++.h>
using namespace std;

#define mx 4*100005

int segment[mx];
void build( int arr[], int node, int start, int end ) {
    if( start==end ) {
        segment[node] = arr[start];
    }
    else {
        int mid = (start+end)/2;
        build( arr, 2*node, start, mid );
        build( arr, 2*node+1, mid+1, end );
        segment[node] = min( segment[2*node], segment[2*node+1] );
    }
}

int query( int node, int start, int end, int l, int r ) {

    if( l>end || r<start ) {
        return mx;
    }
    if( l<=start && r>=end ) {
        return segment[node];
    }
    int mid = (start+end)/2;
    int p1 = query( 2*node,start,mid,l,r );
    int p2 = query( 2*node+1,mid+1,end,l,r );

    return min(p1,p2);
}
int main() {

    int tes,cas=1;
    scanf("%d",&tes);

    while( tes-- ) {
        printf("Case %d:\n",cas++ );
        int n,q;
        scanf("%d%d",&n,&q);

        int arr[n+1];
        for( int i=1;i<=n;i++ ) {
            scanf("%d", &arr[i]);
        }
        build( arr, 1, 1, n );

        int l,r;
        while( q-- ) {
            scanf("%d%d", &l,&r);
            int foo = query( 1,1,n,l,r );
            printf("%d\n",foo );
        }
    }

    return 0;
}
