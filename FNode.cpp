#include "FNode.h"
#include "Node.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

FNode::FNode() : head(nullptr), end(nullptr) {}

FNode::~FNode() {
    Node* temp = head;
    while (temp) {
        Node* deleteNode = temp;
        temp = temp->next;
        delete deleteNode;
    }
}

void FNode::them(int IdPhong, int tienPhong, const Vector<string>& name, const Vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const Vector<string>& taikhoan, const Vector<string>& matkhau) {
    Node* newNode = new Node(IdPhong, tienPhong, name, SDT, sodiensau, sonuocsau, tienWifi, tienRac, taikhoan, matkhau);
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

Node* FNode::loginAdmin(const string& taikhoan, const string& matkhau) {
    for (int i = 0; i < adminUsernames.getsize(); ++i) {
        if (adminUsernames[i] == taikhoan && adminPasswords[i] == matkhau) {
            return new Node(0, 0, {}, {}, 0, 0, 0, 0, {}, {});
        }
    }
    return nullptr;
}

Node* FNode::loginUser(const string& taikhoan, const string& matkhau) {
    Node* temp = head;
    while (temp) {
        for (size_t i = 0; i < temp->taikhoan.getsize(); ++i) {
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
    ghiLaiFile("phongtro.txt");
}

void FNode::loadfile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue; // Bỏ qua các dòng trống
        }

        stringstream ss(line);
        int IdPhong, tienPhong, sodiensau, sonuocsau, tienWifi, tienRac;
        string tenNguoi, sdt, taiKhoan, matKhau;
        bool daDongTienPhong, daDongTienDien, daDongTienNuoc, daDongTienWifi, daDongTienRac;

        try {
            getline(ss, line, ',');
            IdPhong = stoi(line);
            getline(ss, line, ',');
            tienPhong = stoi(line);
            getline(ss, tenNguoi, ',');
            getline(ss, sdt, ',');
            getline(ss, line, ',');
            sodiensau = stoi(line);
            getline(ss, line, ',');
            sonuocsau = stoi(line);
            getline(ss, line, ',');
            tienWifi = stoi(line);
            getline(ss, line, ',');
            tienRac = stoi(line);
            getline(ss, line, ',');
            daDongTienPhong = stoi(line);
            getline(ss, line, ',');
            daDongTienDien = stoi(line);
            getline(ss, line, ',');
            daDongTienNuoc = stoi(line);
            getline(ss, line, ',');
            daDongTienWifi = stoi(line);
            getline(ss, line, ',');
            daDongTienRac = stoi(line);
            getline(ss, taiKhoan, ',');
            getline(ss, matKhau, ',');

            Node* existingNode = Find(IdPhong);
            if (existingNode) {
                existingNode->name.push_back(tenNguoi);
                existingNode->SDT.push_back(sdt);
                existingNode->taikhoan.push_back(taiKhoan);
                existingNode->matkhau.push_back(matKhau);
            } else {
                Vector<string> name;
                name.push_back(tenNguoi);
                Vector<string> SDT;
                SDT.push_back(sdt);
                Vector<string> taikhoan;
                taikhoan.push_back(taiKhoan);
                Vector<string> matkhau;
                matkhau.push_back(matKhau);

                them(IdPhong, tienPhong, name, SDT, sodiensau, sonuocsau, tienWifi, tienRac, taikhoan, matkhau);
            }
        } catch (const invalid_argument& e) {
            cerr << "Invalid argument: " << e.what() << " in line: " << line << endl;
        } catch (const out_of_range& e) {
            cerr << "Out of range: " << e.what() << " in line: " << line << endl;
        }
    }

    file.close();
}

void FNode::loadAdminFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue; // Bỏ qua các dòng trống
        }

        stringstream ss(line);
        string taikhoan, matkhau;
        getline(ss, taikhoan, ',');
        getline(ss, matkhau, ',');

        adminUsernames.push_back(taikhoan);
        adminPasswords.push_back(matkhau);
    }

    file.close();
}

void FNode::ghiFile(const string& filename, int IdPhong, int tienPhong, const Vector<string>& name, const Vector<string>& SDT, int sodiensau, int sonuocsau, int tienWifi, int tienRac, const Vector<string>& taikhoan, const Vector<string>& matkhau) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    for (size_t i = 0; i < name.getsize(); ++i) {
        file << IdPhong << "," << tienPhong << "," << name[i] << "," << SDT[i] << "," << sodiensau << "," << sonuocsau << "," << tienWifi << "," << tienRac << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << 0 << "," << taikhoan[i] << "," << matkhau[i] << endl;
    }
    file << endl; // Thêm dòng trống giữa các phòng

    file.close();
}

void FNode::ghiLaiFile(const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    Node* temp = head;
    while (temp) {
        for (size_t i = 0; i < temp->name.getsize(); ++i) {
            file << temp->IdPhong << "," << temp->tienPhong << "," << temp->name[i] << "," << temp->SDT[i] << "," << temp->sodiensau << "," << temp->sonuocsau << "," << temp->tienWifi << "," << temp->tienRac << "," << (temp->daDongTienPhong ? 1 : 0) << "," << (temp->daDongTienDien ? 1 : 0) << "," << (temp->daDongTienNuoc ? 1 : 0) << "," << (temp->daDongTienWifi ? 1 : 0) << "," << (temp->daDongTienRac ? 1 : 0) << endl;
        }
        temp = temp->next;
    }

    file.close();
}