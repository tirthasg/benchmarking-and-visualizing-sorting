void MergeOptimizedHelper(vector<int> &nums, int start, int end, vector<int> &aux)
{
    if (start == end)
        return;

    int mid = start + (end - start) / 2;
    MergeOptimizedHelper(nums, start, mid, aux);
    MergeOptimizedHelper(nums, mid + 1, end, aux);

    int i = start;
    int j = mid + 1;
    int k = start;
    while (i <= mid && j <= end)
        if (nums[i] <= nums[j])
            aux[k++] = nums[i++];
        else 
            aux[k++] = nums[j++];

    while (i <= mid)
        aux[k++] = nums[i++];

    while (j <= end)
        aux[k++] = nums[j++];

    for (k = start; k <= end; ++k)
        nums[k] = aux[k];
}

auto MergeSortOptimized(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    vector<int> aux(nums.size());
    MergeOptimizedHelper(nums, 0, nums.size() - 1, aux);

    auto endTime = chrono::system_clock::now();

    return endTime - startTime;
}