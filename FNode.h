#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class FNode {
	private:
    Node* head;
    Node* end;
	public:
    FNode();
    void them(int IdPhong, const string& name, const string& quyen,const string& SDT, int sodiensau, int sonuocsau,const string& taikhoan,const string& matkhau);
    Node* Find(int ID);
    Node* dangnhap(const string& taikhoan,const string& matkhau);
    ~FNode();
    void remove(int i);
    void loadfile(const string& filename);
};

