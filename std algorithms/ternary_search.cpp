//ternary search
long long tenary(VI A,function f)
{
	long long s=0,e=A.size()-1,x=0,y=0;
	while(s<e)
	{
		x=(2*s+e)/3;
		y=(s+2*e)/3;
		if(f(x)<=f(y))e=y;
		else s=x+1;
	}
	return s;
}