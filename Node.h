#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int IdPhong;
    int tienPhong;
    vector<string> name;
    string quyen;
    vector<string> SDT;
    int sodientruoc, sodiensau;
    int sonuoctruoc, sonuocsau;
    int tienWifi, tienRac;
    bool daDongTienPhong, daDongTienDien, daDongTienNuoc, daDongTienWifi, daDongTienRac;
    vector<string> taikhoan;
    vector<string> matkhau;
    Node* prev;
    Node* next;

public:
    Node(int IdPhong, int tienPhong, const vector<string>& name, string quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const vector<string>& taikhoan, const vector<string>& matkhau);

    double tinhTienDien() const;
    double tinhTienNuoc() const;
    double tinhTienWifi() const;
    double tinhTienRac() const;
};
#include "Node.cpp"