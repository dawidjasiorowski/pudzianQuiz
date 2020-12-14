#include "Quiz.h"

std::vector<Question> questionList = {};

void Quiz::readQuestions()
{
	std::string line;
	std::ifstream questions("./questions.txt");
	std::vector<std::string> lines;
	while (getline(questions, line)) {
		lines.push_back(line);
	}
	for (int i = 0; i < lines.size(); i += 6) {
		questionList.push_back(Question(lines[i], {lines[i + 1], lines[i + 2], lines[i + 3], lines[i + 4]}, stoi(lines[i + 5])));
	}
}


Question::Question(std::string t, std::vector<std::string> a, int g)
{
	text = t;
	answers = a;
	rightID = g;
}
