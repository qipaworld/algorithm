class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> keys;
        int count = nums.size();
        vector<int> v;
        for (int i = 0; i < count; ++i)
        {
            int value = nums[i];
            int difference = target - value;
            auto difference_index = keys.find(difference);
            if (difference_index != keys.end())
            {
                v.push_back(difference_index->second);
                v.push_back(i);
                break;
            }
            else 
            {
                keys[value] = i;
            }
            
        }
        return v;
    }
};