#pragma once
#include "Image.h"
#include "Exception.h"
#include "LoadSave.h"

using namespace std;

class savedRepository
{
private:

public:
	savedRepository() {};
	virtual void addSavedImage(const Image& image) = 0;
	virtual int getSavedSize() = 0;
	virtual vector<Image> getSavedImages() = 0;
	virtual void open()=0;
};