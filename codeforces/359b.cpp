#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int A[N];

int main() {
	ios_base::sync_with_stdio(0);
	int n, k;
	cin >> n >> k;

	for(int i=0; i<2*k; i++) {
		if(i & 1) {
			A[2*i] = 2*i+1;
			A[2*i + 1] = 2*i+2;
		}
		else {
			A[2*i] = 2*i+2;
			A[2*i + 1] = 2*i+1;
		}
	}

	for(int i=2*k; i<n; i++) {
		A[2*i] = 2*i+2;
		A[2*i+1] = 2*i+1;
	}

	for(int i=0; i<2*n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;

}