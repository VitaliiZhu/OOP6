#include <iostream>
#include <type_traits>
#include<Windows.h>
using namespace std;
template <typename T>
class Checksum {
public:
    static int calculate(T value) {
        static_assert(is_integral<T>::value, "��� ����� �� ���� �������������.");
        int checksum = 0;
        while (value) {
            checksum += value & 1;
            value >>= 1;
        }
        return checksum;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int intValue = 4;
    char charValue = 25;
    long longValue = 42561231;

    cout << "���������� ���� (int): " << Checksum<int>::calculate(intValue) << endl;
    cout << "���������� ���� (char): " << Checksum<char>::calculate(charValue) << endl;
    cout << "���������� ���� (long): " << Checksum<long>::calculate(longValue) << endl;

    return 0;
}
