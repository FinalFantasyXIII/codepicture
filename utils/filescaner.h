#pragma once

#include <filesystem>
#include <thread>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;


struct dirctory {
	int root;
	fs::path value;
};

class filescaner {
public:
	filescaner(std::string&);
	filescaner(const filescaner&) = delete;
	filescaner operator=(const filescaner&) = delete;

	static std::vector<fs::path> target_dirctory_files(const fs::path&);

	void store(const fs::path&);
	std::vector<dirctory> get_deep_dirctory(int) const;
	std::vector<fs::path> local_dirctory_files(const fs::path&) const;

	int root_deep() const { return deep; }
private:
	fs::path source;
	int deep = 1;
	std::vector<fs::path> files;
	std::vector<dirctory> dirctories;
	std::unordered_multimap<wstring, wstring> df;

	void scan(const fs::path&, int);
};

filescaner::filescaner(std::string& s) :source(s) {
	this->scan(this->source, this->deep);
}

void filescaner::scan(const fs::path& source, int root) {
	if (!fs::exists(source))
		return;
	if (root > this->deep)
		this->deep = root;
	for (auto& i : fs::directory_iterator(source)) {
		if (!i.is_directory()) {
			this->files.push_back(i.path());
			df.insert(std::pair<wstring, wstring>(source.c_str(), i.path().c_str()));
		}
		else {
			dirctory d{ root, i.path() };
			dirctories.push_back(d);
			this->scan(i.path(), root + 1);
		}
	}
}

std::vector<dirctory> filescaner::get_deep_dirctory(int dp) const {
	vector<dirctory> result;
	if (dp > this->deep)
		return result;
	for (const auto& i : this->dirctories) {
		if (dp == i.root)
			result.push_back(i);
	}
	return result;
}

std::vector<fs::path> filescaner::target_dirctory_files(const fs::path& p) {
	vector<fs::path> result;
	if (!fs::directory_entry(p).is_directory())
		return result;
	for (const auto& i : fs::directory_iterator(p))
		result.push_back(i.path());
	return result;
}


std::vector<fs::path> filescaner::local_dirctory_files(const fs::path& p) const {
	vector<fs::path> result;
	if (this->df.find(p.c_str()) == this->df.end())
		return result;
	auto range = this->df.equal_range(p.c_str());
	for (auto it = range.first; it != range.second; ++it)
		result.push_back(it->second);
	return  result;
}