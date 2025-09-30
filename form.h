#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

public ref class Note
{
public:
    String^ Title;
    String^ Text;
    String^ Categories;
    int Priority;

    virtual String^ ToString() override
    {
        return String::Format("{0} — {1} — {2} — {3}", Title, Priority, Categories, Text);
    }
};

public ref class Form1 : public Form
{
private:
    TextBox^ txtTitle;
    TextBox^ txtText;
    CheckedListBox^ clbCategories;
    NumericUpDown^ numPriority;
    Button^ btnAdd;
    Button^ btnDelete;
    Button^ btnClear;
    Button^ btnEdit;
    ListBox^ lstNotes;

    List<Note^>^ notes;

public:
    Form1()
    {
        this->Text = "Менеджер нотаток (C++/CLI)";
        this->Width = 720;
        this->Height = 500;

        notes = gcnew List<Note^>();

        Label^ lbl1 = gcnew Label();
        lbl1->Text = "Назва:";
        lbl1->Location = System::Drawing::Point(20, 20);
        this->Controls->Add(lbl1);

        txtTitle = gcnew TextBox();
        txtTitle->Location = System::Drawing::Point(100, 20);
        txtTitle->Width = 200;
        this->Controls->Add(txtTitle);

        Label^ lbl2 = gcnew Label();
        lbl2->Text = "Текст:";
        lbl2->Location = System::Drawing::Point(20, 60);
        this->Controls->Add(lbl2);

        txtText = gcnew TextBox();
        txtText->Location = System::Drawing::Point(100, 60);
        txtText->Multiline = true;
        txtText->Height = 80;
        txtText->Width = 200;
        this->Controls->Add(txtText);

        Label^ lbl3 = gcnew Label();
        lbl3->Text = "Категорії:";
        lbl3->Location = System::Drawing::Point(20, 160);
        this->Controls->Add(lbl3);

        clbCategories = gcnew CheckedListBox();
        clbCategories->Location = System::Drawing::Point(100, 160);
        clbCategories->Items->AddRange(gcnew cli::array<Object^>{"Робота", "Навчання", "Особисте", "Ідеї"});
        this->Controls->Add(clbCategories);

        Label^ lbl4 = gcnew Label();
        lbl4->Text = "Пріоритет:";
        lbl4->Location = System::Drawing::Point(20, 260);
        this->Controls->Add(lbl4);

        numPriority = gcnew NumericUpDown();
        numPriority->Location = System::Drawing::Point(100, 260);
        numPriority->Minimum = 1;
        numPriority->Maximum = 5;
        this->Controls->Add(numPriority);

        btnAdd = gcnew Button();
        btnAdd->Text = "Додати";
        btnAdd->Location = System::Drawing::Point(20, 300);
        btnAdd->Click += gcnew EventHandler(this, &Form1::btnAdd_Click);
        this->Controls->Add(btnAdd);

        btnDelete = gcnew Button();
        btnDelete->Text = "Видалити";
        btnDelete->Location = System::Drawing::Point(120, 300);
        btnDelete->Click += gcnew EventHandler(this, &Form1::btnDelete_Click);
        this->Controls->Add(btnDelete);

        btnClear = gcnew Button();
        btnClear->Text = "Очистити";
        btnClear->Location = System::Drawing::Point(220, 300);
        btnClear->Click += gcnew EventHandler(this, &Form1::btnClear_Click);
        this->Controls->Add(btnClear);

        btnEdit = gcnew Button();
        btnEdit->Text = "Редагувати";
        btnEdit->Location = System::Drawing::Point(320, 300);
        btnEdit->Click += gcnew EventHandler(this, &Form1::btnEdit_Click);
        this->Controls->Add(btnEdit);


        lstNotes = gcnew ListBox();
        lstNotes->Location = System::Drawing::Point(350, 20);
        lstNotes->Width = 340;
        lstNotes->Height = 350;
        this->Controls->Add(lstNotes);
    }

private:
    void btnAdd_Click(Object^ sender, EventArgs^ e)
    {
        if (String::IsNullOrWhiteSpace(txtTitle->Text))
        {
            MessageBox::Show("Назва обов’язкова!");
            return;
        }

        for each (Note ^ n in notes)
        {
            if (n->Title == txtTitle->Text)
            {
                MessageBox::Show("Нотатка з такою назвою вже існує!");
                return;
            }
        }

        Note^ note = gcnew Note();
        note->Title = txtTitle->Text;
        note->Text = txtText->Text;
        note->Priority = (int)numPriority->Value;

        System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
        for each (Object ^ item in clbCategories->CheckedItems)
        {
            if (sb->Length > 0) sb->Append(", ");
            sb->Append(item->ToString());
        }
        note->Categories = sb->ToString();

        notes->Add(note);
        lstNotes->Items->Add(note);
    }

    void btnDelete_Click(Object^ sender, EventArgs^ e)
    {
        if (lstNotes->SelectedIndex >= 0)
        {
            notes->RemoveAt(lstNotes->SelectedIndex);
            lstNotes->Items->RemoveAt(lstNotes->SelectedIndex);
        }
    }

    void btnClear_Click(Object^ sender, EventArgs^ e)
    {
        txtTitle->Clear();
        txtText->Clear();
        for (int i = 0; i < clbCategories->Items->Count; i++)
            clbCategories->SetItemChecked(i, false);
        numPriority->Value = 1;
    }

    void btnEdit_Click(Object^ sender, EventArgs^ e)
    {
        if (lstNotes->SelectedIndex >= 0)
        {
            Note^ note = notes[lstNotes->SelectedIndex];
            txtTitle->Text = note->Title;
            txtText->Text = note->Text;
            numPriority->Value = note->Priority;

            for (int i = 0; i < clbCategories->Items->Count; i++)
            {
                clbCategories->SetItemChecked(i, false);
                if (note->Categories->Contains(clbCategories->Items[i]->ToString()))
                    clbCategories->SetItemChecked(i, true);
            }

            notes->RemoveAt(lstNotes->SelectedIndex);
            lstNotes->Items->RemoveAt(lstNotes->SelectedIndex);
        }
    }
};
