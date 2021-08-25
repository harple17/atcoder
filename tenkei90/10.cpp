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
    int n;
    cin >> n;
    vector<int> class1, class2;
    rep(i,n) {
        int c,p;
        cin >> c >> p;
        if (c==1) {
            class1.push_back(p);
            class2.push_back(0);
        } else {
            class1.push_back(0);
            class2.push_back(p);
        }
    }

    int q;
    cin >> q;
    vector<int> L(q), R(q);
    rep(i,q) {
        cin >> L[i] >> R[i];
        L[i]--; R[i]--;
    }
    vector<ll> S1(n), S2(n);
    S1[0] = class1[0], S2[0] = class2[0];
    for(int i=1;i<n;i++) {
        //cout << class1[i] << " " << class2[i] << endl;
        S1[i] += (S1[i-1] + class1[i]);
        S2[i] += (S2[i-1] + class2[i]);
        //cout << S1[i] << " " << S2[i] << endl;
    }

    rep(i,q) {
        if(L[i]-1>=0) cout << S1[R[i]] - S1[L[i]-1] << " " << S2[R[i]] - S2[L[i]-1] << endl;
        //R[i]までの和-{L[i]-1}までの和
        else cout << S1[R[i]] << " " << S2[R[i]] << endl;
    }

    return 0;
}