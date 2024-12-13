#pragma once
#include <msclr/marshal_cppstd.h>
#include "../Instagram_clone/headers/app/users_graph.h"

namespace Instagramclone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Search
	/// </summary>
	public ref class Search : public System::Windows::Forms::Form
	{
	public:
		Search(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		Search(UserGraph* graph, User* user)
		{
			InitializeComponent();
			this->network = graph;
			this->currUser = user;
			userCardsPanel = gcnew System::Windows::Forms::Panel();
			userCardsPanel->Location = System::Drawing::Point(10, 120); // Position it
			userCardsPanel->Size = System::Drawing::Size(1000, 400); // Size of the panel
			this->Controls->Add(userCardsPanel); // Add the panel to the form
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Search()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Panel^ userCardsPanel;
		   UserGraph* network;
	private: System::Windows::Forms::Label^ title;
		   User* currUser;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->title = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // title
			   // 
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
			   // 
			   // Search
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(27)), static_cast<System::Int32>(static_cast<System::Byte>(21)),
				   static_cast<System::Int32>(static_cast<System::Byte>(55)));
			   this->ClientSize = System::Drawing::Size(1064, 681);
			   this->Controls->Add(this->title);
			   this->Name = L"Search";
			   this->Text = L"Search";
			   this->Load += gcnew System::EventHandler(this, &Search::Search_Load);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

		   // Function to create and display user cards in a vertical layout
		   void loadUserCards() {
			   userCardsPanel->Controls->Clear(); // Clear previous cards
			   int yPosition = 10; // Start from the top of the panel

			   Vertex<User*>* user = this->network->getFirstUser();

			   // Loop over the users in the graph
			   while (user != nullptr) {
				   // Create a new Panel for each user card
				   if (user->value == currUser)
				   {
					   user = user->nextVertex;
					   continue;
				   }
				   Panel^ userCardPanel = gcnew Panel();
				   userCardPanel->Width = 1000;  // Set a fixed width for the user card
				   userCardPanel->Height = 120; // Set a fixed height for the card
				   userCardPanel->Location = System::Drawing::Point(10, yPosition);  // Set the position
				   userCardPanel->BackColor = Color::White; // Set background color for the card
				   userCardPanel->Padding = System::Windows::Forms::Padding(5); // Padding around content

				   // Create and set user info components
				   Label^ usernameLabel = gcnew Label();
				   usernameLabel->Text = "Username: " + gcnew String(user->value->getUsername().c_str());
				   usernameLabel->Font = gcnew System::Drawing::Font("Calibri", 10, FontStyle::Bold); // Bold font
				   usernameLabel->Location = System::Drawing::Point(10, 10); // Position in the panel
				   usernameLabel->AutoSize = true;
				   

				   Label^ cityLabel = gcnew Label();
				   cityLabel->Text = "City: " + gcnew String(user->value->getCity().c_str());
				   cityLabel->Font = gcnew System::Drawing::Font("Calibri", 10); // Regular font
				   cityLabel->Location = System::Drawing::Point(10, 30); // Position in the panel
				   cityLabel->AutoSize = true;
				   

				   Label^ lastLoginLabel = gcnew Label();
				   lastLoginLabel->Text = "Last Login: " + gcnew String(user->value->getLastLogin().c_str());
				   lastLoginLabel->Font = gcnew System::Drawing::Font("Calibri", 10); // Regular font
				   lastLoginLabel->Location = System::Drawing::Point(10, 50); // Position in the panel
				   lastLoginLabel->AutoSize = true;

				   // Create the post label (show most recent post)
				   Label^ recentPostLabel = gcnew Label();
				   // Retrieve most recent post (if exists)
				   if (!user->value->getPosts().isEmpty()) {
					   Post recentPost = user->value->getPosts().peek();
					   recentPostLabel->Text = "Recent Post: " + gcnew String(recentPost.content.c_str());
					   recentPostLabel->Font = gcnew System::Drawing::Font("Calibri", 8); // Smaller font for the post content
					   recentPostLabel->Location = System::Drawing::Point(10, 70);
				   }

				   // Add the labels to the user card panel
				   userCardPanel->Controls->Add(usernameLabel);
				   userCardPanel->Controls->Add(cityLabel);
				   userCardPanel->Controls->Add(lastLoginLabel);
				   userCardPanel->Controls->Add(recentPostLabel);

				   Button^ friendRequestButton = gcnew Button();
				   friendRequestButton->Text = "Friend Request";
				   friendRequestButton->Width = 120;
				   friendRequestButton->Height = 30;
				   friendRequestButton->Location = System::Drawing::Point(userCardPanel->Width - 200, 10); // Position it to the right of the card
				   friendRequestButton->Tag = gcnew String(user->value->getUsername().c_str());	// Store the username in the Tag property
				   friendRequestButton->Click += gcnew EventHandler(this, &Search::FriendRequestButton_Click); // Link to event handler

				   // Create and add the "Follow" button
				   Button^ followButton = gcnew Button();
				   followButton->Text = "Follow";
				   followButton->Width = 120;
				   followButton->Height = 30;
				   followButton->Location = System::Drawing::Point(userCardPanel->Width - 200, 50); // Below the first button
				   followButton->Tag = gcnew String(user->value->getUsername().c_str()); // Store the username in the Tag property
				   followButton->Click += gcnew EventHandler(this, &Search::FollowButton_Click); // Link to event handler

				   // Add the buttons to the user card panel
				   userCardPanel->Controls->Add(friendRequestButton);
				   userCardPanel->Controls->Add(followButton);

				   // Add the user card panel to the main container
				   userCardsPanel->Controls->Add(userCardPanel);

				   // Adjust vertical position for the next card
				   yPosition += userCardPanel->Height + 15; // Add some space between cards
				   user = user->nextVertex;
			   }

			   // Optionally, adjust the size of the userCardsPanel based on its contents
			   userCardsPanel->Height = yPosition;
		   }

		   void FriendRequestButton_Click(System::Object^ sender, System::EventArgs^ e) {
			   Button^ clickedButton = dynamic_cast<Button^>(sender);
			   if (clickedButton != nullptr) {
				   String^ name = clickedButton->Tag->ToString(); // Get the username from the Tag
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
				   String^ name = clickedButton->Tag->ToString(); // Get the username from the Tag
				   // Handle the follow logic for the user
				   std::string username = msclr::interop::marshal_as<std::string>(name);
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
	};
}
