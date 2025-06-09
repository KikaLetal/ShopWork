#include "Application.h"
#include <windows.h>

int main() {

	Application app;
	setlocale(LC_ALL, "Russian"); 
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	app.OnStart();

	app.Run();

	return 0;
}