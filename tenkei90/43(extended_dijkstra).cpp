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

const int INF = 10000000;

const int dr[4] = {1, 0, -1, 0};
const int dc[4] = {0, 1, 0, -1};

struct State {
    int r, c, dir;
};

int main() {
    int h, w, rs, cs, rt, ct;
    cin >> h >> w;
    cin >> rs >> cs;
    cin >> rt >> ct;
    rs--; cs--;
    rt--; ct--;
    vector<string> S(h);
    rep(i, h) cin >> S[i];

    deque<State> Dq;

    vector<vector<vector<int>>> dist(h, vector<vector<int>>(w, vector<int>(4, INF)));

    rep(i, 4) {
        dist[rs][cs][i] = 0;
        Dq.push_back({rs, cs, i});
    }

    while (!Dq.empty()) {
        State st = Dq.front(); Dq.pop_front();
        rep(i ,4) {
            int pr = st.r + dr[i], pc = st.c + dc[i], co = dist[st.r][st.c][st.dir] + (st.dir != i ? 1 : 0);
            if (pr >= 0 && pr < h && pc >= 0 && pc < w && S[pr][pc] == '.' && co < dist[pr][pc][i]) {
                dist[pr][pc][i] = co;
                if (st.dir == i) Dq.push_front({pr, pc, i});
                else Dq.push_back({pr, pc, i});
            }
        }
    }

    int ans = INF;
    rep(i, 4) ans = min(ans, dist[rt][ct][i]);
    cout << ans << endl;
    return 0;
}