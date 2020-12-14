#pragma once
#include <fstream>
#include <string>
#include "vector"

class Question
{
public:
	std::string text;
	std::vector<std::string> answers;
	int rightID;
	Question(std::string t, std::vector<std::string> a, int g);
};

class Quiz
{
public:
	std::vector<Question> questionList;
	void readQuestions();
};


