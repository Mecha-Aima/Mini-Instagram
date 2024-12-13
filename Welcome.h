#pragma once
#include "SignUp.h"
#include "../Instagram_clone/headers/app/user.h"
#include "../Instagram_clone/headers/app/users_graph.h"
#include "../Instagram_clone/headers/app/user_tree.h"
#include "../Instagram_clone/headers/app/admin.h"

namespace Instagramclone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	

				public ref class Welcome : public System::Windows::Forms::Form
	{
	public:
		Welcome(void)
		{
			InitializeComponent();
			try
			{
				this->network = new UserGraph();
				admin = new AdminUser("aimenAmeer", "mySecret13", "London", *network);
								this->network->addUser("amazingUser", "aMazing_123", "Los Angeles");
				this->network->addUser("gamerGirl", "GTA69_waiting", "London");
				this->network->addUser("bookWorm", "iLoveBooks1?", "Paris");
				this->network->addUser("codingNinja", "Center%div23", "Tokyo");
			}
			catch (const std::exception& e)
			{
				cout << "Exception: " << e.what() << endl;
			}

		}

	protected:
								~Welcome()
		{
			if (components)
			{
				delete network;
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Button^ btnGetStarted;
	private: System::Windows::Forms::Button^ btnQuit;
	UserGraph *network;
	AdminUser* admin;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
										void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Welcome::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->btnGetStarted = (gcnew System::Windows::Forms::Button());
			this->btnQuit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
												this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Black;
			this->title->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 48, System::Drawing::FontStyle::Bold));
			this->title->ForeColor = System::Drawing::Color::White;
			this->title->Location = System::Drawing::Point(56, 67);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(454, 77);
			this->title->TabIndex = 0;
			this->title->Text = L"Mini Instagram";
												this->btnGetStarted->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->btnGetStarted->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGetStarted->Font = (gcnew System::Drawing::Font(L"Calibri", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGetStarted->Location = System::Drawing::Point(69, 243);
			this->btnGetStarted->Name = L"btnGetStarted";
			this->btnGetStarted->Size = System::Drawing::Size(261, 51);
			this->btnGetStarted->TabIndex = 1;
			this->btnGetStarted->Text = L"Get Started";
			this->btnGetStarted->UseVisualStyleBackColor = false;
			this->btnGetStarted->Click += gcnew System::EventHandler(this, &Welcome::btnGetStarted_Click);
												this->btnQuit->BackColor = System::Drawing::Color::Black;
			this->btnQuit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnQuit->Font = (gcnew System::Drawing::Font(L"Calibri", 14));
			this->btnQuit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->btnQuit->Location = System::Drawing::Point(69, 325);
			this->btnQuit->Name = L"btnQuit";
			this->btnQuit->Size = System::Drawing::Size(261, 49);
			this->btnQuit->TabIndex = 2;
			this->btnQuit->Text = L"Quit App";
			this->btnQuit->UseVisualStyleBackColor = false;
			this->btnQuit->Click += gcnew System::EventHandler(this, &Welcome::btnQuit_Click);
												this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(242)), static_cast<System::Int32>(static_cast<System::Byte>(243)),
				static_cast<System::Int32>(static_cast<System::Byte>(174)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1064, 681);
			this->Controls->Add(this->btnQuit);
			this->Controls->Add(this->btnGetStarted);
			this->Controls->Add(this->title);
			this->Name = L"Welcome";
			this->Text = L"Welcome";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnGetStarted_Click(System::Object^ sender, System::EventArgs^ e) {
		SignUp^ signUpForm = gcnew SignUp(this->network);
		signUpForm->Show();
		this->Hide();
	}
	private: System::Void btnQuit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
};
}
