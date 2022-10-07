#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "LoadSave.h"

using namespace std;

vector<Image> loadData(string fileName)
{
	ifstream file(fileName, std::ios::in);
	vector<Image> dataset;
	if (!file.is_open())
	{
		std::ofstream outputFile(fileName);
	}
	Image image;
	//ifstream input(fileName.c_str());
	while (file >> image) {
		dataset.push_back(image);
		//cout << image.getString();
	}
	file.close();
	return dataset;
}

void saveData(string fileName, vector<Image> dataset)
{
	ofstream output(fileName,ios::out);
	for (auto image : dataset)
		output << image << endl;
	output.close();
}