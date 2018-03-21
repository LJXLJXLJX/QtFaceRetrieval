#pragma once
#include <string>
#include <vector>
#include <filesystem>

void getFiles(std::string path, std::vector<std::string>& files);

int API_TimeToString(const time_t &timeData, std::string &DateStr);


std::string randomSerise();
