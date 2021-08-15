#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int ans = 0;
    rep(i,h-1)rep(j,w-1) {
        int count = 0;
        for(int k=i;k<i+2;k++) {
            for(int l=j;l<j+2;l++) {
                if(s[k][l] == '#') count++;
            }
        }
        if(count == 1 || count == 3) ans++;
    }
    cout << ans << endl;
    return 0;
}