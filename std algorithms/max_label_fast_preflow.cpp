// wrong until now

// push relabel algorithm
// O(V^2 E)
//source=0, sink = n-1;

#define INF 1000000000
#define maxn 1000

int n;
int cap [maxn][maxn], preflow [maxn] [maxn];
int ht [maxn], excess [maxn];


void push (int u, int v) {
	int d = min(excess[u], (cap[u][v] - preflow[u][v]));
	preflow[u][v] += d;
	preflow[v][u] = -preflow[u][v];
	excess[u] -= d;
	excess[v] += d;
}

void relabel(int u) {
	int d = INF;
	for(int i=0; i<n; i++)
		if(cap[u][i] - preflow[u][i] > 0)
			d = min(d, ht[i]);
	
	if(d == INF)
		return;

	ht[u] = d + 1;
}

void init() {
	memset(ht, 0, sizeof ht);
	memset(excess, 0, sizeof excess);
	memset(preflow, 0, sizeof preflow);

	ht[0] = n;

	for(int i=1; i<n; i++) {
			preflow[0][i] = excess[i] = cap[0][i];
			preflow[i][0] = -cap[0][i];
			excess[0] -= cap[0][i];
	}

}

int pushrelabel() {
	init();
	VI maxh (n);
	int sz = 0;
	while(1) {
		if(! sz)
			for(int i=1; i<n-1; i++)
				if(excess[i] > 0) {
					if(sz && ht[i]>ht[maxh[0]])
						sz = 0;
					if(!sz || ht[i]==ht[maxh[0]])
						maxh[sz++] = i;
				}
		if(! sz)
			break;

		while(sz) {
			int i = maxh[sz-1];
			bool pushed = 0;

			for(int j=0; j<n && excess[i]; j++) {
				if((cap[i][j] - preflow[i][j])>0 && ht[i]==ht[j]+1) {
					pushed = 1;
					push(i,j);
					if(!excess[i])
						sz--;
				}
			}

			if(!pushed) {
				relabel(i);
				if(ht[i] > ht[maxh[0]]) {
					sz = 0;
					break;
				}
			}
		}
	}

	int flow = 0;
	
	for(int i=1; i<n; i++)
		if(cap[0][i])
			flow += preflow[0][i];

	return flow;
}
