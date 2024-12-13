#pragma once
#include "../Instagram_clone/headers/ADTs/stack.h"
#include "../Instagram_clone/headers/app/user.h"
#include "../Instagram_clone/headers/app/users_graph.h"
#include "SearchForm.h"
#include "Friends.h"


namespace Instagramclone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


				public ref class Home : public System::Windows::Forms::Form
	{
	public:
		/*ref class PostControl;*/
		Home(void)
		{
			InitializeComponent();
		}
		Home(User* user, UserGraph* network)
		{
			InitializeComponent();
			this->currUser = user;
			this->network = network;
			this->Load += gcnew System::EventHandler(this, &Home::Form_Load);
		}

	protected:
								~Home()
		{
			if (components)
			{
				delete components;
			}
			this->currUser = nullptr;
			this->network = nullptr;
		}
	private: System::Windows::Forms::Label^ title;
	private: System::Windows::Forms::FlowLayoutPanel^ feedFlowPanel;
		   UserGraph* network;
		   User* currUser;
	private: System::Windows::Forms::PictureBox^ bellIcon;
	private: System::Windows::Forms::Panel^ panel1;
	System::Windows::Forms::Panel^ sidebarPanel;
	System::Windows::Forms::Panel^ notificationPanel;
	bool panelOpen = false;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ friendRequestlbl;
	private: System::Windows::Forms::Panel^ friendRequestPnl;


	private: System::Windows::Forms::PictureBox^ friendIcon;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label4;


	private:
		System::ComponentModel::Container^ components;
		

#pragma region Windows Form Designer generated code
										void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->feedFlowPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->bellIcon = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->sidebarPanel = (gcnew System::Windows::Forms::Panel());
			this->notificationPanel = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->friendRequestlbl = (gcnew System::Windows::Forms::Label());
			this->friendRequestPnl = (gcnew System::Windows::Forms::Panel());
			this->friendIcon = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bellIcon))->BeginInit();
			this->panel1->SuspendLayout();
			this->sidebarPanel->SuspendLayout();
			this->friendRequestPnl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->friendIcon))->BeginInit();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
												this->title->AutoSize = true;
			this->title->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title->ForeColor = System::Drawing::Color::Black;
			this->title->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"title.Image")));
			this->title->Location = System::Drawing::Point(26, 32);
			this->title->Name = L"title";
			this->title->Size = System::Drawing::Size(152, 38);
			this->title->TabIndex = 0;
			this->title->Text = L"Your Feed";
												this->feedFlowPanel->AutoScroll = true;
			this->feedFlowPanel->AutoSize = true;
			this->feedFlowPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->feedFlowPanel->BackColor = System::Drawing::Color::Transparent;
			this->feedFlowPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->feedFlowPanel->Location = System::Drawing::Point(26, 82);
			this->feedFlowPanel->Name = L"feedFlowPanel";
			this->feedFlowPanel->Size = System::Drawing::Size(0, 0);
			this->feedFlowPanel->TabIndex = 1;
			this->feedFlowPanel->WrapContents = false;
												this->bellIcon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bellIcon.BackgroundImage")));
			this->bellIcon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->bellIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bellIcon.Image")));
			this->bellIcon->Location = System::Drawing::Point(14, 7);
			this->bellIcon->Name = L"bellIcon";
			this->bellIcon->Size = System::Drawing::Size(34, 45);
			this->bellIcon->TabIndex = 2;
			this->bellIcon->TabStop = false;
			this->bellIcon->Click += gcnew System::EventHandler(this, &Home::bellIcon_Click);
												this->panel1->Controls->Add(this->bellIcon);
			this->panel1->Location = System::Drawing::Point(708, 32);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(62, 59);
			this->panel1->TabIndex = 3;
												this->sidebarPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->sidebarPanel->Controls->Add(this->notificationPanel);
			this->sidebarPanel->Location = System::Drawing::Point(787, 1);
			this->sidebarPanel->Name = L"sidebarPanel";
			this->sidebarPanel->Size = System::Drawing::Size(280, 720);
			this->sidebarPanel->TabIndex = 0;
			this->sidebarPanel->Visible = false;
												this->notificationPanel->AutoScroll = true;
			this->notificationPanel->AutoSize = true;
			this->notificationPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->notificationPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->notificationPanel->Location = System::Drawing::Point(0, 0);
			this->notificationPanel->Name = L"notificationPanel";
			this->notificationPanel->Size = System::Drawing::Size(280, 0);
			this->notificationPanel->TabIndex = 0;
												this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
												this->friendRequestlbl->AutoSize = true;
			this->friendRequestlbl->BackColor = System::Drawing::Color::Transparent;
			this->friendRequestlbl->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->friendRequestlbl->Location = System::Drawing::Point(60, 21);
			this->friendRequestlbl->Name = L"friendRequestlbl";
			this->friendRequestlbl->Size = System::Drawing::Size(84, 19);
			this->friendRequestlbl->TabIndex = 5;
			this->friendRequestlbl->Text = L"Add Friend";
												this->friendRequestPnl->BackColor = System::Drawing::Color::Khaki;
			this->friendRequestPnl->Controls->Add(this->friendIcon);
			this->friendRequestPnl->Controls->Add(this->friendRequestlbl);
			this->friendRequestPnl->Location = System::Drawing::Point(588, 112);
			this->friendRequestPnl->Name = L"friendRequestPnl";
			this->friendRequestPnl->Size = System::Drawing::Size(182, 60);
			this->friendRequestPnl->TabIndex = 6;
			this->friendRequestPnl->Click += gcnew System::EventHandler(this, &Home::friendRequestPnl_Click);
												this->friendIcon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"friendIcon.BackgroundImage")));
			this->friendIcon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->friendIcon->Location = System::Drawing::Point(12, 13);
			this->friendIcon->Name = L"friendIcon";
			this->friendIcon->Size = System::Drawing::Size(35, 36);
			this->friendIcon->TabIndex = 6;
			this->friendIcon->TabStop = false;
												this->panel2->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(588, 200);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(182, 60);
			this->panel2->TabIndex = 7;
			this->panel2->Click += gcnew System::EventHandler(this, &Home::panel2_Click);
												this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(12, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(35, 36);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
												this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(60, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 19);
			this->label2->TabIndex = 5;
			this->label2->Text = L"View Friends";
												this->panel3->BackColor = System::Drawing::Color::Sienna;
			this->panel3->Controls->Add(this->pictureBox2);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(588, 285);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(182, 60);
			this->panel3->TabIndex = 8;
			this->panel3->Click += gcnew System::EventHandler(this, &Home::panel3_Click);
												this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(12, 13);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(35, 36);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
												this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(60, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 19);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Send Message";
												this->panel4->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel4->Controls->Add(this->pictureBox3);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(588, 363);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(182, 60);
			this->panel4->TabIndex = 9;
			this->panel4->Click += gcnew System::EventHandler(this, &Home::panel4_Click);
												this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(12, 13);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(35, 36);
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
												this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(60, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(61, 19);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Log out";
												this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1081, 698);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->friendRequestPnl);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sidebarPanel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->feedFlowPanel);
			this->Controls->Add(this->title);
			this->Name = L"Home";
			this->Text = L"Home";
			this->Load += gcnew System::EventHandler(this, &Home::Home_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bellIcon))->EndInit();
			this->panel1->ResumeLayout(false);
			this->sidebarPanel->ResumeLayout(false);
			this->sidebarPanel->PerformLayout();
			this->friendRequestPnl->ResumeLayout(false);
			this->friendRequestPnl->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->friendIcon))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void LoadUserFeed() {
						this->currUser->addPost("Today is a nice day!");
			this->currUser->addPost("Mental health is overrated");
			this->currUser->addPost("I recently went to Mount Fuji with my friends. Had a great time!");
			User* followed = this->network->searchUser("gamerGirl");
			User* friendUser = this->network->searchUser("codeNinja");
			User* friend2 = this->network->searchUser("bookWorm");
			if (followed)
			{
				followed->addPost("2025 is a great year for gamers!");
				followed->addPost("Anybody else had a \"Fall Guys\" phase, where you played the game all day?");
				this->currUser->follow(followed);
				followed->sendFriendRequest(this->currUser);
			}
			if (friendUser)
			{
				network->sendRequest(this->currUser, friendUser);
				network->acceptRequest(this->currUser, friendUser);
			}
			if (friend2)
			{
				network->sendRequest(this->currUser, friend2);
				network->acceptRequest(this->currUser, friend2);
			}
						this->currUser->refreshFeed();
			auto posts = this->currUser->getPosts();

						while (!posts.isEmpty()) {
				Post* currentPost = new Post(posts.pop());

				PostControl^ postControl = gcnew PostControl(currentPost);
				feedFlowPanel->Controls->Add(postControl);
				postControl->Show();
			}

			posts = this->currUser->getFollowedPosts();

						while (!posts.isEmpty()) {
				Post* currentPost = new Post(posts.pop());

				PostControl^ postControl = gcnew PostControl(currentPost);
				feedFlowPanel->Controls->Add(postControl);
				postControl->Show();
			}

			User* texter = this->network->searchUser("amazingUser");
			if (texter)
			{
				this->network->sendMessage(texter, this->currUser, "Hi there, let's be friends!");
			}
		}

		void Form_Load(Object^ sender, EventArgs^ e)
		{
			LoadUserFeed();  		}

		void loadNotifications()
		{
			notificationPanel->Controls->Clear();
			int yPosition = 10; 			auto notifications = this->currUser->getNotifications();
			while (!notifications.isEmpty())
			{
				String^ notification = gcnew System::String(notifications.dequeue().c_str());
				Label^ notificationLabel = gcnew Label();
				notificationLabel->Text = notification;
				notificationLabel->Width = 260;  				notificationLabel->Height = 80;  				notificationLabel->Font = gcnew System::Drawing::Font("Calibri", 10);
				notificationLabel->BackColor = Color::White;
				notificationLabel->Padding = System::Windows::Forms::Padding(10);
				notificationLabel->Location = System::Drawing::Point(10, yPosition);	

				notificationPanel->Controls->Add(notificationLabel);

				yPosition += notificationLabel->Height + 15;
			}
			notificationPanel->Height = yPosition + 15;
			
		}


		ref class PostControl : public System::Windows::Forms::UserControl
		{
		public:
			Post* CurrentPost;

			PostControl(Post* post) {
				CurrentPost = post;
				InitializeComponent();
			}

		protected:
			~PostControl() {
			}

		private:
			void InitializeComponent() {
								this->Size = System::Drawing::Size(500, 130);
				this->BackColor = System::Drawing::Color::Cornsilk;



								System::Windows::Forms::Label^ lblContent = gcnew System::Windows::Forms::Label();
				lblContent->Text = gcnew System::String(CurrentPost->content.c_str());
				lblContent->Font = gcnew System::Drawing::Font("Calibri", 12);
				lblContent->BackColor = System::Drawing::Color::Transparent;
				lblContent->Padding = System::Windows::Forms::Padding(10);
				lblContent->Height = 40;
				lblContent->Dock = System::Windows::Forms::DockStyle::Top;
				lblContent->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				lblContent->AutoSize = true;
				this->Controls->Add(lblContent);

								System::Windows::Forms::Label^ ownerContent = gcnew System::Windows::Forms::Label();
				ownerContent->Text = gcnew System::String(CurrentPost->owner.c_str());
				ownerContent->Font = gcnew System::Drawing::Font("Calibri", 14, System::Drawing::FontStyle::Bold);
				ownerContent->AutoSize = true;
				ownerContent->Dock = System::Windows::Forms::DockStyle::Top;
				ownerContent->Height = 20;
				ownerContent->BackColor = System::Drawing::Color::Transparent;
				ownerContent->Padding = System::Windows::Forms::Padding(10);
				this->Controls->Add(ownerContent);


								System::Windows::Forms::Label^ lblTimestamp = gcnew System::Windows::Forms::Label();
				lblTimestamp->Text = "Posted on: " + gcnew System::String(CurrentPost->timestamp.c_str());
				lblTimestamp->Dock = System::Windows::Forms::DockStyle::Bottom;
				lblTimestamp->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				lblTimestamp->AutoSize = true;
				lblTimestamp->Font = gcnew System::Drawing::Font("Calibri", 10);
				lblTimestamp->Padding = System::Windows::Forms::Padding(10);
				lblTimestamp->BackColor = System::Drawing::Color::Transparent;
				this->Controls->Add(lblTimestamp);
			}
		};
#pragma endregion
	private: System::Void bellIcon_Click(System::Object^ sender, System::EventArgs^ e) {
		if (panelOpen)
		{
			this->sidebarPanel->Hide();
		}
		else
		{
			loadNotifications();
			this->sidebarPanel->Show();
		}
		panelOpen = !panelOpen;
	}

private: System::Void Home_Load(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void friendRequestPnl_Click(System::Object^ sender, System::EventArgs^ e) {
	Search^ searchForm = gcnew Search(this->network, this->currUser);
	searchForm->Show();
}
private: System::Void panel2_Click(System::Object^ sender, System::EventArgs^ e) {
	Friends^ friendsForm = gcnew Friends(this->network, this->currUser);
	friendsForm->Show();
}
private: System::Void panel3_Click(System::Object^ sender, System::EventArgs^ e) {
	Search^ searchForm = gcnew Search(this->network, this->currUser);
	searchForm->Show();
}
private: System::Void panel4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	delete this;
}
};
}
