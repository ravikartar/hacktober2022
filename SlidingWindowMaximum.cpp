class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        list<int>l;
        if(k>nums.size()){
            ans.push_back(*max_element(nums.begin(), nums.end()));
            return ans;
        }
        int i=0, j=0;
        while(j<nums.size()){
            while(l.size()>0 && l.back()<nums[j])
                l.pop_back();
            l.push_back(nums[j]);
            if(j-i+1<k)
                j++;
            else if(j-i+1 == k){
                ans.push_back(l.front());
                if(nums[i]==l.front())
                    l.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};
