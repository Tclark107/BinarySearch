//-----------------------------------------------------------------------------------------
// BinarySearch.cpp
//
// My first attempt at using Github during the process of a project.  
// Here is my version of a binary search algorithm in C++.  
// It will print 1 if the element is found and -1 if it is not found.
// It will be tested on the command line.
//
// Tristan Clark
// 9/7/19
//-----------------------------------------------------------------------------------------

#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

// Gets cin and puts each element into a vector
vector<int> CreateVec(int lenOfVec) {
	string s;

	getline(std::cin, s);

	istringstream is(s);
	vector<int> v;
	int x;

	while (is >> x) v.push_back(x);

	return v;
}

// how these are read when passed in
// void foo(vector<int> bar); // by value // what we are using
// void foo(vector<int>& bar); // by reference (non-const, so modifyable inside foo
// void foo(vector<int> const& bar); // by const-reference

// my implementation of the binary search algorithm
// prints 1 or -1 if the element is found or not found
// using nested if statements
int BinarySearch(vector<int> vec, int low, int high, int num) {
	int mid = ((high - low) / 2) + low;
	if (low != high) {
		if (num == vec[mid]) {
			return 1;
		}
		else if (num < vec[mid]) {
			return BinarySearch(vec, low, mid - 1, num);
		}
		else if (num > vec[mid]) {
			return BinarySearch(vec, mid + 1, high, num);
		}
	}
	else {
		if (num == vec[mid]) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

int main() {
	int numOfTests;
	cout << "How many tests do you want(Choose a number greater than zero)? ";
	cin >> numOfTests;

	for (int i = 1; i <= numOfTests; ++i)
	{
		int lenOfVec;
		int numOfInterest;
		cout << "Choose how long you want the length of the Vector and the number you want to find: ";
		cin >> lenOfVec;
		cin >> numOfInterest;

		// take in a list of numbers and put them in a vector
		// we chose a vector instead of an array because array length need to be known by compile time
		cout << "Please choose a vector of length " << lenOfVec << endl;
		vector<int> v = CreateVec(lenOfVec);
		while (v.size() != lenOfVec) {
			cout << "Please choose a vector of length " << lenOfVec << endl;
			v = CreateVec(lenOfVec);
		}

		int result = BinarySearch(v, 0, (v.size() - 1), numOfInterest);
		cout << result << endl;
	}
}