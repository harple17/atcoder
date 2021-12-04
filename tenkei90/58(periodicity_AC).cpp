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
    //余りを考える場合
    //特に周期性に注意
    //TLEしそうでも結局大きな数は考えなくていい場合が多い
    //あまり以外でも普通にループ回せないときは注意
    const int MOD = 100000;
    int n;
    ll k;
    cin >> n >> k;
    vector<vector<int>> visC(MOD,vector<int>(2, -1));
    //visC-> visit count --- vis[i][0]は最初iに訪れたときのカウント
    // visC[i][1]は2度目に訪れた時のカウント
    int z = n;
    visC[z][0] = 0;

    for (int i = 1; i < MOD; i++) {
        int x = z, y = 0;
        while (x > 0) {
            y += (x % 10);
            x /= 10;
        }
        z = (z + y) % MOD;
        if (visC[z][0] != -1) {
            visC[z][1] = i;
            break;
        }
        else visC[z][0] = i;
        //cout << z << endl;
    }

    // 周期
    ll period = (ll)(visC[z][1] - visC[z][0]);
    // 周回的遷移後のあまり

    //ここから
	if (k >= visC[z][0]) {
		k = (k - visC[z][0]) % period + visC[z][0];
	}

	int answer = -1;
	for (int i = 0; i < MOD; ++i) {
		if (visC[i][0] == k) {
			answer = i;
		}
	}
    //ここまでがACの肝
    //なんやけどなんでやねんなんでこれならあうんや一緒やろ!!

    cout << answer << endl;
    
    return 0;
}