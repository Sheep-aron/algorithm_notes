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