#pragma once
#include "../Instagram_clone/headers/ADTs/stack.h"
#include "../Instagram_clone/headers/app/user.h"
#include "../Instagram_clone/headers/app/users_graph.h"

namespace Instagramclone {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Home
	/// </summary>
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
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
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

	private:
		System::ComponentModel::Container^ components;
		

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Home::typeid));
			this->title = (gcnew System::Windows::Forms::Label());
			this->feedFlowPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->bellIcon = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->sidebarPanel = (gcnew System::Windows::Forms::Panel());
			this->notificationPanel = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bellIcon))->BeginInit();
			this->panel1->SuspendLayout();
			this->sidebarPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// title
			// 
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
			// 
			// feedFlowPanel
			// 
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
			// 
			// bellIcon
			// 
			this->bellIcon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bellIcon.BackgroundImage")));
			this->bellIcon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->bellIcon->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bellIcon.Image")));
			this->bellIcon->Location = System::Drawing::Point(14, 7);
			this->bellIcon->Name = L"bellIcon";
			this->bellIcon->Size = System::Drawing::Size(34, 45);
			this->bellIcon->TabIndex = 2;
			this->bellIcon->TabStop = false;
			this->bellIcon->Click += gcnew System::EventHandler(this, &Home::bellIcon_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->bellIcon);
			this->panel1->Location = System::Drawing::Point(708, 32);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(62, 59);
			this->panel1->TabIndex = 3;
			// 
			// sidebarPanel
			// 
			this->sidebarPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(211)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)));
			this->sidebarPanel->Controls->Add(this->notificationPanel);
			this->sidebarPanel->Location = System::Drawing::Point(787, 1);
			this->sidebarPanel->Name = L"sidebarPanel";
			this->sidebarPanel->Size = System::Drawing::Size(280, 720);
			this->sidebarPanel->TabIndex = 0;
			this->sidebarPanel->Visible = false;
			// 
			// notificationPanel
			// 
			this->notificationPanel->AutoScroll = true;
			this->notificationPanel->AutoSize = true;
			this->notificationPanel->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->notificationPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->notificationPanel->Location = System::Drawing::Point(0, 0);
			this->notificationPanel->Name = L"notificationPanel";
			this->notificationPanel->Size = System::Drawing::Size(280, 0);
			this->notificationPanel->TabIndex = 0;
			// 
			// Home
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1064, 681);
			this->Controls->Add(this->sidebarPanel);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->feedFlowPanel);
			this->Controls->Add(this->title);
			this->Name = L"Home";
			this->Text = L"Home";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bellIcon))->EndInit();
			this->panel1->ResumeLayout(false);
			this->sidebarPanel->ResumeLayout(false);
			this->sidebarPanel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void LoadUserFeed() {
			// Add some preloaded posts
			this->currUser->addPost("Today is a nice day!");
			this->currUser->addPost("Mental health is overrated");
			this->currUser->addPost("I recently went to Mount Fuji with my friends. Had a great time!");
			User* followed = this->network->searchUser("bookWorm");
			if (followed)
			{
				followed->addPost("2025 is a great year for gamers!");
				followed->addPost("Anybody else had a \"Fall Guys\" phase, where you played the game all day?");
				this->currUser->follow(followed);
				followed->sendFriendRequest(this->currUser);
			}
			// Create a User and load their feed
			auto posts = this->currUser->getPosts();

			// Iterate through the user's feed and add PostControl for each Post
			while (!posts.isEmpty()) {
				Post* currentPost = new Post(posts.pop());

				PostControl^ postControl = gcnew PostControl(currentPost);
				feedFlowPanel->Controls->Add(postControl);
				postControl->Show();
			}

			posts = this->currUser->getFollowedPosts();

			// Iterate through the user's feed and add PostControl for each Post
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
			LoadUserFeed();  // Load the posts when the form is loaded
		}

		void loadNotifications()
		{
			notificationPanel->Controls->Clear();
			int yPosition = 10; // Starting position for the first notification
			auto notifications = this->currUser->getNotifications();
			while (!notifications.isEmpty())
			{
				String^ notification = gcnew System::String(notifications.dequeue().c_str());
				Label^ notificationLabel = gcnew Label();
				notificationLabel->Text = notification;
				notificationLabel->Width = 220;  // Set width of the label
				notificationLabel->Height = 70;  // Set height of each label
				notificationLabel->Font = gcnew System::Drawing::Font("Calibri", 10);
				notificationLabel->BackColor = Color::White;
				notificationLabel->Padding = System::Windows::Forms::Padding(10);
				notificationLabel->Location = System::Drawing::Point(10, yPosition);

				notificationPanel->Controls->Add(notificationLabel);
				yPosition += notificationLabel->Height + 10;
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
				// Initialize the layout of the post
				this->Size = System::Drawing::Size(500, 130);
				this->BackColor = System::Drawing::Color::Cornsilk;



				// Create and add Label for content
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

				// Create and add Label for owner
				System::Windows::Forms::Label^ ownerContent = gcnew System::Windows::Forms::Label();
				ownerContent->Text = gcnew System::String(CurrentPost->owner.c_str());
				ownerContent->Font = gcnew System::Drawing::Font("Calibri", 14, System::Drawing::FontStyle::Bold);
				ownerContent->AutoSize = true;
				ownerContent->Dock = System::Windows::Forms::DockStyle::Top;
				ownerContent->Height = 20;
				ownerContent->BackColor = System::Drawing::Color::Transparent;
				ownerContent->Padding = System::Windows::Forms::Padding(10);
				this->Controls->Add(ownerContent);


				// Create and add Label for Timestamp
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
};
}
