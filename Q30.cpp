#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num = 0;
    char cha[40];
    char c;
    string co;
    string morse[40], sen[100];
    cin >> c;
    while (c != '*')
    {
        std::cin >> co;
        cha[num] = c;
        morse[num] = co;
        num++;
        cin >> c;
    }
    string wordcode[100];
    int line = 0;
    string word[100];
    std::cin >> word[line];
    while (word[line] != "*")
    {
        for (int i = 0; i < word[line].size(); i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (word[line][i] == cha[j])
                {
                    wordcode[line] = wordcode[line] + morse[j];
                }
            }
        }
        line++;
        std::cin >> word[line];
    }
    for (int i = 0; i < line; i++)
    {
        for (int j = i + 1; j < line; j++)
        {
            if (wordcode[i] == wordcode[j])
            {
                word[i] = word[i] + "!";
            }
        }
    }
    string code[100];
    int len = 0;
    std::cin >> code[len];
    while (code[len] != "*")
    {
        bool leave = false;
        for (int i = 0; i < line; i++)
        {
            if (code[len] == wordcode[i])
            {
                cout << word[i] << endl;
                leave = true;
                break;
            }
        }
        int max[100]={0}, maxsame = 0, wordmuch;
        if (!leave)
        {
            for (int i = 0; i < line; i++)
            {
                int temp = code[len].size();
                if (wordcode[i].size() < code[len].size())
                {
                    temp = wordcode[i].size();
                }
                for (int j = 0; j < temp; j++)
                {
                    if (code[len][j] != wordcode[i][j])
                    {
                        break;
                    }
                    else
                    {
                        max[i]++;
                    }
                }
            }
            for (int k = 0; k < line; k++)
            {
                if (max[k] > maxsame)
                {
                    maxsame = max[k];
                    wordmuch = k;
                }
            }
            if (word[wordmuch][word[wordmuch].size() - 1] == '!')
            {
                string str = word[wordmuch];
                str[word[wordmuch].size() - 1] = '?';
                cout << str << endl;
            }
            else
            {
                cout << word[wordmuch] << "?" << endl;
            }
        }
        len++;
        std::cin >> code[len];
    }
    return 0;
}