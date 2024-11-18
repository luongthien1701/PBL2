#include "Admin.h"
#include <fstream>

Admin::Admin(Node* temp) : User(temp) {}

void Admin::them(FNode& temp, int IdPhong, int tienPhong, const Vector<string>& name, const Vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const Vector<string>& taikhoan, const Vector<string>& matkhau) {
    temp.them(IdPhong, tienPhong, name, SDT, sodiensau, sonuocsau, tienWifi, tienRac, taikhoan, matkhau);
    temp.ghiFile("phongtro.txt", IdPhong, tienPhong, name, SDT, sodiensau, sonuocsau, tienWifi, tienRac, taikhoan, matkhau);
}

void Admin::capnhatsodien(FNode& temp, int IdPhong, int sodiensau) {
    Node* tmp = temp.Find(IdPhong);
    if (tmp) {
        tmp->sodientruoc = tmp->sodiensau;
        tmp->sodiensau = sodiensau;
    }
    temp.ghiLaiFile("phongtro.txt");
}

void Admin::capnhatsonuoc(FNode& temp, int IdPhong, int sonuocsau) {
    Node* tmp = temp.Find(IdPhong);
    if (tmp) {
        tmp->sonuoctruoc = tmp->sonuocsau;
        tmp->sonuocsau = sonuocsau;
    }
    temp.ghiLaiFile("phongtro.txt");
}

void Admin::remove(FNode& temp, int IdPhong) {
    temp.remove(IdPhong);
}

void Admin::capnhatTrangThaiThanhToan(FNode& temp, int IdPhong, const string& dichVu) {
    Node* tmp = temp.Find(IdPhong);
    if (tmp) {
        if (dichVu == "phong") {
            tmp->daDongTienPhong = true;
        } else if (dichVu == "dien") {
            tmp->daDongTienDien = true;
        } else if (dichVu == "nuoc") {
            tmp->daDongTienNuoc = true;
        } else if (dichVu == "wifi") {
            tmp->daDongTienWifi = true;
        } else if (dichVu == "rac") {
            tmp->daDongTienRac = true;
        }
        temp.ghiLaiFile("phongtro.txt");
    }
}

void Admin::display() {
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