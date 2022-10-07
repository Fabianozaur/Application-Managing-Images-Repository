#include "CSVRepository.h"
#include <Windows.h>
#include <shellapi.h>

CSVRepository::CSVRepository(string fileName)
{
	this->fileName = fileName;
}

void CSVRepository::addSavedImage(const Image& newImage)
{
	vector<Image> images{};
	images = loadData(this->fileName);
	images.push_back(newImage);
	saveData(this->fileName, images);
}
int CSVRepository::getSavedSize() 
{
	vector<Image> images{};
	images = loadData(this->fileName);
	return images.size();
}
vector<Image> CSVRepository::getSavedImages()
{
	vector<Image> images{};
	images = loadData(this->fileName);
	return images;
}

void CSVRepository::open()
{
	
	system(this->fileName.c_str());

}