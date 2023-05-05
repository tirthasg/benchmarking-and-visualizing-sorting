void Merge(vector<int> &nums, int start, int mid, int end)
{
    int N = end - start + 1;
    vector<int> aux(N);

    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
        if (nums[i] <= nums[j])
            aux[k++] = nums[i++];
        else
            aux[k++] = nums[j++];

    while (i <= mid)
        aux[k++] = nums[i++];

    while (j <= end)
        aux[k++] = nums[j++];

    for (int k = 0; k < N; ++k)
        nums[k + start] = aux[k];
}

void MergeHelper(vector<int> &nums, int start, int end)
{
    if (start == end)
        return;

    int mid = start + (end - start) / 2;
    MergeHelper(nums, start, mid);
    MergeHelper(nums, mid + 1, end);

    Merge(nums, start, mid, end);
}


auto MergeSort(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    MergeHelper(nums, 0, nums.size() - 1);

    auto endTime = chrono::system_clock::now();


    return endTime - startTime;
}