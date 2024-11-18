#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include "Vector.h"
#include "Node.h"
using namespace std;

class FNode {
private:
    Node* head;
    Node* end;
    Vector<string> adminUsernames; // Lưu tên đăng nhập của admin
    Vector<string> adminPasswords; // Lưu mật khẩu của admin
public:
    FNode();
    void them(int IdPhong, int tienPhong, const Vector<string>& name, const Vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const Vector<string>& taikhoan, const Vector<string>& matkhau);
    Node* Find(int ID);
    Node* loginAdmin(const string& taikhoan, const string& matkhau);
    Node* loginUser(const string& taikhoan, const string& matkhau);
    ~FNode();
    void remove(int IdPhong);
    void loadfile(const string& filename);
    void loadAdminFile(const string& filename);
    void ghiFile(const string& filename, int IdPhong, int tienPhong, const Vector<string>& name, const Vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const Vector<string>& taikhoan, const Vector<string>& matkhau);
    void ghiLaiFile(const string& filename);
};
#include "FNode.cpp"