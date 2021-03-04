#include <iostream> // Мы планируем использовать инструменты доступные в iostream
#include <string>
#include <algorithm>
#include <regex>
#include <map>
using namespace std;


string to_lower(string txt) 
{
    transform(txt.begin(), txt.end(), txt.begin(), ::tolower);
    return txt;
}

void botSay(string text) 
{
    cout << "[BOT]: " << text << endl;
}

string userAsk() 
{
    string question;
    cout << "[USER]: ";
    getline(cin, question);
    question = to_lower(question);
    return question;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    map<string, string> database = 
    {
        {"hello", "oh hi how are you?"},

        {"how are you", "Im doing just fine, LOL"},
        {"what are you doing", "I'm answering stupid question"},
        {"where are you from", "I'm from within your mind"},
        {"how old are you", "I'm only 10 nanoseconds old"},
        {"what are you", "I'm your friendly ChatBot2021"},

        {"exit", "Ok byyyyeeee"},
    };

    botSay("Hello, my name is ChatBot2021!");
    string question; // переменная, содержит вопрос пользователя


    while (question != "exit") 
    {
        question = userAsk();
        int num_answers = 0;
        for (auto entry : database) 
        {
            regex pattern = regex(".*" + entry.first + ".*");
            if (regex_match(question, pattern)) 
            {
                num_answers++;
                botSay(entry.second);
            }
        }
        if (num_answers == 0) 
        {
            botSay("Oiii, I don't knoooow");
        }
        if (num_answers > 5) 
        {
            botSay("Oiii, I'm very talkative today");
        }
    }
}