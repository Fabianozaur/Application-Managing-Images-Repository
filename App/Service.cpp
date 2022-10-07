#include "Service.h"
#include <iostream>

using namespace std;

Image Service::findImageInRepository(const std::string id)
{
	return this->repository.findImage(id);
}

void Service::addImageInSaved(const Image& image)
{
	this->savedrepository.addSavedImage(image);
}

int Service::getSavedSize()
{
	return this->repository.getSavedSize();
}

void Service::addImageInRepository(const std::string& id, const std::string& measurement, float imageClarityLevel, int quantity, const std::string& photograph)
{
	
	Image image{ id,measurement,imageClarityLevel,quantity,photograph };
	this->repository.addImage(image);

}

int Service::deleteImageInRepository(const std::string& id)
{

		Image image{ id,"",0,0,"" };
		return(this->repository.deleteImage(image));
}

int Service::updateImageInRepository(const std::string& id, const std::string& measurement, float imageClarityLevel, int quantity, const std::string& photograph)
{

		Image image{ id,measurement,imageClarityLevel,quantity,photograph };
		return(this->repository.updateImage(image));

}

vector<Image> Service::getAllImagesInRepository() const
{
	return this->repository.getAllImages();
}

vector<Image> Service::getAllInSavedList() const
{
	return this->repository.getSaved();

}

void Service::getValidDigits(const std::string& toValidate)
{
	this->validate.validateStringAllDigits(toValidate);
}

void Service::getValidFloat(const std::string& toValidate)
{
	this->validate.validateStringFloat(toValidate);
}

Image Service::getNext()
{
	return this->repository.getNext();
}

void Service::open()
{
	this->savedrepository.open();
}

