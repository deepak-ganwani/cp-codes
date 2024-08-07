// Template-1 (Recursion)
int bin_pow(int a, int b, int m=M){
    if(b==0) return 1;
    int ans=bin_pow(a,b/2,m);
    int res=ans*ans%m;
    if(b%2) return res*a%m;
    return res;
}
int mul_inv(int b, int m) {return bin_pow(b, m-2)%m;}
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