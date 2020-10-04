#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9+7)
#define mset(a,k) memset(a,k,sizeof(a));
#define fr(i, x, y) for ( ll i = x; i < y;i++)
#define dr(i, x, y) for ( ll i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define pqueue priority_queue<ll>
#define piqueue priority_queue<ll,vll ,greater<ll>>
#define mapcl map<char,ll>
#define mapll map<ll,ll>
#define mapsl map<string,ll>
#define vi vector<ll>
#define vs vector<string>
#define vb vector<bool>
#define psi pair<string,ll>
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define vii vector<pii>
#define vvi vector<vi>
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//----------------------------------------FUNCTIONS-------------------------------------
ll gcd(ll x, ll y )						{if (y == 0) return x; return gcd(y, x % y);}
ll lcm(ll a, ll b)						{return (a * b) / gcd(a, b);}
ll logx(ll base, ll num)				{int cnt = 0; while (num != 1) {num /= base; ++cnt;} return cnt;}
vi vin(ll n)							{vi a(n); fr(i, 0, n) cin >> a[i]; return a;}
void out(vi a)							{for (int i = 0; i < (ll)a.S; i++) { cout << a[i] << " "; } cout << endl;}
void in(ll *a, ll n)        			{for (ll i = 0; i < n; i++)cin >> a[i];}
void out(ll *a, ll n)					{fr(i, 1, n + 1) {cout << a[i] << " ";} cout << '\n';}
void out1(vi v)							{fr(i, 0, (ll)v.S) {cout << v[i] << " ";} cout << endl;}
//----------------------------------------START-------------------------------------------
const ll maxN = (ll)(1 * 1e5 + 5 );
vvi adj, jda;
vb vis;
void sdf(ll u)
{
	vis[u] = true;
	cout << u << " ";
	for (auto it : jda[u])
	{
		if (vis[it] == false)sdf(it);
	}
}
stack<ll> s;
void dfs(ll u)
{
	vis[u] = true;
	for (auto it : adj[u])
	{
		if (!vis[it])dfs(it);
	}
	s.push(u);
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	vis.assign(n, false);
	adj.resize(n);
	jda.resize(n);
	fr(i, 0, m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		jda[v].pb(u);
	}
	fr(i, 0, n)if (vis[i] == false)dfs(i);
	fr(i, 0, n)vis[i] = false;
	while (!s.empty())
	{
		ll u = s.top();
		s.pop();
		if (vis[u] == false)
		{
			sdf(u);
			cout << '\n';
		}

	}
}
int main()
{
	fast();
#ifndef ONLINE_JUDGE
	freopen ("inp1.txt", "r", stdin);
	freopen ("out1.txt", "w", stdout);
#endif
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

