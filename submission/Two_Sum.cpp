class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++) {
            //auto is a type that can have a default type of the assigning variable
            auto p = map.find(target-nums[i]);
            //p is an iterator which is pointing to the element of the class pair
                <const key_type, mapped_type>
            //key_type is the type of the output number of hashtable, and mapped_type 
                is the type of number which is entered to the hashtable
            if (p!=map.end()) {
                // cout << p->first << " " << p->second << endl;
                return {p->second, i};
            }
            map[nums[i]]=i;
        }
    }
};
