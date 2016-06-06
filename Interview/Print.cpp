#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>&);
void printlong(vector<int>&);

void print(vector<int> &arr) {

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void printlong(vector<long long> &arr) {

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

