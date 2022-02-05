const long long INF = 1e18; 
const int mod=1e9+7;
const int mod2=998244353;
inline int add(int x,int y){
    x+=y;
    if (x>=mod) return x-mod;
    return x;
}
inline int sub(int x,int y){
    x-=y;
    if (x<0) return x+mod;
    return x;
}
inline int mul(int x,int y){
    return (x*1ll*y)%mod;
}
inline int power(int x,int y){
    int ans=1;
    while(y){
        if (y&1) ans=mul(ans,x);
        x=mul(x,x);
        y>>=1;
    }
    return ans;
}
inline int inv(int x){
    return power(x,mod-2);
}

const ll FACTORIAL_SIZE = 1.1e6;
ll fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
void gen_factorial(ll n) {
	fact[0] = fact[1] = ifact[0] = ifact[1] = 1;
		
	for (ll i = 2; i <= n; i++) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	ifact[n] = inv(fact[n]);
	for (ll i = n - 1; i >= 2; i--) {
		ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
	}
}


ll nck(ll n, ll k) {
	ll den = (ifact[k] * ifact[n - k]) % mod;
	return (den * fact[n]) % mod;
}
