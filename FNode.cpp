#include "FNode.h"
#include <vector>

FNode::FNode() : head(nullptr), end(nullptr) {}

FNode::~FNode() {
    Node* temp = head;
    while (temp) {
        Node* deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
}

void FNode::them(int IdPhong, const vector<string>& name, const string& quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, const vector<string>& taikhoan, const vector<string>& matkhau) {
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
    return nullptr;
}

Node* FNode::dangnhap(const string& taikhoan, const string& matkhau) {
    Node* temp = head;
    while (temp) {
        for (int i = 0; i < temp->taikhoan.size(); ++i) {
            if (temp->taikhoan[i] == taikhoan && temp->matkhau[i] == matkhau) {
                return temp;
            }
        }
        temp = temp->next;
    }
    return nullptr;
}

void FNode::remove(int IdPhong) {
    Node* temp = Find(IdPhong);
    if (temp) {
        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            end = temp->prev;
        }
        delete temp;
    }
}

void FNode::loadfile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int IdPhong, sodiensau, sonuocsau;
        string tenNguoi, quyen, sdt, taiKhoan, matKhau;

        getline(ss, line, ',');
        IdPhong = stoi(line);
        getline(ss, tenNguoi, ',');
        getline(ss, quyen, ',');
        getline(ss, sdt, ',');
        getline(ss, line, ',');
        sodiensau = stoi(line);
        getline(ss, line, ',');
        sonuocsau = stoi(line);
        getline(ss, taiKhoan, ',');
        getline(ss, matKhau, ',');

        vector<string> name = {tenNguoi};
        vector<string> SDT = {sdt};
        vector<string> taikhoan = {taiKhoan};
        vector<string> matkhau = {matKhau};

        them(IdPhong, name, quyen, SDT, sodiensau, sonuocsau, taikhoan, matkhau);
    }

    file.close();
}
void FNode::ghiFile(const string& filename, int IdPhong, const vector<string>& name, const string& quyen, const vector<string>& SDT, int sodiensau, int sonuocsau, const vector<string>& taikhoan, const vector<string>& matkhau) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }
    file<<endl;
    for (size_t i = 0; i < name.size(); ++i) {
        file << IdPhong << "," << name[i] << "," << quyen << "," << SDT[i] << "," << sodiensau << "," << sonuocsau << "," << taikhoan[i] << "," << matkhau[i] << endl;
    }

    file.close();
}