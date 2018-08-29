#include<bits/stdc++.h>
using namespace std;

void Merge( int arr[], int start, int mid, int end ) {

    int temp[ end-start+1 ],k=0;
    int p = start, q = mid+1;

    for( int i=start;i<=end;i++ ) {
        if( p>mid ) {
            temp[ k++ ] = arr[ q++ ];
        }
        else if( q>end ) {
            temp[ k++ ] = arr[ p++ ];
        }
        else if( arr[p] < arr[q] ) {
            temp[ k++ ] = arr[ p++ ];
        }
        else {
            temp[ k++ ] = arr[q++ ];
        }
    }

    for( int i=0;i<k;i++ ) {
        arr[ start++ ] = temp[ i ];
    }
}

void MergeSort( int arr[], int start, int end ) {

    if( start < end ) {
        int mid = (start+end)/2;

        MergeSort( arr, start, mid );
        MergeSort( arr, mid+1, end );
        Merge( arr, start, mid, end );
    }
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for( int i=0;i<n;i++ ) {
        cin >> arr[i];
    }

    MergeSort( arr, 0, n-1 );

    for( int i=0;i<n;i++ ) {
        cout <<  arr[i] << " ";
    }

    return 0;
}
