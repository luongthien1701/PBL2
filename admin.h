#pragma once
#include "User.h"
#include "FNode.h"
class Admin:public User{
	public:
		Admin(Node* temp);
		void them(FNode& tmp,int IdPhong,string name,string quyen,string SDT,int sodiensau,int sonuocsau,const string& taikhoan,const string& matkhau);
		void capnhatsodien(FNode& tmp,int IdPhong,int sodiensau);
		void capnhatsonuoc(FNode& tmp,int IdPhong,int sonuocsau);
		void remove(FNode& tmp,int IdPhong);
};
#include "admin.cpp"


