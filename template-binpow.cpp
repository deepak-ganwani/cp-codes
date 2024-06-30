// Template-1 (Recursion)
int binpow(int a, int b, int m=M){
    if(b==0) return 1;
    int ans=power(a,b/2,m);
    int res=ans*ans%m;
    if(b%2) return res*a%m;
    return res;
}
int mul_inv(int b, int m) {return binpow(b, m-2)%m;}
int mod_sub(int a, int b, int m=M) {return (a%m-b%m+m)%m;}
int mod_div(int a, int b, int m=M) {return a%m*mul_inv(b, m)%m;}

// Template-2 (Iterative)
int bin_pow(int a, int k) {
    int ans=1;
    while(k>0) {
        if(k&1) ans=ans*a;
        a=a*a;
        k/=2;
    }
    return ans;
}

//  - binpow
// {
// 	"Int a raised to Int b": {
// 		// "scope": "javascript,typescript",
// 		"prefix": "binpow",
// 		"body": [
// 			"int binpow(int a, int b, int m=M){",
// 			"\tif(b==0) return 1;",
// 			"\tint ans=binpow(a,b/2,m);",
// 			"\tint res=ans*ans%m;",
// 			"\tif(b%2) return res*a%m;",
// 			"\treturn res;",
// 			"}",
// 			"int mul_inv(int b, int m) {return binpow(b, m-2)%m;}",
// 			"int mod_sub(int a, int b, int m=M) {return (a%m-b%m+m)%m;}",
// 			"int mod_div(int a, int b, int m=M) {return a%m*mul_inv(b, m)%m;}",
// 		],
// 		"description": "Returns a^b"
// 	}
// }