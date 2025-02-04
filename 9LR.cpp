//#include <iostream>
//#include <fstream>
//#include <string>
//#include <cmath>
//#include <iomanip>
//
//using namespace std;
//
//double f(double x);
//int main()
//{
//    setlocale(0, "ukr");
//    double a = 0.5, b = 1.0, h = 0.1;
//    double x, y, sum = 0;
//    fstream ftxt, fxls;
//    ftxt.open("f1.txt", ios::out);
//    fxls.open("f1.xls", ios::out);
//    if (!ftxt.is_open() || !fxls.is_open()) {
//        cout << "�� ������� ������� �����!" << endl;
//        return 1;
//    }
//    ftxt << "X\tY" << endl;
//    fxls << "X\tY" << endl;
//    cout << setw(10) << "X" << setw(10) << "Y" << endl;
//    for (x = a; x <= b; x += h) {
//        y = f(x);
//        cout << setw(10) << x << setw(10) << y << endl;
//        ftxt << x << "\t" << y << endl;
//        fxls << x << "\t" << y << endl;
//        if (y >= 0 && y < -0.1 ) {
//            sum += y;
//        }
//    }
//    ftxt << endl;
//    ftxt << "���� ������� y (����  y=>0 i y<-0,1): " << sum << endl;
//    ftxt.close();
//    fxls.close();
//    string line;
//    cout << "\n���� ����� f1.txt:" << endl;
//    ftxt.open("f1.txt", ios::in);
//    while (getline(ftxt, line)) {
//        cout << line << endl;
//    }
//    ftxt.close();
//    cout << "\n���� ����� f1.xls:" << endl;
//    fxls.open("f1.xls", ios::in);
//    while (getline(fxls, line)) {
//        cout << line << endl;
//    }
//    fxls.close();
//    ftxt.open("f1.txt", ios::app);
//    ftxt << "������ �����������";
//    ftxt.open("f1.txt", ios::in);
//    while (getline(ftxt, line)) {
//        cout << line << endl;
//    }
//    ftxt.close();
//    fxls.open("f1.xls", ios::app);
//    fxls << "������ �����������";
//    ftxt.open("f1.xls", ios::in);
//    while (getline(fxls, line)) {
//        cout << line << endl;
//    }
//    fxls.close();
//    return 0;
//}
//double f(double x) {
//    return x/(pow(sin(x), 2));
//}


//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <cmath>
//
//using namespace std;
//
//double factorial(int n) {
//    double result = 1;
//    for (int i = 1; i <= n; ++i) {
//        result *= i;
//    }
//    return result;
//}
//void cSeries(double x, double precision, const string& filename) {
//    fstream outFile(filename);
//    outFile.open("rezult.txt", ios::out);
//    if (!outFile) {
//        cout << "�� ������� ������� ����! " << filename << endl;
//        return;
//    }
//    outFile << "n\ta_n\n";
//    int n = 1;
//    double term = pow(2 * x, n) / factorial(n);
//    double seriesSum = term;
//
//    outFile << n << "\t" << fixed << setprecision(6) << term << "\n";
//
//    while (term > precision) {
//        n++;
//        term = pow(2 * x, n) / factorial(n);
//        seriesSum += term;
//        outFile << n << "\t" << fixed << setprecision(6) << term << "\n";
//    }
//
//    outFile << "\n����: " << fixed << setprecision(6) << seriesSum << endl;
//    outFile.close();
//
//    cout << "���������� ���� ������� � " << filename << "." << endl;
//}
//int main() {
//    setlocale(0, "ukr");
//    double x = 0.46; // Given value of x for variant 20
//    double precision = 0.001; // Given precision
//    cSeries(x, precision, "rezult.txt");
//    return 0;
//}



#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Teacher {
    char surname[50];
    char position[50];
};
void cFile(const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cout << "�� ������� ������� ����! " << filename << endl;
        return;
    }
    int teacherCount;
    cout << "������ ���� ����������: ";
    cin >> teacherCount;
    cin.ignore();
    for (int i = 0; i < teacherCount; ++i) {
        Teacher teacher;
        cout << "�������� ������� ��������� " << i + 1 << ": ";
        cin.getline(teacher.surname, 50);
        cout << "�������� ������ ��������� " << i + 1 << ": ";
        cin.getline(teacher.position, 50);
        outFile.write(reinterpret_cast<const char*>(&teacher), sizeof(Teacher));
    }
    outFile.close();
    cout << "�������� ���� " << filename << " ���� ��������." << endl;
}
void pTeachers(const string& filename) {
    ifstream inFile("teachers.dat", ios::binary);
    if (!inFile) {
        cout << "�� ������� ������� ���� " << filename << endl;
        return;
    }
    Teacher teacher;
    cout << "��������� � �������� ��� ���������� �� 'V':\n";
    while (inFile.read(reinterpret_cast<char*>(&teacher), sizeof(Teacher))) {
        if (teacher.surname[0] == 'V') {
            cout << teacher.surname << " - " << teacher.position << endl;
        }
    }
    inFile.close();
}
int main() {
    setlocale(0, "ukr");
    string filename = "teachers.dat";
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. �������� ������� ����\n";
        cout << "2. ��������� � ��������, ��� ���������� �� 'V' \n";
        cout << "3. �����\n";
        cout << "�������� ��� ����: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cFile(filename);
            break;
        case 2:
            pTeachers(filename);
            break;
        case 3:
            cout << "�����..." << endl;
            break;
        default:
            cout << "������������ ����. ��������� �� ���." << endl;
        }
    } while (choice != 3);
    return 0;
}
