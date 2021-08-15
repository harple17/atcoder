#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    //4桁->0000~9999の10000通り
    //->ループでそれぞれ条件満たすか確認すればよさそう
    string s;
    cin >> s;
    int ans = 0;
    rep(i,10000) {
        int x = i;
        vector<int> used(10); //数字jが使われたかどうか
        rep(j,10) {
            int id = x%10;
            used[id] = 1;
            x /= 10;
        }
        bool ok = true;
        rep(j,10) {
            if (s[j]=='x' && used[j]==1) ok = false;
            if (s[j]=='o' && used[j]==0) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}