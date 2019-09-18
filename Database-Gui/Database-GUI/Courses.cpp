#include "Courses.h"

using namespace DatabaseGUI; // Where FDWE Enter your project name

[STAThreadAttribute]
int main()
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MyForm1); //where MyForm() Enter your main form name with () [Bracket]
	return 0;
}

