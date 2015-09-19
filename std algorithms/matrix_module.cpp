//matrix module starts
typedef vector<vector<int> > VVI;
#define mod 1000000007

VVI iden(int n){
	VVI arr;
	arr.resize(n);
	for(int i=0;i<n;i++){
		arr[i].resize(n,0);
		arr[i][i] = 1;
	}
	return arr;
}

VVI mul(VVI A,VVI B){
	int a = A.size();
	int c = B.size();
	int b = B[0].size();
	VVI res;
	res.resize(a);
	for(int i=0;i<a;i++)res[i].resize(b);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			res[i][j] = 0;
			for(int k=0;k<c;k++){
				res[i][j] = (res[i][j] + (A[i][k] * 1ll * B[k][j])%mod)%mod;
			}
		}
	}
	return res;
}

VVI pow(VVI A,int n){
	int sz = A.size();
	VVI res = iden(sz);
	while (n) {
		if(n&1){
			res = mul(res,A);
		}
		n >>= 1;
		A = mul(A,A);
	}
	return res;
}
void print(VVI a){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++)cout << a[i][j] <<" " ; 
		cout << endl;
	}
}
// matrix module ends