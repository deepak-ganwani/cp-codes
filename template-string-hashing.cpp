/*
Solution to the problem:
https://www.codechef.com/problems/BREAKSTRING

- Polynomial Hashing
*/

int pw(int a, int b) {
    if (b == 0) return 1;
    int res = pw(a, b / 2);
    if (b % 2) return (((res * res) % M) * (a % M)) % M;
    return (res * res) % M;
}
int DivM(int a, int b) {
    return (a * pw(b, M - 2)) % M;
}
inline void solve() {
    string s;
    cin >> s;
    int n=s.size();
    int ans=0;
    vector<int> prehash(n+1, 0), power(n+1, 1);
    int p=53;
    for (int i=0; i<n; i++) {
        prehash[i+1]=(prehash[i]+(s[i]-'a'+1)*power[i])%M;
        power[i+1]=(power[i]*p)%M;
    }
    for (int i=0; i<=n; i+=2) {
        int len1 = i/2;
        if ((n-i)%2!=0) continue;
        int len2=(n-i)/2;
        int a=prehash[len1];
        int b=(prehash[2*len1]-prehash[len1]+M)%M;
        b=(DivM(b, power[len1]))%M;
        int c=(prehash[2*len1+len2]-prehash[2*len1]+M)%M;
        c=(DivM(c, power[2*len1]))%M;
        int d=(prehash[2*len1+2*len2]-prehash[2*len1+len2]+M)%M;
        d=(DivM(d, power[2*len1+len2])) % M;
        if(a==b && c==d) ans++;
    }
    cout<<ans<<endl;
}