#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;
int find(char *sptr, char *s)
{
    int ret= 0;
    //
    size_t pos= strlen(sptr);
    char * cp= strstr(s,sptr);
    while( cp ){
        ret++;
        cp += pos;
        cp = strstr(cp,sptr);
    }
    return ret;
}


int main()
{
    char s[12];
    cin >> s;
    int n= find("ZONe", s);
    cout << n << endl;
    return 0;
}