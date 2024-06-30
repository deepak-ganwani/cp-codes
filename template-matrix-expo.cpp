struct Matrix {
    int a[2][2]={{0,0},{0,0}};
    Matrix operator*(const Matrix& b) {
        Matrix res;
        for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++) {
            res.a[i][k]+=a[i][j]*b.a[j][k];
        }
        return res;
    }
};
Matrix expo_power(Matrix a, int k) {
    Matrix ans;
    for(int i=0; i<2; i++) ans.a[i][i]=1;
    while(k>0) {
        if(k&1) ans=ans*a;
        a=a*a;
        k/=2;
    }
    return ans;
}