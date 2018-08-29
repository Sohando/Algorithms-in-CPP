#include<bits/stdc++.h>
using namespace std;

int partition( int arr[], int start, int end ) {
	int pivot = arr[ start ];
	int i = start+1;
	
	for( int j=start+1;j<=end; j++ ) {
		if( arr[j] < pivot ) {
			swap( arr[ j ], arr[ i ] );
			i++;
		}
	}
	swap( arr[ i-1 ], arr[ start ] );
	return i-1;
}

int rand_partition( int arr[], int start, int end ) {
	int _rand = start + rand() % (end-start+1);
	swap( arr[ start ], arr[ _rand ] );
	return partition( arr, start, end );
}

void quick( int arr[], int start, int end ) {
	if( start < end ) {
		int pivot = rand_partition( arr, start, end );
		quick( arr, start, pivot-1 );
		quick( arr, pivot+1, end );
		
	}
}

int main() {
	
	int n;
	cin >> n;
	
	int arr[ n ];
	for( int i=0; i < n; i++ ) {
		cin >> arr[ i ];
	}
	
	quick( arr, 0, n-1 );
	
	for( int i=0; i < n; i++ ) {
		cout << arr[ i ] << " ";
	}
	return 0;
}
