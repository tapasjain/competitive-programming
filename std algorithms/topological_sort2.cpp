//Another Topological Sort
VI sorted,degree;
vector<VI> arr;
stack<long long> S;
void Tsort()
{
	int i;
	while(!S.empty()){
		i=S.top();
		sorted.pb(i);
		S.pop();
		for(int k=0;k<arr[i].size();k++){
			degree[arr[i][k]]--;
			if(degree[arr[i][k]]==0)S.push(arr[i][k]);
		}
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