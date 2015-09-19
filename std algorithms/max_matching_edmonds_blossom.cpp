// vertices 1 to V 

#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int V, E;
#define VI vector <int>
#define pb push_back
VI graph[N];
int Mate[N];
int subset[N];
int vAncestors[N];
int wAncestors[N];
int even[N], odd[N];
int path[N];
int nil = -1;
int parent[N], _rank[N];
queue<int> _queue;
#define PII pair<int,int>
#define mp make_pair
#define F first
#define S second
map <int, PII> bridges;

int par(int x){
    if (parent[x]==x) return x;
    return parent[x]=par(parent[x]);
}

void merge(int x,int y) {
    int px = par(x);
    int py = par(y);

    if(_rank[px] > _rank[py])
        parent[py] = px;
    else
        parent[px] = py;
    
    if(_rank[px] == _rank[py])
        _rank[py]++;
}

int lok(int curr, int (&anc)[N]) {
    curr = par(curr);
    anc[curr] = 1;
    int pa = par(even[curr]);
    if(pa == curr)
        return curr;
    anc[pa] = 1;
    return par(odd[pa]);
}

void reverse(int i, int j) {
    while(i<j) {
        swap(path[i], path[j]); i++; j--;
    }
}

int build(int i, int start, int goal) { 
    while(1) {
        while(odd[start] != nil) {
            PII a = bridges[start];
            int j = build(i, a.F, start);
            reverse(i, j-1); i=j;
            start = a.S;
        }
        path[i++] = start;
        if(!Mate[start])
            return i;
        path[i++] = Mate[start];

        if(path[i-1] == goal)  
            return i;
        start = odd[path[i-1]];
    }
}

void aug(int v) {
    int n = build(0, v, nil);
    for(int i=2; i<n; i+=2) {
        Mate[path[i]] = path[i-1];
        Mate[path[i-1]] = path[i];
    } 
}

VI blossomsup(int v,int w, int base) {
    int n=0;
    path[n++]=par(v); 
    PII b = mp(v,w);

    while(path[n-1] != base) {
        int u = even[path[n-1]];
        path[n++] = u;
        bridges[u] = b;
        _queue.push(u);
        path[n++] = (par(odd[u]));
    }
    VI c(n);
    for(int i=0; i<n; i++)  c[i] = path[i];
    return c;
}

void blossom(int v, int w, int base) {
    base = par(base);
    VI supports1 = blossomsup(v,w,base); 
    VI supports2 = blossomsup(w,v,base);


    for(int i=0; i<supports1.size(); i++) {
        merge(supports1[i], supports1[0]);
    }

    for(int i=0; i<supports2.size(); i++) {
        merge(supports2[i], supports2[0]);
    }
    even[par(base)] = even[base];
}


int check(int v, int w) {
    if(par(v) == par(w))
            return 0;

    for(int i=1; i<=V; i++)  {
        vAncestors[i] = wAncestors[i] = 0;
    }
    int vcurr=v; int wcurr=w;

    while(1) {
        vcurr = lok(vcurr, vAncestors);
        wcurr = lok(wcurr, wAncestors);

        if(vcurr == wcurr) {
            blossom(v,w,vcurr);
            return 0;
        }

        if(par(even[vcurr]) == vcurr && par(even[wcurr]) == wcurr) {
            aug(v); aug(w);
            Mate[v]=w; Mate[w]=v;
            return 1;
        }

        if(wAncestors[vcurr]) {
            blossom(v,w,vcurr);
            return 0;
        }

        if(vAncestors[wcurr]) {
            blossom(v,w,wcurr);
            return 0;
        }
    }
}

int augment() {
    for(int i=1; i<=V; i++)  {
        even[i] = odd[i] = -1;
        parent[i] = i; _rank[i] = 0;
    }

    while(!_queue.empty())
        _queue.pop();
    bridges.clear();

    for(int i=1; i<=V; i++) {
        if(subset[i] && !Mate[i]) {
            even[i] = i;
            _queue.push(i);
        }
    }

    while(!_queue.empty()) {
        int v = _queue.front();
        _queue.pop();

        for(int i=0; i<graph[v].size(); i++) {
            int w = graph[v][i];
            if(!subset[w])
                continue;
            if(even[par(w)] != nil) {
                if(check(v, w))
                    return 1;
            }
            else if(odd[w] == nil) {
                odd[w] = v;
                int u = Mate[w];
                if(even[par(u)] == nil) {
                    even[u] = w;
                    _queue.push(u);
                }
            }
        }
    }
    return 0;
}

void Matching() {
    for(int i=1 ; i<=V; i++) {
        Mate[i] = 0;
        vAncestors[i] = wAncestors[i] = 0;
        subset[i] = 1;
    }
    while(augment());
}

int C[N];
int mapp[N];

int Output() {
    int Count = 0;
    for (int i = 1; i <= V; i++)
        if (Mate[i] > i)
            Count++;
    return Count;
}

#define gc getchar_unlocked
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