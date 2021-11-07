#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

string cezar(string text) {
    cout << endl << "O ile cyfr ma zamieniac? (0-26): ";
    int number;
    cin >> number;
    while (number > 26 || number < 0) {
        cout << endl << "Podaj wartosc pomiedzy 0-26";
        cin >> number;
    }
    for (int i = 0; i < text.length(); i++) {
        if (text[i] + number > 122) 
        {
            text[i] = ((text[i] + number) % 123) + 97;
        }
        else if (text[i] > 122 || text[i] < 97) 
        {
            text[i] = text[i];
        }
        else 
        {
            text[i] = text[i] + number;
        }
    }
    return text;
}

string cof_cezara(string text, int number) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] > 123 || text[i] < 96) {
            text[i] = text[i];
        }
        else if (text[i] - number < 97) {
            text[i] = text[i] - number + 26;
        }
        else {
            text[i] = text[i] - number;
        }
    }
    return text;
}

string przestawiania(string text) {
    string code(text.length(), '.');
    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0) {
            code[i + 1] = text[i];
        }
        else if (i % 2 == 1) {
            code[i - 1] = text[i];
        }
    }
    if (text.length() % 2 == 1) {
        code[text.length() - 1] = text[text.length() - 1];
    }
    return code;
}

string cof_przestawianie(string text) {
    string code(text.length(), '.');
    for (int i = 0; i < text.length(); i++) {
        if (i % 2 == 0) {
            code[i] = text[i + 1];
        }
        else if (i % 2 == 1) {
            code[i] = text[i - 1];
        }
    }
    if (text.length() % 2 == 1) {
        code[text.length() - 1] = text[text.length() - 1];
    }
    return code;
}

string duo(string text) {
    text = przestawiania(text);
    return cezar(text);
}

string odszyfrowanie(string text, int number) {
    if (number == 0) {
        return cof_przestawianie(text);
    }
    string cofanie = cof_cezara(text, number) + "     " + cof_przestawianie(cof_cezara(text, number)); ;
    return cofanie;
}


int main()
{
    while (1) {
        char choice;
        cout << endl << "Czy wyczysc ekran?";
        cout << endl << "1-tak";
        cout << endl << "inny znak - nie" << endl;
        cin >> choice;

        if (choice == '1')
        {
            system("CLS");
        }

        cout << endl << "Napisz zdanie lub slowo: ";
        string text;
        cin.ignore();
        getline(cin, text);
        cout << endl << "Co chcesz?: ";
        cout << endl << "1-Szyfr cezara";
        cout << endl << "2-Szyfr przestawieniowy";
        cout << endl << "3-Szyfr cezara i szyfr przestawieniowy";
        cout << endl << "4-Odszyfrowywanie" << endl;
        cin >> choice;

        if (choice == '1')
        {
            cout << cezar(text);
        }
        else if (choice == '2')
        {
            cout << przestawiania(text);
        }
        else if (choice == '3')
        {
            cout << duo(text);
        }
        else if (choice == '4')
        {
            for (int i = 0; i < 26; i++)
            {
                cout << odszyfrowanie(text, i);
                cout << endl;
            }
        }
    }
}
