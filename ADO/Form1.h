#pragma once


namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Button^ buttonActualizar;














	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		SqlDataAdapter^ dataAdapter;
		DataTable^ table;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->buttonActualizar = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(970, 612);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView1_CellContentClick);
			// 
			// buttonActualizar
			// 
			this->buttonActualizar->Location = System::Drawing::Point(997, 589);
			this->buttonActualizar->Name = L"buttonActualizar";
			this->buttonActualizar->Size = System::Drawing::Size(75, 23);
			this->buttonActualizar->TabIndex = 1;
			this->buttonActualizar->Text = L"Actualizar";
			this->buttonActualizar->UseVisualStyleBackColor = true;
			this->buttonActualizar->Click += gcnew System::EventHandler(this, &Form1::buttonActualizar_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1159, 670);
			this->Controls->Add(this->buttonActualizar);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		PopulateDataGridView();

	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}


	public: void PopulateDataGridView()
	{
		// Set your connection string
		String^ connectionString = "Server=tcp:sepesepe.database.windows.net,1433;Initial Catalog=Banco;Persist Security Info=False;User ID=as;Password=P0t@toP0t@to;MultipleActiveResultSets=False;Encrypt=True;TrustServerCertificate=False;Connection Timeout=30;"; // Replace with your actual connection string

		// Create a connection and data adapter
		SqlConnection^ connection = gcnew SqlConnection(connectionString);
		dataAdapter = gcnew SqlDataAdapter();
		dataAdapter->SelectCommand = gcnew SqlCommand("SELECT * FROM Clientes", connection);
		SqlCommandBuilder^ builder = gcnew SqlCommandBuilder(dataAdapter);
		dataAdapter->InsertCommand = builder->GetInsertCommand();
		dataAdapter->UpdateCommand = builder->GetUpdateCommand();
		dataAdapter->DeleteCommand = builder->GetDeleteCommand();


		// Create a DataTable to hold the data
		table = gcnew DataTable();
		dataAdapter->Fill(table);
		DataRow^ fila = table->NewRow();
		fila["CodCliente"] = 19;
		fila["Nombre"] = "Manolo";
		table->Rows->Add(fila);
		// Bind the DataTable to the DataGridView
		//this->dataGridView1->ReadOnly = true;
		this->dataGridView1->DataSource = table;
	}
	private: System::Void bindingNavigator1_RefreshItems(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void buttonActualizar_Click(System::Object^ sender, System::EventArgs^ e) {
	dataAdapter->Update(table);
}
};
}