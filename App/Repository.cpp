#include "Repository.h"

memoryRepository::memoryRepository()
{
	this->positionOfImage = 0;
}

Image memoryRepository::findImage(const std::string id)
{
	//return this->image.findId(id);
	for (auto i = image.begin(); i < image.end(); i++)
		if (i->getId() == id)
			return *i;}

int memoryRepository::getPosition(const Image& images)
{
	Image foundImage = findImage(images.getId());
	if (foundImage.getId() != "")
		return distance(image.begin(), find(image.begin(), image.end(),foundImage));
	return -1;
}

void memoryRepository::addImage(const Image& newImage)
{
	//return(this->image.addElement(image));
	for (auto i = image.begin(); i < image.end(); i++)
		if (newImage.getId() == i->getId())
			throw AddException{ "The image you try to add already exists\n" };
	image.push_back(newImage);
}
int memoryRepository::deleteImage(const Image& SoonToBeDeletedImage)
{
	//return(this->image.deleteElement(image.getId()));
	std::string id = SoonToBeDeletedImage.getId();
	for (auto i = image.begin(); i < image.end(); i++)
		if (i->getId() == id)
		{
			image.erase(i);
			return 1;}
	return 0;
}
int memoryRepository::updateImage(const Image& newImage)
{
	//return(this->image.updateElement(image));
	for (auto& i : image)
		if (i.getId() == newImage.getId())
		{
			i = newImage;
			return 1;
		}
	return 0;

}
vector<Image> memoryRepository::getSaved() const
{
	return this->saved;
}
int memoryRepository::getSavedSize()
{
	return this->saved.size();
}
int memoryRepository::addSavedImage(const Image& newImage)
{
	for (auto i = saved.begin(); i < saved.end(); i++)
		if (newImage.getId() == i->getId())
			return 0;
	saved.push_back(newImage);
	return 1;
}

Image memoryRepository::getNext()
{
	if (this->positionOfImage == image.size())this->positionOfImage = 0;
	return image[this->positionOfImage++];
}

vector<Image> memoryRepository::getAllImages() 
{
	return this->image;
}
