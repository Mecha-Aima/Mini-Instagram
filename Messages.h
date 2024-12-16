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

	public ref class Messages : public System::Windows::Forms::Form
	{
	public:
		Messages(void)
		{
			InitializeComponent();
		}
		Messages(UserGraph* graph, User* user)
		{
			this->network = graph;
			this->currUser = user;
			InitializeComponent();
		}

	protected:
		~Messages()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ sendBtn;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::FlowLayoutPanel^ flowPanel;
		   static RadioButton^ selectedRadioButton = nullptr;
		   UserGraph* network;
		   User* currUser;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::FlowLayoutPanel^ inboxPanel;
	protected:

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->sendBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->flowPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->inboxPanel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(94, 568);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(690, 80);
			this->textBox1->TabIndex = 0;
			// 
			// sendBtn
			// 
			this->sendBtn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(18)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->sendBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->sendBtn->Font = (gcnew System::Drawing::Font(L"Calibri", 12));
			this->sendBtn->ForeColor = System::Drawing::Color::White;
			this->sendBtn->Location = System::Drawing::Point(808, 580);
			this->sendBtn->Name = L"sendBtn";
			this->sendBtn->Size = System::Drawing::Size(112, 51);
			this->sendBtn->TabIndex = 2;
			this->sendBtn->Text = L"Send";
			this->sendBtn->UseVisualStyleBackColor = false;
			this->sendBtn->Click += gcnew System::EventHandler(this, &Messages::sendBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(91, 543);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 15);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Type your message";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(89, 32);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 29);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Select Receiver";
			// 
			// flowPanel
			// 
			this->flowPanel->AutoScroll = true;
			this->flowPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->flowPanel->Location = System::Drawing::Point(94, 90);
			this->flowPanel->Name = L"flowPanel";
			this->flowPanel->Size = System::Drawing::Size(356, 420);
			this->flowPanel->TabIndex = 0;
			this->flowPanel->WrapContents = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Calibri", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(549, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 29);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Inbox";
			// 
			// inboxPanel
			// 
			this->inboxPanel->AutoScroll = true;
			this->inboxPanel->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->inboxPanel->Location = System::Drawing::Point(554, 90);
			this->inboxPanel->Name = L"inboxPanel";
			this->inboxPanel->Size = System::Drawing::Size(445, 420);
			this->inboxPanel->TabIndex = 6;
			this->inboxPanel->WrapContents = false;
			// 
			// Messages
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(243)), static_cast<System::Int32>(static_cast<System::Byte>(244)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)));
			this->ClientSize = System::Drawing::Size(1064, 681);
			this->Controls->Add(this->inboxPanel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->flowPanel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sendBtn);
			this->Controls->Add(this->textBox1);
			this->Name = L"Messages";
			this->Text = L"Messages";
			this->Load += gcnew System::EventHandler(this, &Messages::Messages_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void createCards()
		{
			this->flowPanel->Controls->Clear();
			ListNode<User*>* friendsNode = currUser->listFriends();
			ListNode<User*>* followedNode = currUser->listFollowed();

			// Iterate over the friends and followed lists to create cards
			for (ListNode<User*>* node = friendsNode; node != nullptr; node = node->next) {
				createUserCard(node->data);
			}

			for (ListNode<User*>* node = followedNode; node != nullptr; node = node->next) {
				createUserCard(node->data);
			}
		}

		void createUserCard(User* user)
		{
			Panel^ userCard = gcnew Panel();
			userCard->BackColor = Color::White;
			userCard->Size = System::Drawing::Size(250, 50);

			// Create the radio button
			RadioButton^ radioButton = gcnew RadioButton();
			radioButton->Text = gcnew String(user->getUsername().c_str());
			radioButton->Location = Point(10, 25);
			radioButton->Tag = gcnew String(user->getUsername().c_str());
			radioButton->CheckedChanged += gcnew EventHandler(this, &Messages::RadioButton_CheckedChanged);

			userCard->Controls->Add(radioButton);
			this->flowPanel->Controls->Add(userCard);
		}

		void RadioButton_CheckedChanged(Object^ sender, EventArgs^ e)
		{
			// Ensure only one radio button is selected at a time
			RadioButton^ radioButton = (RadioButton^)sender;

			if (radioButton->Checked)
			{
				// Uncheck the previously selected radio button
				if (selectedRadioButton != nullptr && selectedRadioButton != radioButton)
				{
					selectedRadioButton->Checked = false;
				}

				selectedRadioButton = radioButton;
				textBox1->Enabled = true;
			}
			else
			{
				// Disable the message textbox if no radio button is selected
				if (selectedRadioButton == radioButton)
				{
					selectedRadioButton = nullptr;
					textBox1->Enabled = false;
				}
			}
		}

		void createInbox() {
			this->currUser->openInbox();
			auto messages = this->currUser->getMessages();
			auto messageNode = messages.getTop();
			this->inboxPanel->Controls->Clear();

			for (auto node = messageNode; node != nullptr; node = node->next) {
				Panel^ messageCard = gcnew Panel();
				messageCard->BackColor = Color::White;
				messageCard->Size = System::Drawing::Size(350, 100);
				messageCard->Padding = System::Windows::Forms::Padding(10);

				Label^ senderLabel = gcnew Label();
				senderLabel->Text = "From: " + gcnew String(node->data.getSender().c_str());
				senderLabel->Font = gcnew System::Drawing::Font("Calibri", 8, System::Drawing::FontStyle::Bold);
				senderLabel->Location = System::Drawing::Point(10, 10);  
				senderLabel->AutoSize = true;  

				Label^ receiverLabel = gcnew Label();
				receiverLabel->Text = "To: " + gcnew String(node->data.getReceiver().c_str());
				receiverLabel->Font = gcnew System::Drawing::Font("Calibri", 8);
				receiverLabel->Location = System::Drawing::Point(10, 30);
				receiverLabel->AutoSize = true;

				Label^ messageLabel = gcnew Label();
				messageLabel->Text = gcnew String(node->data.getContent().c_str());
				messageLabel->Font = gcnew System::Drawing::Font("Calibri", 10);
				messageLabel->Location = System::Drawing::Point(10, 50);
				messageLabel->AutoSize = true;	

				messageCard->Controls->Add(senderLabel);
				messageCard->Controls->Add(receiverLabel);
				messageCard->Controls->Add(messageLabel);

				this->inboxPanel->Controls->Add(messageCard);
			}
		}


#pragma endregion
	private: System::Void Messages_Load(System::Object^ sender, System::EventArgs^ e) {
		this->createCards();
		this->createInbox();
	}
private: System::Void sendBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(this->textBox1->Text))
	{
		MessageBox::Show("Cannot send empty message.");
		return;
	}
	String^ selectedUser = nullptr;

	// Loop through all radio buttons in the flow panel to find the selected one
	for each (Control ^ control in this->flowPanel->Controls)
	{
		Panel^ panel = dynamic_cast<Panel^>(control);
		if (panel != nullptr)
		{
			RadioButton^ radioButton = dynamic_cast<RadioButton^>(panel->Controls[0]);
			if (radioButton != nullptr && radioButton->Checked)
			{
				selectedUser = radioButton->Text;  
				break;
			}
		}
	}

	if (selectedUser != nullptr)
	{
		std::string username = msclr::interop::marshal_as<std::string>(selectedUser);
		User* receiver = this->network->searchUser(username);
		if (receiver)
		{
			std::string message = msclr::interop::marshal_as<std::string>(textBox1->Text);
			this->network->sendMessage(this->currUser, receiver, message);
		}
		MessageBox::Show("Message sent to " + selectedUser);
	}
	else
	{
		MessageBox::Show("Please select a user to send the message to.");
	}
}
};
}
