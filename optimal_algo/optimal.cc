// 283.移动零
class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int len = nums.size();
        for (int dest = -1, curr = 0; curr <= len - 1; ++curr)
        {
            if (0 != nums[curr])
                swap(nums[++dest], nums[curr]);
        }
        
    }
};

// 1089.复写零
class Solution 
{
public:
    void duplicateZeros(vector<int>& arr) 
    {
        int len = arr.size();
        int curr = 0, dest = -1;
        for (; dest < len; ++curr)
        {
            if (arr[curr])
                ++dest;
            else
                dest += 2;
            if (dest >= len - 1)
                break;
        }
        cout << curr << " : " << dest << endl;
        if (dest == len)
        {
            arr[--dest] = 0;
            --dest, --curr;
        }
        cout << curr << " : " << dest;

        while (curr >= 0)
        {
            if (arr[curr])
                arr[dest--] = arr[curr--];
            else
            {
                arr[dest--] = arr[curr];
                arr[dest--] = arr[curr--];
            }
        }
    }
};