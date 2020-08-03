class Solution {
private:
    long int maxDifference(int bound, vector<int>& cuts) {
        long int maxi = cuts[0] - 0;
        for (int i = 1; i < cuts.size(); i++)
            maxi = max((long int)(cuts[i] - cuts[i-1]), maxi);
        maxi = max((long int)(bound - cuts.back()), maxi);
        return maxi;
    }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
        {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        return (int)((maxDifference(h, horizontalCuts) * maxDifference(w, 
            verticalCuts)) % (long int)(pow(10, 9) + 7));
    }
};
