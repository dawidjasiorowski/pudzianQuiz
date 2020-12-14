#pragma once

#include "wx/wx.h"
#include "wx/frame.h"
#include "Application.h"
#include "Quiz.h"

class appMain : public wxFrame
{
public:
	appMain();
	~appMain();
	void OnButtonClicked(wxCommandEvent& evt);
	void changeLabels(int current);
	Quiz quiz;
	int points = 0;
	int currentQuestion = 0;

private:
	wxButton* btn1;
	wxButton* btn2;
	wxButton* btn3;
	wxButton* btn4;
	wxStaticText* t;

};
