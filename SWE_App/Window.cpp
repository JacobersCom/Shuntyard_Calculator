#include "Window.h"

enum IDs {
	BUTTON_IDCLEAR,
	BUTTON_IDPOSNEG,
	BUTTON_IDPOINT,
	BUTTON_IDCE,
	BUTTON_IDDE

};

wxBEGIN_EVENT_TABLE(Window, wxFrame)
EVT_BUTTON(BUTTON_IDCLEAR, Window::buttonPressClear)
wxEND_EVENT_TABLE()

Window::Window() :wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(200,200), wxSize(340,530))
{
	pro = std::make_unique<Processes>();

	textCtrl = factory->CreateTextCtrl(this);
	textCtrl->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	textCtrl->SetEditable(false);
	textCtrl->AppendText("0");
	
	//First row
	Modulo = factory->CreateModButton(this);
	clearEntry = factory->CreateButton(this, BUTTON_IDCE, "CE", wxPoint(82, 130), wxSize(x, y));
	Clear = factory->CreateButton(this, BUTTON_IDCLEAR, "C", wxPoint(162, 130), wxSize(x, y));
	Delete = factory->CreateButton(this, BUTTON_IDDE, "Delete", wxPoint(242, 130), wxSize(x, y));

	//Second row
	cos = factory->CreateCosButton(this);
	sin = factory->CreateSinButton(this);
	tan = factory->CreateTanButton(this);
	Divide = factory->CreateDivButton(this);
	
	//Thrid row
	Seven = factory->CreateSevenButton(this);
	Eight = factory->CreateEightButton(this);
	Nine = factory->CreateNineButton(this);
	Multiple = factory->CreateMulButton(this);

	//Fourth row
	Four = factory->CreateFourButton(this);
	Five = factory->CreateFiveButton(this);
	Six = factory->CreateSixButton(this);
	Subtract = factory->CreateSubButton(this);

	//Fifth row
	One = factory->CreateOneButton(this);
	Two = factory->CreateTwoButton(this);
	Three = factory->CreateThreeButton(this);
	Add = factory->CreateAddButton(this);

	//Sixth row
	pos_neg = factory->CreateNegButton(this);
	Zero = factory->CreateZeroButton(this);
	Point = factory->CreateButton(this, BUTTON_IDPOINT, ".", wxPoint(162, 430), wxSize(x, y));
	Equal = factory->CreateEqualButton(this);

	

	Zero->Bind(wxEVT_BUTTON, &Window::buttonPress0, this, Zero->GetId());
	One->Bind(wxEVT_BUTTON, &Window::buttonPress1, this, One->GetId());
	Two->Bind(wxEVT_BUTTON, &Window::buttonPress2, this, Two->GetId());
	Three->Bind(wxEVT_BUTTON, &Window::buttonPress3, this, Three->GetId());
	Four->Bind(wxEVT_BUTTON, &Window::buttonPress4, this, Four->GetId());
	Five->Bind(wxEVT_BUTTON, &Window::buttonPress5, this, Five->GetId());
	Six->Bind(wxEVT_BUTTON, &Window::buttonPress6, this, Six->GetId());
	Seven->Bind(wxEVT_BUTTON, &Window::buttonPress7, this, Seven->GetId());
	Eight->Bind(wxEVT_BUTTON, &Window::buttonPress8, this, Eight->GetId());
	Nine->Bind(wxEVT_BUTTON, &Window::buttonPress9, this, Nine->GetId());
	
	Add->Bind(wxEVT_BUTTON, &Window::buttonPressADD, this, Add->GetId());
	Subtract->Bind(wxEVT_BUTTON, &Window::buttonPressSUB, this, Subtract->GetId());
	Multiple->Bind(wxEVT_BUTTON, &Window::buttonPressMUL, this, Multiple->GetId());
	Divide->Bind(wxEVT_BUTTON, &Window::buttonPressDIV, this, Divide->GetId());
	Modulo->Bind(wxEVT_BUTTON, &Window::buttonPressMOD, this, Modulo->GetId());
	cos->Bind(wxEVT_BUTTON, &Window::buttonPressCos, this, cos->GetId());
	sin->Bind(wxEVT_BUTTON, &Window::buttonPressSin, this, sin->GetId());
	tan->Bind(wxEVT_BUTTON, &Window::buttonPressTan, this, tan->GetId());
	Equal->Bind(wxEVT_BUTTON, &Window::buttonPressEqual, this, Equal->GetId());
	pos_neg->Bind(wxEVT_BUTTON, &Window::buttonPressNegPos, this, pos_neg->GetId());
	Delete->Bind(wxEVT_BUTTON, &Window::buttonPressDelete, this, Delete->GetId());
}



