#include <iostream>
#include <vector>
// Take d to be the size of the characters.
long long modulo(int a,int b,int c){
	long long x=1, y=a;
	while(b > 0){
		if (b % 2 == 1) {
			x=(x*y)%c;
		}
		y = (y*y)%c;
		b /= 2;
	}
	return x%c;
}

std::vector<int> rabin_karp(std::string t, std::string p, long long d, long long q) {
	std::vector<int> matches;
	int n;
	n = t.size();
	int m;
	m = p.size();
	long long h;
	h = modulo(d, m-1, q);
	long long pp = 0;
	long long tp[n-m+1];
	tp[0] = 0;
	for (int i = 0; i < m; i++) {
		pp = (d*pp + p[i]) % q;
		tp[0] = (d*tp[0] + t[i]) % q;
	}
	for (int s = 0; s < n-m+1; s++) {
		//std::cout << s << tp[s] << std::endl;
		if (pp == tp[s]) {
			bool val = true;
			for (int i = 0; i < m; i++) {
				if (p[i] != t[s+i]) {
					val = false;
					break;
				}
			}
			if (val == true) {
				matches.push_back(s);
			}
		}
		if (s < n - m) {
			tp[s+1] = (d*(tp[s] - t[s]*h) + t[s+m]) % q;
			if (tp[s+1] < 0) {
				tp[s+1] += q;
			}
		}
	}
	return matches;
}

using namespace std;

int main(int argc, char *argv[]) {
	std::vector<int> v;
	v = rabin_karp("this is the randomness of the lanthewitchthethethe", "the", 26, 101);
	for (int i = 0; i < v.size(); i++) {
	cout << v[i] << endl;
}
}