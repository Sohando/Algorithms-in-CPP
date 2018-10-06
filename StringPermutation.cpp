#include <bits/stdc++.h>
using namespace std;

map<char, int>Mp;
char Ans[100];

void reset() {
	Mp.clear();
	memset(Ans, '.', sizeof(Ans));
}
void backtrack(char str[], int depth, int length) {
	if(depth == length) {
		for(int i=0; i<length; i++) {
			printf("%c", Ans[i]);
		}
		printf("\n");
	}
	
	for(int i=0; i<length; i++) {
		if(Mp[str[i]] != 0) {
			Mp[str[i]]--;
			Ans[depth] = str[i];
			backtrack(str, depth+1, length);
			Mp[str[i]]++;
		}
	}
}
void backtrackhelper(char str[], int sz) {
	
	reset();
	char btr[100];
	
	for(int i=0; i<sz; i++) {
		Mp[str[i]]++;
	}
	
	int te= 0;
	for(auto c : Mp) {
		btr[te++] = c.first;
	}
	
	backtrack(btr, 0, sz);
}

int main(void) {
	char str[100];
	scanf("%s", &str);
	int sz = strlen(str);
	backtrackhelper(str, sz);
	return 0;
}
