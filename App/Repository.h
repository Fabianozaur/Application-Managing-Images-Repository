#pragma once
#include "DynamicVector.h"
#include "LoadSave.h"
#include "Exception.h"


using namespace std;

class Repository
{
private:
	
public:
	Repository() {};
	virtual Image findImage(const std::string id)=0;
	virtual int getPosition(const Image& image) = 0;
	virtual void addImage(const Image& image)=0;
	virtual int deleteImage(const Image& image)=0;
	virtual int updateImage(const Image& image)=0;
	virtual vector<Image> getSaved() const=0;
	virtual int getSavedSize()=0;
	virtual int addSavedImage(const Image& image)=0;
	virtual vector<Image> getAllImages() = 0;
	virtual Image getNext() = 0;
};

class memoryRepository :public Repository
{
private:
	vector<Image> image;
	vector<Image> saved;
	int positionOfImage;
public:
	memoryRepository();
	Image findImage(const std::string id) override;
	int getPosition(const Image& image) override;
	void addImage(const Image& image) override;
	int deleteImage(const Image& image) override;
	int updateImage(const Image& image) override;
	vector<Image> getSaved() const override;
	int getSavedSize() override;
	int addSavedImage(const Image& image) override;
	Image getNext() override;
	vector<Image> getAllImages()  override;
};

class secondaryMemoryRepoitory : public Repository
{

};

