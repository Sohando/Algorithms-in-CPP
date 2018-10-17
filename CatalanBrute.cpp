#include <bits/stdc++.h>
using namespace std;
unsigned long int solve(int n) {
      if(n <= 1) return 1;
      unsigned long int res = 0;
      for(int i = 0; i < n; i++) {
            res += solve(i) * solve(n - i - 1);
      }
      return res;
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
