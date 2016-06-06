#include "stdafx.h"
#include "helpers.h"
#include <iostream>
#include <vector>

using namespace std;

void maxSubArray1(vector<int>&);
void maxSubArray2(vector<int>&);
void maxSubArrayMain();

void maxSubArray1(vector<int> &A) {
    int i;
    vector<long long> maxArrayCount;
    maxArrayCount.resize(A.size());

    vector<int> maxArrayLength(A.size(), 1);

    if (A[A.size() - 1] > 0) {
        maxArrayCount[A.size() - 1] = static_cast<long long>(A[A.size() - 1]);
    }
    else {
        maxArrayCount[A.size() - 1] = 0L;
        maxArrayLength[A.size() - 1] = 0;
    }

    for (i = A.size() - 2; i >= 0; i--) {
        if (A[i]<0) {

            // Can't be an element in the max non-negative sub array.
            maxArrayCount[i] = 0L;
            maxArrayLength[i] = 0;

        }
        else {
            maxArrayCount[i] = static_cast<long long>(A[i]) + maxArrayCount[i + 1];
            maxArrayLength[i] = maxArrayLength[i + 1] + 1;
        }
    }

    print(maxArrayLength);
    printlong(maxArrayCount);

    long long maxSum = 0;
    int length = 0, index = 0;

    for (i = 0; i < A.size(); i++) {
        if (maxArrayCount[i] > maxSum) {
            maxSum = maxArrayCount[i];
            length = maxArrayLength[i];
            index = i;
        }
        else if (maxArrayCount[i] == maxSum) {
            if (maxArrayLength[i] > length) {
                maxSum = maxArrayCount[i];
                length = maxArrayLength[i];
                index = i;
            }
            else if (i < index) {
                maxSum = maxArrayCount[i];
                length = maxArrayLength[i];
                index = i;
            }
        }
    }

    cout << index << " " << length << endl;
    vector<int> subarray(A.begin() + index, A.begin() + index + length);

    print(subarray);
}

void maxSubArray2(vector<int> &A) {
    long long maxSum = 0, curSum = 0;
    int maxStartIndex = 0, maxLength = 0, curStartIndex = 0, curLength = 0, i;
    bool updateMax = false;

    for (i = 0; i < A.size(); i++) {

        updateMax = false;

        if (A[i] < 0) {

            if (curSum > maxSum) {
                updateMax = true;
            }
            else if (curSum == maxSum) {
                if (maxLength < curLength) {
                    updateMax = true;
                }
                else if (maxStartIndex > curStartIndex) {
                    updateMax = true;
                }
            }
            curSum = 0;
            curStartIndex = i + 1;
            curLength = 0;
        }
        else {
            curSum += static_cast<long long>(A[i]);
            cout << curSum << endl;
            curLength += 1;

            if (curSum > maxSum) {
                updateMax = true;
            }
            else if (curSum == maxSum) {
                if (maxLength < curLength) {
                    updateMax = true;
                }
                else if (maxStartIndex > curStartIndex) {
                    updateMax = true;
                }
            }
        }

        if (updateMax) {
            maxSum = curSum;
            maxLength = curLength;
            maxStartIndex = curStartIndex;
        }
    }

    cout << maxStartIndex << " " << maxLength << " " << maxSum << endl;
    vector<int> subarray(A.begin() + maxStartIndex, A.begin() + maxStartIndex + maxLength);

    print(subarray);
}

void maxSubArrayMain() {

    int size, i, temp;
    vector<int> A;

    cin >> size;

    for (i = 0; i < size; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    maxSubArray2(A);
}
