int arr[1e6 + 1];
void sieve(){
    int maxN = 1e6;
    for (int i = 1; i <= maxN;i++)   //preprocessing takes O(n) time
        arr[i] = -1;

    for (int i = 2; i * i <= maxN;i++){
        if(arr[i]==-1){
            for (int j = i * i; j <= maxN;j+=i){
                if (arr[j]==-1)                    //O(logn) time
                    arr[j] = i;
            }
        }
    }
}

//this works well when there are multiple queries.