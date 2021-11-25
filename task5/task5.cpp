#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n, N, count, f;
    f = 0;
    while (f == 0)
    {
        cout << "������� ���-�� ������ ������� n = ";
        cin >> n;
      
        while (n < 1)
        {
            cout << "\n �� ����� ������������ ������.\n ������� ����� ����� �� 1 : ";
            cin >> n;
        }
        cout << " \n ����� ������� �� ������ ������?\n 1 - �����������. \n 2 - ��������.\n 3 - �����.\n ��� �����: ";
        cin >> count;
        while (count < 1 || count > 3) {
            cout << "\n �� ����� ������������ ������.\n ������� ����� ����� �� 1 �� 2 : ";
            cin >> count;
        }
        if (count == 3)
        {
            return 0;
        }
        N = 2 * n;
        int* mus1 = new int[n];
        int* mus2 = new int[n];
        int* mus3 = new int[N];
        for (int i = 0; i < n; ++i) {
            mus1[i] = 0 + rand() % 50;
            mus2[i] = 0 + rand() % 50;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (count == 1) {
                for (int j = i + 1; j < n; j++)   //�����������
                {
                    if (mus1[i] > mus1[j]) {
                        int temp = mus1[i];
                        mus1[i] = mus1[j];
                        mus1[j] = temp;
                    }
                }
                for (int j = i + 1; j < n; j++)
                {
                    if (mus2[i] > mus2[j]) {
                        int temp = mus2[i];
                        mus2[i] = mus2[j];
                        mus2[j] = temp;
                    }
                }
            }
            else {
                for (int j = i + 1; j < n; j++)     //��������
                {
                    if (mus1[i] < mus1[j]) {
                        int temp = mus1[i];
                        mus1[i] = mus1[j];
                        mus1[j] = temp;
                    }
                }
                for (int j = i + 1; j < n; j++)
                {
                    if (mus2[i] < mus2[j]) {
                        int temp = mus2[i];
                        mus2[i] = mus2[j];
                        mus2[j] = temp;
                    }
                }
            }
        }
        int j = 0;
        while (j < n) {
            mus3[j] = mus1[j];
            j++;
        }
        int m = n;
        int d = 0;
        while (m < N) {
            mus3[m] = mus2[d];
            m++;
            d++;
        }
        for (int i = 0; i < N - 1; i++) {
            if (count == 1) {
                for (int j = i + 1; j < N; j++)   //�����������
                {
                    if (mus3[i] > mus3[j]) {
                        int temp = mus3[i];
                        mus3[i] = mus3[j];
                        mus3[j] = temp;
                    }
                }
            }
            else {
                for (int j = i + 1; j < N; j++)     //��������
                {
                    if (mus3[i] < mus3[j]) {
                        int temp = mus3[i];
                        mus3[i] = mus3[j];
                        mus3[j] = temp;
                    }
                }
            }
        }
        cout << "\n ������ 1";
        for (int i = 0; i < n; i++) {
            cout << "\n [" << i << "] : " << mus1[i];
        }
        cout << "\n\n ������ 2";
        for (int i = 0; i < n; i++) {
            cout << "\n [" << i << "] : " << mus2[i];
        }
        cout << "\n\n ������ 3";
        for (int i = 0; i < N; i++) {
            cout << "\n [" << i << "] : " << mus3[i];
        }
        cout << "\n\n";
        system("pause");
        system("cls");
        delete[] mus1;
        delete[] mus2;
        delete[] mus3;
    }
}
