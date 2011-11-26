#pragma once

#include "ConfigFile.h"

namespace MS_06S
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Anaheim::TcpSocket;

	/// <summary>
	/// MainForm の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

#pragma region フィールド

	private: ConfigFile^ config;			///< コンフィグファイル
	private: TcpClientSocket^ tcpClient;	///< TCPクライアント

	private: System::Windows::Forms::Button^  buttonDisConnect;
	private: System::Windows::Forms::TextBox^  textServerIp;
	private: System::Windows::Forms::Button^  buttonConnect;
	private: System::Windows::Forms::TextBox^  textServerPort;
	private: System::Windows::Forms::Label^  labelServerPort;
	private: System::Windows::Forms::Label^  labelServerIp;
	private: System::Windows::Forms::Label^  labelLocalPort;
	private: System::Windows::Forms::Label^  labelLocalIp;
	private: System::Windows::Forms::TextBox^  textLocalPort;
	private: System::Windows::Forms::TextBox^  textLocalIp;
	private: System::Windows::Forms::Button^  buttonSend;
	private: System::Windows::Forms::TextBox^  textMessage;
	private: System::Windows::Forms::ListBox^  listMessage;
	private: System::Windows::Forms::Button^  buttonClear;
	private: System::Windows::Forms::RadioButton^  radioUtf8;
	private: System::Windows::Forms::RadioButton^  radioAscii;
	private: System::Windows::Forms::Label^  labelMessage;

