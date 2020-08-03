class KthLargest {
private:
    int k;
    vector<int> minheap;
    
    void insert(int val) {
        if (minheap.size() > k) {
            if (val > minheap[1]) {
                minheap[1] = val;
                for (int i=1; i*2<=minheap.size()-1;) {
                    int j = i*2;
                    if (j < minheap.size()-1)
                        //check if minheap[j+1] is exist
                        if (minheap[j] > minheap[j+1])
                            j++;
                    if (minheap[i] < minheap[j]) break;
                    else {
                        swap(minheap[i], minheap[j]);
                        i = j;
                    }
                }
            }
        }
        else {
            minheap.push_back(val);
            for (int i=minheap.size()-1; i/2>0;) {
                if (minheap[i/2] > minheap[i]) {
                    swap(minheap[i/2], minheap[i]);
                    i /= 2;
                }
                else break;
            }
        }
    }
public:
    KthLargest(int k, vector<int> nums) {
        this->k = k;
        minheap.push_back(0);
        for (int i=0; i<nums.size(); i++)
            insert(nums[i]);
    }
    
    int add(int val) {
        insert(val);
        return minheap[1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
