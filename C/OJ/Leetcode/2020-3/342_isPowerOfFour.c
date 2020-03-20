// 执行用时 : 4 ms, 在所有 C 提交中击败了 71.12 % 的用户 内存消耗 : 5 MB, 在所有 C 提交中击败了 100.00 % 的用户

bool isPowerOfFour(int num)
{
    if (num & 0xaaaaaaaa)
        return 0;
    else
    {
        if (!(num & (num - 1)) && num)
            return 1;
    }
    return 0;
}