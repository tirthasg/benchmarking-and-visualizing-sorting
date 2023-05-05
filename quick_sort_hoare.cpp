int PartitionHoare(vector<int> &nums, int start, int end)
{
    int randIndex = start + rand() % (end - start + 1);
    swap(nums[start], nums[randIndex]);

    int pivot = nums[start];
    int smaller = start + 1;
    int bigger = end;
    while (smaller <= bigger)
        if (nums[smaller] <= pivot)
            ++smaller;
        else if (nums[bigger] > pivot)
            --bigger;
        else 
            swap(nums[smaller++], nums[bigger--]);

    swap(nums[start], nums[bigger]);
}

void HelperHoare(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    int pivotIndex = Partition(nums, start, end);
    HelperHoare(nums, start, pivotIndex - 1);
    HelperHoare(nums, pivotIndex + 1, end);
}

auto QuickSortHoare(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    HelperHoare(nums, 0, nums.size() - 1);

    auto endTime = chrono::system_clock::now();
    
    return endTime - startTime;
}