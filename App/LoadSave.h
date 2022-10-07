#pragma once
#include <string>
#include <vector>
#include "Image.h"

using namespace std;

vector<Image> loadData(string fileName);
void saveData(string fileName, vector<Image> dataset);