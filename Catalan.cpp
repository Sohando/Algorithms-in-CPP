#include <bits/stdc++.h>
using namespace std;
unsigned long int binomial(int n, int k) {            /// n*(n-1)*(n-2)*(n-k) / 1*2*3*k
      k = k > n - k ? n - k : k;
      unsigned long int ans = 1;
      for(int i = 0; i < k; i++) {
            ans *= (n - i);
            ans /= (i+1);
      }
      return ans;
}
unsigned long int solve(int n) {                     /// Cn = (1 / (n + 1)) * (2nCn)
      unsigned long int x = binomial(2*n, n);
      return x / (n + 1);
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
