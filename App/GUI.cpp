#include "GUI.h"
#include <qlayout.h>
#include <qformlayout.h>
#include <qmessagebox.h>

GUI::GUI(Service& s) : serv{s}
{
	this->initGUI();
	this->populateList();
	this->connectSignals();
}

void GUI::initGUI()
{
	ImagesListWidget = new QListWidget{};
	this->idLine = new QLineEdit{};
	this->photograpLine = new QLineEdit{};
	this->quantityLine = new QLineEdit{};
	this->imageClarityLine = new QLineEdit{};
	this->measurementLine = new QLineEdit{};
	addButton = new QPushButton{"Add"};
	deleteButton = new QPushButton{"Delete"};

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };
	mainLayout->addWidget(this->ImagesListWidget);

	QFormLayout* imageDetailsLayout = new QFormLayout{};
	imageDetailsLayout->addRow("Id", idLine);
	imageDetailsLayout->addRow("Measurement", measurementLine);
	imageDetailsLayout->addRow("Image Clarity Level", imageClarityLine);
	imageDetailsLayout->addRow("Quantity", quantityLine);
	imageDetailsLayout->addRow("Photograph", photograpLine);

	mainLayout->addLayout(imageDetailsLayout);

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->addButton, 0, 0);
	buttonsLayout->addWidget(this->deleteButton, 0, 1);
	mainLayout->addLayout(buttonsLayout);


}

void GUI::populateList()
{
	ImagesListWidget->clear();
	vector<Image> allImages = this->serv.getAllImagesInRepository();
	for (Image& image : allImages)
		this->ImagesListWidget->addItem(QString::fromStdString(image.getId() + " - " + image.getPhotograph()));

}

void GUI::connectSignals()
{
	QObject::connect(ImagesListWidget, &QListWidget::itemSelectionChanged, [this]() {
		int selectedIndex = getSelectedIndex();
		if (selectedIndex < 0)
			return 0;
		Image selectImage = this->serv.getAllImagesInRepository()[selectedIndex];
		idLine->setText(QString::fromStdString(selectImage.getId()));
		measurementLine->setText(QString::fromStdString(selectImage.getMeasurement()));
		imageClarityLine->setText(QString::number(selectImage.getImageClarityLevel()));
		quantityLine->setText(QString::number(selectImage.getQuantity()));
		photograpLine->setText(QString::fromStdString(selectImage.getPhotograph()));

		});

	QObject::connect(this->addButton, &QPushButton::clicked,this, &GUI::addImage);
	QObject::connect(this->deleteButton, &QPushButton::clicked, this, &GUI::deleteImage);

}

int GUI::getSelectedIndex() const
{
	QModelIndexList selectedIndexes = this->ImagesListWidget->selectionModel()->selectedIndexes();
	if (selectedIndexes.size() == 0)
	{
		this->idLine->clear();
		this->measurementLine->clear();
		this->imageClarityLine->clear();
		this->quantityLine->clear();
		this->photograpLine->clear();
		return -1;
	}
	int selectedIndex = selectedIndexes.at(0).row();
	return selectedIndex;
}

void GUI::addImage()
{
	string id = idLine->text().toStdString();
	string measurement = measurementLine->text().toStdString();
	float imageClarityLevel = imageClarityLine->text().toFloat();
	int quantity = quantityLine->text().toInt();
	string photograph = photograpLine->text().toStdString();
	this->serv.addImageInRepository(id, measurement, imageClarityLevel, quantity, photograph);
	this->populateList();
	int lastImage = serv.getAllImagesInRepository().size() - 1;
	ImagesListWidget->setCurrentRow(lastImage);
}

void GUI::deleteImage()
{
	int selectedIndex = this->getSelectedIndex();
	if (selectedIndex < 0)
	{
		QMessageBox::critical(this, "Error", "No Image selected");
		return;
	}
	Image selectedImage = serv.getAllImagesInRepository()[selectedIndex];
	serv.deleteImageInRepository(selectedImage.getId());
	this->populateList();
	//int lastImage = serv.getAllImagesInRepository().size() - 1;
	//ImagesListWidget->setCurrentRow(lastImage);

}
