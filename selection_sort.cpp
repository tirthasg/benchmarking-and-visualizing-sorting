auto SelectionSort(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    for (int i = 0; i < nums.size(); ++i) {
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); ++j)
            if (nums[j] < nums[minIndex])
                minIndex = j;
        
        swap(nums[i], nums[minIndex]);
    }

    auto endTime = chrono::system_clock::now();

    return endTime - startTime;
}