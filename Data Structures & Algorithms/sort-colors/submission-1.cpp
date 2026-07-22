class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0 ; i < n; i++) {
            if(nums[i] == 2) {
                while(n >0 && (n-1 !=i) && nums[n-1] == 2)
                    n--;
                swap(nums[n-1],nums[i]);
                //cout<<"2 "<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<endl;
                n--;
            }
            if(nums[i] == 0) {
                swap(nums[k++], nums[i]);
                //cout<<"0 "<<nums[0]<<" "<<nums[1]<<" "<<nums[2]<<endl;
                
            }
        }
        //cout<<" n "<<n<<" k "<<k<<endl;
//for(int i = k; i<n ; i++) {
  //          nums[i] = 1;
    //    }
    }
};