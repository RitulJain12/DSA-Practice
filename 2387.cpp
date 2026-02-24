//it is the best question of bs on ans in which we  have to find the median of an 2d array in which row is sorted so we take l=minimum  elem and h=max ele and we apply binary search on the answer 

#include<bits/stdc++.h>
using namespace std;
int countLessEqual(vector<vector<int>>& matrix, int mid) {
    int count = 0;
    for (const auto& row : matrix) {
        count += upper_bound(row.begin(), row.end(), mid) - row.begin();
    }
    return count;
}

int findMedian(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = matrix[0][0];
    int high = matrix[n - 1][m - 1];
    int desired = (n * m + 1) / 2;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (countLessEqual(matrix, mid) < desired) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median: " << findMedian(matrix) << endl;
    return 0;
}