vector<int> ThreeWayLomutoPartition(vector<int> &nums, int start, int end)
{
    int randIndex = start + rand() % (end - start + 1);
    swap(nums[start], nums[randIndex]);

    int pivot = nums[start];
    int smaller = start;
    int equal = start;
    for (int bigger = start + 1; bigger <= end; ++bigger)
        if (nums[bigger] == pivot)
            swap(nums[++equal], nums[bigger]);
        else if (nums[bigger] < pivot) {
            swap(nums[++equal], nums[bigger]);
            swap(nums[++smaller], nums[equal]);
        }

    swap(nums[start], nums[smaller]);

    return vector<int> {smaller, equal};
}

void QuickHelperThreeWayLomuto(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    vector<int> indices = ThreeWayLomutoPartition(nums, start, end);
    QuickHelperThreeWayLomuto(nums, start, indices[0] - 1);
    QuickHelperThreeWayLomuto(nums, indices[1] + 1, end);
}

auto QuickSortThreeWayLomuto(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();
    
    QuickHelperThreeWayLomuto(nums, 0, nums.size() - 1);
    
    auto endTime = chrono::system_clock::now();

    return endTime - startTime;
}