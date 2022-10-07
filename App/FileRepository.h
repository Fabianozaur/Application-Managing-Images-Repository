#pragma once
#include "Repository.h"
#include <vector>

using namespace std;

class FileRepository :public Repository
{
private:
	int positionOfImage;
	vector<Image> saved;
	string fileName;
public:
	FileRepository(const string fileName);
	void setFileName(const std::string path);
	Image findImage(const std::string id) override;
	int getPosition(const Image& image)override;
	void addImage(const Image& image) override;
	int deleteImage(const Image& image)override;
	int updateImage(const Image& image)override;
	vector<Image> getSaved() const override;
	vector<Image> getAllImages() override;
	int getSavedSize() override;
	int addSavedImage(const Image& image) override;
	Image getNext()override;
	
};