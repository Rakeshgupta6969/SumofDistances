// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
        
//     // using the brute force solution.
// //     int n = nums.size();
// //    vector<long long> ans(n,0);



// //    for(int i = 0; i<n; i++){

// //     long long sum = 0;
    
// //     for(int j = 0; j<n; j++){
     
// //      if(nums[i] == nums[j]  && (i != j)){
// //         sum += fabs(i - j);
// //      }

// //       ans[i] = sum;
// //     }

// //    }

     



// //      return ans;



//    // using the optimap solution.(even these cause the time limit exceeded )

// //    int n  =  nums.size();

// //    unordered_map<long long ,vector<long long>> mp;


// //    for(int i = 0; i<n; i++){
// //     mp[nums[i]].push_back(i); 
// //    } 



// //    vector<long long> ans(n,0);


// //    for(auto & arr : mp){

// //     int p = arr.second.size();
// //     if(p == 1){
// //       ans[arr.second[0]]  = 0;
// //     }

// //     for(long long i = 0; i<p; i++){
// //         long long sum  = 0;
// //         for(long long j  = 0; j<p; j++){
// //              if(i == j) continue;

// //              sum += fabs(arr.second[i] - arr.second[j]);
// //         }

// //         ans[arr.second[i]] = sum;
// //     }


// //    }



// //   return ans;



//     }
// };



class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n, 0);

  
        for (auto& [val, indices] : mp) {
            int k = indices.size();

         
            vector<long long> prefix(k, 0);
            prefix[0] = indices[0];
            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + indices[i];
            }

     
            for (int i = 0; i < k; i++) {
                long long left = i > 0 ? (1LL * i * indices[i] - prefix[i - 1]) : 0;
                long long right = (prefix[k - 1] - prefix[i]) - 1LL * (k - i - 1) * indices[i];
                ans[indices[i]] = left + right;
            }
        }

        return ans;
    }
};