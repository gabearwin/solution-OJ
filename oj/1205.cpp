#include<stdio.h>
int main(){
    int n;
    long long f[100];
    f[0]=0,f[1]=1,f[2]=2;
    for(int i=3;i<90;i++){
        f[i]=f[i-1]+f[i-2];
    }
    while(scanf("%d",&n)!=EOF){
        printf("%lld\n",f[n]);
    }
    return 0;
}
