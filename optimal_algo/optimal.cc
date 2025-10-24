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

// 202. 快乐数
class Solution 
{
public:
    int bitSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += pow(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        int slow = n, fast = bitSum(n);
        while (slow != fast)
        {
            slow = bitSum(slow);
            fast = bitSum(bitSum(fast));
        }
        return 1 == slow;
    }
};

// 11. 盛最多水的容器
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int n = height.size(), left = 0, right = n - 1, maxArea = 0;
        while (left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            maxArea = max(area, maxArea);
            if (height[left] <= height[right])
                ++left;
            else
                --right;
        }
        return maxArea;

    }
};

// 611. 有效三角形的个数
class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        if (nums.size() < 3)
            return 0;
        int len = nums.size(), sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = len - 1; i >= 2; --i)
        {
            for (int left = 0, right = i - 1; left < right;)
            {
                if (nums[left] + nums[right] <= nums[i])
                    ++left;
                else
                {
                    sum += right - left;
                    --right;
                }
            }
        }
        return sum;
    }
};

// LCR 179. 查找总价格为目标值的两个商品
class Solution 
{
public:
    vector<int> twoSum(vector<int>& price, int target) 
    {
        int len = price.size();
        for (int left = 0, right = len - 1; left < right; )
        {
            if (price[left] + price[right] > target)
                --right;
            else if (price[left] + price[right] < target)
                ++left;
            else
                return {price[left], price[right]};
        }
        return vector<int>(2);
    }
};

// 15. 三数之和
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> threeNum;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for (int i = len - 1; i >= 2; )
        {
            if (nums[i] < 0)
                break;
            int target = -nums[i];
            for (int left = 0, right = i - 1; left < right; )
            {
                int sum = nums[left] + nums[right];
                if (sum > target)
                    --right;
                else if (sum < target)
                    ++left;
                else
                {
                    threeNum.push_back({nums[left++], nums[right--], nums[i]});
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
            }
            --i;
            while (i >= 2 && nums[i] == nums[i + 1]) --i; 
        }
        return threeNum;
    }
};

// 18. 四数之和
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int len = nums.size();
        vector<vector<int>> fourNum;
        sort(nums.begin(), nums.end());
        for (int i = len - 1; i >= 3; )
        {
            for (int j = i - 1; j >= 2; )
            {
                long long ret = (long long)target - nums[i] - nums[j];
                for (int left = 0, right = j - 1; left < right; )
                {
                    long long sum = nums[left] + nums[right];
                    if (sum > ret)
                        --right;
                    else if (sum < ret)
                        ++left;
                    else
                    {
                        fourNum.push_back({nums[left++], nums[right--], nums[j], nums[i]});
                        while (left < right && nums[left] == nums[left - 1])    ++left;
                        while (left < right && nums[right] == nums[right + 1])    --right;
                        cout <<  "i: " << i << ", j: " << j << ", left: " << left << ", right: " << right << endl;
                    }
                }
                --j;
                while (j >= 2 && nums[j] == nums[j + 1])    --j;
            }
            --i;
            while (i >= 3 && nums[i] == nums[i + 1])    --i;
        }
        return fourNum;
    }
};

// 209. 长度最小的子数组
class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        
        int len = nums.size(), minLen = INT_MAX, sum = 0;
        for (int left = 0, right = 0; right < len; ++right)
        {
            sum += nums[right];
            while (sum >= target)
            {
                minLen = min(right - left + 1, minLen);
                sum -= nums[left++];
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};

// 3. 无重复字符的最长子串
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.empty())
            return 0;
        int arr[128] = {0};
        int len = INT_MIN, n = s.size();
        for (int left = 0, right = 0; right < n; ++right)
        {
            arr[s[right]]++;
            while (arr[s[right]] > 1)
                arr[s[left++]]--;
            len = max(right - left + 1, len);
        }
        return len;
    }
};

// 1004. 最大连续1的个数 III
class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n = nums.size(), ret = 0, maxLen = INT_MIN;
        for (int left = 0, right = 0; right < n; ++right)
        {
            if (0 == nums[right])
                ++ret;
            while (ret > k)
            {
                if(0 == nums[left++])
                    --ret;
            }
            maxLen = max(right - left + 1, maxLen);
        }
        return maxLen;
    }
};