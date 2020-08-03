class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty())  return nums1;
        if (nums2.empty())  return nums2;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> ans;
        int i,left=0,right=nums1.size()-1,mid;
        
        for (i=0;i<nums2.size();i++) {
            while (left < right) {
                mid = (left+right)/2;
                if (nums2[i] > nums1[mid]) {
                    left = mid+1;
                    cout << "*" << endl;
                }
                else if (nums2[i] < nums1[mid])
                    right = mid-1;
                else
                    right = mid;
            }
            cout << endl;
            if (nums1[left] == nums2[i]) {
                ans.push_back(nums1[left]);
                left++;
            }
            right = nums1.size();
        }
        
        return ans;
    }
};
