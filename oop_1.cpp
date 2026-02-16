#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string ERRORMESSAGE = "Ошибка открытия файла ";
const string TEXTNOTFIND = "Текст не найден ";

void FindText(const string& text, const string& file_name, bool& TextwasFind)
{
    ifstream file(file_name);
    if (!file.is_open())
    {
        cerr << ERRORMESSAGE << file_name << endl;
        return;
    }

    string line;
    int count_lines = 0;
    while (getline(file, line))
    {
        count_lines++;
        if (line.find(text) != string::npos)
        {
            cout << count_lines << endl;
            TextwasFind = true;
        }
    }

    if (!TextwasFind)
        cout << TEXTNOTFIND << endl;
}

int main(int argc, char* argv[])
{
    bool TextwasFind = false;
    string text, file_name;
    file_name = argv[1];
    text = argv[2];
    FindText(text, file_name, TextwasFind);
    return !TextwasFind;
}