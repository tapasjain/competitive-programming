//Topological Sort
VI sorted,visited;
long long current;
vector<VI> arr;
void dfs(long long i){
	if(visited[i]==1)return;
	visited[i]=1;
	for(long long k=0;k<arr[i].size();k++){
		dfs(arr[i][k]);
	}
	sorted[current--]=i;
}

void Tsort(){
	current =arr.size()-1;
	for(long long i=0;i<arr.size();i++){
		dfs(i);
	}
}

int main()
{
	long long n;fcin(n);degree.resize(n);
	arr.resize(n);
	long long m; fcin(m);
	long long x,y;
	for(long long i=0;i<m;i++){fcin(x);fcin(y);
		arr[x].pb(y);
		degree[y]++;
	}
	for(int i=0;i<n;i++)if(degree[i]==0)S.push(i);
	Tsort();
	for(int i=0;i<n;i++)cout<<sorted[i]<<" ";cout<<endl;
	return 0;
}