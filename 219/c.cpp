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

string x;
map<char, int> MapX;

bool comp(const string& s1, const string& s2) {
    int size = 0;
    if (s1.size() <= s2.size()) size = s1.size();
    else size = s2.size();
    rep(i, size) {
        if (MapX.at(s1[i]) < MapX.at(s2[i])) return true;
        if (MapX.at(s1[i]) > MapX.at(s2[i])) return false;
    }
    return (s1.size() < s2.size());
}

int main() {
    int n;
    cin >> x;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i, 26) MapX.insert(make_pair(x[i], i));

    /**
    for(auto itr = MapX.begin(); itr != MapX.end(); ++itr) {
        std::cout << "key = " << itr->first           // キーを表示
                        << ", val = " << itr->second << "\n";    // 値を表示
    }
    **/
    
    sort(s.begin(), s.end(), comp);
    rep(i,n) cout << s[i] << endl;
    return 0;
}