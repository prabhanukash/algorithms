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
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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
const ll maxN = (ll)(1 * 1e5 + 5 );
struct segtree {
	vi sums;
	ll size;
	void init(ll n)
	{
		size = 1;
		while (size < n)size *= 2;
		sums.assign(2 * size, 0LL);
	}
	void set(ll i, ll v, ll x , ll lx, ll rx)
	{
		if (rx - lx == 1)
		{
			sums[x] = v;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m)
		{
			set(i, v, x, lx, m);
		}
		else
		{
			set(i, v, x, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void set(ll i, ll v)
	{
		set( i,  v,  0, 0, size);
	}
	ll sum(ll l , ll r, ll x , ll lx, ll rx)
	{
		if (lx >= r || l >= rx)return 0;
		if (l <= lx && rx <= r) return sums[x];
		ll m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}
	ll sum(ll l, ll r)
	{
		return sum(l, r, 0, 0, size);
	}
	void build(vi &a, ll x, ll lx, ll rx)
	{
		if (rx - lx == 1)
		{
			if (lx < a.S)	sums[x] = a[lx];
			return ;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void build(vi &a)
	{
		build(a, 0, 0, size);
	}
};
int main()
{
#ifndef ONLINE_JUDGE
	freopen ("inp4.txt", "r", stdin);
	freopen ("out4.txt", "w", stdout);
#endif
	fast();
	ll t = 1;
	//cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> n >> m;
		vi a;
		segtree st;
		st.init(n);
		fr(i, 0, n)
		{
			ll x;
			cin >> x;
			a.pb(x);
		}
		st.build(a);
		while (m--)
		{
			ll op;
			cin >> op;
			if (op == 1) {
				ll i, v;
				cin >> i >> v;
				st.set(i, v);
			}
			else
			{
				ll l, r;
				cin >> l >> r;
				cout << st.sum(l, r) << '\n';
			}
		}
	}

}