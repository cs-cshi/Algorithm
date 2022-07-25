#include "bits/stdc++.h"

using namespace std;

void mergeSortCore(vector<int> &data, vector<int> &dataTemp, int low, int high)
{
    if (low >= high)
        return;
    int len = high - low, mid = low + len / 2;
    int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
    mergeSortCore(data, dataTemp, start1, end1);
    mergeSortCore(data, dataTemp, start2, end2);
    int index = low;
    while (start1 <= end1 && start2 <= end2)
    {
        dataTemp[index++] = data[start1] < data[start2] ? data[start1++] : data[start2++];
    }
    while (start1 <= end1)
    {
        dataTemp[index++] = data[start1++];
    }
    while (start2 <= end2)
    {
        dataTemp[index++] = data[start2++];
    }
    for (index = low; index <= high; ++index)
    {
        data[index] = dataTemp[index];
    }
}
void mergeSort(vector<int> &data)
{
    int len = data.size();
    vector<int> dataTemp(len, 0);
    mergeSortCore(data, dataTemp, 0, len - 1);
}