#include "FNode.h"
using namespace std;
FNode::FNode() {
    this->head = NULL;
    this->end = NULL;
}
FNode::~FNode() {
    Node* temp = head;
    while (temp) {
        Node* deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
}
void FNode::them(int IdPhong, const string& name, const string& quyen, const string& SDT, int sodiensau, int sonuocsau, const string& taikhoan, const string& matkhau) {
    Node* newNode = new Node(IdPhong, name, quyen, SDT, sodiensau, sonuocsau, taikhoan, matkhau);
    if (!head) {
        head = end = newNode;
    } else {
        end->next = newNode;
        newNode->prev = end;
        end = newNode;
    }
}
Node* FNode::Find(int ID) {
    Node* temp = head;
    while (temp) {
        if (temp->IdPhong == ID) {  
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
void FNode::remove(int IdPhong) {
    Node* temp = head;
    while (temp) {
        if (temp->IdPhong == IdPhong) {
            if (temp == head) {
                head = temp->next;
                if (head) {
                    head->prev = NULL;
                }
            } else if (temp == end) {
                end = temp->prev;
                if (end) {
                    end->next = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            return; 
        }
        temp = temp->next;
    }
}
Node* FNode::dangnhap(const string& taikhoan, const string& matkhau) {
    Node* temp = head;
    while (temp) {
        if (temp->taikhoan == taikhoan && temp->matkhau == matkhau) {
            return temp;
        }
        temp = temp->next;
    }
    cout << "Dang nhap khong thanh cong!" << endl;
    return NULL;
}
void FNode::loadfile(const string& filename) {
    ifstream tofile(filename.c_str());
    if (!tofile.is_open()) {
        cout << "Khong the mo file " << filename << "\n";
        return;
    }

    string line;
    while (getline(tofile, line)) {
        stringstream ss(line);
        string tmp;
        int IdPhong, sodien, sonuoc;
        string name, quyen, SDT, taikhoan, matkhau;

        getline(ss, tmp, ',');
        IdPhong = stoi(tmp);
        
        getline(ss, name, ',');
        getline(ss, quyen, ',');
        getline(ss, SDT, ',');

        getline(ss, tmp, ',');
        sodien = stoi(tmp);

        getline(ss, tmp, ',');
        sonuoc = stoi(tmp);

        getline(ss, taikhoan, ',');
        getline(ss, matkhau, ',');

        them(IdPhong, name, quyen, SDT, sodien, sonuoc, taikhoan, matkhau);
    }
    tofile.close();
}
