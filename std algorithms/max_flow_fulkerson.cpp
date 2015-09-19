// EDMONDS KARP MODULE STARTS ADJ LIST
// O(maxflow * E)
// adjacency list -> arr

int source, sink;
int N;
vector < vector<int> > arr;

const int maxn = 1000;
const int INF = 1e9;

int capacity[maxn][maxn];
int from[maxn], v[maxn];

int bfs(){
	queue<int> q;
	memset(v,0,sizeof v);
	memset(from,-1,sizeof from);
	v[source] = 1;
	q.push(source);
	int where, next = -1, prev;
	while (!q.empty()) {
		where = q.front();
		q.pop();
		for(int i=0;i<arr[where].size();i++){
			next = arr[where][i];
			if(v[next] == 0 && capacity[where][next] > 0){
				from[next] = where;
				v[next] = 1;
				if(next == sink) goto outofwhile;
				q.push(next);
			}
		}
	}
	outofwhile:
	int minCap = INF;
	where = sink;
	while(from[where] != -1){
		prev = from[where];
		minCap = min(minCap,capacity[prev][where]);
		where = prev;
	}
	where = sink;
	while(from[where] != -1){
		prev = from[where];
		capacity[prev][where] -= minCap;
		capacity[where][prev] += minCap;
		where = prev;
	}
	if(minCap == INF) return 0;
	return minCap;
}

int maxFlow(){
	int ret = 0;
	int temp;
	do{
		temp = bfs();
		ret += temp;
	} while(temp > 0);
	return ret;
}
// EDMONDS KARP MODULE ENDS