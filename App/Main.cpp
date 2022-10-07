#include "UI.h"
#include "Tests.h"
#include <crtdbg.h>


int main()
{
		//Test test{};
		//test.testAll();
		memoryRepository repository{};
		memoryRepository second{};
		Service service{ repository,second };
		UI ui{ service };
		ui.start();
		string filePath,filePathMylist;
		std::getline(std::cin, filePath);
		FileRepository repository{filePath.substr(13)};
		std::getline(std::cin, filePathMylist);
		if (filePathMylist[filePathMylist.size() - 1] == 'l')
		{
			HTMLRepository htmlRepository{ filePathMylist.substr(15) };
			Service service{ repository,htmlRepository };
			UI ui{ service };
			ui.start();
		}
		else
		{
			CSVRepository cvsRepository{ filePathMylist.substr(15) };
			Service service{ repository,cvsRepository };
			UI ui{ service };
			ui.start();
		}
	_CrtDumpMemoryLeaks;
	return 0;
}
