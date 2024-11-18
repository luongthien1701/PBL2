#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Node.h"
using namespace std;

class FNode {
private:
    Node* head;
    Node* end;
public:
    FNode();
    void them(int IdPhong, int tienPhong, const vector<string>& name, const string& quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const vector<string>& taikhoan, const vector<string>& matkhau);
    Node* Find(int ID);
    Node* dangnhap(const string& taikhoan, const string& matkhau);
    ~FNode();
    void remove(int IdPhong);
    void loadfile(const string& filename);
    void ghiFile(const string& filename, int IdPhong, int tienPhong, const vector<string>& name, const string& quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const vector<string>& taikhoan, const vector<string>& matkhau);
    void ghiLaiFile(const string& filename);
};
#include "FNode.cpp"