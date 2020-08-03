class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int radius=0,i,j,len1=houses.size(),len2=heaters.size();
        int left,right,mid,first,last;
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        //îñìéËÁheaterîÜêÈöÇãÀfirst
        first = 0;
        left = 0;
        right = len1-1;
        for (i=0;i<heaters.size();i++) {
            while (left <= right) {
                mid = (left + right)/2;
                
                if (heaters[i] < houses[mid])
                    right = mid-1;
                else if (heaters[i] > houses[mid]) 
                    left = mid+1;
                else {
                    left = mid;
                    break;
                }
            }
            //ı­ìéËÁheaterîÜêÈöÇãÀlast
            last = left;
            if (i == 0) {
                radius = heaters[i] - houses[0];
                first = last;
                left = first;
                right = len1-1;
                continue;
            }
            //ÍöÛÜÏ¡ÎÔğíî¤
            if ((heaters[i] - heaters[i-1]) > 2*radius) {
                for (j=first;j<last;j++) {
                    //÷÷Ó¨ãÀÜúî¤ÍöÛÜÏ¡ÊàÒ®
                    if (houses[j] > heaters[i-1]+radius && houses[j] < heaters[i]
                        -radius) {
                        if ((houses[j] - heaters[i-1]) <= (heaters[i] - houses[j]))
                            radius = houses[j] - heaters[i-1];
                        else if ((houses[j] - heaters[i-1]) > (heaters[i] - houses[j]
                            ))
                            radius = heaters[i] - houses[j];
                    }
                    else if (houses[j] > heaters[i-1]+radius && houses[j] > 
                        heaters[i]-radius)
                        break;
                }
                first = last;
            }
            left = first;
            right = len1-1;
        }
        if (houses[len1-1] - heaters[len2-1] > radius)
            radius = houses[len1-1] - heaters[len2-1];
        return radius; 
    }
    
    void quick_sort(vector<int>& arr,int front,int end) {
        int pivot,i,j;
        pivot = arr[end];
        i = front-1;
        
        if (front < end) {
            for (j=front;j<end;j++) {
                if (arr[j] < pivot) {
                    i++;
                    swap(arr[i],arr[j]);
                }
            }
            i++;
            swap(arr[i],arr[end]);
            quick_sort(arr,front,i-1);
            quick_sort(arr,i+1,end);
        }
    }
    
    void swap(int& a,int& b) {
        int t;
        t = a;
        a = b;
        b = t;
    }
};
