//------------ MILLER RABIN
/* Deterministic for 2**64, --> all 12 primes till 37
if n < 1,373,653, it is enough to test a = 2 and 3;
if n < 9,080,191, it is enough to test a = 31 and 73;
if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.*/

unsigned long long modmult(unsigned long long a,unsigned long long b,unsigned long long N)
{
	if(a>=N)a%=N;
	unsigned long long res=0;
	while(b)
	{
		if(b&1)
		{
			res+=a;
			if(res>=N)res-=N;
		}
		b>>=1;
		a<<=1;
		if(a>=N)a-=N;
	}
	return res;
}

unsigned long long modpow(unsigned long long a,unsigned long long b,unsigned long long N)
{
	if(a>=N)a%=N;
	unsigned long long res=1ll;
	while(b)
	{
		if(b&1)res=modmult(a,res,N);
		b>>=1;
		a=modmult(a,a,N);
	}
	return res;
}

bool Miller(unsigned long long N)
{
	if(N<2)return false;
	else if(N<4) return true;
	else if((N&1)==0)return false;
	unsigned long long D=N-1,S=0;
	while((D&1)==0)
	{
		D>>=1;
		S++;
	}
	for(int a=0;a<5;a++)
	{
		unsigned long long ad=modpow(rand()%(N-4)+2,D,N);
		if(ad==1||ad==N-1) continue;
		for(unsigned long long r=0;r<S-1;r++)
			if((ad=modmult(ad,ad,N))==N-1)
				goto BPP;
		return false;
		BPP:;
	}
	return true;
}