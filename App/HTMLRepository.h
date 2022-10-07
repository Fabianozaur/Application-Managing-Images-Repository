#pragma once
#include "SavedRepository.h"
#include <iostream>
#include <vector>

using namespace std;

class HTMLRepository :public savedRepository
{
private:
	string fileName;
	int len;
public:
	HTMLRepository(string fileName);
	void addSavedImage(const Image& image) override;
	int getSavedSize() override;
	vector<Image> getSavedImages() override;
	vector<Image> loadHTMLData(std::string filename);
	void saveDataInHTML(std::string filename, std::vector<Image> dataset);
	void open() override;

};