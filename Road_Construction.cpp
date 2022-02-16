#include<bits/stdc++.h>
using namespace std;

int par[100001],R[100001];

int find(int a){
    if(par[a] == -1) return a;
    return par[a] = find(par[a]);
}

int uni(int a, int b){
    a = find(a);
    b = find(b);

    if(R[a]>R[b]) swap(a,b);

    par[a] =b;
    R[b]+=R[a];
    
    return R[b];
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        par[i]=-1;
        R[i]=1;
    }
    int cc = n;
    int mx = 1;
    while(m--){
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b)){
            mx = max(mx,uni(a,b));
            cc--;
        }
        cout<<cc<<" "<<mx<<endl;
    }
    return 0;
}