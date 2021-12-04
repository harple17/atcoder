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

int main() {
    //半分全列挙→要素を半分にしてそれぞれ全探索
    //結果をうまく結合する手法
    //今回のような選ぶ・選ばないの指数オーダーの時は指数部が半分になり
    //ループ数が多いときループ数が半減する、という使い方がある
    int n, k;
    ll p;
    cin >> n >> k >> p;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    vector<vector<ll>> Arr1(n+10);
    vector<vector<ll>> Arr2(n+10);
    int mid =  n / 2;
    for (int i = 0; i < (1<<mid); i++) {
        ll val = 0;
        int NofG = 0;
        for (int j = 0; j < mid; j++) {
            if (i & (1 << j)) {
                val += a[j];
                NofG++;
            }
        }
        Arr1[NofG].push_back(val);
    }

    for (int i = 0; i < (1 << (n-mid)); i++) {
        ll val = 0;
        int NofG = 0;
        for (int j = 0; j < n - mid; j++) {
            if (i & (1 << j)) {
                val += a[mid + j];
                NofG++;
            }
        }
        Arr2[NofG].push_back(val);
    }
    //debug
    //cout << "ok" << endl;

    //Arr1,2のidxは選ぶ個数なので0からnまでであることに注意
    for(int i=0; i <= n; i++) {
        sort(Arr1[i].begin(), Arr1[i].end());
        sort(Arr2[i].begin(), Arr2[i].end());
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < (int)Arr1[i].size(); j++) {
            ll possible_combi = lower_bound(Arr2[k - i].begin(), Arr2[k - i].end(), p - Arr1[i][j] + 1) - Arr2[k - i].begin();
            ans += possible_combi;
        }
    }
    cout << ans << endl;

    return 0;
}