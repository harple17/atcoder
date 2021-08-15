#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> a(h);
    rep(i,h) cin >> a[i];
    //自分も相手も最良の選択で動く->minimax法
    //dp[i][j]を(i,j)から動かしたときの最良の動かし方とすると
    //dp[h-1][w-1]=0としてこれを基準に降順に遷移すればよい
    //(最初dp[0][0]は計算しないとわからないが、dp[h-1][w-1]=0は確定している)
    vector<vector<int>> dp(h,vector<int>(w,0));
    auto f = [&](int y, int x) {
        if(x==0&&y==0) return 0;
        if(a[y][x]=='+') return 1;
        else return -1;
    };
    dp[h-1][w-1]=0;
    for(int i=h-1;i>=0;i--) {
        for(int j=w-1;j>=0;j--) {
            if(i==h-1&&j==w-1) continue;
            if((i+j)%2==0) {
                if(i<h-1&&j<w-1) dp[i][j] = max(dp[i+1][j]+f(i+1,j),dp[i][j+1]+f(i,j+1));
                else if(i<h-1) dp[i][j] = dp[i+1][j]+f(i+1,j);
                else dp[i][j] = dp[i][j+1]+f(i,j+1);
            } else {
                if(i<h-1&&j<w-1) dp[i][j] = min(dp[i+1][j]-f(i+1,j),dp[i][j+1]-f(i,j+1));
                else if(i<h-1) dp[i][j] = dp[i+1][j]-f(i+1,j);
                else dp[i][j] = dp[i][j+1]-f(i,j+1);
            }
        }
    }
    if(dp[0][0]>0) cout << "Takahashi" << endl;
    else if(dp[0][0]==0) cout << "Draw" << endl;
    else cout << "Aoki" << endl;
    return 0;
}