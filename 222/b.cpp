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

bool comp(P p1, P p2) {
    if (p1.first > p2.first) return true;
    else if (p1.first == p2.first) {
        return (p1.second < p2.second);
    } else return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(2 * n);
    rep(i, 2 * n) cin >> a[i];
    vector<P> Rank(2 * n); //pair<win, who>
    rep(i, 2 * n) Rank[i] = pair(0, i);

    rep(i, m) {
        for (int j = 0; j < 2 * n; j += 2) {
            if ((a[Rank[j].second][i] == 'G' && a[Rank[j + 1].second][i] == 'C') ||
            (a[Rank[j].second][i] == 'C' && a[Rank[j + 1].second][i] == 'P') || 
            (a[Rank[j].second][i] == 'P' && a[Rank[j + 1].second][i] == 'G')) Rank[j].first++;
            if ((a[Rank[j].second][i] == 'C' && a[Rank[j + 1].second][i] == 'G') ||
            (a[Rank[j].second][i] == 'P' && a[Rank[j + 1].second][i] == 'C') || 
            (a[Rank[j].second][i] == 'G' && a[Rank[j + 1].second][i] == 'P')) Rank[j+1].first++;
            //cout << "now: " <<Rank[j].second+1 << " vs " << Rank[j+1].second+1<< endl;
        }
        sort(Rank.begin(), Rank.end(), comp);
    }

    rep(i, 2 * n) cout << Rank[i].second + 1 << endl;
    //rep(i, 2 * n) cout << Rank[i].first << endl;
    return 0;
}