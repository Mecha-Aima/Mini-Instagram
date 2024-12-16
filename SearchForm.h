#pragma once
#include <msclr/marshal_cppstd.h>
#include "headers/app/users_graph.h"

namespace Instagramclone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Search : public System::Windows::Forms::Form
	{
	public:
		Search(void)
		{
			InitializeComponent();
		}
		Search(UserGraph* graph, User* user)
		{
			InitializeComponent();
			this->network = graph;
			this->currUser = user;
			userCardsPanel = gcnew System::Windows::Forms::Panel();
			userCardsPanel->Location = System::Drawing::Point(10, 120); 			
			userCardsPanel->Size = System::Drawing::Size(1000, 400); 			
			this->Controls->Add(userCardsPanel);
		}

	protected:
		~Search()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Panel^ userCardsPanel;
		   UserGraph* network;
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Panel^ panel4;

	private: System::Windows::Forms::Label^ label4;
		   User* currUser;


#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->title = (gcnew System::Windows::Forms::Label());
			   this->panel4 = (gcnew System::Windows::Forms::Panel());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->panel4->SuspendLayout();
			   this->SuspendLayout();
			   this->title->AutoSize = true;
			   this->title->BackColor = System::Drawing::Color::Transparent;
			   this->title->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->title->ForeColor = System::Drawing::Color::White;
			   this->title->Location = System::Drawing::Point(55, 31);
			   this->title->Name = L"title";
			   this->title->Size = System::Drawing::Size(211, 58);
			   this->title->TabIndex = 1;
			   this->title->Text = L"All Users";
			   this->panel4->BackColor = System::Drawing::Color::WhiteSmoke;
			   this->panel4->Controls->Add(this->label4);
			   this->panel4->Location = System::Drawing::Point(819, 31);
			   this->panel4->Name = L"panel4";
			   this->panel4->Size = System::Drawing::Size(141, 43);
			   this->panel4->TabIndex = 10;
			   this->panel4->Click += gcnew System::EventHandler(this, &Search::panel4_Click);
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Transparent;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->ForeColor = System::Drawing::Color::Black;
			   this->label4->Location = System::Drawing::Point(39, 11);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(64, 19);
			   this->label4->TabIndex = 5;
			   this->label4->Text = L"Go Back";
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				   static_cast<System::Int32>(static_cast<System::Byte>(55)));
			   this->ClientSize = System::Drawing::Size(1064, 681);
			   this->Controls->Add(this->panel4);
			   this->Controls->Add(this->title);
			   this->Name = L"Search";
			   this->Text = L"Search";
			   this->Load += gcnew System::EventHandler(this, &Search::Search_Load);
			   this->panel4->ResumeLayout(false);
			   this->panel4->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

		   void loadUserCards() {
			   userCardsPanel->Controls->Clear(); 			   
			   int yPosition = 10;
			   Vertex<User*>* user = this->network->getFirstUser();

			   while (user != nullptr) {
				   if (user->value == currUser)
				   {
					   user = user->nextVertex;
					   continue;
				   }
				   Panel^ userCardPanel = gcnew Panel();
				   userCardPanel->Width = 1000;  				   
				   userCardPanel->Height = 120; 				   
				   userCardPanel->Location = System::Drawing::Point(10, yPosition);  				   
				   userCardPanel->BackColor = System::Drawing::Color::White; 				   
				   userCardPanel->Padding = System::Windows::Forms::Padding(5);
				   Label^ usernameLabel = gcnew Label();
				   usernameLabel->Text = "Username: " + gcnew String(user->value->getUsername().c_str());
				   usernameLabel->Font = gcnew System::Drawing::Font("Calibri", 10, FontStyle::Bold); 				   
				   usernameLabel->Location = System::Drawing::Point(10, 10); 				   
				   usernameLabel->AutoSize = true;


				   Label^ cityLabel = gcnew Label();
				   cityLabel->Text = "City: " + gcnew String(user->value->getCity().c_str());
				   cityLabel->Font = gcnew System::Drawing::Font("Calibri", 10); 				   
				   cityLabel->Location = System::Drawing::Point(10, 30); 				   
				   cityLabel->AutoSize = true;


				   Label^ lastLoginLabel = gcnew Label();
				   lastLoginLabel->Text = "Last Login: " + gcnew String(user->value->getLastLogin().c_str());
				   lastLoginLabel->Font = gcnew System::Drawing::Font("Calibri", 10); 				   
				   lastLoginLabel->Location = System::Drawing::Point(10, 50); 				   
				   lastLoginLabel->AutoSize = true;

				   Label^ recentPostLabel = gcnew Label();
				   if (!user->value->getPosts().isEmpty()) {
					   Post recentPost = user->value->getPosts().peek();
					   recentPostLabel->Text = "Recent Post: " + gcnew String(recentPost.content.c_str());
					   recentPostLabel->Font = gcnew System::Drawing::Font("Calibri", 8); 					   
					   recentPostLabel->Location = System::Drawing::Point(10, 70);
				   }

				   userCardPanel->Controls->Add(usernameLabel);
				   userCardPanel->Controls->Add(cityLabel);
				   userCardPanel->Controls->Add(lastLoginLabel);
				   userCardPanel->Controls->Add(recentPostLabel);

				   Button^ friendRequestButton = gcnew Button();
				   friendRequestButton->Text = "Friend Request";
				   friendRequestButton->Width = 120;
				   friendRequestButton->Height = 30;
				   friendRequestButton->BackColor = System::Drawing::Color::DarkSlateBlue;
				   friendRequestButton->ForeColor = System::Drawing::Color::White;
				   friendRequestButton->Font = gcnew System::Drawing::Font("Calibri", 10);
				   friendRequestButton->Location = System::Drawing::Point(userCardPanel->Width - 200, 10); 				   
				   friendRequestButton->Tag = gcnew String(user->value->getUsername().c_str());					   
				   friendRequestButton->Click += gcnew EventHandler(this, &Search::FriendRequestButton_Click);
				   Button^ followButton = gcnew Button();
				   followButton->Text = "Follow";
				   followButton->Width = 120;
				   followButton->Height = 30;
				   followButton->Font = gcnew System::Drawing::Font("Calibri", 10);
				   followButton->Location = System::Drawing::Point(userCardPanel->Width - 200, 50); 				   
				   followButton->Tag = gcnew String(user->value->getUsername().c_str()); 				   
				   followButton->Click += gcnew EventHandler(this, &Search::FollowButton_Click);
				   userCardPanel->Controls->Add(friendRequestButton);
				   userCardPanel->Controls->Add(followButton);

				   userCardsPanel->Controls->Add(userCardPanel);

				   yPosition += userCardPanel->Height + 15; 				   
				   user = user->nextVertex;
			   }

			   userCardsPanel->Height = yPosition;
		   }

		   void FriendRequestButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   Button^ clickedButton = dynamic_cast<Button^>(sender);
			   if (clickedButton != nullptr) {
				   String^ name = clickedButton->Tag->ToString(); 				   
				   std::string username = msclr::interop::marshal_as<std::string>(name);
				   if (username != "")
				   {
					   this->network->sendRequest(this->currUser, this->network->searchUser(username));
				   }
			   }
		   }

		   void FollowButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   Button^ clickedButton = dynamic_cast<Button^>(sender);
			   if (clickedButton != nullptr) {
				   String^ name = clickedButton->Tag->ToString(); 				   				   std::string username = msclr::interop::marshal_as<std::string>(name);
				   if (username != "")
				   {
					   this->network->sendFollowRequest(this->currUser, this->network->searchUser(username));
				   }
			   }
		   }

#pragma endregion

	private: System::Void Search_Load(System::Object^ sender, System::EventArgs^ e) {
		loadUserCards();
	}
	private: System::Void panel4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
