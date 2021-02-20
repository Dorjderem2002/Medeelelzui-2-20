#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"
const int lam = 1e6;
int xPos[lam+1],yPos[lam+1];
int bagaX[lam+1],bagaY[lam+1],greaterX[lam+1],greaterY[lam+1];

void solve()
{
	int n;
	cin>>n;
	
	for(ll i=0;i<n;i++)
	{
		int x,y,x1,y1,x2,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		int mxx = max(x,max(x1,x2));
		int mnx = min(x,min(x1,x2));
		int mxy = max(y,max(y1,y2));
		int mny = min(y,min(y1,y2));
		bagaX[mnx]++;
		greaterX[mxx-1]--;
		bagaY[mny]++;
		greaterY[mxy-1]--;
	}
	int c = 0;
	for(int i=0;i<=lam;i++)
	{
		xPos[i] = c;
		c += bagaX[i];
		c += greaterX[i];
	}
	c=0;
	for(int i=0;i<=lam;i++)
	{
		yPos[i] = c;
		c += bagaY[i];
		c += greaterY[i];
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++)
	{
		char dir,omg;
		int val;
		cin>>dir>>omg>>val;
		if(dir == 'y')
		{
			cout<<yPos[val];
		}
		else
		{
			cout<<xPos[val];
		}
		cout<<endl;
	}
} 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}