#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define S size()
#define mod (ll)(1e9+7)
#define mset(a,k) memset(a,k,sizeof(a))
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
#define vvii vector<vii>
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
const ll MAXN = (ll)(1 * 1e5 + 5 ), level = 25;
vi adj[MAXN];
ll depth[MAXN];
ll parent[MAXN][level];

// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(ll cur, ll prev)
{
	depth[cur] = depth[prev] + 1;
	parent[cur][0] = prev;
	for (auto it : adj[cur])
	{
		if (it != prev)dfs(it, cur);
	}
}

// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precompute(ll n)
{
	for (ll i = 1; i < level; i++)
	{
		for (ll u = 1; u <= n; u++)
		{
			if (parent[u][i - 1] != -1)
				parent[u][i] = parent[parent[u][i - 1]][i - 1];
		}
	}
}

// Returning the LCA of u and v
// Time complexity : O(log n)
ll lca(ll u, ll v)
{
	if (depth[v] < depth[u])
		swap(u, v);

	ll diff = depth[v] - depth[u];

	// Step 1 of the pseudocode
	for (ll i = 0; i < level; i++)
		if ((diff >> i) & 1)
			v = parent[v][i];

	// now depth[u] == depth[v]
	if (u == v)
		return u;

	// Step 2 of the pseudocode
	for (ll i = level - 1; i >= 0; i--)
		if (parent[u][i] != parent[v][i])
		{
			u = parent[u][i];
			v = parent[v][i];
		}

	return parent[u][0];
}
void clr(ll n)
{
	for (ll i = 1; i <= n; i++)adj[i].clear(), depth[i] = 0;
}
void solve()
{
	memset(parent, -1, sizeof(parent));

	ll n;
	cin >> n;
	clr(n);
	fr(i, 1, n + 1)
	{
		ll sz;
		cin >> sz;
		fr(j, 0, sz)
		{
			ll x;
			cin >> x;
			adj[i].pb(x);
			adj[x].pb(i);
		}
	}
	depth[0] = 0;
	dfs(1, 0);
	precompute(n);
//	cout<<par[2][0]<<'\n';
	ll q;
	cin >> q;
	fr(i, 0, q)
	{
		ll u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("inp2.txt", "r", stdin);
	freopen ("out2.txt", "w", stdout);
#endif
	fast();
	ll t = 1;
	cin >> t;
	fr(i, 0, t)
	{
		cout << "Case " << i + 1 << ":\n";
		solve();
	}
}
