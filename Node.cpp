#include "Node.h"

Node::Node(int IdPhong, int tienPhong, const Vector<string>& name, const Vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const Vector<string>& taikhoan, const Vector<string>& matkhau) {
    this->IdPhong = IdPhong;
    this->tienPhong = tienPhong;
    this->name = name;
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
        tienDien = soDien * 1806;
    } else if (soDien <= 100) {
        tienDien = 50 * 1806 + (soDien - 50) * 1886;
    } else {
        tienDien = 50 * 1806 + 50 * 1886 + (soDien - 100) * 1886;
    }
    return tienDien;
}

double Node::tinhTienNuoc() const {
    int soNuoc = sonuocsau - sonuoctruoc;
    double tienNuoc = 0;
    if (soNuoc <= 10) {
        tienNuoc = soNuoc * 6869;
    } else if (soNuoc <= 20) {
        tienNuoc = 10 * 6869 + (soNuoc - 10) * 8110;
    } else if (soNuoc <= 30) {
        tienNuoc = 10 * 6869 + 10 * 8110 + (soNuoc - 20) * 9968;
    } else {
        tienNuoc = 10 * 6869 + 10 * 8110 + 10 * 9968 + (soNuoc - 30) * 18318;
    }
    return tienNuoc;
}

double Node::tinhTienWifi() const {
    return 50;
}

double Node::tinhTienRac() const {
    return 50 * name.getsize();
}