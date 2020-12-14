#include "appMain.h"

appMain::appMain() : wxFrame(nullptr, wxID_ANY, "Quiz", wxPoint(20, 20), wxSize(600, 600))
{
	t = new wxStaticText(this, wxID_ANY, "Pytanie",wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL);

	wxFont myFont(24, wxFONTFAMILY_ROMAN, wxFONTSTYLE_MAX, wxFONTWEIGHT_BOLD);
	t->SetFont(myFont);

	wxWindow* buttonParent = new wxWindow(this, wxID_ANY);
	btn1 = new wxButton(buttonParent, 101, "1");
	btn2 = new wxButton(buttonParent, 102, "2");
	btn3 = new wxButton(buttonParent, 103, "3");
	btn4 = new wxButton(buttonParent, 104, "4");

	wxBoxSizer* btnGrid = new wxBoxSizer(wxHORIZONTAL);
	wxBoxSizer* mainGrid = new wxBoxSizer(wxVERTICAL);

	btn1->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &appMain::OnButtonClicked, this);
	btn2->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &appMain::OnButtonClicked, this);
	btn3->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &appMain::OnButtonClicked, this);
	btn4->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &appMain::OnButtonClicked, this);

	btnGrid->Add(btn1, 1, wxEXPAND | wxALL);
	btnGrid->Add(btn2, 1, wxEXPAND | wxALL);
	btnGrid->Add(btn3, 1, wxEXPAND | wxALL);
	btnGrid->Add(btn4, 1, wxEXPAND | wxALL);

	mainGrid->Add(t, 1, wxEXPAND | wxALL);
	mainGrid->Add(buttonParent, 1, wxEXPAND | wxALL);

	this->SetSizer(mainGrid);
	buttonParent->SetSizer(btnGrid);

	quiz.readQuestions();

	changeLabels(0);
	
}

appMain::~appMain()
{
}

void appMain::OnButtonClicked(wxCommandEvent& evt)
{
	int id = evt.GetId() - 100;
	if (id == quiz.questionList[currentQuestion].rightID) {
		points++;
	}
	currentQuestion++;
	if (currentQuestion < quiz.questionList.size()) {
		changeLabels(currentQuestion);
	}
	else {
		t->SetLabelText("Twoja ilosc punktow to " + std::to_string(points));
		btn1->SetLabel("Gratulacje");
		btn2->SetLabel("Gratulacje");
		btn3->SetLabel("Gratulacje");
		btn4->SetLabel("Gratulacje");
		btn1->Enable(false);
		btn2->Enable(false);
		btn3->Enable(false);
		btn4->Enable(false);
	}
	evt.Skip();
}
void appMain::changeLabels(int current)
{
	Question q = quiz.questionList[current];
	t->SetLabelText(q.text);
	btn1->SetLabel(q.answers[0]);
	btn2->SetLabel(q.answers[1]);
	btn3->SetLabel(q.answers[2]);
	btn4->SetLabel(q.answers[3]);
}