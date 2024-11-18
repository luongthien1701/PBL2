#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int IdPhong;
    vector<string> name;
    string quyen;
    vector<string> SDT;
    int sodientruoc, sodiensau;
    int sonuoctruoc, sonuocsau;
    vector<string> taikhoan;
    vector<string> matkhau;
    Node* prev;
    Node* next;

public:
    Node(int IdPhong, const vector<string>& name, string quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, const vector<string>& taikhoan, const vector<string>& matkhau) {
        this->IdPhong = IdPhong;
        this->name = name;
        this->quyen = quyen;
        this->SDT = SDT;
        this->sodiensau = sodiensau;
        this->sonuocsau = sonuocsau;
        this->taikhoan = taikhoan;
        this->matkhau = matkhau;
        this->prev = nullptr;
        this->next = nullptr;
    }
};