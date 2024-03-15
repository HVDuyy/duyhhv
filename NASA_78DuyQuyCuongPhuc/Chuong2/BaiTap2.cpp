#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CauhoiTN {
private:
    string noiDung;
    string dapAnA;
    string dapAnB;
    char dapAnDung;

public:
    void nhap() {
        cout << "Nhap noi dung cau hoi: ";
        cin.ignore();
        getline(cin, noiDung);
        cout << "Nhap dap an A: ";
        getline(cin, dapAnA);
        cout << "Nhap dap an B: ";
        getline(cin, dapAnB);
        cout << "Nhap dap an dung (A hoac B): ";
        cin >> dapAnDung;
    }

    void docfile(ifstream& f) {
        getline(f, noiDung);
        getline(f, dapAnA);
        getline(f, dapAnB);
        f >> dapAnDung;
        f.ignore();
    }

    void ghifile(ofstream& f) {
        f << noiDung << endl;
        f << dapAnA << endl;
        f << dapAnB << endl;
        f << dapAnDung << endl;
    }

    void kiemtra() {
        cout << "Cau hoi: " << noiDung << endl;
        char chon;
        cout << "Nhap dap an cua ban (A hoac B): ";
        cin >> chon;
        if (toupper(chon) == toupper(dapAnDung)) {
            cout << "Dap an dung!" << endl;
        }
        else {
            cout << "Dap an sai!" << endl;
        }
    }

    void xuat() {
        cout << "Cau hoi: " << noiDung << endl;
        cout << "A. " << dapAnA << endl;
        cout << "B. " << dapAnB << endl;
        cout << "Dap an dung: " << dapAnDung << endl;
    }

    friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};

bool giongnhau(CauhoiTN cau1, CauhoiTN cau2) {
    return (cau1.noiDung == cau2.noiDung &&
        cau1.dapAnA == cau2.dapAnA &&
        cau1.dapAnB == cau2.dapAnB &&
        cau1.dapAnDung == cau2.dapAnDung);
}

int main() {
    int choice;
    CauhoiTN cauhoi;
    ifstream inFile;
    ofstream outFile;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tao de thi trac nghiem" << endl;
        cout << "2. Doc noi dung de thi tu file" << endl;
        cout << "3. Xoa khoang trang thua trong file" << endl;
        cout << "4. Kiem tra hai cau hoi co giong nhau khong" << endl;
        cout << "5. Thoat chuong trinh" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
        case 1:
            outFile.open("de_thi.TTN", ios::app);
            cauhoi.nhap();
            cauhoi.ghifile(outFile);
            outFile.close();
            break;
        case 2:
            inFile.open("de_thi.TTN");
            while (!inFile.eof()) {
                cauhoi.docfile(inFile);
                cauhoi.xuat();
            }
            inFile.close();
            break;
        case 3:
            cauhoi.kiemtra();
            break;
        case 4:
            inFile.open("de_thi.ttn");
            while (!inFile.eof()) {
                cauhoi.docfile(inFile);
                cauhoi.xuat();
            }
            inFile.close();
            break;
            break;
        case 5:
            cout << "Tam biet!";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai." << endl;
        }
    } while (choice != 5);

    return 0;
}
