#pragma once
#include <qwidget.h>
#include "Service.h"
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
class GUI : public QWidget
{
private:
	Service& serv;
	QListWidget* ImagesListWidget;
	QLineEdit* idLine, * photograpLine, * measurementLine, * imageClarityLine, * quantityLine ;
	QPushButton* addButton, * deleteButton;

public:
	GUI(Service& s);
private:
	void initGUI();
	void populateList();
	void connectSignals();
	int getSelectedIndex() const;
	void addImage();
	void deleteImage();
};

