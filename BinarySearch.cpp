//-----------------------------------------------------------------------------------------
// BinarySearch.cpp
//
// My first attempt at using Github during the process of a project.  
// Here is my version of a binary search algorithm in C++.  
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
void BinarySearch(vector<int> vec) {
	int low, mid, high;

	high = vec.size();
	//cout << "high: " << high << endl;

	low = vec[0];
	//cout << "low: " << low << endl;


	
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
		// cout << "The length of the Array is: " << lenOfArr << " and the number you want to find is: " << numOfInterest << endl;

		// take in a list of numbers and put them in a vector
		// we chose a vector instead of an array because array length need to be known by compile time
		cout << "Please choose a vector of length " << lenOfVec << endl;
		vector<int> v = CreateVec(lenOfVec);
		while (v.size() != lenOfVec) {
			cout << "Please choose a vector of length " << lenOfVec << endl;
			v = CreateVec(lenOfVec);
		}

		BinarySearch(v);
	}
}