#pragma once
#include "User.h"
#include "FNode.h"
#include <vector>
using namespace std;

class Admin : public User {
public:
    Admin(Node* temp);
    void them(FNode& temp, int IdPhong, int tienPhong, const vector<string>& name, string quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const vector<string>& taikhoan, const vector<string>& matkhau);
    void capnhatsodien(FNode& temp, int IdPhong, int sodiensau);
    void capnhatsonuoc(FNode& temp, int IdPhong, int sonuocsau);
    void remove(FNode& temp, int IdPhong);
    void capnhatTrangThaiThanhToan(FNode& temp, int IdPhong, const string& dichVu);
    void display() override;
};
#include "Admin.cpp"