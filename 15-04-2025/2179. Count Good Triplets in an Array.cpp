class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        idx++;  // Fenwick Tree is 1-based
        while (idx <= n) {
            bit[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        idx++;  // 1-based
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        // Map value -> index in nums2
        vector<int> posInNums2(n);
        for (int i = 0; i < n; ++i) {
            posInNums2[nums2[i]] = i;
        }

        // Convert nums1 to their positions in nums2
        vector<int> mapped(n);
        for (int i = 0; i < n; ++i) {
            mapped[i] = posInNums2[nums1[i]];
        }

        // left[i] = count of numbers less than mapped[i] to the left of i
        vector<int> left(n), right(n);
        FenwickTree bit(n);
        for (int i = 0; i < n; ++i) {
            left[i] = bit.query(mapped[i] - 1);
            bit.update(mapped[i], 1);
        }

        // Reset Fenwick Tree for right side
        bit = FenwickTree(n);
        for (int i = n - 1; i >= 0; --i) {
            right[i] = bit.query(n - 1) - bit.query(mapped[i]);
            bit.update(mapped[i], 1);
        }

        // Count total good triplets
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * left[i] * right[i];
        }

        return ans;
    }
};




// Brute Force
// class Solution {
// public:
//     long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         vector<pair<int,int>> n1(n),n2(n);
//         int j = 0;
//         for(int i = 0;i < n;i++){
//             n1[j] = {nums1[i],i};
//             n2[j] = {nums2[i],i};
//             j++;
//         }
//         sort(n1.begin(),n1.end(),[](pair<int,int>& a,pair<int,int>& b){
//             return a.first < b.first;
//         });
//         sort(n2.begin(),n2.end(),[](pair<int,int>& a,pair<int,int>& b){
//             return a.first < b.first;
//         });
//         // for(auto& num : n1) cout<<"( "<<num.first<<", "<<num.second<<" ), ";
//         // cout<<endl;
//         // for(auto& num : n2) cout<<"( "<<num.first<<", "<<num.second<<" ), ";
//         // cout<<endl;
//         long long ans = 0;

//         for(int i = 0;i < n;i++){
//             const pair<int,int> x = {n1[i].second,n2[i].second};
//             for(int j = 0;j < n;j++){
//                 if(j == i) continue;
//                 const pair<int,int> y = {n1[j].second,n2[j].second};
//                 if(x.first > y.first || x.second > y.second) continue;
//                 for(int k = 0;k < n;k++){
//                     if(k == j || k == i) continue;
//                     const pair<int,int> z = {n1[k].second,n2[k].second};
//                     if(y.first > z.first || y.second > z.second) continue;
//                     ans++;
//                 }
//             }
//         }

//         return ans;

//     }
// };
