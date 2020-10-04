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
#define allr(v) v.rbegin(), v.rend()
#define pqueue priority_queue<ll>
#define mapcl map<char,ll>
#define mapll map<ll,ll>
#define mapsl map<string,ll>
#define vi vector<ll>
#define vs vector<string>
#define psi pair<string,ll>
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define vii vector<pii>
using namespace std;
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
//----------------------------------------FUNCTIONS---------------------------------------------------
ll gcd(ll x, ll y )						{if (y == 0) return x; return gcd(y, x % y);}
ll lcm(ll a, ll b)						{return (a * b) / gcd(a, b);}
ll logx(ll base, ll num)				{int cnt = 0; while (num != 1) {num /= base; ++cnt;} return cnt;}
vi vin(ll n)							{vi a(n); fr(i, 0, n) cin >> a[i]; return a;}
void vout(vi a)							{for (int i = 0; i < (ll)a.S; i++) { cout << a[i] << " "; } cout << endl;}
void in(ll *a, ll n)        			{for (ll i = 0; i < n; i++)cin >> a[i];}
void in1(ll *a, ll n)        			{for (ll i = 1; i <= n; i++)cin >> a[i];}
void out1(ll *a, ll n)					{fr(i, 1, n + 1) {cout << a[i] << " ";} cout << '\n';}
void out(ll *a, ll n)					{fr(i, 0, n) {cout << a[i] << " ";} cout << endl;}
//----------------------------------------START--------------------------------------------------------
const ll maxN = (ll)(1 * 1e6 + 5 );
vii adj[maxN];
ll dist[maxN];
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("inp3.txt", "r", stdin);
	freopen ("out3.txt", "w", stdout);
#endif
	fast();
	ll n, m;
	cin >> n >> m;
	fr(i, 0, m)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	fr(i, 0, maxN)dist[i] = INT_MAX;
	ll src;
	cin >> src;
	dist[src ] = 0;
	priority_queue< pii, vii , greater<pii> > pq;
	pq.push({0, src});
	while (!pq.empty())
	{
		ll u = pq.top().ss;
		pq.pop();
		for (auto i : adj[u])
		{
			ll v = i.ff;
			ll w = i.ss;
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	fr(i, 0, n)
	{
		cout << dist[i] << '\n';
	}

}
