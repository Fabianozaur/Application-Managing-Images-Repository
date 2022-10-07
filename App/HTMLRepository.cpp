#include "HTMLRepository.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include <shellapi.h>

HTMLRepository::HTMLRepository(string fileName)
{
	this->fileName = fileName;
	this->len = 0;
}

void HTMLRepository::addSavedImage(const Image& newImage)
{
	vector<Image> images{};
	images = loadHTMLData(this->fileName);
	images.push_back(newImage);
	saveDataInHTML(this->fileName, images);
}
int HTMLRepository::getSavedSize()
{
	vector<Image> images{};
	images = loadHTMLData(this->fileName);
	return images.size();
}
vector<Image> HTMLRepository::getSavedImages()
{
	vector<Image> images{};
	images = loadHTMLData(this->fileName);
	return images;
}

std::vector<Image> HTMLRepository::loadHTMLData(std::string filename)
{
	ifstream file(filename, std::ios::in);
	vector<Image> dataset;
	string line,id, measurement, photograph;
	int i, j, quantity;
	float imageClarityLevel;
	if (!file.is_open())
	{
		ofstream outputFile(filename);
		return dataset;
	}
	for (i = 0; i < 7; ++i)
		getline(file, line);
	for (i = 0; i < this->len; ++i)
	{
		for (j = 0; j < 7; ++j)
		{
			getline(file, line);
			if (j == 1)
				id = line.substr(4, line.size() - 6);
			else if (j == 2)
				measurement = line.substr(4, line.size() - 6);
			else if (j == 3)
				imageClarityLevel = stof(line.substr(4, line.size() - 6));
			else if (j == 4)
				quantity = stoi(line.substr(4, line.size() - 6));
			else if (j == 5)
				photograph = line.substr(4, line.size() - 6);
		}
		dataset.push_back(Image{ id,measurement,imageClarityLevel,quantity,photograph });
	}
	file.close();
	return dataset;
}

void HTMLRepository::saveDataInHTML(std::string filename, std::vector<Image> dataset)
{
	ofstream file(filename, std::ios::out);
	file << "<!DOCTYPE html>\n<html>\n<head>\n<title>Saved Images</title>\n</head>\n<body>\n<table border=\"1\">\n";
	for (auto iterator = dataset.begin(); iterator != dataset.end(); ++iterator)
	{
		Image image = *iterator;
		file << "<tr>\n<td>" << image.getId() << "</td>\n<td>" << image.getMeasurement() << "</td>\n<td>" << to_string(image.getImageClarityLevel()) << "</td>\n<td>" << to_string(image.getQuantity())<<"</td>\n<td>"<< image.getPhotograph() << "</td>\n</tr>\n";
	}
	file << "</table>\n</body>\n</html>";
	file.close();
}


void HTMLRepository::open()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);

}