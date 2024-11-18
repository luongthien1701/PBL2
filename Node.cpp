#include "Node.h"

Node::Node(int IdPhong, int tienPhong, const vector<string>& name, string quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const vector<string>& taikhoan, const vector<string>& matkhau) {
    this->IdPhong = IdPhong;
    this->tienPhong = tienPhong;
    this->name = name;
    this->quyen = quyen;
    this->SDT = SDT;
    this->sodiensau = sodiensau;
    this->sonuocsau = sonuocsau;
    this->tienWifi = tienWifi;
    this->tienRac = tienRac;
    this->daDongTienPhong = false;
    this->daDongTienDien = false;
    this->daDongTienNuoc = false;
    this->daDongTienWifi = false;
    this->daDongTienRac = false;
    this->taikhoan = taikhoan;
    this->matkhau = matkhau;
    this->prev = nullptr;
    this->next = nullptr;
}

double Node::tinhTienDien() const {
    int soDien = sodiensau - sodientruoc;
    double tienDien = 0;
    if (soDien <= 50) {
        tienDien = soDien * 1.806;
    } else if (soDien <= 100) {
        tienDien = 50 * 1.806 + (soDien - 50) * 1.886;
    } else {
        tienDien = 50 * 1.806 + 50 * 1.886 + (soDien - 100) * 1.886;
    }
    return tienDien;
}

double Node::tinhTienNuoc() const {
    int soNuoc = sonuocsau - sonuoctruoc;
    double tienNuoc = 0;
    if (soNuoc <= 10) {
        tienNuoc = soNuoc * 6.869;
    } else if (soNuoc <= 20) {
        tienNuoc = 10 * 6.869 + (soNuoc - 10) * 8.110;
    } else if (soNuoc <= 30) {
        tienNuoc = 10 * 6.869 + 10 * 8.110 + (soNuoc - 20) * 9.968;
    } else {
        tienNuoc = 10 * 6.869 + 10 * 8110 + 10 * 9.968 + (soNuoc - 30) * 18.318;
    }
    return tienNuoc;
}

double Node::tinhTienWifi() const {
    return 50;
}

double Node::tinhTienRac() const {
    return 50 * name.size();
}