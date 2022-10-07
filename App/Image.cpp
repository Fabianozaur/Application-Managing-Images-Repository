#include "Image.h"
#include <string>
#include <vector>

using namespace std;


Image::Image() : id(""), measurement(""), imageClarityLevel(), quantity(0), photograph("") {}

Image::Image(const std::string& id, const std::string& measurement, float imageClarityLevel, int quantity, const std::string& photograph)
{
	this->id = id;
	this->measurement = measurement;
	this->imageClarityLevel = imageClarityLevel;
	this->quantity = quantity;
	this->photograph = photograph;
}

std::string Image::getString()
{
	return this->id + ": " + this->measurement + " measure, " + std::to_string(this->imageClarityLevel) + " clarity, " + std::to_string(this->quantity) + " quantity, " + this->photograph+"\n";
}

bool Image::operator==(const Image& image)
{
	return this->id == image.id;
}

std::istream& operator>>(istream& stream, Image& image)
{
	int id = 0, measurement = 1, imageClarity = 2, quantity = 3, photo = 4;
	string line="",argument;
	getline(stream, line);
	vector<string> token;
	stringstream input(line);
	while (getline(input, argument,','))
		token.push_back(argument);
	if (token.size() != 5)
		return stream;
	image.id = token[id];
	image.measurement = token[measurement];
	image.imageClarityLevel = stof(token[imageClarity]);
	image.quantity = stoi(token[quantity]);
	image.photograph = token[photo];

	return stream;
}

std::ostream& operator<<(ostream& stream, Image image)
{
	stream << image.id << "," << image.measurement << "," << image.imageClarityLevel << "," << image.quantity << "," << image.photograph;
	return stream;
}