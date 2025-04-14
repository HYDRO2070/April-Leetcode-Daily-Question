class Solution {
public:
    int countGoodTriplets(const vector<int>& arr, const int a,const int b,const int c) {
        int ans = 0;
        const int n = arr.size();

        for(int i = 0;i < n-2;i++){
            const int x = arr[i];
            for(int j = i+1;j < n-1;j++){
                const int y = arr[j];
                if(abs(x-y) > a) continue;
                for(int k = j+1;k < n;k++){
                    const int z = arr[k];
                    if(abs(y-z) > b) continue;
                    if(abs(x-z) <= c) ans++;
                }
            }
        }
        return ans;
    }
};
