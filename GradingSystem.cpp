#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

class student
{
private:
    int rollno;
    char name[20];
    float marks;
    char grade;

public:
    void readstudent()
    {
        cout << "\nEnter the roll number :";
        cin >> rollno;
        cout << "\nEnter the marks:";
        cin >> marks;
    }
    void dispstudent()
    {
        calcgrade();
        cout << "\nRollno :" << rollno << "\nMarks:" << marks << "\nGrade:" << grade;
    }
    int getrollno()
    {
        return rollno;
    }
    float getmarks()
    {
        return marks;
    }
    void calcgrade()
    {
        if (marks >= 75)
            grade = 'A';
        else if (marks >= 60)
            grade = 'B';
        else if (marks >= 50)
            grade = 'C';
        else if (marks >= 40)
            grade = 'D';
        else
            grade = 'F';
    }
};
int main()
{
    int N;
        cout<<endl<<"Enter how many Students you want to add"<<endl;
        cin>>N;

    student xiia[N];
    for (int i = 0; i < N; i++)
    {
        cout << "\nEnter the details of student " << i + 1 << ":";
        xiia[i].readstudent();
    }
    int choice, rno, pos = -1, high = 0;
    do
    {
        cout << "\nMain menu\n"
             << "1.Specific student\n"
             << "2.Topper\n"
             << "3.Exit\n";
        cout << "Enter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter the roll number of the student whose info you want to see:";
            cin >> rno;
            for (int i = 0; i < N; i++)
            {
                if (xiia[i].getrollno() == rno)
                {
                    xiia[i].dispstudent();
                }
            }
            break;
        case 2:
            for (int i = 0; i < N; i++)
            {
                if (xiia[i].getmarks() > high)
                {
                    pos = i;
                    high = xiia[i].getmarks();
                }
            }
            xiia[pos].dispstudent();
            break;
        case 3:
            exit(0);
        default:
            cout << "\nWrong choice";
        }
    } while (choice >= 0 && choice <= 3);
    getch();
}