class Solution {
    private:
    int subset(vector<int>& arr,int i,int x){
        if(i >= arr.size()){
            return x;
        }
        int a = subset(arr,i+1,x);
        return a + subset(arr,i+1,x^arr[i]);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        return subset(nums,0,0);
        
    }
};
