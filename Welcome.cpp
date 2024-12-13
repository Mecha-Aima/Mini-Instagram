#include "Welcome.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Instagramclone::Welcome form;     Application::Run(% form);
}
