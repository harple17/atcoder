//include libraries
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <valarray>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, ll>;
using T = pair<int, P>;

int main() {
    int n;
    cin >> n;
    vector<T> Arr(n);
    rep(i,n) cin >> Arr[i].first >> Arr[i].second.first >> Arr[i].second.second;
    sort(Arr.begin(), Arr.end());

    vector<vector<ll>> dp(n, vector<ll>(Arr[n-1].first+1));

    //i=0のみ先に処理
    for(int j=1; j<=Arr[n-1].first; j++) {
        //現在時間が期限を超えておらず、現在時間が所要時間以上の場合
        //最初のタスクを実行できる
        if (!(Arr[0].first < j || Arr[0].second.first > j)) dp[0][j] = Arr[0].second.second;
    }

    for(int i=1;i<n;i++) {
        for(int j=1; j<=Arr[n-1].first; j++) {
            //現在時間が期限を超えている、もしくは現在時間が所要時間より小さい場合は
            //i番目のタスクを実行できない
            if (Arr[i].first < j || Arr[i].second.first > j) dp[i][j] = dp[i-1][j];
            //i番目のタスクをとっていない場合、i番目のタスクをとっていた場合
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-Arr[i].second.first]+Arr[i].second.second);
        }
    }

    ll ans = 0;
    rep(i,Arr[n-1].first+1) ans = max(ans, dp[n-1][i]);

    cout << ans << endl;

    return 0;
}