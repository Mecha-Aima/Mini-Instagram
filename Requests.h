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

	/// <summary>
	/// Summary for Requests
	/// </summary>
	public ref class Requests : public System::Windows::Forms::Form
	{
	public:
		Requests(void)
		{
			InitializeComponent();
		}
		Requests(UserGraph *graph, User *user)
		{
			InitializeComponent();
			this->network = graph;
			this->currUser = user;
			CreateRequestCards();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Requests()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ title;
		   UserGraph* network;
		   User* currUser;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Requests::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// title
			// 
			this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Transparent;
			this->title->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::Black;
			this->title->Location = System::Drawing::Point(72, 28);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(449, 58);
			this->title->TabIndex = 3;
			this->title->Text = L"Your Friend Requests";
			// 
			// Requests
			// 
			this->AutoScroll = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(964, 501);
			this->Controls->Add(this->title);
			this->Name = L"Requests";
			this->Text = L"Requests";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void CreateRequestCards() {
			int cardYPosition = 150; // Initial Y position for the first card
			int cardSpacing = 20;    // Space between cards

			// Iterate through the friendRequests list of currUser
			auto requestNode = this->currUser->getRequests();
			while (requestNode != nullptr) {
				if (requestNode->data->status == "declined" || requestNode->data->status == "accepted")
					continue;
				FriendRequest* request = requestNode->data;
				String^ senderUsername = gcnew String(request->sender.c_str());

				// Create a panel to represent a single card
				Panel^ card = gcnew Panel();
				card->Size = System::Drawing::Size(600, 100);
				card->Location = System::Drawing::Point(100, cardYPosition);
				cardYPosition += card->Height + cardSpacing;

				// Create the username label
				Label^ usernameLabel = gcnew Label();
				usernameLabel->Text = senderUsername;
				usernameLabel->Font = gcnew System::Drawing::Font(L"Calibri", 12);
				usernameLabel->Location = System::Drawing::Point(10, 10);
				usernameLabel->AutoSize = true;

				// Create the "Accept" button
				Button^ acceptButton = gcnew Button();
				acceptButton->Text = L"Accept";
				acceptButton->Size = System::Drawing::Size(75, 30);
				acceptButton->Location = System::Drawing::Point(500, 10);
				acceptButton->Click += gcnew EventHandler(this, &Requests::AcceptRequest_Click);
				acceptButton->BackColor = System::Drawing::Color::DarkSalmon;
				acceptButton->Tag = senderUsername; // Attach username for event handling

				// Create the "Reject" button
				Button^ rejectButton = gcnew Button();
				rejectButton->Text = L"Reject";
				rejectButton->Size = System::Drawing::Size(75, 30);
				rejectButton->Location = System::Drawing::Point(500, 50);
				rejectButton->Click += gcnew EventHandler(this, &Requests::RejectRequest_Click);
				rejectButton->Tag = senderUsername; // Attach username for event handling

				// Add controls to the card panel
				card->Controls->Add(usernameLabel);
				card->Controls->Add(acceptButton);
				card->Controls->Add(rejectButton);

				// Add the card to the form
				this->Controls->Add(card);

				// Move to the next request
				requestNode = requestNode->next;
			}
		}

		// Event handler for the "Accept" button
		void AcceptRequest_Click(Object^ sender, EventArgs^ e) {
			Button^ acceptButton = (Button^)sender;
			String^ senderUsername = (String^)acceptButton->Tag; // Extract the username
			std::string username = msclr::interop::marshal_as<std::string>(senderUsername);

			// Find the sender user and accept the friend request
			User* senderUser = network->searchUser(username);
			if (senderUser != nullptr) {
				network->acceptRequest(senderUser, currUser);
				for each (Control ^ ctrl in this->Controls) {
					if (dynamic_cast<Panel^>(ctrl) != nullptr) {
						// If the control is a Panel (request card), remove it
						this->Controls->Remove(ctrl);
						delete ctrl;
					}
				}
				this->CreateRequestCards();
			}
		}

		// Event handler for the "Reject" button
		void RejectRequest_Click(Object^ sender, EventArgs^ e) {
			Button^ rejectButton = (Button^)sender;
			String^ senderUsername = (String^)rejectButton->Tag; // Extract the username
			std::string username = msclr::interop::marshal_as<std::string>(senderUsername);

			// Find the sender user and reject the friend request
			User* senderUser = network->searchUser(username);
			if (senderUser != nullptr) {
				network->rejectRequest(senderUser, currUser);
				for each (Control ^ ctrl in this->Controls) {
					if (dynamic_cast<Panel^>(ctrl) != nullptr) {
						// If the control is a Panel (request card), remove it
						this->Controls->Remove(ctrl);
						delete ctrl;
					}
				}
				this->CreateRequestCards();
			}
		}
#pragma endregion
	};
}
