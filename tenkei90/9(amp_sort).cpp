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

struct Point {
    double px, py;
};


//when overloading operator, to avoid using too much memory,
//(not to make copy) use ref by pointer
//and to avoid rewriting contents of ref, use const
Point operator-(const Point& P1, const Point& P2) {
    return Point{P1.px-P2.px, P1.py-P2.py};
}

double getAngle(const Point& P) {
    return atan2(P.py, P.px)*180/acos(-1);
}

double getAngle180(double arg1, double arg2) {
    return min(abs(arg1-arg2), 360-abs(arg1-arg2));
}

double solve(int v, vector<Point> Ps) {
    vector<double> args; 
    rep(i,Ps.size()) {
        if (i==v) continue;
        args.push_back(getAngle(Ps[i]-Ps[v])); 
        //argsをPs.size()とってarg[i]=getangleにするとWA なぜ？
    }
    sort(args.begin(), args.end());

    double ans = 0;
    rep(i,args.size()) {
        double target = (args[i] < 180) ? args[i] + 180 : args[i] - 180;
        int l=0,r=args.size()-1;
        while (r-l>1) {
            int mid = (l+r)/2;
            if (args[mid]>target) r = mid;
            else l = mid;
        }
        ans = max(max(ans, getAngle180(args[i], args[l])), getAngle180(args[i], args[r]));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<Point> Ps(n);
    rep(i,n) cin >> Ps[i].px >> Ps[i].py;
    
    double final_ans = 0;
    rep(i,n) {
        double cand = solve(i, Ps);
        final_ans = max(final_ans, cand);
    }

    printf("%.11lf\n",final_ans);
    
    return 0;
}