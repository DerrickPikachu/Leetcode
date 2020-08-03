class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,len;
        len = prices.size();
        
        if (prices.empty())  return 0;
        find(&ans,prices,0,len-1);
        return ans;
    }
    
    void find(int* maximum,vector<int>& arr,int front,int end) {
        int mid,min,max;
        mid = (front + end)/2;
        
        if (front < end) {
            max = get_max(arr,mid+1,end);
            min = get_min(arr,front,mid);
            if (*maximum < (max-min))
                *maximum = max-min;
            find(maximum,arr,mid+1,end);
            find(maximum,arr,front,mid);
        }
    }
    
    int get_min(vector<int>& arr,int front,int end) {
        int i,min=INT_MAX;
        for (i=front;i<=end;i++) {
            if (min > arr[i])
                min = arr[i];
        }
        return min;
    }
    
    int get_max(vector<int>& arr,int front,int end) {
        int i,max=0;
        for (i=front;i<=end;i++) {
            if (max < arr[i])
                max = arr[i];
        }
        return max;
    }
};
