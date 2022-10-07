#pragma once
#include "SavedRepository.h"
#include <iostream>
#include <vector>

using namespace std;

class CSVRepository :public savedRepository
{
private:
	string fileName;
public:
	CSVRepository(string fileName);
	void addSavedImage(const Image& image) override;
	int getSavedSize() override;
	vector<Image> getSavedImages() override;
	void open() override;
	
};