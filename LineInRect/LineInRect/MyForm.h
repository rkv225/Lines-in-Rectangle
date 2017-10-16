#pragma once

namespace LineInRect {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	struct point
	{
		float x;
		float y;
	};

	struct line
	{
		point point1;
		point point2;
		float a;
		float b;
		float c;
		bool sel;
	};

	struct rectangle
	{
		point pointD1;
		point pointD2;
	};

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	//user defined properties for program logic
	public:
		point *pointP;
		point *pointQ;
		bool IsNewLine;
		bool IsDrawingLine;
		bool CanDrawRectangle;

		int n;
		array<line*>^ lines;
	private: System::Windows::Forms::Button^  button1;
	public:
		rectangle *rect;
		int intersectionCount;
	private: System::Windows::Forms::Label^  label3;
	public:
	private: System::Windows::Forms::Label^  label4;
			 int intLineCount;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			label2->Text = "";
			label4->Text = "";
			pointP = new point();
			pointQ = new point();
			IsNewLine = true;
			CanDrawRectangle = true;
			pictureBox1->Image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			lines = gcnew array<line*>(100);
			n = 0;
			rect = new rectangle();
			intersectionCount = 0;
			intLineCount = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)	
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  LineButton;
	protected:
	private: System::Windows::Forms::Button^  RectangleButton;
	private: System::Windows::Forms::Button^  IntersectButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			this->LineButton = (gcnew System::Windows::Forms::Button());
			this->RectangleButton = (gcnew System::Windows::Forms::Button());
			this->IntersectButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// LineButton
			// 
			this->LineButton->Location = System::Drawing::Point(811, 38);
			this->LineButton->Name = L"LineButton";
			this->LineButton->Size = System::Drawing::Size(75, 23);
			this->LineButton->TabIndex = 0;
			this->LineButton->Text = L"Line";
			this->LineButton->UseVisualStyleBackColor = true;
			this->LineButton->Click += gcnew System::EventHandler(this, &MyForm::LineButton_Click);
			// 
			// RectangleButton
			// 
			this->RectangleButton->Location = System::Drawing::Point(811, 94);
			this->RectangleButton->Name = L"RectangleButton";
			this->RectangleButton->Size = System::Drawing::Size(75, 23);
			this->RectangleButton->TabIndex = 1;
			this->RectangleButton->Text = L"Rectangle";
			this->RectangleButton->UseVisualStyleBackColor = true;
			this->RectangleButton->Click += gcnew System::EventHandler(this, &MyForm::RectangleButton_Click);
			// 
			// IntersectButton
			// 
			this->IntersectButton->Location = System::Drawing::Point(811, 149);
			this->IntersectButton->Name = L"IntersectButton";
			this->IntersectButton->Size = System::Drawing::Size(75, 45);
			this->IntersectButton->TabIndex = 2;
			this->IntersectButton->Text = L"Find Intersections";
			this->IntersectButton->UseVisualStyleBackColor = true;
			this->IntersectButton->Click += gcnew System::EventHandler(this, &MyForm::IntersectButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(807, 217);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"No. of Intersections:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(807, 243);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"label2";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(793, 454);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(817, 406);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(807, 278);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"No. of Lines:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(812, 304);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"label4";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(942, 478);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->IntersectButton);
			this->Controls->Add(this->RectangleButton);
			this->Controls->Add(this->LineButton);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		Point mouseLocation = Point(e->X, e->Y);
		if (IsDrawingLine)
		{
			if (IsNewLine)
			{
				pointP->x = mouseLocation.X;
				pointP->y = mouseLocation.Y;
				IsNewLine = !IsNewLine;
			}
			else
			{
				pointQ->x = mouseLocation.X;
				pointQ->y = mouseLocation.Y;
				if (!IsNewLine)
				{
					CreatingLines(pointP->x, pointP->y, pointQ->x, pointQ->y);
					Graphics^ g = Graphics::FromImage(pictureBox1->Image);
					g->DrawLine(System::Drawing::Pens::Black, float(pointP->x), float(pointP->y), float(pointQ->x), float(pointQ->y));
					pictureBox1->Refresh();
					IsNewLine = true;
				}
			}
		}
		else
		{
			if (IsNewLine)
			{
				pointP->x = mouseLocation.X;
				pointP->y = mouseLocation.Y;
				IsNewLine = !IsNewLine;
			}
			else
			{
				pointQ->x = mouseLocation.X;
				pointQ->y = mouseLocation.Y;
				if (!IsNewLine && CanDrawRectangle)
				{
					rect->pointD1.x = pointP->x;
					rect->pointD1.y = pointP->y;
					rect->pointD2.x = pointQ->x;
					rect->pointD2.y = pointQ->y;
					Graphics^ g = Graphics::FromImage(pictureBox1->Image);
					g->DrawRectangle(System::Drawing::Pens::Black, pointP->x, pointP->y, (pointQ->x - pointP->x), (pointQ->y - pointP->y));
					pictureBox1->Refresh();
					IsNewLine = true;
					CanDrawRectangle = false;
				}
			}
		}
	}

