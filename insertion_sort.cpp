auto InsertionSort(vector<int> nums)
{
    auto startTime = chrono::system_clock::now();

    for (int i = 0; i < nums.size(); ++i) {
        int temp = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > temp) {
            nums[j + 1] = nums[j];
            --j;
        }

        nums[j + 1] = temp;
    }

    auto endTime = chrono::system_clock::now();

    return endTime - startTime;
}