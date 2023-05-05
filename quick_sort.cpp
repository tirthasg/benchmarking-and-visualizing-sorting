int Partition(vector<int> &nums, int start, int end)
{
    int randIndex = start + rand() % (end - start + 1);
    swap(nums[start], nums[randIndex]);

    int pivot = nums[start];
    int smaller = start;
    for (int bigger = start + 1; bigger <= end; ++bigger)
        if (nums[bigger] <= pivot)
            swap(nums[++smaller], nums[bigger]);

    swap(nums[start], nums[smaller]);
    return smaller;
}


void QuickHelper(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    int pivotIndex = Partition(nums, start, end);
    QuickHelper(nums, start, pivotIndex - 1);
    QuickHelper(nums, pivotIndex + 1, end);
}

auto QuickSort(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    QuickHelper(nums, 0, nums.size() - 1);
    
    auto endTime = chrono::system_clock::now();

    return endTime - startTime;
}