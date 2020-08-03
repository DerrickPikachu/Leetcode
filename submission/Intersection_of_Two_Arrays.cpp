class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums2.begin(),nums2.end());
        int left,right,len1,len2,i,j,mid;
        unordered_set<int> ans;
        
        len1 = nums1.size();
        len2 = nums2.size();
        if (nums2.empty() || nums1.empty())  return vector<int> (ans.begin(),ans.end
            ());
        for (i=0;i<len1;i++) {
            //identify whether the element is existed in the ans set
            if (ans.count(nums1[i]) == 0) {
                left = 0;
                right = len2-1;
                while(left <= right) {
                    mid = (left + right)/2;
                    
                    if (nums1[i] < nums2[mid])
                        right = mid-1;
                    else if (nums1[i] > nums2[mid])
                        left = mid+1;
                    else {
                        left = mid;
                        ans.insert(nums1[i]);
                        break;
                    }
                }
            }
            else
                continue;
        }
        return vector<int> (ans.begin(),ans.end());
    }
};
