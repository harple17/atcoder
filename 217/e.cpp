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

/**
 * @brief 
 * クエリ3でいちいちソートしていたら、
 * 配列の要素数をO(n)として、一回につきO(nlogn)かかるので、
 * 全体ではO(n^2logn)となりTLE。
 * 
 * いちいちソートするのではなく、優先度つきキューで
 * ずっと大小関係を保っておけば、m個の要素を追加すると
 * クエリの順番によらずO(mlog(m+n))となる。
 * クエリ3の回数をq3とすると
 * m1+m2+...m_q3がクエリ1の回数で抑えられるので
 * クエリ1がQ/2、クエリ3がQ/2回でもO(Q/2+Q/2(logQ))
 * 結局全体ではO(QlogQ)。
 * 
 * イメージとしては、いちいちソートするとソート済みの列も含めて再度ソートするため計算量が多くなるが、
 * 優先度付きキューでは二分探索によりソート済みの列を利用するので計算量が削減できる。
 * →一個一個要素を追加し大小関係を利用するなら優先度付きキューがいい
 */

deque<ll> Q1;
priority_queue<ll, vector<ll>, greater<ll>> Q2;

void query1(ll x) {
    Q1.push_back(x);
}

void query2() {
    if (!Q2.empty()) {
        cout << Q2.top() << endl;
        Q2.pop();
    } else {
        cout << Q1.front() << endl;
        Q1.pop_front();
    }
}

void query3() {
    while (!Q1.empty()) {
        Q2.push(Q1.front());
        Q1.pop_front();
    }
}

int main() {
    int q;
    cin >> q;
    rep(i,q) {
        int query;
        cin >> query;
        if (query == 1) {
            ll x;
            cin >> x;
            query1(x);
        } else if (query == 2) {
            query2();
        } else {
            query3();
        }
    }
    return 0;
}