#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class Student
{
public:
    string surname;
    int number;
};


int increment(long inc[], long size) {
    int p1, p2, p3, s;
    p1 = p2 = p3 = 1;
    s = -1;
    do
    {
        if (++s % 2) {
            inc[s] = 8 * p1 - 6 * p2 + 1;
        }
        else {
            inc[s] = 9 * p1 - 9 * p3 + 1;
            p2 *= 2;
            p3 *= 2;
        }
        p1 *= 2;
    } while (3 * inc[s] < size);
    return s > 0 ? --s : 0;
}
void shellSort(vector<Student>& a, long size) {
    long inc, i, j, seq[40];
    int s;
    // ���������� ������������������ ����������
    s = increment(seq, size);
    while (s >= 0)
    {
        // ���������� ��������� � ������������ inc
        inc = seq[s--];
        for (i = inc; i < size; i++) {
            string temp = a[i].surname;
            for (j = i - inc; (j >= 0) && (a[j].surname > temp); j -= inc)
                a[j + inc] = a[j];
            a[j + inc].surname = temp;
        }
    }
}



int binarySearch(vector<Student> students, string val)
{
    int lastIndex = students.size() - 1;
    int firstIndex = 0;
    while (lastIndex >= firstIndex)
    {
        int middleIndex = (firstIndex + lastIndex) / 2;
        if (students[middleIndex].surname == val)
        {
            return middleIndex;
        }
        else
            if (students[middleIndex].surname < val)
                firstIndex = middleIndex + 1;
            else
                if (students[middleIndex].surname > val)
                    lastIndex = middleIndex - 1;
    }
    return -1;
}

void bubbleSort(vector <Student>& a, int start, int fin) {
    Student buff;
    for (int i = start; i < fin - 1; i++)
    {
        for (int j = fin - 1; j > i; j--)
        {
            if (a[j].number < a[j - 1].number)
            {
                buff = a[j - 1];
                a[j - 1] = a[j];
                a[j] = buff;
            }
        }
    }
}

void GetSlice(vector <Student>& a)
{
    int buff = 0;
    
    for (int i = 1; i < a.size(); i++)
    {
        if (a[buff].surname[0] != a[i].surname[0])
        {
            if (i != 1)
            {
                bubbleSort(a, buff, i);
                buff = i;
            }
            else
            {
                buff = i;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<Student> students = { {"������", 30}, {"������", 40}, {"�����", 35}, {"��������", 50}, {"�����", 45} };
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    shellSort(students, students.size());

    GetSlice(students);

    for (const auto& student : students) {
        cout << student.surname << " " << student.number << endl;
    }

    string target; cout << "���� ����� �����? "; cin >> target;
    int result = binarySearch(students, target);

    if (result != -1)
        cout << "������(�) " << target << " �� ����� ����� " << result << endl;
    else
        cout << target << " �� �������" << endl;

    return 0;
}
