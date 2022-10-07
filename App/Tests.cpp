#include "Tests.h"
#include <assert.h>
/*
void Test::testAll()
{
	Test test{};
	test.getId_getImagesId_idIsCorect();
	test.getMeasurement_getImagesMeasurement_measurementIsCorect();
	test.getImageClarity_getImagesImageClarity_imageClairtyIsCorect();
	test.getQuantity_getImagesQuantity_imageQuantityIsCorect();
	test.getPhotograph_getImagePhotograph_imagePhotographIsCorect();
	test.addImage_ValidInput_addsImageToRepository();
	test.addImage_InvalidInput_DosntAddImageToRepository();
	test.deleteImage_ValidInput_deleteImageFromRepository();
	test.updateImage_InvalidInput_DoesntUpdateImageInRepository();
	test.updateImage_ValidInput_UpdatesImageInRepository();
	test.getAllImages_ValidInput_sizeIsCorrect();
	test.validateStringAllLettersAndSpecialCharacters_InvalidInput_stringAreNotValidated();
	test.validateStringAllLettersAndSpecialCharacters_ValidInput_stringIsValidated();
	test.addImageRepository_ValidInput_addedToService();
	test.addImageRepository_DuplicateInput_notAddedToService();
	test.addImageRepository_InvalidId_notAddedToService();
	test.addImageRepository_InvalidMeasurement_notAddedToService();
	test.deleteImageRepository_InvalidInput_notDeletedFromService();
	test.deleteImageRepository_ValidInput_deletedFromService();
	test.updateImageRepository_InvalidInput_notUpdatedService();
	test.updateImageRepository_ValidInput_updatedService();
	
	test.deleteImage_InvalidInput_DosntDeleteImageToRepository();
	test.validateDigits_ValidInput_IntIsValidated();
	test.validateDigits_InvalidInput_IntIsNotValidated();
	test.printImage_ValidInput_imagePrinted();
	test.constructorImage_ValidConstructor_defaultConstruct();
	test.addImageSaved_ValidInput_addedToSaved();
	test.addImageSaved_InvalidInput_addedToSaved();
	test.findImageInRepo_ValidInput_found();
	test.getSavedSize_Valid_givesSize();
	test.getAllInSaved_Valid_returnElements();
	test.getAllInRepo_Valid_returnElements();
	test.getSavedSize_Valid_givesSizeFile();
	test.getAllInSaved_Valid_returnElementsFile();
	test.addImageSaved_ValidInput_addedToSavedNotFile();
	test.addImageSaved_InvalidInput_notAddedToSavedNotFile();
	test.findImageInFileRepo_ValidInput_found();
	test.deleteImageFileRepository_InvalidInput_notDeletedFromService();
	
} 

void Test::getId_getImagesId_idIsCorect()
{
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(image.getId() == "12sd23");
}

void Test::getMeasurement_getImagesMeasurement_measurementIsCorect()
{
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(image.getMeasurement() == "23X12X10");
}

void Test::getImageClarity_getImagesImageClarity_imageClairtyIsCorect()
{
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(image.getImageClarityLevel() == 1);
}

void Test::getQuantity_getImagesQuantity_imageQuantityIsCorect()
{
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(image.getQuantity() == 13);
}

void Test::getPhotograph_getImagePhotograph_imagePhotographIsCorect()
{
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(image.getPhotograph() == "DSC13241.jpg");
}


void Test::addImage_ValidInput_addsImageToRepository()
{
	Repository repository{};
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(repository.addImage(image));

}

void Test::addImage_InvalidInput_DosntAddImageToRepository()
{
	Repository repository{};
	Image FirstImage{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	repository.addImage(FirstImage);
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(!(repository.addImage(image)));

}

void Test::deleteImage_ValidInput_deleteImageFromRepository()
{
	Repository repository{};
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	repository.addImage(image);
	assert(repository.deleteImage(image));

}

void Test::deleteImage_InvalidInput_DosntDeleteImageToRepository()
{
	Repository repository{};
	Image FirstImage{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	repository.addImage(FirstImage);
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert((repository.deleteImage(image))==1);

}

void Test::updateImage_ValidInput_UpdatesImageInRepository()
{
	Repository repository{};
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	repository.addImage(image);
	Image newImage{ "12sd23", "23X1210", 1, 13, "DSC13241.jpg" };
	assert(repository.updateImage(newImage));
}

void Test::updateImage_InvalidInput_DoesntUpdateImageInRepository()
{
	Repository repository{};
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	repository.addImage(image);
	Image newImage{ "12s23", "23X1210", 1, 13, "DSC13241.jpg" };
	assert(!(repository.updateImage(newImage)));
}

void Test::getAllImages_ValidInput_sizeIsCorrect()
{
	Repository repository{};
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	repository.addImage(image);
	vector<Image> vector = repository.getAllImages();
	assert(vector.size() == 1);
}

void Test::validateStringAllLettersAndSpecialCharacters_ValidInput_stringIsValidated()
{
	FileRepository repository{};
	Service service{ repository };
	Validate validator{};
	assert(service.getValidLetters("abc123"));
}

void Test::validateStringAllLettersAndSpecialCharacters_InvalidInput_stringAreNotValidated()
{
	Validate validator{};
	assert(!(validator.validateStringAllLetters("abc123%")));
}

void Test::validateDigits_ValidInput_IntIsValidated()
{
	FileRepository repository{};
	Service service{ repository };
	Validate validator{};
	assert(service.getValidDigits("123"));
}

void Test::validateDigits_InvalidInput_IntIsNotValidated()
{
	Validate validator{};
	assert(!(validator.validateStringAllDigits("123a")));
}

void Test::addImageRepository_ValidInput_addedToService()
{
	FileRepository repository{};
	Service service{ repository };
	assert(service.addImageInRepository("12sd23", "23X12X10", 1, 13, "DSC13241.jpg"));
}

void Test::addImageRepository_DuplicateInput_notAddedToService()
{
	FileRepository repository{};
	Service service{ repository };
	service.readFile("fileLocation C:\Users\Cata\Desktop\Anul 1\OOP\Assigment 8\Details for Private investigations\test.txt");
	service.addImageInRepository("12sd23", "23X12X10", 1, 13, "DSC13241.jpg");
	assert(!service.addImageInRepository("12sd23", "23X12X10", 1, 13, "DSC13241.jpg"));
}

void Test::addImageRepository_InvalidId_notAddedToService()
{
	FileRepository repository{};
	Service service{ repository };
	assert(!service.addImageInRepository("&", "23X12X1", 1, 13, "DSC13241.jpg"));
}

void Test::addImageRepository_InvalidMeasurement_notAddedToService()
{
	FileRepository repository{};
	Service service{ repository };
	assert(!service.addImageInRepository("12sd23", "*", 1, 13, "DSC13241.jpg"));
}

void Test::deleteImageRepository_ValidInput_deletedFromService()
{
	FileRepository repository{};
	Service service{ repository };
	service.readFile("fileLocation C:\Users\Cata\Desktop\Anul 1\OOP\Assigment 8\Details for Private investigations\test2.txt");
	service.addImageInRepository("12sd23", "23X12X10", 1, 13, "DSC13241.jpg");
	assert(service.deleteImageInRepository("12sd23"));
}

void Test::deleteImageRepository_InvalidInput_notDeletedFromService()
{
	Repository repository{};
	Image image{ "12sd23", "23X12X10", 1, 13, "DSC13241.jpg" };
	assert(!repository.deleteImage(image));
}

void Test::updateImageRepository_ValidInput_updatedService()
{
	FileRepository repository{};
	Service service{ repository };
	service.readFile("fileLocation C:\Users\Cata\Desktop\Anul 1\OOP\Assigment 8\Details for Private investigations\test3.txt");
	service.addImageInRepository("12sd23", "23X12X10", 1, 13, "DSC13241.jpg");
	assert(service.updateImageInRepository("12sd23", "23X1210", 1, 13, "DSC13241.jpg"));
}

void Test::updateImageRepository_InvalidInput_notUpdatedService()
{
	FileRepository repository{};
	Service service{ repository };
	assert(!service.updateImageInRepository("12sd23", "23X12X10", 1, 13, "DSC13241.jpg"));
}

void Test::printImage_ValidInput_imagePrinted()
{
	FileRepository repository{};
	Service service{ repository };
	Image image{ "1", "1", 1, 13, "1.jpg" };
	assert(image.getString()=="1: 1 measure, 1.000000 clarity, 13 quantity, 1.jpg\n");	
}

void Test::constructorImage_ValidConstructor_defaultConstruct()
{
	Image image{ };
}

void Test::findImageInRepo_ValidInput_found()
{
	FileRepository repository{};
	Service service{ repository };
	service.readFile("fileLocation C:\Users\Cata\Desktop\Anul 1\OOP\Assigment 8\Details for Private investigations\test.txt");
	service.addImageInRepository("1", "1", 1, 13, "DSC13241.jpg");
	Image newImage=service.findImageInRepository("1") ;
	assert(newImage.getId() == "1");
}

void Test::addImageSaved_ValidInput_addedToSaved()
{
	FileRepository repository{};
	Service service{ repository };
	Image image{ "1", "1", 1, 13, "1.jpg" };
	assert(service.addImageInSaved(image));
}

void Test::addImageSaved_InvalidInput_addedToSaved()
{
	FileRepository repository{};
	Service service{ repository };
	Image image{ "1", "1", 1, 13, "1.jpg" };
	Image newimage{ "1", "1", 1, 13, "1.jpg" };
	service.addImageInSaved(newimage);
	assert(!service.addImageInSaved(newimage));
}

void Test::getSavedSize_Valid_givesSize()
{
	FileRepository repository{};
	Service service{ repository };
	assert(service.getSavedSize() == 0);
}

void Test::getAllInSaved_Valid_returnElements()
{
	FileRepository repository{};
	Service service{ repository };
	vector<Image> mylist = service.getAllInSavedList();
}

void Test::getAllInRepo_Valid_returnElements()
{
	FileRepository repository{};
	Service service{ repository };
	vector<Image> mylist = service.getAllImagesInRepository();
}

void Test::getSavedSize_Valid_givesSizeFile()
{
	Repository repository{};
	assert(repository.getSavedSize()==0);
}

void Test::getAllInSaved_Valid_returnElementsFile()
{
	Repository repository{};
	vector<Image> mylist = repository.getSaved();
}

void Test::addImageSaved_ValidInput_addedToSavedNotFile()
{
	Repository repository{};
	Image image{ "1", "1", 1, 13, "1.jpg" };
	assert(repository.addSavedImage(image));
}

void Test::addImageSaved_InvalidInput_notAddedToSavedNotFile()
{
	Repository repository{};
	Image image{ "1", "1", 1, 13, "1.jpg" };
	assert(repository.addSavedImage(image));
	assert(!(repository.addSavedImage(image)));

}

void Test::findImageInFileRepo_ValidInput_found()
{
	Repository repository{};
	Image image{ "1", "1", 1, 13, "1.jpg" };
	repository.addImage(image);
	Image newImage=repository.findImage("1");
}

void Test::deleteImageFileRepository_InvalidInput_notDeletedFromService()
{
	FileRepository repository{};
	Service service{ repository };
	assert(!service.deleteImageInRepository("12sd23"));
}

*/