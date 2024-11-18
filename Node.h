#pragma once
#include <iostream>
#include <string>
#include "Vector.h"
using namespace std;

class Node {
public:
    int IdPhong;
    int tienPhong;
    Vector<string> name;
    Vector<string> SDT;
    int sodientruoc, sodiensau;
    int sonuoctruoc, sonuocsau;
    int tienWifi, tienRac;
    bool daDongTienPhong, daDongTienDien, daDongTienNuoc, daDongTienWifi, daDongTienRac;
    Vector<string> taikhoan;
    Vector<string> matkhau;
    Node* prev;
    Node* next;

public:
    Node(int IdPhong, int tienPhong, const Vector<string>& name, const Vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const Vector<string>& taikhoan, const Vector<string>& matkhau);

    double tinhTienDien() const;
    double tinhTienNuoc() const;
    double tinhTienWifi() const;
    double tinhTienRac() const;
};
#include "Node.cpp"