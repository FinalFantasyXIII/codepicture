#pragma once
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>


using namespace std;
using uint = unsigned int;

template<typename T,uint N>
ostream& operator<< (ostream& os, const array<T,N>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const vector<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const deque<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const forward_list<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const list<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const stack<T>& target)
{
	auto sb = target;
	while (!sb.empty())
	{
		cout << sb.top() << " ";
		sb.pop();
	}
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const queue<T>& target)
{
	auto sb = target;
	while (!sb.empty())
	{
		cout << sb.front() << " ";
		sb.pop();
	}
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const priority_queue<T>& target)
{
	auto sb = target;
	while (!sb.empty())
	{
		cout << sb.top() << " ";
		sb.pop();
	}
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const set<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const multiset<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const unordered_set<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T>
ostream& operator<< (ostream& os, const unordered_multiset<T>& target)
{
	for (const auto& i : target)
		cout << i << " ";
	cout << endl;
	return os;
}

template<typename T, typename U>
ostream& operator<< (ostream& os, const pair<T, U>& target)
{
	cout << target.first << " " << target.second << "\n";
	return os;
}

template<typename T, typename U>
ostream& operator<< (ostream& os, const map<T, U>& target)
{
	for (const auto& i : target)
		cout << i;
	return os;
}

template<typename T, typename U>
ostream& operator<< (ostream& os, const multimap<T, U>& target)
{
	for (const auto& i : target)
		cout << i;
	return os;
}

template<typename T, typename U>
ostream& operator<< (ostream& os, const unordered_map<T, U>& target)
{
	for (const auto& i : target)
		cout << i;
	return os;
}

template<typename T, typename U>
ostream& operator<< (ostream& os, const unordered_multimap<T, U>& target)
{
	for (const auto& i : target)
		cout << i;
	return os;
}
