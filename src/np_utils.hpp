// Util functions that provide similar functionality to NumPy
#pragma once
#include <vector>
#include <algorithm>


// Main Functionalities
std::vector<std::vector<int>> ndindex(const std::vector<int>& shape);


// Helper
std::vector<int> unravel_index(int index, const std::vector<int>& shape);

