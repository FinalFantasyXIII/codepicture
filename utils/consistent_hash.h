#pragma once

#include <set>
#include <string>
#include <unordered_map>
#include <algorithm>

class chash {
public:
	chash(int);
	chash(chash&) = delete;
	chash operator= (chash&) = delete;
	std::string get_node(const std::string&)const ; 
	void add_node(const std::string&);
	void del_node(const std::string&);
private:
	std::hash<std::string>									hashFn;
	int																	replicas;
	std::set<size_t>												nodes;
	std::unordered_map<size_t, std::string>		data;
};

chash::chash(int r) :replicas(r) {}

void chash::add_node(const std::string& s) {
	for (int i = 0; i < this->replicas; ++i) {
		std::string n = s + std::to_string(i);
		size_t node_value = this->hashFn(n);
		this->nodes.insert(node_value);
		this->data.insert(std::pair<size_t, std::string>(node_value, s));
	}
}

void chash::del_node(const std::string& s) {
	for (int i = 0; i < this->replicas; ++i) {
		std::string n = s + std::to_string(i);
		size_t node_value = this->hashFn(n);
		this->data.erase(node_value);
		this->nodes.erase(node_value);
	}
}

std::string chash::get_node(const std::string& s) const {
	if (this->nodes.empty())
		return " ";
	std::size_t node_value = this->hashFn(s);
	auto pos = std::upper_bound(this->nodes.begin(), this->nodes.end(), node_value);
	if (pos != this->nodes.end()) {
		return this->data.at(*pos);
	}
	return this->data.at(*this->nodes.begin());
}