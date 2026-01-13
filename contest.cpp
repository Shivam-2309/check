// Author : Shivam Kapoor
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll mod7 = 1e9 + 7, mod9 = 998244353, INF = 1e18;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) (v).begin(), (v).end()
#define sz(v) ((ll)(v).size())
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)

#ifndef ONLINE_JUDGE
    #define debug(x) cout << "DEBUG: " << #x << " = " << (x) << endl;
    #define print(v) do { \
        cout << "vect--" << #v << " = [ "; \
        for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " "; \
        cout << "]\n"; \
    } while(0)
#else
    #define debug(x)
    #define print(v)
#endif

void myerase(ordered_set &t, int v) {
    auto it = t.find_by_order(t.order_of_key(v));
    if (it != t.end() && *it == v) t.erase(it);
}

ll modAdd(ll a, ll b, ll m = mod7) { return (a + b) % m; }
ll modSub(ll a, ll b, ll m = mod7) { return (a - b + m) % m; }
ll modMul(ll a, ll b, ll m = mod7) { return (a * b) % m; }
ll modExp(ll base, ll exp, ll m = mod7) { 
    ll res = 1; 
    while (exp) { 
        if (exp % 2) res = modMul(res, base, m); 
        base = modMul(base, base, m); 
        exp /= 2; 
    } 
    return res; 
}
ll modInv(ll a, ll m = mod7) { return modExp(a, m - 2, m); }

/*
    Simplify The Problem
*/

/*
    Simple Observations
    ans will always be in decreasing order (not striclty decreasing)
*/

/*
    Algorithm
*/

// So for values of k = 1, 2, 3 ---> n - 1
// how is a good array ? -> agr saare adjacent ka abs diff >= k
void solve() { 
    ll n; cin >> n;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    map<ll, vector<ll>> mp;
    for(ll i = 0; i < n - 1; i++){
        mp[abs(v[i] - v[i + 1])].push_back(i + 1);
    }

    set<pair<ll, ll>> curr;  
    curr.insert({1, n});
    vector<ll> ans;
    ans.push_back((n * (n - 1)) / 2);

    auto contrib = [](ll len) -> ll {
        return len * (len - 1) / 2;
    };

    for(ll k = 2; k < n; k++){
        ll res = ans.back();
        vector<ll> breakPoints = mp[k - 1];
        for(ll bp : breakPoints){
            auto it = curr.upper_bound({bp + 1, -1LL}); 
            --it;
            pair<ll, ll> x = *it;
            ll l = x.first;
            ll r = x.second;

            ll len = r - l + 1;
            res -= contrib(len);
            ll len1 = bp - l + 1;
            ll len2 = r - bp;
            res += contrib(len1) + contrib(len2);

            curr.erase(it);
            curr.insert({l, bp});
            curr.insert({bp + 1, r});
        }
        ans.push_back(res);
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
}

int main() {
    fast_io
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    ll t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
// abcd