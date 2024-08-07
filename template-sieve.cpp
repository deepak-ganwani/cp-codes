const int N=2e5+10;
vector<int> primes(N,0), pr;
void fill(){
    for(int i=2; i<N; i++){
        if(primes[i]==0){
            pr.emplace_back(i);
            for(int j=i*i; j<=N; j+=i) primes[j]=1;
        }
        primes[i]^=1;
    }
}

// Template - 2
const int N=2e5+10;
vector<int> primes(N,1), pr;
void fill(){
    primes[0]=primes[1]=0;
    for(int i=2; i<N; i++){
        if(primes[i]==0) continue;
        if(primes[i]){
            pr.emplace_back(i);
            for(int j=2*i; j<=N; j+=i) primes[j]=0;
        }
    }
}

// - sieve
// {
// "Sieve of Erastosthenes": {
// 		// "scope": "javascript,typescript",
// 		"prefix": "sieve",
// 		"body": [
// 			"int N=1e5+1;",
// 			"vector<int> primes(N,0), pr;",
// 			"int binpow(int a, int b, int m=M){",
// 			"\tif(b==0) return 1;",
// 			"\tint ans=power(a,b/2,m);",
// 			"\tint res=ans*ans%m;",
// 			"\tif(b%2) return res*a%m;",
// 			"\treturn res;",
// 			"}",
// 			"void fill(){",
// 			"\tfor(int i=2; i<=N; i++){",
// 			"\t\tif(primes[i]==0){",
// 			"\t\t\tpr.emplace_back(i);",
// 			"\t\t\tfor(int j=i*i; j<=N; j+=i) primes[j]=0;",
// 			"\t\t}",
// 			"\t\tprimes[i]^=1;",
// 			"\t}",
// 			"}",
// 		],
// 		"description": "Pre-computes the primes till 1e5+1"
// 	}
// 	}
// }