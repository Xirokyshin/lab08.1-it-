#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char* str) {
    if (strlen(str) < 3)
        return 0;

    int k = 0;
    for (int i = 1; str[i + 1] != '\0'; i++) {
        if (str[i - 1] == 'n' && str[i + 1] == 'o') 
            k++;
    }
    return k;
}

char* Change(char* str) {
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 2 + 1]; // �������� ����� ���'��
    char* t = tmp;
    tmp[0] = '\0'; 
    size_t i = 0;

    while (i < len) {
        if (i < len - 2 && str[i] == 'n' && str[i + 2] == 'o') { 
            t += 2; // ���������� �� ��� ������� ������
            i += 3; // ���������� �����
        }
        else {
            *t++ = str[i++]; // ������� �������� ������
            *t = '\0'; // ��������� �����
        }
    }

    strcpy(str, tmp); // ������� ����� � �������� �����
    return tmp; // ��������� ���������� �����
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'n?o'" << endl;

    char* dest = Change(str); // ������ ������� ���� �����
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // ��������� ���'��
    return 0;
}
