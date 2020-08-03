class ProductOfNumbers {
private:
    vector<int> numList;
public:
    ProductOfNumbers() {
        numList = {1};
    }
    
    void add(int num) {
        if (num)
            numList.push_back(num * numList.back());
        else
            numList = {1};
    }
    
    int getProduct(int k) {
        if (k < numList.size())
            return numList.back() / numList[numList.size() - k - 1];
        else
            return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
