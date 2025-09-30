#pragma once

namespace LengthConverter {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    private:
        NumericUpDown^ numericUpDown1;
        ComboBox^ comboBoxFrom;
        ComboBox^ comboBoxTo;
        Button^ buttonConvert;
        Label^ labelResult;

    public:
        Form1()
        {
            this->Text = "��������� ������";
            this->Width = 400;
            this->Height = 250;

            numericUpDown1 = gcnew NumericUpDown();
            numericUpDown1->Location = System::Drawing::Point(20, 20);
            numericUpDown1->Maximum = 100000;
            this->Controls->Add(numericUpDown1);

            comboBoxFrom = gcnew ComboBox();
            comboBoxFrom->Location = System::Drawing::Point(20, 60);
            comboBoxFrom->Items->AddRange(gcnew cli::array<Object^>{"�����", "ʳ�������", "���"});
            comboBoxFrom->SelectedIndex = 0;
            this->Controls->Add(comboBoxFrom);

            comboBoxTo = gcnew ComboBox();
            comboBoxTo->Location = System::Drawing::Point(200, 60);
            comboBoxTo->Items->AddRange(gcnew cli::array<Object^>{"�����", "ʳ�������", "���"});
            comboBoxTo->SelectedIndex = 1;
            this->Controls->Add(comboBoxTo);

            buttonConvert = gcnew Button();
            buttonConvert->Text = "������������";
            buttonConvert->Location = System::Drawing::Point(20, 100);
            buttonConvert->Click += gcnew EventHandler(this, &Form1::buttonConvert_Click);
            this->Controls->Add(buttonConvert);

            labelResult = gcnew Label();
            labelResult->Text = "���������:";
            labelResult->AutoSize = true;
            labelResult->Location = System::Drawing::Point(20, 150);
            this->Controls->Add(labelResult);
        }

    private:
        void buttonConvert_Click(Object^ sender, EventArgs^ e)
        {
            double value = Decimal::ToDouble(numericUpDown1->Value);
            String^ from = comboBoxFrom->Text;
            String^ to = comboBoxTo->Text;

            double meters = 0;

            if (from == "�����") meters = value;
            else if (from == "ʳ�������") meters = value * 1000;
            else if (from == "���") meters = value * 1609.34;

            double result = 0;
            if (to == "�����") result = meters;
            else if (to == "ʳ�������") result = meters / 1000;
            else if (to == "���") result = meters / 1609.34;

            labelResult->Text = String::Format("{0} {1} = {2:F2} {3}", value, from, result, to);
        }
    private: System::Void InitializeComponent() {
        this->SuspendLayout();
        // 
        // Form1
        // 
        this->ClientSize = System::Drawing::Size(957, 533);
        this->Name = L"Form1";
        this->ResumeLayout(false);
    }
    };
}

namespace TempConverter {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class Form1 : public Form
    {
    private:
        NumericUpDown^ numericUpDown1;
        ComboBox^ comboBoxFrom;
        ComboBox^ comboBoxTo;
        Button^ buttonConvert;
        Label^ labelResult;

    public:
        Form1()
        {
            this->Text = "��������� ����������";
            this->Width = 400;
            this->Height = 250;

            numericUpDown1 = gcnew NumericUpDown();
            numericUpDown1->Location = System::Drawing::Point(20, 20);
            numericUpDown1->Maximum = 1000;
            numericUpDown1->Minimum = -273;
            this->Controls->Add(numericUpDown1);

            comboBoxFrom = gcnew ComboBox();
            comboBoxFrom->Location = System::Drawing::Point(20, 60);
            comboBoxFrom->Items->AddRange(gcnew cli::array<Object^>{"������", "���������", "������"});
            comboBoxFrom->SelectedIndex = 0;
            this->Controls->Add(comboBoxFrom);

            comboBoxTo = gcnew ComboBox();
            comboBoxTo->Location = System::Drawing::Point(200, 60);
            comboBoxTo->Items->AddRange(gcnew cli::array<Object^>{"������", "���������", "������"});
            comboBoxTo->SelectedIndex = 1;
            this->Controls->Add(comboBoxTo);

            buttonConvert = gcnew Button();
            buttonConvert->Text = "������������";
            buttonConvert->Location = System::Drawing::Point(20, 100);
            buttonConvert->Click += gcnew EventHandler(this, &Form1::buttonConvert_Click);
            this->Controls->Add(buttonConvert);

            labelResult = gcnew Label();
            labelResult->Text = "���������:";
            labelResult->AutoSize = true;
            labelResult->Location = System::Drawing::Point(20, 150);
            this->Controls->Add(labelResult);
        }

    private:
        void buttonConvert_Click(Object^ sender, EventArgs^ e)
        {
            double value = Decimal::ToDouble(numericUpDown1->Value);
            String^ from = comboBoxFrom->Text;
            String^ to = comboBoxTo->Text;

            double celsius = 0;

            if (from == "������") celsius = value;
            else if (from == "���������") celsius = (value - 32) * 5.0 / 9.0;
            else if (from == "������") celsius = value - 273.15;

            double result = 0;
            if (to == "������") result = celsius;
            else if (to == "���������") result = (celsius * 9.0 / 5.0) + 32;
            else if (to == "������") result = celsius + 273.15;

            labelResult->Text = String::Format("{0} {1} = {2:F2} {3}", value, from, result, to);
        }
    };
}
