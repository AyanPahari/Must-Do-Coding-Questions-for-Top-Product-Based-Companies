class Solution {
public:
    
    int merge(vector<int>&arr,int low,int mid,int high){
        
        int count=0;
        int n1=mid-low+1;
        int n2=high-mid;
        int left[n1],right[n2];
        
        for(int i=0;i<n1;i++) left[i]=arr[low+i];
        for(int i=0;i<n2;i++) right[i]=arr[mid+i+1];
        
        int ptr=0;
        for(int i=0;i<n1;i++){
            while(ptr<n2 && left[i]>2LL*right[ptr]) ptr++;
            count+=ptr;
        }
        
        int i=0,j=0,k=low;
        
        while(i<n1 && j<n2){
            if(left[i]<=right[j]){
                arr[k++]=left[i++];
            }
            else{
                arr[k++]=right[j++];
            }
        }
        while(i<n1){
            arr[k++]=left[i++];
        }
        while(j<n2){
            arr[k++]=right[j++];
        }
        return count;
    }
    
    int mergeSort(vector<int>&arr,int low,int high){
        
        int count=0;
        if(low<high){
            int mid=low+(high-low)/2;
            count+=mergeSort(arr,low,mid);
            count+=mergeSort(arr,mid+1,high);

            count+=merge(arr,low,mid,high);
        }
        return count;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};