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
#define rep(i, n) for (int i=0; i < (n); i++)
#define rep1(i, n, w) for (int i=0; i < (n); i+=j)
#define rep2(i, n, w) for (int i=(n); i > 0; i-=j)
#define rep3(i, s, e, j) for (int i=s; i < (e); i += j)
using ll = long long;
using P = pair<int, int>;

int main() {
    // 変な制約に注目
    // 今回のh <= 8はbit全探索をしても2^8 = 256 
    int h, w;
    cin >> h >> w;
    vector<vector<int>> P(h , vector<int>(w));
    rep(i, h)rep(j, w) cin >> P[i][j];

    vector<int> rows, nums;
    int ans = 0;
    rep(i, 1 << h) {
        rows.clear();
        nums.clear();
        rep(j, h) {
            // bit全探索で使う行を探索
            if (1 << j & i) rows.push_back(j);
        }
        // 一つも選んでないとき
        if (rows.size() == 0) continue;
        // 同じ数字が書かれていない列を排除
        vector<bool> flag(w, true);
        rep(k, w) {
            // 一つだけ選んでいるとき
            if (rows.size() == 1) nums.push_back(P[rows[0]][k]);
            // 二行以上の時
            rep(j, rows.size() - 1) {
                if (P[rows[j]][k] != P[rows[j + 1]][k]) flag[k] = false;
            }
        }
        rep(k, w) if(flag[k] && rows.size() > 1) nums.push_back(P[rows[0]][k]); 
        // numsの中で最も登場する数字を探索
        map<int, int> M;
        int max_f = 0;
        for (int k: nums) {
            M[k]++;
            max_f = max(M[k], max_f);
        }
        //cout << max_f << endl;
        ans = max(ans, (int)rows.size() * max_f);
    }
    cout << ans << endl;
    return 0;
}