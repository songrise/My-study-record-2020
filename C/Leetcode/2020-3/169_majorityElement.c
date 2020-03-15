// 执行用时 : 20 ms, 在所有 C 提交中击败了 95.48 % 的用户 内存消耗 : 7.4 MB, 在所有 C 提交中击败了 100.00 % 的用户
//Moore majority vote algorithm(摩尔投票算法) https://www.cnblogs.com/zhonghuasong/p/6536665.html
int majorityElement(int *nums, int numsSize)
{
    int i, count = 1, ans = nums[0], temp = ans;
    for (i = 1; i < numsSize; i++)
    {
        temp = nums[i];

        if (ans == temp) //unpredictable
        // but I think it may be hard to optimize (using conditional move) this as count will be used later in each iteration.
        {
            count++;
            continue; //add this to promote 50% performance. This is close to 50% penalty for a unpredictable "if"
        }
        else
        {
            count--;
        }

        if (!count)
        {
            ans = temp;
            count++;
        }
    }
    return ans;
}
