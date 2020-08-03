class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0;
        int i=0, j=0;
        vector<int> merge;
        
        for (; i<nums1.size() && j < nums2.size();) {
            if (nums1[i] > nums2[j]) {
                merge.push_back(nums2[j]);
                j++;
            }
            else {
                merge.push_back(nums1[i]);
                i++;
            }
        }
        
        if (i >= nums1.size())
            merge.insert(merge.end(), nums2.begin() + j, nums2.end());
        else
            merge.insert(merge.end(), nums1.begin() + i, nums1.end());
        // cout << merge.size() << endl;
        res = (merge.size() % 2 == 0)? ((double)(merge[merge.size() / 2 - 1] + 
            merge[merge.size() / 2]) / 2.0):(double)merge[merge.size() / 2];
        
        return res;
    }
};
