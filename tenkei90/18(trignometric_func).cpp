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

const double PI = 3.1415926535;

void pos(int t, double &y, double &z, double T, double L) {
    y = -L*sin(2*PI*t/T)/2;
    z = -L*cos(2*PI*t/T)/2+L/2;
}

double theta(ll X, ll Y, ll t, ll T, ll L) {
    double y,z;
    pos(t, y, z, T, L);
    double tmp = atan2(z,sqrt((Y-y)*(Y-y)+X*X));
    return tmp*180/PI;
}

int main() {
    double T,L,X,Y;
    int Q;
    cin >> T;
    cin >> L >> X >> Y;
    cin >> Q;
    vector<double> E(Q);
    rep(i,Q) cin >> E[i];

    rep(i,Q) {
        printf("%.8lf\n", theta(X,Y,E[i],T,L));
    }

    return 0;
}