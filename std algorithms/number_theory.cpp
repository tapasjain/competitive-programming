// -------------------------------------- return a % b (positive value) ------------------------------------------------
int mod(int a, int b) {
	return ((a%b)+b)%b;
}

//  ------------------------------------- computes gcd(a,b) -------------------------------------------------------------
int gcd(int a, int b) {
	int tmp;
	while(b){
		a%=b; 
		tmp=a; 
		a=b; 
		b=tmp;
	}
	return a;
}

// -------------------------------------------computes lcm(a,b) ---------------------------------------------------------
int lcm(int a, int b) {
	return a/gcd(a,b)*b;
}

// ---------------------------------------- returns d = gcd(a,b); finds x,y such that d = ax + by ----------------------
int extended_euclid(int a, int b, int &x, int &y) {
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a/b;
		int t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
	return a;
}


// ----------------------------------- finds all solutions to ax = b (mod n) -------------------------------------------
VI modular_linear_equation_solver(int a, int b, int n) {
	int x, y;
	VI solutions;
	int d = extended_euclid(a, n, x, y);
	if (!(b%d)) {
		x = mod (x*(b/d), n);
		for (int i = 0; i < d; i++)
			solutions.push_back(mod(x + i*(n/d), n));
	}
	return solutions;
}

// ------------------------------------------ a^b % m --------------------------------------------------------------------------
ll powm(ll a, ll b, ll m) {
	ll i = a, k=1ll;
	while(b) {
		if(b&1) k = (k*i) % m;
		i = (i*i) % m;
		b >>= 1;
	}
	return k;
}

int powm(int a, int b, int m) {
	int i=a, k=1;
	while(b) {
		if(b&1) k = (k*1ll*i)%m;
		i = (i*1ll*i)%m;
		b >>= 1;
	}
	return k;
}

// ------------------------------------------ a^b --------------------------------------------------------------------------
ll pow(ll a, ll b) {
	ll i = a, k=1ll;
	while(b) {
		if(b&1) k *= i;
		i *= i;
		b >>= 1;
	}
	return k;
}

int powm(int a, int b) {
	int i=a, k=1;
	while(b) {
		if(b&1) k *= i;
		i *= i;
		b >>= 1;
	}
	return k;
}

// --------------------------------- computes b such that ab = 1 (mod n), returns -1 on failure --------------------------------
int mod_inverse(int a, int n) {
	int x, y;
	int d = extended_euclid(a, n, x, y);
	if (d > 1) return -1;
	return mod(x,n);
}

// -------------------------------------------------------------------------------------------------------------------------------
// Chinese remainder theorem (special case): find z such that
// z % x = a, z % y = b. Here, z is unique modulo M = lcm(x,y).
// Return (z,M). On failure, M = -1. 
PII chinese_remainder_theorem(int x, int a, int y, int b) {
	int s, t;
	int d = extended_euclid(x, y, s, t);
	if (a%d != b%d) return make_pair(0, -1);
	return make_pair(mod(s*b*x+t*a*y,x*y)/d, x*y/d);
}

// computes x and y such that ax + by = c; on failure, x = y = -1
bool find_any_solution (int a, int b, int c, int & x0, int & y0, int & g) {
	g = gcd (abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0)   x0 *= -1;
	if (b < 0)   y0 *= -1;
	return true;
}




//------------------------------------------------- n! mod p (prime) in O(p log n) ---------------------------------------------------
int factmod (int n, int p)  {
	int res = 1;

	while (n > 1)  {
		res = (res * ((n/p) % 2 ? p-1 : 1)) % p;
		
		for (int i=2; i<=n%p; ++i)
			res = (res * i) % p;
		
		n /= p;
	}
	return res % p;
}


//-----------------------------------------------------------Solution to a^x = b (mod m) ------------------------------------------
int solve (int a, int b, int m)  {
	int n = (int) sqrt (m + .0) + 1;
	map<int,int> vals;

	for (int i=n; i>=1; --i)
		vals[ powm (a, i * n, m) ] = i;

	for (int i=0; i<=n; ++i) {
		int cur = (powm (a, i, m) * b) % m;
		if (vals.count(cur)) {
			int ans = vals[cur] * n - i;
			if (ans < m)
				return ans;
		}
	}

	return -1;
}



