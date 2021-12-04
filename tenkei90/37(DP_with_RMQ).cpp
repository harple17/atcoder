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
using P = pair<int, int>;

class segment_tree {
    private:
        int size;
        vector<ll> seg, lazy;
        void lazy_eval(int k) {
            if (k < size) {
                lazy[k * 2] = max(lazy[k * 2], lazy[k]);
                lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
            }
            seg[k] = max(seg[k], lazy[k]);
            lazy[k] = -1;
        }
        /**
         * @brief ある区間のセグ木を更新
         * 
         * @param a 操作したい区間の左端
         * @param b 操作したい区間の右端
         * @param x 更新する値
         * @param k 現在見ているノード
         * @param l ノードkが集約している値の左端
         * @param r ノードkが集約している値の右端
         */
        void update(int a, int b, ll x, int k, int l, int r) {
            lazy_eval(k);
            if (r <= a || b <= l) return;
            if (a <= l && r <= b) {
                lazy[k] = x;
                lazy_eval(k);
                return;
            }
            update(a, b, x, 2 * k, l, (l + r) / 2);
            update(a, b, x, 2 * k + 1, (l + r) / 2, r);
            seg[k] = max(seg[2 * k], seg[2 * k + 1]);
        }
        /**
         * @brief ある区間の範囲の最大値を返す
         * 
         * @param a 操作したい区間の左端
         * @param b 操作したい区間の右端
         * @param k 現在見ているノード
         * @param l ノードkが集約している値の左端
         * @param r ノードkが集約している値の右端
         * @return int 区間[a,b)の最大値
         */
        ll range_max(int a, int b, int k, int l, int r) {
            lazy_eval(k);
            if (r <= a || b <= l) return -1;
            if (a <= l && r <= b) return seg[k];
            ll lc = range_max(a, b, k * 2, l, (l + r) / 2);
            ll rc = range_max(a, b, k * 2 + 1, (l + r) / 2, r);
            return max(lc, rc);
        }

    public:
        segment_tree(): size(0), seg(), lazy() {};
        segment_tree(int n) {
            size = 1;
            while (size < n) {
                size *= 2;
            }
            seg = vector<ll>(size * 2, -1);
            lazy = vector<ll>(size * 2, -1);
        }
        void update(int l, int r, ll x) {
            update(l, r, x, 1, 0, size);
        }
        ll range_max(int l, int r) {
            return range_max(l, r, 1, 0, size);
        }
    };

int main() {
    int w, n;
    cin >> w >> n;
    vector<segment_tree> segs;
    rep(i, n + 2) segs.push_back(segment_tree(w + 2));

    vector<int> L, R, V;
    //dummy to avoid arg0
    L.push_back(0),
    R.push_back(0);
    V.push_back(0);

    rep(i, n) {
        int l, r, v;
        cin >> l >> r >> v;
        L.push_back(l);
        R.push_back(r);
        V.push_back(v);
    }

    vector<vector<ll>> dp(n + 10, vector<ll>(w + 10, -1));

    dp[0][0] = 0;
    segs[0].update(0, 1, 0);

    for (int i = 1; i <= n; i++) {
        //これを先にしておかないと、
        //後のif文の評価式がval == -1のとき
        //更新を引き継がない部分ができてしまう
        for (int j = 0; j<= w; j++) dp[i][j] = dp[i-1][j];

        for (int j = 0; j <= w; j++) {
            int rangeL = max(0, j - R[i]);
            int rangeR = max(0, j - L[i] + 1);
            if (rangeL == rangeR) continue;
            ll val = segs[i-1].range_max(rangeL, rangeR);
            if (val != -1) {
                dp[i][j] = max(dp[i][j], val + V[i]);
            }
            //cout << "(" << i << "," << j << "):" << dp[i][j] << endl;
            
        }
        for (int j = 0; j <= w; j++) segs[i].update(j, j+1, dp[i][j]);
    }
    cout << dp[n][w] << endl;
    //cout << "debug: segs[3].range_max(2999,3100): " << segs[1].range_max(3000,3000) << endl;
    return 0;
}