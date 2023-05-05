#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <chrono>
using namespace std;

#include "print_vector.cpp"
#include "selection_sort.cpp"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "merge_sort.cpp"
#include "merge_sort_optimized.cpp"
#include "quick_sort.cpp"
#include "quick_sort_hoare.cpp"
#include "quick_sort_three_way_lomuto.cpp"
#include "quick_sort_three_way_hoare.cpp"

int main()
{
    srand(time(0));
    int start = 0;
    int end = 100;

    int N = 100000;
    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
        nums[i] = start + rand() % (end - start + 1); 

    /*
    cout << "Unsorted vector: ";
    PrintVector(nums);
    cout << endl;
    */
    
    auto selectionTime = SelectionSort(nums);
    cout << "Selection Sort: "
         << chrono::duration_cast<chrono::milliseconds>(selectionTime).count() / 1000.0 << " seconds" << endl;

    auto bubbleTime = BubbleSort(nums);
    cout << "Bubble Sort: "
         << chrono::duration_cast<chrono::milliseconds>(bubbleTime).count() / 1000.0 << " seconds" << endl;

    auto insertionTime = InsertionSort(nums);
    cout << "Insertion Sort: " 
         << chrono::duration_cast<chrono::milliseconds>(insertionTime).count() / 1000.0 << " seconds" << endl;

    auto mergeTime = MergeSort(nums);
    cout << "Merge Sort: " 
         << chrono::duration_cast<chrono::milliseconds>(mergeTime).count() / 1000.0 << " seconds" << endl;

    auto mergeOptimizedTime = MergeSortOptimized(nums);
    cout << "Merge Sort Optimized: " 
         << chrono::duration_cast<chrono::milliseconds>(mergeOptimizedTime).count() / 1000.0 << " seconds" << endl;

    auto quickTime = QuickSort(nums);
    cout << "Quick Sort Two Way Lomuto: " 
         << chrono::duration_cast<chrono::milliseconds>(quickTime).count() / 1000.0 << " seconds" << endl;

    auto quickHoareTime = QuickSortHoare(nums);
    cout << "Quick Sort Two Way Hoare: " 
         << chrono::duration_cast<chrono::milliseconds>(quickHoareTime).count() / 1000.0 << " seconds" << endl;

    auto quickThreeWayLomutoTime = QuickSortThreeWayLomuto(nums);
    cout << "Quick Sort Three Way Lomuto: " 
         << chrono::duration_cast<chrono::milliseconds>(quickThreeWayLomutoTime).count() / 1000.0 << " seconds" << endl;

    auto quickThreeWayHoareTime = QuickSortThreeWayHoare(nums);
    cout << "Quick Sort Three Way Hoare: " 
         << chrono::duration_cast<chrono::milliseconds>(quickThreeWayHoareTime).count() / 1000.0 << " seconds" << endl;

    return 0;
}