#include "Welcome.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Instagramclone::Welcome form; // Replace with your actual form name
    Application::Run(% form);
}