void Window::buttonPress1(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0") {
		textCtrl->SetValue(One->GetLabel());
	}
	else
	{
		textCtrl->AppendText(One->GetLabel());
	}

}
void Window::buttonPress2(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Two->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Two->GetLabel());

	}
}
void Window::buttonPress3(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Three->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Three->GetLabel());
	}
}
void Window::buttonPress4(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Four->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Four->GetLabel());
	}
}
void Window::buttonPress5(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Five->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Five->GetLabel());
	}
}
void Window::buttonPress6(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Six->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Six->GetLabel());
	}
}
void Window::buttonPress7(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Seven->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Seven->GetLabel());
	}
}
void Window::buttonPress8(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Eight->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Eight->GetLabel());
	}
}
void Window::buttonPress9(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Nine->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Nine->GetLabel());
	}
}
void Window::buttonPress0(wxCommandEvent& evt)
{
	if (textCtrl->GetValue() == "0")
	{
		textCtrl->SetValue(Zero->GetLabel());
	}
	else
	{
		textCtrl->AppendText(Zero->GetLabel());
	}
}


void Window::buttonPressADD(wxCommandEvent& evt)
{
	textCtrl->AppendText(" + ");
}
void Window::buttonPressSUB(wxCommandEvent& evt)
{	
	textCtrl->AppendText(" - ");
}
void Window::buttonPressMUL(wxCommandEvent& evt)
{	
	textCtrl->AppendText(" x ");
}
void Window::buttonPressDIV(wxCommandEvent& evt)
{	
	textCtrl->AppendText(" / ");	
}
void Window::buttonPressMOD(wxCommandEvent& evt)
{
	textCtrl->AppendText(" % ");
}
void Window::buttonPressCos(wxCommandEvent& evt)
{
	textCtrl->AppendText(" Cos ");
}
void Window::buttonPressSin(wxCommandEvent& evt)
{
	textCtrl->AppendText(" Sin ");
}
void Window::buttonPressTan(wxCommandEvent& evt)
{
	textCtrl->AppendText(" Tan ");
}

void Window::buttonPressEqual(wxCommandEvent& evt)
{
	std::string input = std::string(textCtrl->GetValue());
	std::string output = pro->Calculate(input);
	textCtrl->SetValue(output);
}

void Window::buttonPressClear(wxCommandEvent& evt)
{
	textCtrl->Clear();
}

void Window::buttonPressDelete(wxCommandEvent& evt)
{
	std::string input = std::string(textCtrl->GetValue());
	if (input.size() > 0)
	{
		input.pop_back();
		textCtrl->SetValue(input);
	}
}

void Window::buttonPressNegPos(wxCommandEvent& evt)
{
	//The current method resets the value and just prints a - to the left num
	// I want it to print () around the number to pharse them out in the shunting yard algo 
	//Than I will be able to use the - sign without an issue hopefully

	//Testing
	int result = 0;
	std::string input = std::string(textCtrl->GetValue());
	result = std::stod(input) *  -1;
	textCtrl->SetValue(std::to_string(result));
}