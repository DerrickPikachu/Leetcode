class Solution {
public:
    int findContentChildren(vector<int>& child, vector<int>& cookie) {
        if (child.empty() || cookie.empty())    return 0;
        sort(child.rbegin(),child.rend());
        sort(cookie.rbegin(),cookie.rend());
        int thisChild=0,content=0;
        
        for (int i=0; i<cookie.size(); i++) {
            while (cookie[i] < child[thisChild]) {
                thisChild++;
                if (thisChild >= child.size())
                    return content;
            }
            content++;
            thisChild++;
            if (thisChild >= child.size())
                return content;
        }
        
        return content;
    }
};
