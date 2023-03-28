#pragma once

namespace ZbiorMandelbrota {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	protected:
	private: System::Windows::Forms::VScrollBar^ vScrollBarRed;
	private: System::Windows::Forms::VScrollBar^ vScrollBarGreen;
	private: System::Windows::Forms::VScrollBar^ vScrollBarBlue;

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->vScrollBarRed = (gcnew System::Windows::Forms::VScrollBar());
			this->vScrollBarGreen = (gcnew System::Windows::Forms::VScrollBar());
			this->vScrollBarBlue = (gcnew System::Windows::Forms::VScrollBar());
			this->SuspendLayout();
			// 
			// progressBar1
			// 
			this->progressBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->progressBar1->Location = System::Drawing::Point(278, 10);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(228, 9);
			this->progressBar1->Step = 1;
			this->progressBar1->TabIndex = 0;
			// 
			// vScrollBarRed
			// 
			this->vScrollBarRed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->vScrollBarRed->LargeChange = 1;
			this->vScrollBarRed->Location = System::Drawing::Point(538, 162);
			this->vScrollBarRed->Maximum = 16;
			this->vScrollBarRed->Name = L"vScrollBarRed";
			this->vScrollBarRed->Size = System::Drawing::Size(16, 196);
			this->vScrollBarRed->TabIndex = 1;
			this->vScrollBarRed->Value = 7;
			this->vScrollBarRed->MouseCaptureChanged += gcnew System::EventHandler(this, &MyForm::vScrollBarRed_MouseCaptureChanged);
			// 
			// vScrollBarGreen
			// 
			this->vScrollBarGreen->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->vScrollBarGreen->LargeChange = 1;
			this->vScrollBarGreen->Location = System::Drawing::Point(560, 162);
			this->vScrollBarGreen->Maximum = 16;
			this->vScrollBarGreen->Name = L"vScrollBarGreen";
			this->vScrollBarGreen->Size = System::Drawing::Size(16, 196);
			this->vScrollBarGreen->TabIndex = 2;
			this->vScrollBarGreen->Value = 7;
			this->vScrollBarGreen->MouseCaptureChanged += gcnew System::EventHandler(this, &MyForm::vScrollBarGreen_MouseCaptureChanged);
			// 
			// vScrollBarBlue
			// 
			this->vScrollBarBlue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->vScrollBarBlue->LargeChange = 1;
			this->vScrollBarBlue->Location = System::Drawing::Point(581, 162);
			this->vScrollBarBlue->Maximum = 16;
			this->vScrollBarBlue->Name = L"vScrollBarBlue";
			this->vScrollBarBlue->Size = System::Drawing::Size(16, 196);
			this->vScrollBarBlue->TabIndex = 3;
			this->vScrollBarBlue->Value = 7;
			this->vScrollBarBlue->MouseCaptureChanged += gcnew System::EventHandler(this, &MyForm::vScrollBarBlue_MouseCaptureChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 366);
			this->Controls->Add(this->vScrollBarBlue);
			this->Controls->Add(this->vScrollBarGreen);
			this->Controls->Add(this->vScrollBarRed);
			this->Controls->Add(this->progressBar1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Zbiór Mandelbrota";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseWheel);
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void vScrollBarRed_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!vScrollBarRed->Capture) Rysuj();
}
private: System::Void vScrollBarGreen_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!vScrollBarGreen->Capture) Rysuj();
}
private: System::Void vScrollBarBlue_MouseCaptureChanged(System::Object^ sender, System::EventArgs^ e) {
	if (!vScrollBarBlue->Capture) Rysuj();
}
private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Rysuj();
}
private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Button == System::Windows::Forms::MouseButtons::Left) Powiekszenie(e->X, e->Y);
	else if (e->Button == System::Windows::Forms::MouseButtons::Right) Pomniejszenie(e->X, e->Y);
	else if (e->Button == System::Windows::Forms::MouseButtons::Middle) Resetowanie();
	Rysuj();
}
private: System::Void MyForm_MouseWheel(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (e->Delta > 0) Powiekszenie(e->X, e->Y);
	else if (e->Delta < 0) Pomniejszenie(e->X, e->Y);
	Rysuj();
}

double pX = -2, pY = -2, sz = 4, wy = 4; // parametry prostok¹ta zbioru Mandelbrota
int szerokosc, wysokosc; // rozmiary okna w pikselach

void Resetowanie()
{
	pX = pY = -2;
	sz = wy = 4;
}

void Pomniejszenie(int x, int y)
{
	pX += sz * (static_cast<double>(x) / szerokosc - 1);
	pY += wy * (static_cast<double>(y) / wysokosc - 1);
	sz *= 2; wy *= 2;
}

void Powiekszenie(int x, int y)
{
	pX += sz * (static_cast<double>(x) / szerokosc - .25);
	pY += wy * (static_cast<double>(y) / wysokosc - .25);
	sz /= 2; wy /= 2;
}

void Rysuj()
{
	Graphics^ g = this->CreateGraphics();

	szerokosc = static_cast<int>(g->VisibleClipBounds.Width);
	wysokosc = static_cast<int>(g->VisibleClipBounds.Height);
	if (wysokosc < 1) return;
	Bitmap^ b = gcnew Bitmap(szerokosc, wysokosc);

	double xx = sz / szerokosc, yy = wy / wysokosc; // jednostki na piksel
	progressBar1->Value = 0;
	for (int i = 0; i < szerokosc; ++i)
	{
		for (int j = 0; j < wysokosc; ++j)
		{
			int k = Kolor(pX + i * xx, pY + j * yy);
			int niebieski = k % 256;
			int zielony = k / 256;
			int czerwony = (zielony / 256) % 256;
			zielony %= 256;
			b->SetPixel(i, j, Color::FromArgb(czerwony, zielony, niebieski));
		}
		progressBar1->Value = 100 * i / (szerokosc - 1);
	}
	g->DrawImage(b, 0, 0);
}

int Kolor(double x0, double y0)
{
	double x = x0, y = y0, x2, y2;
	int n = 0; // iloœæ iteracji ci¹gu
	do
	{
		x2 = x * x; y2 = y * y;
		y = 2 * x * y + y0;
		x = x2 - y2 + x0;
	} while (x2 + y2 < 4 && ++n < 256);
	return (0x1000 * vScrollBarRed->Value + 0x10 * vScrollBarGreen->Value + vScrollBarBlue->Value) * n;
}
};
}
