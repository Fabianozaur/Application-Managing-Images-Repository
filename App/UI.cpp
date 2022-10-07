#include "UI.h"
#include <iostream>
#include <string>
#include <exception>

using namespace std;

void UI::printModeA()
{
	cout << "\n|------------------------------------------------------------------------------------------|\n|   Menu Mode A:                                                                           |\n|   add id, measurement, imageClarityLevel, quantity, photograph                           |\n|   update id, newMeasurement, newImageClarityLevel, newQuantity, newPhotograph            |\n|   delete id                                                                              |\n|   list                                                                                   |\n|   exit                                                                                   |\n|------------------------------------------------------------------------------------------|\n";
}

void UI::printModeB()
{
	cout << "\nMenu mode B:\nnext\nsave id\nlist measurement,quantity\nmylist\n";
}

void UI::start()
{

	printf("Start by selcetic the mode: mode A or mode B\n");
	char mode = NULL;
	while (1)
	{
		
		bool wasInt = false, wasFloat = true;
		std::string readCommand, readId, readPhotograph, readMeasurement;
		int readQuantity, readImageClarityLevel, numberOfWords, startNextWord, stopNextWord, lengthOfWord,positionOfNext=0;
		char* command;
		vector<Image> myList{};
		vector<Image> forNext = this->service.getAllImagesInRepository();
		std::getline(std::cin, readCommand);
		if (readCommand.substr(0, 4) == "exit")
			return;
		else if (readCommand.substr(0, 4) == "mode")
		{
			mode = readCommand[5];
			if (mode == 'A')
				UI::printModeA();
			else
				UI::printModeB();
		}
		else if (readCommand.substr(0, 3) == "add")
		{
			if (mode == 'A')
			{
				try
				{

					readCommand[3] = '_';
					startNextWord = 4;
					for (numberOfWords = 0; numberOfWords < 4; ++numberOfWords)
					{
						stopNextWord = readCommand.find(", ");
						lengthOfWord = stopNextWord - startNextWord;
						if (numberOfWords == 0)
							readId = readCommand.substr(startNextWord, lengthOfWord);
						else if (numberOfWords == 1)
							readMeasurement = readCommand.substr(startNextWord, lengthOfWord);
						else if (numberOfWords == 2)
						{
							std::string substring = readCommand.substr(startNextWord, lengthOfWord);
							this->service.getValidFloat(substring);
							readImageClarityLevel = std::stof(substring);
						}
						else if (numberOfWords == 3)
						{
							std::string substring = readCommand.substr(startNextWord, lengthOfWord);
							this->service.getValidDigits(substring);
							readQuantity = std::stoi(substring);
						}
						startNextWord = stopNextWord + 2;
						readCommand.replace(stopNextWord, 2, "__");
					}

					stopNextWord = readCommand.length();
					lengthOfWord = stopNextWord - startNextWord;
					readPhotograph = readCommand.substr(startNextWord, lengthOfWord);
					this->service.addImageInRepository(readId, readMeasurement, readImageClarityLevel, readQuantity, readPhotograph);
					/*
					if (wasInt && wasFloat)
						if (!this->service.addImageInRepository(readId, readMeasurement, readImageClarityLevel, readQuantity, readPhotograph))
							cout << "One of the strings introduced were not good";
						else
						{
							if (wasInt == false && wasFloat == true)
								cout << "The quantity was wrongfully introduced\n";
							if (wasFloat == false && wasInt == true)
								cout << "The image clarity was wrongfully introduced";
							if (wasInt == false && wasFloat == false)
								cout << "The quantity and the image clarity were wrongfully introduced ";
							continue;
						}
						*/
				}
				catch (AddException error)
				{
					cout << error.what();
				}
				catch (ValidationDigitsException error)
				{
					cout << error.what();
				}

			}
			else
			{
				cout << "You can't add if the selected mode is not A\n";
			}
		}
		else if (readCommand.substr(0, 6) == "delete")
		{

			if (mode == 'A')
			{
				try
				{
					readCommand[6] = '_';
					startNextWord = 7;
					stopNextWord = readCommand.length();
					lengthOfWord = stopNextWord - startNextWord;
					readId = readCommand.substr(startNextWord, lengthOfWord);
					this->service.deleteImageInRepository(readId);
				}
				catch (DeleteException error)
				{
					cout << error.what();
				}
				catch (ValidationDigitsException error)
				{
					cout << error.what();
				}
			}
			else
			{
				cout << "You can't delete if the selected mode is not A\n";
			}

		}
		else if (readCommand.substr(0, 6) == "update")
		{
			if (mode == 'A')
			{

				try
				{
					wasFloat = true;
					wasInt = false;
					readCommand[6] = '_';
					startNextWord = 7;
					for (numberOfWords = 0; numberOfWords < 4; ++numberOfWords)
					{
						stopNextWord = readCommand.find(", ");
						lengthOfWord = stopNextWord - startNextWord;
						if (numberOfWords == 0)
							readId = readCommand.substr(startNextWord, lengthOfWord);
						else if (numberOfWords == 1)
							readMeasurement = readCommand.substr(startNextWord, lengthOfWord);
						else if (numberOfWords == 2)
						{
							std::string substring = readCommand.substr(startNextWord, lengthOfWord);
							this->service.getValidFloat(substring);
							readImageClarityLevel = std::stof(substring);
						}
						else if (numberOfWords == 3)
						{
							std::string substring = readCommand.substr(startNextWord, lengthOfWord);
							this->service.getValidDigits(substring);
							readQuantity = std::stoi(substring);
						}
						startNextWord = stopNextWord + 2;
						readCommand.replace(stopNextWord, 2, "__");
					}
					stopNextWord = readCommand.length();
					lengthOfWord = stopNextWord - startNextWord;
					readPhotograph = readCommand.substr(startNextWord, lengthOfWord);
					this->service.updateImageInRepository(readId, readMeasurement, readImageClarityLevel, readQuantity, readPhotograph);
					
				}
				catch (UpdateException error)
				{
					cout << error.what();
				}
				catch (ValidationDigitsException error)
				{
					cout << error.what();
				}

			}
			else
			{
				cout << "You can't update if the selected mode is not A\n";

			}
		}
		else if (readCommand.substr(0, 4) == "list")
		{
			if (mode == 'A')
			{

				if (readCommand.length() == 4)
				{
					vector<Image> imageList = this->service.getAllImagesInRepository();
					int imageLength = imageList.size();
					for (int i = 0; i < imageLength; ++i)
					{
						Image image = imageList.at(i);
						cout << image.getString() << '\n';
					}
				}
			}
			else if(mode =='B')
			{
				if (readCommand.length() != 4)
				{
					readCommand[4] = '_';
					startNextWord = 5;
					if (readCommand.find(", ") < readCommand.length())
					{
						stopNextWord = readCommand.find(", ");
						lengthOfWord = stopNextWord - startNextWord;
						readMeasurement = readCommand.substr(startNextWord, lengthOfWord);
						startNextWord = stopNextWord + 2;
						readCommand.replace(stopNextWord, 2, "__");
						stopNextWord = readCommand.length();
						lengthOfWord = stopNextWord - startNextWord;
						readQuantity=std::stoi(readCommand.substr(startNextWord, lengthOfWord));
						vector<Image> imageList = this->service.getAllImagesInRepository();
						int imageLength = imageList.size();
						for (int i = 0; i < imageLength; ++i)
						{
							Image image = imageList.at(i);
							if (image.getMeasurement() == readMeasurement && image.getQuantity() < readQuantity)
								std::cout << image.getString() << '\n';
						}
					}
					else
					{
						int notQuantity = 0;
						stopNextWord = readCommand.length();
						lengthOfWord = stopNextWord - startNextWord;
						try 
						{
							readQuantity = std::stoi(readCommand.substr(startNextWord, lengthOfWord));
							vector<Image> imageList = this->service.getAllImagesInRepository();
							int imageLength = imageList.size();
							for (int i = 0; i < imageLength; ++i)
							{
								Image image = imageList.at(i);
								if (image.getQuantity() < readQuantity)
									std::cout << image.getString() << '\n';
							}
						}
						catch (exception)
						{
							readMeasurement = readCommand.substr(startNextWord, lengthOfWord);
							vector<Image> imageList = this->service.getAllImagesInRepository();
							int imageLength = imageList.size();
							for (int i = 0; i < imageLength; ++i)
							{
								Image image = imageList.at(i);
								if (image.getMeasurement() == readMeasurement )
									std::cout << image.getString() << ' \n';
							}
						}
					}
				}
				

			}
			else
				cout << "You can't list if the selected mode is not A or B\n";
			
		}
		else if (readCommand.substr(0, 4) == "save")
		{
			if (mode == 'B')
			{
				readId = readCommand.substr(5, readCommand.length());
				Image image = this->service.findImageInRepository(readId);
				this->service.addImageInSaved(image);

			}
			else
				cout << "You can't save if the selected mode is not B\n";
		}
		else if (readCommand.substr(0, 6) == "mylist")
		{
			if (mode == 'B')
			{
				this->service.open();
			}
			else std::cout << "You can't save if the selected mode is not B\n";

		}
		else if (readCommand.substr(0, 4) == "next")
		{
		if (mode == 'B')
			{
			std::cout << this->service.getNext().getString();
			}
		else
		  std::cout << "You can't save if the selected mode is not B\n";



		}
		
		else std::cout << "Invalid command!\n";
		

	}
	


}