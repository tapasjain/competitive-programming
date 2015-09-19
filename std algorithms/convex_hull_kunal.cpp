//CONVEX HULL (kunal's code)
struct point
{
	int x,y;
	point(int a, int b){x=a;y=b;}
	point(){x=y=0;}
};
struct line
{
	point p1,p2;
	bool segment;
	line(point a,point b,bool s){p1=a;p2=b;segment=s;}
	line(point a,point b){p1=a;p2=b;segment=1;}
	line(){p1=point();p2=point();segment=1;}
	void print(){cout<<"("<<p1.x<<","<<p1.y<<")-("<<p2.x<<","<<p2.y<<")\n";}
};

int CrossPdt(line a, point b)
{
	return ((a.p1.x-a.p2.x)*(a.p2.y-b.y)-(a.p1.y-a.p2.y)*(a.p2.x-b.x));
}

int compare(point a, point b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

int n;
vector<point> arr;
stack<point> L,P;
stack<line> hull;

int main()
{
	cin>>n;
	int x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		arr.push_back(point(x,y));
	}

	sort(arr.begin(),arr.end(),compare);
	//convex hull construction
	L.push(arr[0]);L.push(arr[1]);
	hull.push(line(arr[0],arr[1]));
	for(int i=2; i<n; i++)
	{
		while(L.size()>=2)
		{
			if(CrossPdt(hull.top(),arr[i])>=0)
			{
				hull.push(line(L.top(),arr[i]));
				L.push(arr[i]);
				break;
			}
			hull.pop();L.pop();
		}
		if(L.size()==1)
		{
			hull.push(line(L.top(),arr[i]));
			L.push(arr[i]);
		}
	}

	P.push(arr[n-1]);P.push(arr[n-2]);
	hull.push(line(arr[n-1],arr[n-2]));
	for(int i=n-3;i>=0;i--)
	{
		while(P.size()>=2)
		{
			if(CrossPdt(hull.top(),arr[i])>=0)
			{
				hull.push(line(P.top(),arr[i]));
				P.push(arr[i]);
				break;
			}
			hull.pop();P.pop();
		}
		if(P.size()==1)
		{
			hull.push(line(P.top(),arr[i]));
			P.push(arr[i]);
		}
	}

	int j=1;
	while(!hull.empty())
	{
		cout<<j++<<": ";
		hull.top().print();hull.pop();
	}
	system("pause");
}