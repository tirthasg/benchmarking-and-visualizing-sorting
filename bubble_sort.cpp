auto BubbleSort(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    for (int i = 0; i < nums.size(); ++i)
        for (int j = nums.size() - 1; j > i; --j)
            if (nums[j - 1] > nums[j])
                swap(nums[j - 1], nums[j]);

    auto endTime = chrono::system_clock::now();

    return endTime - startTime;
}