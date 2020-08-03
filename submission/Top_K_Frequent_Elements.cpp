class Solution {
private:
    void binarySearch(int element, int key, vector<int>& arr, unordered_map<int, int
        >& mp, int k) {
        int left = 0, right = arr.size()-1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (mp[arr[mid]] > key)
                left = mid + 1;
            else if (mp[arr[mid]] < key)
                right = mid - 1;
            else {
                left = mid;
                break;
            }
        }
        
        arr.insert(arr.begin() + left, element);
        if (arr.size() > k)
            arr.pop_back();
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        unordered_set<int> viewed;
        vector<int> ans;
        
        for (int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (!viewed.count(nums[i])) {
                viewed.insert(nums[i]);
                binarySearch(nums[i], mp[nums[i]], ans, mp, k);
            }
        }
        
        return ans;
    }
};