#pragma endregion

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
			this->Initialize();
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->buttonDisConnect = (gcnew System::Windows::Forms::Button());
			this->textServerIp = (gcnew System::Windows::Forms::TextBox());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->textServerPort = (gcnew System::Windows::Forms::TextBox());
			this->labelServerPort = (gcnew System::Windows::Forms::Label());
			this->labelServerIp = (gcnew System::Windows::Forms::Label());
			this->labelLocalPort = (gcnew System::Windows::Forms::Label());
			this->labelLocalIp = (gcnew System::Windows::Forms::Label());
			this->textLocalPort = (gcnew System::Windows::Forms::TextBox());
			this->textLocalIp = (gcnew System::Windows::Forms::TextBox());
			this->buttonSend = (gcnew System::Windows::Forms::Button());
			this->textMessage = (gcnew System::Windows::Forms::TextBox());
			this->listMessage = (gcnew System::Windows::Forms::ListBox());
			this->buttonClear = (gcnew System::Windows::Forms::Button());
			this->labelMessage = (gcnew System::Windows::Forms::Label());
			this->radioUtf8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioAscii = (gcnew System::Windows::Forms::RadioButton());
			this->SuspendLayout();
			// 
			// buttonDisConnect
			// 
			this->buttonDisConnect->Enabled = false;
			this->buttonDisConnect->Location = System::Drawing::Point(187, 33);
			this->buttonDisConnect->Name = L"buttonDisConnect";
			this->buttonDisConnect->Size = System::Drawing::Size(75, 23);
			this->buttonDisConnect->TabIndex = 17;
			this->buttonDisConnect->Text = L"切断";
			this->buttonDisConnect->UseVisualStyleBackColor = true;
			this->buttonDisConnect->Click += gcnew System::EventHandler(this, &MainForm::buttonDisConnect_Click);
			// 
			// textServerIp
			// 
			this->textServerIp->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->textServerIp->Location = System::Drawing::Point(81, 6);
			this->textServerIp->Name = L"textServerIp";
			this->textServerIp->Size = System::Drawing::Size(100, 19);
			this->textServerIp->TabIndex = 14;
			// 
			// buttonConnect
			// 
			this->buttonConnect->Location = System::Drawing::Point(187, 4);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(75, 23);
			this->buttonConnect->TabIndex = 16;
			this->buttonConnect->Text = L"接続";
			this->buttonConnect->UseVisualStyleBackColor = true;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &MainForm::buttonConnect_Click);
			// 
			// textServerPort
			// 
			this->textServerPort->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->textServerPort->Location = System::Drawing::Point(81, 35);
			this->textServerPort->Name = L"textServerPort";
			this->textServerPort->Size = System::Drawing::Size(100, 19);
			this->textServerPort->TabIndex = 15;
			// 
			// labelServerPort
			// 
			this->labelServerPort->AutoSize = true;
			this->labelServerPort->Location = System::Drawing::Point(12, 38);
			this->labelServerPort->Name = L"labelServerPort";
			this->labelServerPort->Size = System::Drawing::Size(63, 12);
			this->labelServerPort->TabIndex = 21;
			this->labelServerPort->Text = L"Server Port";
			// 
			// labelServerIp
			// 
			this->labelServerIp->AutoSize = true;
			this->labelServerIp->Location = System::Drawing::Point(23, 9);
			this->labelServerIp->Name = L"labelServerIp";
			this->labelServerIp->Size = System::Drawing::Size(52, 12);
			this->labelServerIp->TabIndex = 20;
			this->labelServerIp->Text = L"Server IP";
			// 
			// labelLocalPort
			// 
			this->labelLocalPort->AutoSize = true;
			this->labelLocalPort->Location = System::Drawing::Point(309, 38);
			this->labelLocalPort->Name = L"labelLocalPort";
			this->labelLocalPort->Size = System::Drawing::Size(57, 12);
			this->labelLocalPort->TabIndex = 23;
			this->labelLocalPort->Text = L"Local Port";
			// 
			// labelLocalIp
			// 
			this->labelLocalIp->AutoSize = true;
			this->labelLocalIp->Location = System::Drawing::Point(320, 9);
			this->labelLocalIp->Name = L"labelLocalIp";
			this->labelLocalIp->Size = System::Drawing::Size(46, 12);
			this->labelLocalIp->TabIndex = 22;
			this->labelLocalIp->Text = L"Local IP";
			// 
			// textLocalPort
			// 
			this->textLocalPort->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->textLocalPort->Location = System::Drawing::Point(372, 35);
			this->textLocalPort->Name = L"textLocalPort";
			this->textLocalPort->ReadOnly = true;
			this->textLocalPort->Size = System::Drawing::Size(100, 19);
			this->textLocalPort->TabIndex = 19;
			// 
			// textLocalIp
			// 
			this->textLocalIp->ImeMode = System::Windows::Forms::ImeMode::Off;
			this->textLocalIp->Location = System::Drawing::Point(372, 6);
			this->textLocalIp->Name = L"textLocalIp";
			this->textLocalIp->ReadOnly = true;
			this->textLocalIp->Size = System::Drawing::Size(100, 19);
			this->textLocalIp->TabIndex = 18;
			// 
			// buttonSend
			// 
			this->buttonSend->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->buttonSend->Enabled = false;
			this->buttonSend->Location = System::Drawing::Point(397, 430);
			this->buttonSend->Name = L"buttonSend";
			this->buttonSend->Size = System::Drawing::Size(75, 23);
			this->buttonSend->TabIndex = 25;
			this->buttonSend->Text = L"送信";
			this->buttonSend->UseVisualStyleBackColor = true;
			this->buttonSend->Click += gcnew System::EventHandler(this, &MainForm::buttonSend_Click);
			// 
			// textMessage
			// 
			this->textMessage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->textMessage->Location = System::Drawing::Point(12, 432);
			this->textMessage->Name = L"textMessage";
			this->textMessage->Size = System::Drawing::Size(379, 19);
			this->textMessage->TabIndex = 24;
			// 
			// listMessage
			// 
			this->listMessage->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->listMessage->FormattingEnabled = true;
			this->listMessage->HorizontalScrollbar = true;
			this->listMessage->ItemHeight = 12;
			this->listMessage->Location = System::Drawing::Point(12, 108);
			this->listMessage->Name = L"listMessage";
			this->listMessage->Size = System::Drawing::Size(460, 316);
			this->listMessage->TabIndex = 26;
			// 
			// buttonClear
			// 
			this->buttonClear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonClear->Location = System::Drawing::Point(397, 82);
			this->buttonClear->Name = L"buttonClear";
			this->buttonClear->Size = System::Drawing::Size(75, 23);
			this->buttonClear->TabIndex = 27;
			this->buttonClear->Text = L"クリア";
			this->buttonClear->UseVisualStyleBackColor = true;
			this->buttonClear->Click += gcnew System::EventHandler(this, &MainForm::buttonClear_Click);
			// 
			// labelMessage
			// 
			this->labelMessage->AutoSize = true;
			this->labelMessage->Location = System::Drawing::Point(12, 87);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(58, 12);
			this->labelMessage->TabIndex = 28;
			this->labelMessage->Text = L"MESSAGE";
			// 
			// radioUtf8
			// 
			this->radioUtf8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioUtf8->AutoSize = true;
			this->radioUtf8->Location = System::Drawing::Point(415, 60);
			this->radioUtf8->Name = L"radioUtf8";
			this->radioUtf8->Size = System::Drawing::Size(57, 16);
			this->radioUtf8->TabIndex = 30;
			this->radioUtf8->Text = L"UTF-8";
			this->radioUtf8->UseVisualStyleBackColor = true;
			this->radioUtf8->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CharCodeRadioCheckedChanged);
			// 
			// radioAscii
			// 
			this->radioAscii->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->radioAscii->AutoSize = true;
			this->radioAscii->Checked = true;
			this->radioAscii->Location = System::Drawing::Point(357, 60);
			this->radioAscii->Name = L"radioAscii";
			this->radioAscii->Size = System::Drawing::Size(52, 16);
			this->radioAscii->TabIndex = 29;
			this->radioAscii->TabStop = true;
			this->radioAscii->Text = L"ASCII";
			this->radioAscii->UseVisualStyleBackColor = true;
			this->radioAscii->CheckedChanged += gcnew System::EventHandler(this, &MainForm::CharCodeRadioCheckedChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Snow;
			this->ClientSize = System::Drawing::Size(484, 463);
			this->Controls->Add(this->radioUtf8);
			this->Controls->Add(this->radioAscii);
			this->Controls->Add(this->labelMessage);
			this->Controls->Add(this->buttonClear);
			this->Controls->Add(this->listMessage);
			this->Controls->Add(this->buttonSend);
			this->Controls->Add(this->textMessage);
			this->Controls->Add(this->buttonDisConnect);
			this->Controls->Add(this->textServerIp);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->textServerPort);
			this->Controls->Add(this->labelServerPort);
			this->Controls->Add(this->labelServerIp);
			this->Controls->Add(this->labelLocalPort);
			this->Controls->Add(this->labelLocalIp);
			this->Controls->Add(this->textLocalPort);
			this->Controls->Add(this->textLocalIp);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(500, 500);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MS-06S";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/// 初期化
	private: void Initialize()
			 {
				 String^ filename = System::IO::Path::ChangeExtension(System::Windows::Forms::Application::ExecutablePath, ".ini");
				 this->config = gcnew ConfigFile(filename);
				 this->config->LoadFormSizeAndLocation(this);
				 this->textServerIp->Text = this->config->GetTcpIPEndPoint()->Address->ToString();
				 this->textServerPort->Text = this->config->GetTcpIPEndPoint()->Port.ToString();

				 this->tcpClient = gcnew TcpClientSocket();
				 this->tcpClient->Received += gcnew TcpEventHandler(this, &MainForm::ReceivedClient);
				 this->tcpClient->DisConnected += gcnew TcpEventHandler(this, &MainForm::DisConnectedClient);

				 this->tcpClient->Encoding = this->config->GetTcpEncoding();
				 if (this->tcpClient->Encoding == System::Text::Encoding::ASCII)
				 {
					 this->radioAscii->Checked = true;
					 this->radioUtf8->Checked = false;
				 }
				 else if (this->tcpClient->Encoding == System::Text::Encoding::UTF8)
				 {
					 this->radioAscii->Checked = false;
					 this->radioUtf8->Checked = true;
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// クローズ後処理
	private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
			 {
				 if (this->tcpClient->Connected)
				 {
					 this->tcpClient->DisConnect();
				 }
				 this->config->SaveFormSizeAndLocation(this);
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// 接続
	private: System::Void buttonConnect_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (this->textServerIp->Text->Equals(String::Empty) || this->textServerPort->Text->Equals(String::Empty)) return;

				 try
				 {
					 IPEndPoint^ endPoint = gcnew IPEndPoint(IPAddress::Parse(this->textServerIp->Text), int::Parse(this->textServerPort->Text));
					 if (this->tcpClient->Connect(endPoint))
					 {
						 this->listMessage->Items->Add("【" + DateTime::Now.ToString() + "】 " + this->tcpClient->RemoteEndPoint->Address->ToString() + " : " + this->tcpClient->RemoteEndPoint->Port.ToString());
						 this->listMessage->Items->Add("*** CONNECT ***");
						 this->listMessage->SelectedIndex = this->listMessage->Items->Count - 1;
						 this->listMessage->Items->Add(String::Empty);
						 this->UpdateControl();
						 this->config->SetTcpIPEndPoint(endPoint);
					 }
					 else
					 {
						 System::Windows::Forms::MessageBox::Show("接続に失敗しました！", this->Text, MessageBoxButtons::OK, MessageBoxIcon::Error);
					 }
				 }
				 catch (Exception^)
				 {
					 System::Windows::Forms::MessageBox::Show("接続に失敗しました！", this->Text, MessageBoxButtons::OK, MessageBoxIcon::Error);
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// 切断
	private: System::Void buttonDisConnect_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (this->tcpClient->DisConnect())
				 {
					 this->listMessage->Items->Add("【" + DateTime::Now.ToString() + "】 " + this->textServerIp->Text + " : " + this->textServerPort->Text);
					 this->listMessage->Items->Add("*** DISCONNECT ***");
					 this->listMessage->SelectedIndex = this->listMessage->Items->Count - 1;
					 this->listMessage->Items->Add(String::Empty);
					 this->UpdateControl();
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// クリア
	private: System::Void buttonClear_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 this->listMessage->Items->Clear();
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// 送信
	private: System::Void buttonSend_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (this->textMessage->Text->Equals(String::Empty)) return;

				 this->tcpClient->SendMessage(this->textMessage->Text);
				 this->listMessage->Items->Add("【" + DateTime::Now.ToString() + "】 " + this->tcpClient->RemoteEndPoint->Address->ToString() + " : " + this->tcpClient->RemoteEndPoint->Port.ToString());
				 this->listMessage->Items->Add(">>  " + this->textMessage->Text);
				 this->listMessage->SelectedIndex = this->listMessage->Items->Count - 1;
				 this->listMessage->Items->Add(String::Empty);
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// 受信
	private: void ReceivedClient(System::Object ^sender, Anaheim::TcpSocket::TcpEventArgs ^e)
			 {
				 this->listMessage->Items->Add("【" + DateTime::Now.ToString() + "】 " + e->RemoteEndPoint->Address->ToString() + " : " + e->RemoteEndPoint->Port.ToString());
				 this->listMessage->Items->Add("<<  " + e->Message);
				 this->listMessage->SelectedIndex = this->listMessage->Items->Count - 1;
				 this->listMessage->Items->Add(String::Empty);
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// 切断
	private: void DisConnectedClient(System::Object ^sender, Anaheim::TcpSocket::TcpEventArgs ^e)
			 {
				 this->listMessage->Items->Add("【" + DateTime::Now.ToString() + "】 " + this->textServerIp->Text + " : " + this->textServerPort->Text);
				 this->listMessage->Items->Add("*** DISCONNECTED ***");
				 this->listMessage->SelectedIndex = this->listMessage->Items->Count - 1;
				 this->listMessage->Items->Add(String::Empty);
				 this->UpdateControl();
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// コントロール更新
	private: void UpdateControl()
			 {
				 try
				 {
					 if (this->tcpClient->Connected)
					 {
						 this->buttonConnect->Enabled = false;
						 this->buttonDisConnect->Enabled = true;
						 this->buttonSend->Enabled = true;
						 this->textLocalIp->Text = this->tcpClient->LocalEndPoint->Address->ToString();
						 this->textLocalPort->Text = this->tcpClient->LocalEndPoint->Port.ToString();
						 this->textServerIp->ReadOnly = true;
						 this->textServerPort->ReadOnly = true;
					 }
					 else
					 {
						 this->buttonConnect->Enabled = true;
						 this->buttonDisConnect->Enabled = false;
						 this->buttonSend->Enabled = false;
						 this->textLocalIp->Text = String::Empty;
						 this->textLocalPort->Text = String::Empty;
						 this->textServerIp->ReadOnly = false;
						 this->textServerPort->ReadOnly = false;
					 }
				 }
				 catch (Exception^)
				 {
					 return;
				 }
			 }
			 // ----------------------------------------------------------------------------------------------------

	/// 文字コード
	private: System::Void CharCodeRadioCheckedChanged(System::Object^  sender, System::EventArgs^  e)
			 {
				 if (this->radioAscii->Checked)
				 {
					 this->tcpClient->Encoding = System::Text::Encoding::ASCII;
				 }
				 else if (this->radioUtf8->Checked)
				 {
					 this->tcpClient->Encoding = System::Text::Encoding::UTF8;
				 }
				 this->config->SetTcpEncoding(this->tcpClient->Encoding);
			 }
			 // ----------------------------------------------------------------------------------------------------

	};
}

