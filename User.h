#pragma once
#include <string>
#include <iostream>
#include <vector>
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
            cout << "Ten: ";
            for (const auto& name : temp->name) {
                cout << name << " ";
            }
            cout << endl;
            cout << "SDT: ";
            for (const auto& sdt : temp->SDT) {
                cout << sdt << " ";
            }
            cout << endl;
            cout << "Quyen: " << temp->quyen << endl;
            cout << "So dien truoc: " << temp->sodientruoc << endl;
            cout << "So dien sau: " << temp->sodiensau << endl;
            cout << "So nuoc truoc: " << temp->sonuoctruoc << endl;
            cout << "So nuoc sau: " << temp->sonuocsau << endl;
            cout << "Tai khoan: ";
            for (const auto& tk : temp->taikhoan) {
                cout << tk << " ";
            }
            cout << endl;
            cout << "Mat khau: ";
            for (const auto& mk : temp->matkhau) {
                cout << mk << " ";
            }
            cout << endl;
        }
    }
};