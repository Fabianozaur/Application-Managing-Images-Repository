#pragma once
#include <iostream>
#include <sstream>
#include <vector>

class Image
{
private:
	std::string id;
	std::string measurement;
	float imageClarityLevel;
	int quantity;
	std::string photograph;
public:
	//default constructor
	Image();
	//constructor with parameters
	Image(const std::string& id, const std::string& measurement, float imageClarityLevel, int quantity, const std::string& photograph);
	std::string getId() const { return id; }
	std::string getMeasurement() const { return measurement; }
	float getImageClarityLevel() const { return imageClarityLevel; }
	int getQuantity() const { return quantity; }
	std::string getPhotograph() const { return photograph; }
	std::string getString();

	bool operator==(const Image& image);

	friend std::istream& operator>>(std::istream& stream, Image& image);

	friend std::ostream& operator<<(std::ostream& stream, Image image);

};
