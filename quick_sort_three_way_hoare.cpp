vector<int> ThreeWayHoarePartition(vector<int> &nums, int start, int end)
{
    int randIndex = start + rand() % (end - start + 1);
    swap(nums[start], nums[randIndex]);

    int pivot = nums[start];
    int smaller = start;
    int equal = start;
    int bigger = end + 1;
    while (bigger - equal > 1)
        if (nums[equal + 1] == pivot)
            ++equal;
        else if (nums[equal + 1] < pivot)
            swap(nums[++smaller], nums[++equal]);
        else 
            swap(nums[--bigger], nums[equal + 1]);

    swap(nums[start], nums[smaller]);

    return vector<int> {smaller, equal};
}

void QuickHelperThreeWayHoare(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    vector<int> indices = ThreeWayHoarePartition(nums, start, end);
    QuickHelperThreeWayHoare(nums, start, indices[0] - 1);
    QuickHelperThreeWayHoare(nums, indices[1] + 1, end);
}

auto QuickSortThreeWayHoare(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    QuickHelperThreeWayHoare(nums, 0, nums.size() - 1);

    auto endTime = chrono::system_clock::now();

    return endTime - startTime;
}