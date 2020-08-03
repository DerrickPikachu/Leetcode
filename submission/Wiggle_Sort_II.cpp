class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> heap(nums.begin(), nums.end());
        vector<int> min;
        vector<int> max;
        heap.insert(heap.begin(), 0);
        //heapify
        for (int i=(heap.size()-1)/2; i>0; i--) {
            int k = i;
            while (k*2 < heap.size()) {
                int j = k*2;
                if (j+1 < heap.size()) {
                    if (heap[j] > heap[j+1])
                        j++;
                }
                if (heap[k] <= heap[j]) break;
                else swap(heap[k], heap[j]);
                k = j;
            }
        }
        for (int j=1; j<=nums.size(); j++) {
            if (j <= (nums.size()+1)/2) min.push_back(heap[1]);
            else max.push_back(heap[1]);
            int i = 1;
            heap[1] = heap[heap.size()-1];
            heap.pop_back();
            while (i*2 < heap.size()) {
                int k = i*2;
                if (k+1 < heap.size())
                    if (heap[k] > heap[k+1])
                        k++;
                if (heap[i] <= heap[k]) break;
                else swap(heap[i], heap[k]);
                i = k;
            }
        }
        for (int i=0, j=min.size()-1, k=max.size()-1; i<nums.size(); i+=2, j--, k
            --) {
            nums[i] = min[j];
            if (k >= 0)
                nums[i+1] = max[k];
            heap.pop_back();
        }
    }

