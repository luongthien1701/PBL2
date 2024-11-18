#include "admin.h"
Admin::Admin(Node* temp) : User(temp) {}

void Admin::them(FNode& temp, int IdPhong, const vector<string>& name, string quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, const vector<string>& taikhoan, const vector<string>& matkhau) {
    temp.them(IdPhong, name, quyen, SDT, sodiensau, sonuocsau, taikhoan, matkhau);
    temp.ghiFile("phongtro.txt", IdPhong, name, quyen, SDT, sodiensau, sonuocsau, taikhoan, matkhau);
}

void Admin::capnhatsodien(FNode& temp, int IdPhong, int sodiensau) {
    Node* tmp = temp.Find(IdPhong);
    if (tmp) {
        tmp->sodientruoc = tmp->sodiensau;
        tmp->sodiensau = sodiensau;
    }
}

void Admin::capnhatsonuoc(FNode& temp, int IdPhong, int sonuocsau) {
    Node* tmp = temp.Find(IdPhong);
    if (tmp) {
        tmp->sonuoctruoc = tmp->sonuocsau;
        tmp->sonuocsau = sonuocsau;
    }
}

void Admin::remove(FNode& temp, int IdPhong) {
    temp.remove(IdPhong);
}