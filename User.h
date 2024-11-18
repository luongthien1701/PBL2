#pragma once
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

class User {
protected:
    Node* temp;
public:
    User(Node* temp) : temp(temp) {}

    virtual void display() {
        if (temp) {
            cout << "So phong: " << temp->IdPhong << endl;
            cout << "Tien phong: " << temp->tienPhong << endl;
            for (size_t i = 0; i < temp->name.getsize(); ++i) {
                cout << "Ten: " << temp->name[i] << endl;
                cout << "SDT: " << temp->SDT[i] << endl;
                cout << "Tai khoan: " << temp->taikhoan[i] << endl;
                cout << "Mat khau: " << temp->matkhau[i] << endl;
            }
            cout << "So dien truoc: " << temp->sodientruoc << endl;
            cout << "So dien sau: " << temp->sodiensau << endl;
            cout << "So nuoc truoc: " << temp->sonuoctruoc << endl;
            cout << "So nuoc sau: " << temp->sonuocsau << endl;
            cout << "Tien Wifi: " << temp->tinhTienWifi() << endl;
            cout << "Tien Rac: " << temp->tinhTienRac() << endl;
            cout << "Trang thai thanh toan: " << endl;
            cout << "Tien phong: " << (temp->daDongTienPhong ? "Da dong" : "Chua dong") << endl;
            cout << "Tien dien: " << (temp->daDongTienDien ? "Da dong" : "Chua dong") << endl;
            cout << "Tien nuoc: " << (temp->daDongTienNuoc ? "Da dong" : "Chua dong") << endl;
            cout << "Tien Wifi: " << (temp->daDongTienWifi ? "Da dong" : "Chua dong") << endl;
            cout << "Tien Rac: " << (temp->daDongTienRac ? "Da dong" : "Chua dong") << endl;
        }
    }
};