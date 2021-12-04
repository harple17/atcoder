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

char c[20][20];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool vst[20][20];
int h,w;

int dfs(int sx, int sy, int px, int py) {
    if (sx == px && sy == py && vst[px][py]) return 0;
    vst[px][py] = true;

    //retの値が十分小さくないと，
    //一周できなかった場合ret += 1が移動可能マス分続くので
    //求めたい場合より大きくなる可能性がある
    //ret = -10だとh * w = 16に耐え切れずにWAする
    int ret = -20;
    rep(i, 4) {
        int nx = px + dx[i], ny = py + dy[i];
        if (nx < 0 || ny < 0 || nx >= h || ny >= w || c[nx][ny] == '#') continue;
        if ((nx != sx || ny != sy) && vst[nx][ny]) continue;
        //if (vst[nx][ny]) continue;//ではWA
        //start位置に行こうとしているのにcontinueしちゃうと再帰がおかしくなる
        ret = max(ret, dfs(sx, sy, nx, ny) + 1);
    }
    vst[px][py] = false;
    return ret; 
}

int main() {
    cin >> h >> w;
    rep(i, h)rep(j, w) {
        cin >> c[i][j];
    }

    int ans = -1;
    rep(i, h)rep(j, w) {
        ans = max(ans, dfs(i, j, i, j));
    }
    if (ans < 3) ans = -1;
    cout << ans << endl;
    return 0;
}