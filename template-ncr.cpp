int N=1e5+1;
int binpow(int a, int b, int m=M){
    if(b==0) return 1;
    int ans=power(a,b/2,m);
    int res=ans*ans%m;
    if(b%2) return res*a%m;
    return res;
}
vector<int> fact(N), invfact(N);
void preComp(int mod=M){
    fact[0]=1;
    int i;
    for(i=1; i<N; i++) fact[i]=i*fact[i-1]%mod;
    i--;
    invfact[i]=binpow(fact[i], mod-2, mod);
    for(i=N-2; i>=0; i--) invfact[i]=invfact[i+1]*(i+1)%mod;
}
int ncr(int n, int r, int mod=M){
    if(r>n || n<0 || r<0) return 0;
    return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}

// - ncr
// {
// 	"ncr": {
// 	// 	"scope": "javascript,typescript",
// 		"prefix": "ncr",
// 		"body": [
// 			"int N=1e5+1;",
// 			"int binpow(int a, int b, int m=M){",
// 			"\tif(b==0) return 1;",
// 			"\tint ans=power(a,b/2,m);",
// 			"\tint res=ans*ans%m;",
// 			"\tif(b%2) return res*a%m;",
// 			"\treturn res;",
// 			"}",
// 			"vector<int> fact(N), invfact(N);",
// 			"void preComp(int mod=M){",
// 			"\tfact[0]=1;",
// 			"\tint i;",
// 			"\tfor(i=1; i<N; i++) fact[i]=i*fact[i-1]%mod;",
// 			"\ti--;",
// 			"\tinvfact[i]=binpow(fact[i], mod-2, mod);",
// 			"\tfor(i=N-2; i>=0; i--) invfact[i]=invfact[i+1]*(i+1)%mod;",
// 			"}",
// 			"int ncr(int n, int r, int mod=M){",
// 			"\tif(r>n || n<0 || r<0) return 0;",
// 			"\treturn fact[n]*invfact[r]%mod*invfact[n-r]%mod;",
// 			"}",
// 		],
// 		"description": "ncr"
// 	}
// }