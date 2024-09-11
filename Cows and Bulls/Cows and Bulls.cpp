// Cows and Bulls.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;
string GetInput(string inputMessage);
array<int, 4> GenerateNumber();
array<int, 4> answer = {GenerateNumber()};
void CowsBulls(array<int, 4> answer);

int main()
{
    CowsBulls(answer);
}

string GetInput(string inputMessage)
{
    string userInput = "";
    while (true)
    {
        cout << inputMessage << endl;
        string rawInput;
        getline(cin, rawInput);
        try
        {
            if (rawInput.length() != 4)
            {
                throw new exception;
            }
            else
            {
                userInput = rawInput;
                break;
            }
        }
        catch (...)
        {
            cout << "not a valid input" << endl;
        }
    }
    return userInput;
}

array<int, 4> GenerateNumber()
{
    srand((unsigned)time(NULL));
    array<int, 4> answerList;
    for (int x = 0; x < 4; x++)
    {
        answerList[x] = rand() % 9;
    }
    return answerList;
}
void CowsBulls(array<int, 4> answer)
{
    while (true)
    {
        string guess = GetInput("please input a 4 digit number");
        array<int, 4> guessArray;
        int i = 0;
        for (char c : guess)
        {
            guessArray[i] = c - '0';
            i++;
        }
        int cow = 0;
        int bull = 0; 
        cout << endl;
        for (int x = 0; x < 4; x++)
        {
            bool cowX = false;
            bool bullX = false;
            for (int y = 0; y < 4; y++)
            {
                if (answer[y] == guessArray[x] && x == y)
                {
                    cow += 1;
                    cowX = true;
                    break;
                }
                else if (answer[y] == guessArray[x] && x != y)
                {
                    bullX = true;
                }
            }
            if (cowX == false && bullX == true)
            {
                bull += 1;
            }
        }
        cout << "bull: " << bull << endl;
        cout << "cow " << cow << endl;
        if (cow == 4)
        {
            cout << "YOU WIN!!" << endl;
            break;
        }
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
