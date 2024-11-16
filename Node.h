#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Node {
	public:
    int IdPhong;
    string name;
    string quyen;
    string SDT;
    int sodientruoc,sodiensau;
    int sonuoctruoc,sonuocsau;
    string taikhoan;
    string matkhau;
    Node* prev;
    Node* next;
    
	public:
	Node(int IdPhong,string name,string quyen,string SDT,int sodiensau,int sonuocsau,const string& taikhoan,const string& matkhau){
		this->IdPhong=IdPhong;
		this->name=name;
		this->quyen=quyen;
		this->SDT=SDT;
		this->sodientruoc=0;
		this->sodiensau=sodiensau;
		this->sonuoctruoc=0;
		this->sonuocsau=sonuocsau;
		this->taikhoan=taikhoan;
		this->matkhau=matkhau;
		this->prev=NULL;
		this->next=NULL;	
	}	
};