//user defined functions
public:
	void CreatingLines(float x1, float y1, float x2, float y2)
	{
		line *tmp = new line();

		tmp->point1.x = pointP->x;
		tmp->point1.y = pointP->y;
		tmp->point2.x = pointQ->x;
		tmp->point2.y = pointQ->y;
		tmp->a = pointQ->y - pointP->y;
		tmp->b = pointP->x - pointQ->x;
		tmp->c = (tmp->a*pointP->x) + (tmp->b*pointP->y);
		tmp->sel = false;
		lines[n++] = tmp;
	}
			
private: System::Void LineButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	IsDrawingLine = true;
}
private: System::Void RectangleButton_Click(System::Object^  sender, System::EventArgs^  e) {
	IsDrawingLine = false;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	label2->Text = "";
	label4->Text = "";
	pointP = new point();
	pointQ = new point();
	IsNewLine = true;
	CanDrawRectangle = true;
	pictureBox1->Image = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
	lines = gcnew array<line*>(100);
	n = 0;
	rect = new rectangle();
	intersectionCount = 0;
	intLineCount = 0;
}
private: System::Void IntersectButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			float det = (lines[i]->a*lines[j]->b) - (lines[j]->a*lines[i]->b);
			if (det == 0)//lines are parallel
			{

			}
			else//lines intersect
			{
				//finding the coordinates of the intersection
				float x = ((lines[j]->b*lines[i]->c) - (lines[i]->b*lines[j]->c)) / det;
				float y = ((lines[i]->a*lines[j]->c) - (lines[j]->a*lines[i]->c)) / det;

				//checking if the intersection point lies lies on both the lines
				if (x > min(lines[i]->point1.x, lines[i]->point2.x) &&
					x < max(lines[i]->point1.x, lines[i]->point2.x) &&
					y > min(lines[i]->point1.y, lines[i]->point2.y) &&
					y < max(lines[i]->point1.y, lines[i]->point2.y) &&

					x > min(lines[j]->point1.x, lines[j]->point2.x) &&
					x < max(lines[j]->point1.x, lines[j]->point2.x) &&
					y > min(lines[j]->point1.y, lines[j]->point2.y) &&
					y < max(lines[j]->point1.y, lines[j]->point2.y))
				{
					//if the intersection point lies between the rectangle increment the count and change the color of the lines
					if (x > min(rect->pointD1.x, rect->pointD2.x) && 
						x < max(rect->pointD1.x, rect->pointD2.x) && 
						y > min(rect->pointD1.y, rect->pointD2.y) &&
						y < max(rect->pointD1.y, rect->pointD2.y))
					{
						intersectionCount++;
						//intLineCount = 0;
						drawPoint(x, y);
						if (!lines[i]->sel)
						{
							redrawLine(i);
							lines[i]->sel = true;
							intLineCount++;
						}
						if (!lines[j]->sel)
						{
							redrawLine(j);
							lines[j]->sel = true;
							intLineCount++;
						}
					}
				}
			}
		}
	}
	label2->Text = intersectionCount.ToString();
	label4->Text = intLineCount.ToString();
}

		 void redrawLine(int s)
		 {
			 Graphics^ g = Graphics::FromImage(pictureBox1->Image);
			 g->DrawLine(System::Drawing::Pens::Red, float(lines[s]->point1.x), float(lines[s]->point1.y), float(lines[s]->point2.x), float(lines[s]->point2.y));
			 pictureBox1->Refresh();
		 }

		 void drawPoint(float x, float y)
		 {
			 Graphics^ g = Graphics::FromImage(pictureBox1->Image);
			 g->FillEllipse(System::Drawing::Brushes::Blue, x-3, y-3, 8.0F, 8.0F);
			 pictureBox1->Refresh();
		 }

		 float min(float x, float y)
		 {
			 if (x < y)
				 return x;
			 else
				 return y;
		 }

		 float max(float x, float y)
		 {
			 if (x > y)
				 return x;
			 else
				 return y;
		 }
};
}