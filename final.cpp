/*410921365 陳祁鎔
	My project can help me to manage students’ scores. 
    	The project can store students' scores and you can use it to calculate everyone's average score on different subject.
    	There are some functions that can add someone’s grades, modify the grades and find the average scores.
Here is my source code:
*/
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <iomanip>
using namespace std;
class student
{
    int studentid, score[100][100], classcount = 0, classscorecount[100] = {0};
    string classname[100];

public:
    student()
    {
        studentid = 0;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                score[i][j] = 0;
            }
        }
        for (int i = 0; i < 100; i++)
        {
            classname[i] = "\0";
        }
    }
    student(int stuid)
    {
        stuid = studentid;
        memset(score, 0, sizeof(score));
        memset(classname, '0', sizeof(classname));
    }
    void setstudentid(int stuid)
    {
        studentid = stuid;
    }
    void setclassname(string clasname)
    {
        classname[classcount] = clasname;
        classcount++;
    }
    void setscore(int sco, int index)
    {
        score[index][classscorecount[index]] = sco;
        classscorecount[index]++;
    }
    void modify(int sco, int index, int n)
    {
        score[index][n] = sco;
    }
    int getstudentid()
    {
        return studentid;
    }
    int getscore(int index, int index2)
    {
        return score[index][index2];
    }
    int getclasscount()
    {
        return classcount;
    }
    int getclassscorecount(int index)
    {
        return classscorecount[index];
    }
    string getclassname(int index)
    {
        return classname[index];
    }
    float average(int index)
    {
        float sum;
        for (int i = 0; i < classscorecount[index]; i++)
        {
            //cout<<score[index][i]<<endl;
            sum = sum + score[index][i];
        }
        return sum / classscorecount[index];
    }
};
int main()
{
    fstream file;
    student *programmingclass = new student[100];
    string Class;
    int student_num = 0, id, i = 0, j = 0, n, k, i_file = 0, test = 0, purpose;
    float score;
    //file.open("myfile.txt", ios::out | ios::binary | ios::in);
    if (!file)
    {
        cout << "File cannot be opened" << endl;
        exit(1);
    }
    cout << "Please make a instruction." << endl;
    cout << "1: Add a score to the list." << endl;
    cout << "2: Modify the score in the list." << endl;
    cout << "3: Find someone's score list with average" << endl;
    cout << "4: List all the scores. " << endl;
    while (file >> id)
    {
        //cout<<id<<endl;
        programmingclass[student_num].setstudentid(id);
        i_file = 0;
        while (file >> Class)
        {
            //cout<<"!"<<Class<<endl;
            programmingclass[student_num].setclassname(Class);
            while (file >> score)
            {
                //cout<<score;
                programmingclass[student_num].setscore(score, i_file);
                if (file.get() == '\n')
                {
                    break;
                }
            }
            i_file++;
            if (file.get() == '\n')
            {
                break;
            }
        }
        student_num++;
    }
    file.close();
    file.open("myfile.txt", ios::out | ios::binary | ios::in | ios::trunc);
    while (cin >> purpose)
    {
        if (purpose == 0)
        {
            break;
        }
        if (purpose == 1)
        {
            while (1)
            {
                cout << "ID(enter 0 to leave the instruction): ";
                cin >> id;
                if (id == 0)
                {
                    break;
                }
                if (student_num == 0)
                {
                    programmingclass[0].setstudentid(id);
                    i = 0;
                    student_num++;
                }
                else
                {
                    for (i = 0; i < student_num; i++)
                    {
                        if (id == programmingclass[i].getstudentid())
                        {
                            break;
                        }
                        if (i == student_num - 1)
                        {
                            programmingclass[student_num].setstudentid(id);
                            student_num++;
                        }
                    }
                }
                cout << "Class: ";
                cin >> Class;
                if (programmingclass[i].getclasscount() == 0)
                {
                    programmingclass[i].setclassname(Class);
                    j = 0;
                }
                else
                {
                    for (j = 0; j < programmingclass[i].getclasscount(); j++)
                    {
                        if (Class == programmingclass[i].getclassname(j))
                        {
                            break;
                        }
                        if (j == programmingclass[i].getclasscount() - 1)
                        {
                            programmingclass[i].setclassname(Class);
                        }
                    }
                }
                cout << "Score: ";
                cin >> score;
                programmingclass[i].setscore(score, j);
            }
        }
        else if (purpose == 2)
        {
            while (1)
            {
                cout << "ID(enter 0 to leave the instruction): ";
                cin >> id;
                if (id == 0)
                {
                    break;
                }
                cout << "Class: ";
                cin >> Class;
                cout << "Which score of the class you wanted to correct? Please enter a reasonable integer, which the number is ";
                cin >> n;
                cout << "The score was modifed is ";
                cin >> score;
                for (i = 0; i < student_num; i++)
                {
                    if (id == programmingclass[i].getstudentid())
                    {
                        for (j = 0; j < programmingclass[i].getclasscount(); j++)
                        {
                            if (Class == programmingclass[i].getclassname(j))
                            {
                                programmingclass[i].modify(score, j, n - 1);
                            }
                        }
                    }
                }
            }
        }
        else if (purpose == 3)
        {
            cout << "ID: ";
            cin >> id;
            for (i = 0; i < student_num; i++)
            {
                if (id == programmingclass[i].getstudentid())
                {
                    //file << id;
                    for (j = 0; j < programmingclass[i].getclasscount(); j++)
                    {
                        cout << "Each score of " << programmingclass[i].getclassname(j) << " is : ";
                        for (int k = 0; k < programmingclass[i].getclassscorecount(j); k++)
                        {
                            cout << programmingclass[i].getscore(j, k);
                            if (k == programmingclass[i].getclassscorecount(j) - 1)
                            {
                                cout << endl;
                            }
                            else
                            {
                                cout << " ";
                            }
                        }
                        cout << "The average of " << programmingclass[i].getclassname(j) << " is : " << programmingclass[i].average(j) << endl;
                    }
                }
            }
        }
        else if (purpose == 4)
        {
            cout << "-------------------------------------------------------" << endl;
            cout << "ID        "
                 << "SUBJECT   "
                 << "SCORES" << endl;
            cout << "-------------------------------------------------------" << endl;
            for (int q = 0; q < student_num; q++)
            {
                cout << programmingclass[q].getstudentid() << " ";
                file << programmingclass[q].getstudentid() << " ";
                for (int w = 0; w < programmingclass[q].getclasscount(); w++)
                {
                    if (w != 0)
                    {
                        cout << "          ";
                        file << "          ";
                    }
                    cout << programmingclass[q].getclassname(w);
                    file << programmingclass[q].getclassname(w);
                    for (int e = 0; e < 10 - programmingclass[q].getclassname(w).length(); e++)
                    {
                        cout << " ";
                        file << " ";
                    }
                    for (int e = 0; e < programmingclass[q].getclassscorecount(w); e++)
                    {
                        cout << programmingclass[q].getscore(w, e);
                        file << programmingclass[q].getscore(w, e);
                        if (e == programmingclass[q].getclassscorecount(w) - 1)
                        {
                            cout << endl;
                            file << endl;
                        }
                        else
                        {
                            cout << " ";
                            file << " ";
                        }
                    }
                }
                file << endl;
            }
        }
        cout << "Please make a instruction." << endl;
        cout << "1: Add a score to the list." << endl;
        cout << "2: Modify the score in the list." << endl;
        cout << "3: Find someone's score list with average" << endl;
        cout << "4: List all the scores. " << endl;
        cout << "enter 0 to leave" << endl;
    }
    file.close();
    return 0;
}
