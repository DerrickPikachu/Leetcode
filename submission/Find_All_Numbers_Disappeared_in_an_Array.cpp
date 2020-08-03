class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int lenth = nums.size();
        bool check[lenth+1]={0};
        int i;
        vector<int> answer;
        
        for (i=0;i<lenth;i++) {
            check[nums.at(i)] = 1;
        }
        
        for (i=1;i<=lenth;i++) {
            if (check[i] == 0) {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};
