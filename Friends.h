#pragma once
#include "headers/app/users_graph.h"
#include <msclr/marshal_cppstd.h>

namespace Instagramclone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

				public ref class Friends : public System::Windows::Forms::Form
	{
	public:
		Friends(void)
		{
			InitializeComponent();
		}
		Friends(UserGraph* graph, User* user)
		{
			this->network = graph;
			this->currUser = user;
			InitializeComponent();
			LoadFriendAndFollowerPanels(); 		}

	protected:
		~Friends()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::Panel^ friendsPanel;
	private: System::Windows::Forms::Panel^ followersPanel;
	private: System::Windows::Forms::Label^ followersTitle;

	protected:
		System::ComponentModel::Container^ components;
		UserGraph* network;
		User* currUser;

		void LoadFriendAndFollowerPanels()
		{
						friendsPanel = gcnew Panel();
			friendsPanel->BackColor = System::Drawing::Color::DarkSlateBlue;
			friendsPanel->Location = System::Drawing::Point(50, 150);
			friendsPanel->Size = System::Drawing::Size(450, 400);

						followersPanel = gcnew Panel();
			followersPanel->BackColor = System::Drawing::Color::DarkSlateBlue;
			followersPanel->Location = System::Drawing::Point(550, 150);
			followersPanel->Size = System::Drawing::Size(450, 400);

						this->Controls->Add(friendsPanel);
			this->Controls->Add(followersPanel);

						this->title->AutoSize = true;
			this->title->BackColor = System::Drawing::Color::Transparent;
			this->title->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::White;
			this->title->Location = System::Drawing::Point(52, 37);
			this->title->Size = System::Drawing::Size(281, 58);
			this->title->Text = L"Your Friends";
			this->Controls->Add(this->title);

						followersTitle = gcnew Label();
			followersTitle->AutoSize = true;
			followersTitle->BackColor = System::Drawing::Color::Transparent;
			followersTitle->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			followersTitle->ForeColor = System::Drawing::Color::White;
			followersTitle->Location = System::Drawing::Point(550, 37);
			followersTitle->Size = System::Drawing::Size(347, 58);
			followersTitle->Text = L"People you follow";
			this->Controls->Add(followersTitle);

						int yPosition = 10; 			auto friendUser = this->currUser->listFriends();
			while (friendUser != nullptr)
			{
								Label^ friendCard = gcnew Label();
				friendCard->Text = gcnew String(friendUser->data->getUsername().c_str());
				friendCard->Width = 400;
				friendCard->Height = 60;
				friendCard->Font = gcnew System::Drawing::Font("Calibri", 12);
				friendCard->BackColor = Color::White;
				friendCard->Padding = System::Windows::Forms::Padding(10);
				friendCard->Location = System::Drawing::Point(10, yPosition);
								Button^ messageButton = gcnew Button();
				messageButton->Text = L"Message";
				messageButton->BackColor = System::Drawing::Color::DarkSlateBlue;
				messageButton->ForeColor = System::Drawing::Color::White;
				messageButton->Width = 100;
				messageButton->Height = 40;
				messageButton->Location = System::Drawing::Point(300, yPosition + 10);
				messageButton->Click += gcnew System::EventHandler(this, &Friends::MessageButton_Click);

								friendsPanel->Controls->Add(messageButton);
				friendsPanel->Controls->Add(friendCard);


				yPosition += 70;
				friendUser = friendUser->next;
			}

						yPosition = 10; 			auto follower = this->currUser->listFollowed();
			while (follower != nullptr)
			{
								Label^ followerCard = gcnew Label();
				followerCard->Text = gcnew String(follower->data->getUsername().c_str());
				followerCard->Width = 400;
				followerCard->Height = 60;
				followerCard->Font = gcnew System::Drawing::Font("Calibri", 12);
				followerCard->BackColor = System::Drawing::Color::White;
				followerCard->Padding = System::Windows::Forms::Padding(10);
				followerCard->Location = System::Drawing::Point(10, yPosition);
								Button^ messageButton = gcnew Button();
				messageButton->Text = L"Message";
				messageButton->BackColor = System::Drawing::Color::DarkSlateBlue;
				messageButton->ForeColor = System::Drawing::Color::White;
				messageButton->Width = 100;
				messageButton->Height = 40;
				messageButton->Location = System::Drawing::Point(300, yPosition + 10);
				messageButton->Click += gcnew System::EventHandler(this, &Friends::MessageButton_Click);

								followersPanel->Controls->Add(messageButton);
				followersPanel->Controls->Add(followerCard);

				yPosition += 70;
				follower = follower->next;
			}
		}

		void Friends::MessageButton_Click(System::Object^ sender, System::EventArgs^ e)
		{
						Button^ clickedButton = dynamic_cast<Button^>(sender);

			if (clickedButton != nullptr)
			{
								Point buttonLocation = clickedButton->Location;
				Control^ buttonParent = clickedButton->Parent;

								for each (Control ^ control in buttonParent->Controls)
				{
					if (control->Location == Point(buttonLocation.X - 360, buttonLocation.Y)) 					{
						Label^ userLabel = dynamic_cast<Label^>(control);
						if (userLabel != nullptr)
						{
														std::string username = msclr::interop::marshal_as<std::string>(userLabel->Text);
						}
						break;
					}
				}
			}
		}

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Friends::typeid));
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
			this->title->Location = System::Drawing::Point(52, 37);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(281, 58);
			this->title->TabIndex = 2;
			this->title->Text = L"Your Friends";
			// 
			// Friends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1064, 681);
			this->Controls->Add(this->title);
			this->Name = L"Friends";
			this->Text = L"Friends";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
