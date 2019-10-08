#pragma once

namespace devtale
{
	using namespace System;
	using namespace ComponentModel;
	using namespace Collections;
	using namespace Windows::Forms;
	using namespace Data;
	using namespace Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

		virtual property System::Windows::Forms::CreateParams^ CreateParams
		{
			System::Windows::Forms::CreateParams^ get() override
			{
				System::Windows::Forms::CreateParams^ overrideParams = Form::CreateParams;
				overrideParams->ClassStyle = overrideParams->ClassStyle | 0x200;
				return overrideParams;
			}
		}

	private:
		System::Windows::Forms::TabControl^ tabControl1;
	private:
		System::Windows::Forms::TabPage^ tabPage1;
	private:
		System::Windows::Forms::GroupBox^ groupBox1;
	private:
		System::Windows::Forms::TabPage^ tabPage2;
	private:
		System::Windows::Forms::GroupBox^ groupBox2;
	private:
		System::Windows::Forms::TextBox^ packetLogTextBox;
	private:
		System::Windows::Forms::CheckBox^ logSentPacketCheckBox;
	private:
		System::Windows::Forms::CheckBox^ logReceivePacketsCheckBox;
	private:
		System::Windows::Forms::CheckBox^ enableReceivedPacketFilterCheckBox;
	private:
		System::Windows::Forms::CheckBox^ enableSentPacketFilterCheckBox;
	private:
		System::Windows::Forms::Label^ label1;
	private:
		System::Windows::Forms::TabControl^ tabControl2;
	private:
		System::Windows::Forms::TabPage^ tabPage3;
	private:
		System::Windows::Forms::TabPage^ tabPage4;
	private:
		System::Windows::Forms::GroupBox^ groupBox4;
	private:
		System::Windows::Forms::TextBox^ textBox7;
	private:
		System::Windows::Forms::TextBox^ textBox6;
	private:
		System::Windows::Forms::RadioButton^ radioButton2;
	private:
		System::Windows::Forms::RadioButton^ radioButton1;
	private:
		System::Windows::Forms::Button^ multiplePacketSendButton;
	private:
		System::Windows::Forms::TextBox^ multiplePacketSendText;
	private:
		System::Windows::Forms::GroupBox^ groupBox3;
	private:
		System::Windows::Forms::Button^ singlePacketSendButton;
	private:
		System::Windows::Forms::TextBox^ singlePacketSendText;
	private:
		System::Windows::Forms::GroupBox^ groupBox5;
	private:
		System::Windows::Forms::TextBox^ textBox4;
	private:
		System::Windows::Forms::TextBox^ textBox8;
	private:
		System::Windows::Forms::RadioButton^ radioButton3;
	private:
		System::Windows::Forms::RadioButton^ radioButton4;
	private:
		System::Windows::Forms::TextBox^ multiplePacketReceiveText;
	private:
		System::Windows::Forms::Button^ multiplePacketReceiveButton;


	private:
		System::Windows::Forms::GroupBox^ groupBox6;
	private:
		System::Windows::Forms::Button^ singlePacketReceiveButton;

	private:
		System::Windows::Forms::TextBox^ singlePacketReceiveText;


