typedef long long ll;
#define double long double
 
int po(int x, int y) {
  if(!y) return 1;
  int ret = po(x,y/2);
  ret = (ret*(ll)ret)%mod;
  if(y&1) ret = (ret*(ll)x)%mod;
  return ret;
}
 
int inv(int x) {
  return po(x,mod-2);
}
 
typedef complex<double> base;
 
void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
 
	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

void multiply ( vector<ll> & a, vector<ll> & b) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	int n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);
 
	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

  a.resize(n);
	for (size_t i=0; i<a.size(); ++i)
		a[i] = (ll (fa[i].real() + 0.5))%mod;
}


// This part is when multiplying (x+b0)(x+b1)...(x+bn).
int multiply(vector<int> &b) {
  int n = b.size();
  vector<vector<ll> > a = vector<vector<ll> >(n,vector<ll>(2));
  for(int i=0; i<n; i++) {
    a[i][0] = 1;
    a[i][1] = b[i];
  }
  while(n>1) {
    for(int i=0; i<n/2; i++) {
      multiply(a[i],a[n-1-i]);
    }
    n = (n+1)/2;
  }
  int ans = a[0][k]%mod;
  if(ans<0) ans+=mod;
  return ans;
}
 