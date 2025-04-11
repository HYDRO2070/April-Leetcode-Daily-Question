class Solution {
    private:
    // Brute Force
    // static bool check(const int num){
    //     // string s_num = to_string(num);
    //     int n = s_num.size();
    //     if(n&1) return false;
    //     int sum = 0;
    //     for(int i = 0;i <(n/2);i++){
    //         sum += (s_num[i] - '0') - (s_num[n-1-i] - '0');
    //     }
    //     return (sum == 0);
    // }
    static bool check(const int num,const int size){
        int temp = num;
        int sum = 0;
        for(int i = 0;i < size;i++){
            sum += temp%10;
            temp /= 10;
        }
        for(int i = 0;i < size;i++){
            sum -= temp%10;
            temp /= 10;
        }
        return (sum == 0);
    }
public:
    int countSymmetricIntegers(const int low,const int high) {
        int ans = 0;

        // auto check = [](int num,int size){
        //     int sum = 0;
        //     string s_num = to_string(num);
        //     for(int i = 0;i <(size/2);i++){
        //         sum += (s_num[i] - '0') - (s_num[size-1-i] - '0');
        //     }
        //     return (sum == 0);
        // };


        for(int i = low;i <= high;i++){
            int n = log10(i)+1;
            if(n%2 == 0 && check(i,n/2)) ans++;
        }


        return ans;
    }
};