	private:
		System::Windows::Forms::TabPage^ tabPage5;
	private:
		System::Windows::Forms::GroupBox^ groupBox8;
	private:
		System::Windows::Forms::Button^ newReceivedPacketFilterButton;
	private:
		System::Windows::Forms::Button^ removeSelectedReceiveFilter;
	private:
		System::Windows::Forms::TextBox^ newReceivedPacketFilterText;
	private:
		System::Windows::Forms::ListBox^ filterReceivedList;
	private:
		System::Windows::Forms::GroupBox^ groupBox7;
	private:
		System::Windows::Forms::Button^ newSentPacketFilterButton;
	private:
		System::Windows::Forms::TextBox^ newSentPacketFilterText;
	private:
		System::Windows::Forms::Button^ removeSentPacketFilter;
	private:
		System::Windows::Forms::ListBox^ filterSentList;
	private:
		System::Windows::Forms::TabPage^ tabPage6;
	private:
		System::Windows::Forms::GroupBox^ groupBox10;
	private:
		System::Windows::Forms::GroupBox^ groupBox9;
	private:
		System::Windows::Forms::TextBox^ textBox3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabControl2 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->multiplePacketSendButton = (gcnew System::Windows::Forms::Button());
			this->multiplePacketSendText = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->singlePacketSendButton = (gcnew System::Windows::Forms::Button());
			this->singlePacketSendText = (gcnew System::Windows::Forms::TextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->multiplePacketReceiveText = (gcnew System::Windows::Forms::TextBox());
			this->multiplePacketReceiveButton = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->singlePacketReceiveButton = (gcnew System::Windows::Forms::Button());
			this->singlePacketReceiveText = (gcnew System::Windows::Forms::TextBox());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->newReceivedPacketFilterButton = (gcnew System::Windows::Forms::Button());
			this->removeSelectedReceiveFilter = (gcnew System::Windows::Forms::Button());
			this->newReceivedPacketFilterText = (gcnew System::Windows::Forms::TextBox());
			this->filterReceivedList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->newSentPacketFilterButton = (gcnew System::Windows::Forms::Button());
			this->newSentPacketFilterText = (gcnew System::Windows::Forms::TextBox());
			this->removeSentPacketFilter = (gcnew System::Windows::Forms::Button());
			this->filterSentList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->packetLogTextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->enableReceivedPacketFilterCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->enableSentPacketFilterCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->logSentPacketCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->logReceivePacketsCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox10 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->groupBox8->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(6, 6);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(802, 499);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->tabControl2);
			this->tabPage1->Controls->Add(this->groupBox1);
			this->tabPage1->Controls->Add(this->groupBox2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(794, 473);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Packet Tool";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabControl2
			// 
			this->tabControl2->Controls->Add(this->tabPage3);
			this->tabControl2->Controls->Add(this->tabPage4);
			this->tabControl2->Controls->Add(this->tabPage5);
			this->tabControl2->Location = System::Drawing::Point(370, 90);
			this->tabControl2->Name = L"tabControl2";
			this->tabControl2->SelectedIndex = 0;
			this->tabControl2->Size = System::Drawing::Size(418, 377);
			this->tabControl2->TabIndex = 2;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->groupBox4);
			this->tabPage3->Controls->Add(this->groupBox3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(6);
			this->tabPage3->Size = System::Drawing::Size(410, 351);
			this->tabPage3->TabIndex = 0;
			this->tabPage3->Text = L"Send packets";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox7);
			this->groupBox4->Controls->Add(this->textBox6);
			this->groupBox4->Controls->Add(this->radioButton2);
			this->groupBox4->Controls->Add(this->radioButton1);
			this->groupBox4->Controls->Add(this->multiplePacketSendButton);
			this->groupBox4->Controls->Add(this->multiplePacketSendText);
			this->groupBox4->Location = System::Drawing::Point(9, 95);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(6);
			this->groupBox4->Size = System::Drawing::Size(392, 247);
			this->groupBox4->TabIndex = 2;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Multiple packets";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(226, 187);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(58, 20);
			this->textBox7->TabIndex = 5;
			this->textBox7->Text = L"1";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(59, 187);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(37, 20);
			this->textBox6->TabIndex = 4;
			this->textBox6->Text = L"1";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(146, 188);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(164, 17);
			this->radioButton2->TabIndex = 3;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Send every                        ms";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(9, 188);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(131, 17);
			this->radioButton1->TabIndex = 2;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Send                 time(s)";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// multiplePacketSendButton
			// 
			this->multiplePacketSendButton->Location = System::Drawing::Point(9, 215);
			this->multiplePacketSendButton->Name = L"multiplePacketSendButton";
			this->multiplePacketSendButton->Size = System::Drawing::Size(75, 23);
			this->multiplePacketSendButton->TabIndex = 1;
			this->multiplePacketSendButton->Text = L"Send";
			this->multiplePacketSendButton->UseVisualStyleBackColor = true;
			// 
			// multiplePacketSendText
			// 
			this->multiplePacketSendText->Location = System::Drawing::Point(9, 22);
			this->multiplePacketSendText->Multiline = true;
			this->multiplePacketSendText->Name = L"multiplePacketSendText";
			this->multiplePacketSendText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->multiplePacketSendText->Size = System::Drawing::Size(374, 148);
			this->multiplePacketSendText->TabIndex = 0;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->singlePacketSendButton);
			this->groupBox3->Controls->Add(this->singlePacketSendText);
			this->groupBox3->Location = System::Drawing::Point(9, 9);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(6);
			this->groupBox3->Size = System::Drawing::Size(392, 80);
			this->groupBox3->TabIndex = 0;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Single packet";
			// 
			// singlePacketSendButton
			// 
			this->singlePacketSendButton->Location = System::Drawing::Point(9, 48);
			this->singlePacketSendButton->Name = L"singlePacketSendButton";
			this->singlePacketSendButton->Size = System::Drawing::Size(75, 23);
			this->singlePacketSendButton->TabIndex = 1;
			this->singlePacketSendButton->Text = L"Send";
			this->singlePacketSendButton->UseVisualStyleBackColor = true;
			// 
			// singlePacketSendText
			// 
			this->singlePacketSendText->Location = System::Drawing::Point(9, 22);
			this->singlePacketSendText->Name = L"singlePacketSendText";
			this->singlePacketSendText->Size = System::Drawing::Size(374, 20);
			this->singlePacketSendText->TabIndex = 0;
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->groupBox5);
			this->tabPage4->Controls->Add(this->groupBox6);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(6);
			this->tabPage4->Size = System::Drawing::Size(410, 351);
			this->tabPage4->TabIndex = 1;
			this->tabPage4->Text = L"Receive packets";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->textBox4);
			this->groupBox5->Controls->Add(this->textBox8);
			this->groupBox5->Controls->Add(this->radioButton3);
			this->groupBox5->Controls->Add(this->radioButton4);
			this->groupBox5->Controls->Add(this->multiplePacketReceiveText);
			this->groupBox5->Controls->Add(this->multiplePacketReceiveButton);
			this->groupBox5->Location = System::Drawing::Point(9, 95);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(6);
			this->groupBox5->Size = System::Drawing::Size(392, 247);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Multiple packets";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(255, 187);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(58, 20);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"1";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(74, 187);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(37, 20);
			this->textBox8->TabIndex = 9;
			this->textBox8->Text = L"1";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(161, 188);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(179, 17);
			this->radioButton3->TabIndex = 8;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Receive every                        ms";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(9, 188);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(146, 17);
			this->radioButton4->TabIndex = 7;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Receive                 time(s)";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// multiplePacketReceiveText
			// 
			this->multiplePacketReceiveText->Location = System::Drawing::Point(9, 22);
			this->multiplePacketReceiveText->Multiline = true;
			this->multiplePacketReceiveText->Name = L"multiplePacketReceiveText";
			this->multiplePacketReceiveText->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->multiplePacketReceiveText->Size = System::Drawing::Size(374, 148);
			this->multiplePacketReceiveText->TabIndex = 6;
			// 
			// multiplePacketReceiveButton
			// 
			this->multiplePacketReceiveButton->Location = System::Drawing::Point(9, 215);
			this->multiplePacketReceiveButton->Name = L"multiplePacketReceiveButton";
			this->multiplePacketReceiveButton->Size = System::Drawing::Size(75, 23);
			this->multiplePacketReceiveButton->TabIndex = 1;
			this->multiplePacketReceiveButton->Text = L"Receive";
			this->multiplePacketReceiveButton->UseVisualStyleBackColor = true;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->singlePacketReceiveButton);
			this->groupBox6->Controls->Add(this->singlePacketReceiveText);
			this->groupBox6->Location = System::Drawing::Point(9, 9);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Padding = System::Windows::Forms::Padding(6);
			this->groupBox6->Size = System::Drawing::Size(392, 80);
			this->groupBox6->TabIndex = 3;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Single packet";
			// 
			// singlePacketReceiveButton
			// 
			this->singlePacketReceiveButton->Location = System::Drawing::Point(9, 48);
			this->singlePacketReceiveButton->Name = L"singlePacketReceiveButton";
			this->singlePacketReceiveButton->Size = System::Drawing::Size(75, 23);
			this->singlePacketReceiveButton->TabIndex = 1;
			this->singlePacketReceiveButton->Text = L"Receive";
			this->singlePacketReceiveButton->UseVisualStyleBackColor = true;
			// 
			// singlePacketReceiveText
			// 
			this->singlePacketReceiveText->Location = System::Drawing::Point(9, 22);
			this->singlePacketReceiveText->Name = L"singlePacketReceiveText";
			this->singlePacketReceiveText->Size = System::Drawing::Size(374, 20);
			this->singlePacketReceiveText->TabIndex = 0;
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->groupBox8);
			this->tabPage5->Controls->Add(this->groupBox7);
			this->tabPage5->Location = System::Drawing::Point(4, 22);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(410, 351);
			this->tabPage5->TabIndex = 2;
			this->tabPage5->Text = L"Filters";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->newReceivedPacketFilterButton);
			this->groupBox8->Controls->Add(this->removeSelectedReceiveFilter);
			this->groupBox8->Controls->Add(this->newReceivedPacketFilterText);
			this->groupBox8->Controls->Add(this->filterReceivedList);
			this->groupBox8->Location = System::Drawing::Point(213, 6);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(201, 339);
			this->groupBox8->TabIndex = 1;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Received packets";
			// 
			// newReceivedPacketFilterButton
			// 
			this->newReceivedPacketFilterButton->Location = System::Drawing::Point(116, 308);
			this->newReceivedPacketFilterButton->Name = L"newReceivedPacketFilterButton";
			this->newReceivedPacketFilterButton->Size = System::Drawing::Size(75, 23);
			this->newReceivedPacketFilterButton->TabIndex = 5;
			this->newReceivedPacketFilterButton->Text = L"Add";
			this->newReceivedPacketFilterButton->UseVisualStyleBackColor = true;
			// 
			// removeSelectedReceiveFilter
			// 
			this->removeSelectedReceiveFilter->Location = System::Drawing::Point(6, 279);
			this->removeSelectedReceiveFilter->Name = L"removeSelectedReceiveFilter";
			this->removeSelectedReceiveFilter->Size = System::Drawing::Size(185, 23);
			this->removeSelectedReceiveFilter->TabIndex = 2;
			this->removeSelectedReceiveFilter->Text = L"Remove selected filter";
			this->removeSelectedReceiveFilter->UseVisualStyleBackColor = true;
			// 
			// newReceivedPacketFilterText
			// 
			this->newReceivedPacketFilterText->Location = System::Drawing::Point(6, 309);
			this->newReceivedPacketFilterText->Name = L"newReceivedPacketFilterText";
			this->newReceivedPacketFilterText->Size = System::Drawing::Size(104, 20);
			this->newReceivedPacketFilterText->TabIndex = 4;
			// 
			// filterReceivedList
			// 
			this->filterReceivedList->FormattingEnabled = true;
			this->filterReceivedList->Location = System::Drawing::Point(6, 19);
			this->filterReceivedList->Name = L"filterReceivedList";
			this->filterReceivedList->Size = System::Drawing::Size(185, 251);
			this->filterReceivedList->TabIndex = 1;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->newSentPacketFilterButton);
			this->groupBox7->Controls->Add(this->newSentPacketFilterText);
			this->groupBox7->Controls->Add(this->removeSentPacketFilter);
			this->groupBox7->Controls->Add(this->filterSentList);
			this->groupBox7->Location = System::Drawing::Point(7, 6);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(196, 339);
			this->groupBox7->TabIndex = 0;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Sent packets";
			// 
			// newSentPacketFilterButton
			// 
			this->newSentPacketFilterButton->Location = System::Drawing::Point(115, 306);
			this->newSentPacketFilterButton->Name = L"newSentPacketFilterButton";
			this->newSentPacketFilterButton->Size = System::Drawing::Size(75, 23);
			this->newSentPacketFilterButton->TabIndex = 3;
			this->newSentPacketFilterButton->Text = L"Add";
			this->newSentPacketFilterButton->UseVisualStyleBackColor = true;
			// 
			// newSentPacketFilterText
			// 
			this->newSentPacketFilterText->Location = System::Drawing::Point(6, 308);
			this->newSentPacketFilterText->Name = L"newSentPacketFilterText";
			this->newSentPacketFilterText->Size = System::Drawing::Size(103, 20);
			this->newSentPacketFilterText->TabIndex = 2;
			// 
			// removeSentPacketFilter
			// 
			this->removeSentPacketFilter->Location = System::Drawing::Point(6, 279);
			this->removeSentPacketFilter->Name = L"removeSentPacketFilter";
			this->removeSentPacketFilter->Size = System::Drawing::Size(184, 23);
			this->removeSentPacketFilter->TabIndex = 1;
			this->removeSentPacketFilter->Text = L"Remove selected filter";
			this->removeSentPacketFilter->UseVisualStyleBackColor = true;
			// 
			// filterSentList
			// 
			this->filterSentList->FormattingEnabled = true;
			this->filterSentList->Location = System::Drawing::Point(6, 19);
			this->filterSentList->Name = L"filterSentList";
			this->filterSentList->Size = System::Drawing::Size(184, 251);
			this->filterSentList->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->packetLogTextBox);
			this->groupBox1->Location = System::Drawing::Point(6, 6);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(6);
			this->groupBox1->Size = System::Drawing::Size(358, 461);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Log";
			// 
			// packetLogTextBox
			// 
			this->packetLogTextBox->Location = System::Drawing::Point(9, 22);
			this->packetLogTextBox->Multiline = true;
			this->packetLogTextBox->Name = L"packetLogTextBox";
			this->packetLogTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->packetLogTextBox->Size = System::Drawing::Size(340, 430);
			this->packetLogTextBox->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->enableReceivedPacketFilterCheckBox);
			this->groupBox2->Controls->Add(this->enableSentPacketFilterCheckBox);
			this->groupBox2->Controls->Add(this->logSentPacketCheckBox);
			this->groupBox2->Controls->Add(this->logReceivePacketsCheckBox);
			this->groupBox2->Location = System::Drawing::Point(370, 6);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(6);
			this->groupBox2->Size = System::Drawing::Size(200, 78);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Enable logging";
			// 
			// enableReceivedPacketFilterCheckBox
			// 
			this->enableReceivedPacketFilterCheckBox->AutoSize = true;
			this->enableReceivedPacketFilterCheckBox->Location = System::Drawing::Point(130, 47);
			this->enableReceivedPacketFilterCheckBox->Name = L"enableReceivedPacketFilterCheckBox";
			this->enableReceivedPacketFilterCheckBox->Size = System::Drawing::Size(61, 17);
			this->enableReceivedPacketFilterCheckBox->TabIndex = 3;
			this->enableReceivedPacketFilterCheckBox->Text = L"w\\ filter";
			this->enableReceivedPacketFilterCheckBox->UseVisualStyleBackColor = true;
			// 
			// enableSentPacketFilterCheckBox
			// 
			this->enableSentPacketFilterCheckBox->AutoSize = true;
			this->enableSentPacketFilterCheckBox->Location = System::Drawing::Point(130, 24);
			this->enableSentPacketFilterCheckBox->Name = L"enableSentPacketFilterCheckBox";
			this->enableSentPacketFilterCheckBox->Size = System::Drawing::Size(61, 17);
			this->enableSentPacketFilterCheckBox->TabIndex = 2;
			this->enableSentPacketFilterCheckBox->Text = L"w\\ filter";
			this->enableSentPacketFilterCheckBox->UseVisualStyleBackColor = true;
			// 
			// logSentPacketCheckBox
			// 
			this->logSentPacketCheckBox->AutoSize = true;
			this->logSentPacketCheckBox->Location = System::Drawing::Point(11, 24);
			this->logSentPacketCheckBox->Name = L"logSentPacketCheckBox";
			this->logSentPacketCheckBox->Size = System::Drawing::Size(89, 17);
			this->logSentPacketCheckBox->TabIndex = 1;
			this->logSentPacketCheckBox->Text = L"Sent packets";
			this->logSentPacketCheckBox->UseVisualStyleBackColor = true;
			// 
			// logReceivePacketsCheckBox
			// 
			this->logReceivePacketsCheckBox->AutoSize = true;
			this->logReceivePacketsCheckBox->Location = System::Drawing::Point(11, 47);
			this->logReceivePacketsCheckBox->Name = L"logReceivePacketsCheckBox";
			this->logReceivePacketsCheckBox->Size = System::Drawing::Size(113, 17);
			this->logReceivePacketsCheckBox->TabIndex = 0;
			this->logReceivePacketsCheckBox->Text = L"Received packets";
			this->logReceivePacketsCheckBox->UseVisualStyleBackColor = true;
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->groupBox10);
			this->tabPage6->Controls->Add(this->groupBox9);
			this->tabPage6->Location = System::Drawing::Point(4, 22);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(794, 473);
			this->tabPage6->TabIndex = 2;
			this->tabPage6->Text = L"Lua IDE";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// groupBox10
			// 
			this->groupBox10->Location = System::Drawing::Point(617, 6);
			this->groupBox10->Name = L"groupBox10";
			this->groupBox10->Size = System::Drawing::Size(171, 461);
			this->groupBox10->TabIndex = 1;
			this->groupBox10->TabStop = false;
			this->groupBox10->Text = L"Menu";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->textBox3);
			this->groupBox9->Location = System::Drawing::Point(6, 6);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(605, 461);
			this->groupBox9->TabIndex = 0;
			this->groupBox9->TabStop = false;
			this->groupBox9->Text = L"Editor";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(6, 19);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(593, 436);
			this->textBox3->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(6);
			this->tabPage2->Size = System::Drawing::Size(794, 473);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"About";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(483, 182);
			this->label1->TabIndex = 0;
			this->label1->Text = resources->GetString(L"label1.Text");
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(814, 511);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MainForm";
			this->Padding = System::Windows::Forms::Padding(3);
			this->Text = L"DevTale";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabControl2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->tabPage5->ResumeLayout(false);
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->tabPage6->ResumeLayout(false);
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
