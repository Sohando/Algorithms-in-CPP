#include <bits/stdc++.h>
using namespace std;
unsigned long int solve(int n) {
      unsigned long int catalan[n + 1];

      catalan[0] = catalan[1] = 1;
      for(int i = 2; i <= n; i++) {
            catalan[i] = 0;
            for(int j = 0; j < i; j++) {
                  catalan[i] += catalan[j] * catalan[i - j - 1];
            }
      }
      return catalan[n];
}
int main() {
      ios_base::sync_with_stdio(0), cin.tie(0);
      int n, Q = 1;
      while(cin >> n) {
            if(Q == 0) cout << endl;
            Q = 0;
            cout << solve(n) << endl;
      }
      return 0;
}
