#pragma once
#include <msclr/marshal_cppstd.h>	
#include "../Instagram_clone/headers/app/user.h"
#include "../Instagram_clone/headers/app/users_graph.h"

namespace Instagramclone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class SignUp : public System::Windows::Forms::Form
	{
	public:
		SignUp(void)
		{
			InitializeComponent();
			loginActive = false;
			// this->network = network; // store reference
		}
		SignUp(UserGraph *graph)
		{
			InitializeComponent();
			loginActive = false;
			this->network = graph; // store reference
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ title;

	private: System::Windows::Forms::TextBox^ usernameBox;
	private: System::Windows::Forms::Panel^ usernamePnl;

	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ passLabel;
	private: System::Windows::Forms::Panel^ passPanel;
	private: System::Windows::Forms::TextBox^ passBox;
	private: System::Windows::Forms::Button^ btnSignUp;
	private: System::Windows::Forms::CheckBox^ terms;

	private: System::Windows::Forms::LinkLabel^ loginBtn;
	private: System::Windows::Forms::Panel^ cityPnl;
	private: System::Windows::Forms::TextBox^ cityBox;
	private: System::Windows::Forms::Label^ cityLabel;
		   bool loginActive;
	UserGraph* network;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignUp::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->usernameBox = (gcnew System::Windows::Forms::TextBox());
			this->usernamePnl = (gcnew System::Windows::Forms::Panel());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passLabel = (gcnew System::Windows::Forms::Label());
			this->passPanel = (gcnew System::Windows::Forms::Panel());
			this->passBox = (gcnew System::Windows::Forms::TextBox());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->terms = (gcnew System::Windows::Forms::CheckBox());
			this->loginBtn = (gcnew System::Windows::Forms::LinkLabel());
			this->cityPnl = (gcnew System::Windows::Forms::Panel());
			this->cityBox = (gcnew System::Windows::Forms::TextBox());
			this->cityLabel = (gcnew System::Windows::Forms::Label());
			this->usernamePnl->SuspendLayout();
			this->passPanel->SuspendLayout();
			this->cityPnl->SuspendLayout();
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Transparent;
			this->title->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 40, System::Drawing::FontStyle::Bold));
			this->title->Location = System::Drawing::Point(345, 85);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(345, 65);
			this->title->TabIndex = 0;
			this->title->Text = L"Create Account";
			// 
			// usernameBox
			// 
			this->usernameBox->BackColor = System::Drawing::Color::White;
			this->usernameBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->usernameBox->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->usernameBox->Location = System::Drawing::Point(13, 13);
			this->usernameBox->Name = L"usernameBox";
			this->usernameBox->Size = System::Drawing::Size(325, 17);
			this->usernameBox->TabIndex = 2;
			// 
			// usernamePnl
			// 
			this->usernamePnl->BackColor = System::Drawing::Color::White;
			this->usernamePnl->Controls->Add(this->usernameBox);
			this->usernamePnl->Location = System::Drawing::Point(326, 224);
			this->usernamePnl->Name = L"usernamePnl";
			this->usernamePnl->Size = System::Drawing::Size(378, 48);
			this->usernamePnl->TabIndex = 3;
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->BackColor = System::Drawing::Color::Transparent;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->usernameLabel->ForeColor = System::Drawing::Color::Black;
			this->usernameLabel->Location = System::Drawing::Point(322, 198);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(115, 19);
			this->usernameLabel->TabIndex = 5;
			this->usernameLabel->Text = L"Enter username ";
			// 
			// passLabel
			// 
			this->passLabel->AutoSize = true;
			this->passLabel->BackColor = System::Drawing::Color::Transparent;
			this->passLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->passLabel->ForeColor = System::Drawing::Color::Black;
			this->passLabel->Location = System::Drawing::Point(323, 283);
			this->passLabel->Name = L"passLabel";
			this->passLabel->Size = System::Drawing::Size(109, 19);
			this->passLabel->TabIndex = 7;
			this->passLabel->Text = L"Enter password";
			// 
			// passPanel
			// 
			this->passPanel->BackColor = System::Drawing::Color::White;
			this->passPanel->Controls->Add(this->passBox);
			this->passPanel->Location = System::Drawing::Point(327, 309);
			this->passPanel->Name = L"passPanel";
			this->passPanel->Size = System::Drawing::Size(378, 48);
			this->passPanel->TabIndex = 6;
			// 
			// passBox
			// 
			this->passBox->BackColor = System::Drawing::Color::White;
			this->passBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->passBox->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passBox->Location = System::Drawing::Point(13, 13);
			this->passBox->Name = L"passBox";
			this->passBox->Size = System::Drawing::Size(325, 16);
			this->passBox->TabIndex = 2;
			this->passBox->UseSystemPasswordChar = true;
			// 
			// btnSignUp
			// 
			this->btnSignUp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->btnSignUp->Enabled = false;
			this->btnSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignUp->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignUp->ForeColor = System::Drawing::Color::White;
			this->btnSignUp->Location = System::Drawing::Point(382, 499);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(261, 51);
			this->btnSignUp->TabIndex = 8;
			this->btnSignUp->Text = L"Sign Up";
			this->btnSignUp->UseVisualStyleBackColor = false;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &SignUp::btnSignUp_Click);
			// 
			// terms
			// 
			this->terms->AutoSize = true;
			this->terms->BackColor = System::Drawing::Color::Transparent;
			this->terms->Font = (gcnew System::Drawing::Font(L"Calibri", 10));
			this->terms->Location = System::Drawing::Point(370, 467);
			this->terms->Name = L"terms";
			this->terms->Size = System::Drawing::Size(294, 21);
			this->terms->TabIndex = 9;
			this->terms->Text = L"I have read and agreed to Terms and Conditions";
			this->terms->UseVisualStyleBackColor = false;
			this->terms->CheckedChanged += gcnew System::EventHandler(this, &SignUp::terms_CheckedChanged);
			// 
			// loginBtn
			// 
			this->loginBtn->ActiveLinkColor = System::Drawing::Color::OrangeRed;
			this->loginBtn->AutoSize = true;
			this->loginBtn->BackColor = System::Drawing::Color::Transparent;
			this->loginBtn->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->loginBtn->LinkBehavior = System::Windows::Forms::LinkBehavior::AlwaysUnderline;
			this->loginBtn->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->loginBtn->Location = System::Drawing::Point(485, 571);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(57, 23);
			this->loginBtn->TabIndex = 11;
			this->loginBtn->TabStop = true;
			this->loginBtn->Text = L"Log In";
			this->loginBtn->VisitedLinkColor = System::Drawing::SystemColors::InfoText;
			this->loginBtn->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SignUp::loginBtn_LinkClicked);
			// 
			// cityPnl
			// 
			this->cityPnl->BackColor = System::Drawing::Color::White;
			this->cityPnl->Controls->Add(this->cityBox);
			this->cityPnl->Location = System::Drawing::Point(327, 399);
			this->cityPnl->Name = L"cityPnl";
			this->cityPnl->Size = System::Drawing::Size(378, 48);
			this->cityPnl->TabIndex = 12;
			// 
			// cityBox
			// 
			this->cityBox->BackColor = System::Drawing::Color::White;
			this->cityBox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->cityBox->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cityBox->Location = System::Drawing::Point(13, 13);
			this->cityBox->Name = L"cityBox";
			this->cityBox->Size = System::Drawing::Size(325, 16);
			this->cityBox->TabIndex = 2;
			// 
			// cityLabel
			// 
			this->cityLabel->AutoSize = true;
			this->cityLabel->BackColor = System::Drawing::Color::Transparent;
			this->cityLabel->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->cityLabel->ForeColor = System::Drawing::Color::Black;
			this->cityLabel->Location = System::Drawing::Point(323, 373);
			this->cityLabel->Name = L"cityLabel";
			this->cityLabel->Size = System::Drawing::Size(110, 19);
			this->cityLabel->TabIndex = 13;
			this->cityLabel->Text = L"Enter city name";
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1016, 681);
			this->Controls->Add(this->cityPnl);
			this->Controls->Add(this->cityLabel);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->terms);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->passLabel);
			this->Controls->Add(this->title);
			this->Controls->Add(this->passPanel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->usernamePnl);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->usernamePnl->ResumeLayout(false);
			this->usernamePnl->PerformLayout();
			this->passPanel->ResumeLayout(false);
			this->passPanel->PerformLayout();
			this->cityPnl->ResumeLayout(false);
			this->cityPnl->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void terms_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (terms->Checked && !String::IsNullOrWhiteSpace(usernameBox->Text) && !String::IsNullOrWhiteSpace(passBox->Text))
		{
			btnSignUp->Enabled = true;
		}
		else
		{
			btnSignUp->Enabled = false;
		}

	}
	private: System::Void loginBtn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		if (!loginActive)
		{
			loginActive = true;
			this->title->Text = "Welcome Back";
			this->btnSignUp->Text = "Log In";
			this->loginBtn->Text = "Sign up";
			this->cityBox->Hide(); this->cityLabel->Hide(); this->cityPnl->Hide();
		}
		else
		{
			loginActive = false;
			this->title->Text = "Create Account";
			this->btnSignUp->Text = "Sign Up";
			this->loginBtn->Text = "Log In";
			this->cityBox->Show(); this->cityLabel->Show(); this->cityPnl->Show();
		}
		
	}
	private: System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
		if (loginActive)
		{
			std::string username = msclr::interop::marshal_as<std::string>(usernameBox->Text);
			std::string password = msclr::interop::marshal_as<std::string>(passBox->Text);
			
			if (network->authenticateLogin(username, password))
			{
				cout << "Hello\n";
			}
			else
			{
				MessageBox::Show("Username or password is incorrect", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else
		{
			std::string username = msclr::interop::marshal_as<std::string>(usernameBox->Text);
			std::string password = msclr::interop::marshal_as<std::string>(passBox->Text);
			std::string city = msclr::interop::marshal_as<std::string>(cityBox->Text);
			User *newUser = new User(username, password, city);
			if (newUser->isEmpty())
			{
				MessageBox::Show("Invalid username or password:\nUsername must only contain letters & digits\nPassword must contain: letters, digits, special characters", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else
			{
				this->network->addUser(newUser);
			}
		}
	}
};
}
