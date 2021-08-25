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

const int MOD = 1e9+7;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    string obj = "atcoder";
    int l = obj.size();
    vector<vector<int>> dp(n, vector<int>(l));
    rep(i,n) {
        if(s[i]==obj[0]) dp[i][0]++;
        rep(j,l) {
            if(s[i]==obj[j]&&i>0&&j>0) dp[i][j]+=dp[i-1][j-1];
            dp[i][j]%=MOD;
            if(i>0) dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }

    //debug
    /**
    rep(i,n) {
        rep(j,l) {
            printf("%d ",dp[i][j]);
        }
        cout << "" << endl;
    }
    **/

    cout << dp[n-1][l-1] << endl;
    return 0;
}