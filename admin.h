#pragma once
#include "User.h"
#include "FNode.h"
#include "vector.h"
#include <fstream>
using namespace std;

class Admin : public User {
public:
    Admin(Node* temp);
    void them(FNode& temp, int IdPhong, const vector<string>& name, string quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, const vector<string>& taikhoan, const vector<string>& matkhau);
    void capnhatsodien(FNode& temp, int IdPhong, int sodiensau);
    void capnhatsonuoc(FNode& temp, int IdPhong, int sonuocsau);
    void remove(FNode& temp, int IdPhong);
};
#include "admin.cpp"


