#include  "Exception.h"
#include "FileRepository.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;


void FileRepository::setFileName(const string path)
{
	this->fileName = path;
}

FileRepository::FileRepository(const string fileName)
{
	this->setFileName(fileName);
	this->positionOfImage = 0;
}

Image FileRepository::findImage(const std::string id)
{
	vector<Image> images;
	images = loadData(this->fileName);
	auto iterator = std::find_if(images.begin(), images.end(), [&id](const Image& obj) {return obj.getId() == id; });
	if (iterator == images.end())
		return Image{};
	return *iterator;
}
int FileRepository::getPosition(const Image& image)
{
	vector<Image> images;
	images = loadData(this->fileName);
	Image foundImage = findImage(image.getId());

	if(foundImage.getId()!="")
		return distance(images.begin(), find(images.begin(), images.end(), foundImage));
	return -1;
}

void FileRepository::addImage(const Image& newImage)
{
	vector<Image> images{};
	images = loadData(this->fileName);
	Image foundImage = findImage(newImage.getId());
	if (foundImage.getId() != "")
		throw AddException{ "The image you try to add already exists\n" };
	images.push_back(newImage);
	saveData(this->fileName, images);
}
int FileRepository::deleteImage(const Image& SoonToBeDeletedImage)
{
	vector<Image> images;
	images = loadData(this->fileName);
	std::string id = SoonToBeDeletedImage.getId();
	Image foundImage = findImage(SoonToBeDeletedImage.getId());
	if (foundImage.getId() == "")
		throw DeleteException{ "The image you try to delete doesnt exists\n" };
	for (auto i = images.begin(); i < images.end(); i++)
		if (i->getId() == id)
		{
			images.erase(i);
			saveData(this->fileName, images);
			}
	return 0;
}
int FileRepository::updateImage(const Image& newImage)
{
	vector<Image> images;
	images = loadData(this->fileName);
	Image foundImage = findImage(newImage.getId());
	if (foundImage.getId() == "")
		throw UpdateException{ "The image you try to update doesnt exists\n" };
	for (auto& i : images)
		if (i.getId() == newImage.getId())
		{
			i = newImage;
			saveData(this->fileName, images);
		}
}
vector<Image> FileRepository::getSaved() const
{
	return this->saved;
}
vector<Image> FileRepository::getAllImages() 
{
	vector<Image> images;
	images = loadData(this->fileName);
	return images;
}
int FileRepository::getSavedSize()
{
	return this->saved.size();
}
int FileRepository::addSavedImage(const Image& newImage)
{
	for (auto i = saved.begin(); i < saved.end(); i++)
		if (newImage.getId() == i->getId())
			return 0;
	saved.push_back(newImage);
	return 1;
}

Image FileRepository::getNext()
{
	std::vector<Image> images{};
	images = loadData(this->fileName);
	if (this->positionOfImage == images.size())this->positionOfImage = 0;
	return images[this->positionOfImage++];
}
