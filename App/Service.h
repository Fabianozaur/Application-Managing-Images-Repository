#pragma once
#include "Repository.h"
#include "Validate.h"
#include "FileRepository.h"
#include "SavedRepository.h"
#include "CSVRepository.h"
#include "HTMLRepository.h"

class Service
{
private:
	Repository& repository;
	savedRepository& savedrepository;
	Validate validate;
public:
	Service(Repository& repository, savedRepository& savedrepository) : repository{ repository }, savedrepository{ savedrepository }{};
	Image findImageInRepository(const std::string id);
	void addImageInSaved(const Image& image);
	int getSavedSize();
	void addImageInRepository(const std::string& id, const std::string& measurement, float imageClarityLevel, int quantity, const std::string& photograph);
	int deleteImageInRepository(const std::string& id);
	int updateImageInRepository(const std::string& id, const std::string& measurement, float imageClarityLevel, int quantity, const std::string& photograph);

	vector<Image> getAllImagesInRepository() const;
	vector<Image> getAllInSavedList() const;
	void getValidDigits(const std::string& toValidate);
	void getValidFloat(const std::string& toValidate);
	Image getNext();
	void open();
};