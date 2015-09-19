#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define VI vector<int>
#define PII pair<int,int>
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define gc getchar

inline int inp() {
    char c = gc();
    while(c<'0' || c>'9') c = gc();
    int ret = 0;
    while(c>='0' && c<='9') {
        ret = (ret << 3) + (ret << 1) + c - 48;
        c = gc();
    }
    return ret;
}

const int N = 1e5 + 10;
const int INF = 1e9 + 7;



int main() {

}