#include <iostream>
#include <vector>
#include "Node.h"
#include "FNode.h"
#include "User.h"
#include "Admin.h"
using namespace std;

void showMenu(User* user) {
    if (dynamic_cast<Admin*>(user)) {
        cout << "Menu Admin:\n";
        cout << "1. Thêm phòng\n";
        cout << "2. Cập nhật số điện\n";
        cout << "3. Cập nhật số nước\n";
        cout << "4. Xóa phòng\n";
        cout << "5. Xem thông tin phòng\n";
        cout << "6. Thoát\n";
    } else {
        cout << "Menu User:\n";
        cout << "1. Xem thông tin phòng\n";
        cout << "2. Thoát\n";
    }
}

User* login(FNode& fnode) {
    string taikhoan, matkhau;
    cout << "Nhap tai khoan: ";
    cin >> taikhoan;
    cout << "Nhap mat khau: ";
    cin >> matkhau;

    Node* userNode = fnode.dangnhap(taikhoan, matkhau);
    if (userNode) {
        if (userNode->quyen == "admin") {
            return new Admin(userNode);
        } else {
            return new User(userNode);
        }
    }
    return nullptr;
}

int main() {
    FNode fnode;
    fnode.loadfile("phongtro.txt");
    User* currentUser = nullptr;

    // Đăng nhập
    while (!currentUser) {
        currentUser = login(fnode);
        if (!currentUser) {
            cout << "Dang nhap that bai! Vui long thu lai.\n";
        }
    }

    while (true) {
        showMenu(currentUser);
        int choice;
        cout << "Nhap lua chon: ";
        cin >> choice;

        if (dynamic_cast<Admin*>(currentUser)) {
            Admin* adminUser = dynamic_cast<Admin*>(currentUser);
            switch (choice) {
                case 1: {
                    int IdPhong, tienPhong, sodiensau, sonuocsau;
                    vector<string> name, SDT, taikhoan, matkhau;
                    string quyen, temp;

                    cout << "Nhap IdPhong: ";
                    cin >> IdPhong;
                    cout << "Nhap tien phong: ";
                    cin >> tienPhong;
                    cout << "Nhap quyen: ";
                    cin >> quyen;
                    cout << "Nhap so dien sau: ";
                    cin >> sodiensau;
                    cout << "Nhap so nuoc sau: ";
                    cin >> sonuocsau;

                    cout << "Nhap ten (ket thuc bang '|'): ";
                    while (cin >> temp && temp != "|") {
                        name.push_back(temp);
                    }

                    cout << "Nhap SDT (ket thuc bang '|'): ";
                    while (cin >> temp && temp != "|") {
                        SDT.push_back(temp);
                    }

                    cout << "Nhap tai khoan (ket thuc bang '|'): ";
                    while (cin >> temp && temp != "|") {
                        taikhoan.push_back(temp);
                    }

                    cout << "Nhap mat khau (ket thuc bang '|'): ";
                    while (cin >> temp && temp != "|") {
                        matkhau.push_back(temp);
                    }

                    int tienWifi = 50;
                    int tienRac = 50 * name.size();

                    adminUser->them(fnode, IdPhong, tienPhong, name, quyen, SDT, sodiensau, sonuocsau, tienWifi, tienRac, taikhoan, matkhau);
                    break;
                }
                case 2: {
                    int IdPhong, sodiensau;
                    cout << "Nhap IdPhong va So dien sau: ";
                    cin >> IdPhong >> sodiensau;
                    adminUser->capnhatsodien(fnode, IdPhong, sodiensau);
                    break;
                }
                case 3: {
                    int IdPhong, sonuocsau;
                    cout << "Nhap IdPhong va So nuoc sau: ";
                    cin >> IdPhong >> sonuocsau;
                    adminUser->capnhatsonuoc(fnode, IdPhong, sonuocsau);
                    break;
                }
                case 4: {
                    int IdPhong;
                    cout << "Nhap IdPhong can xoa: ";
                    cin >> IdPhong;
                    adminUser->remove(fnode, IdPhong);
                    break;
                }
                case 5: {
                    int IdPhong;
                    cout << "Nhap IdPhong can xem thong tin: ";
                    cin >> IdPhong;
                    Node* node = fnode.Find(IdPhong);
                    if (node) {
                        Admin tempAdmin(node);
                        tempAdmin.display();
                    } else {
                        cout << "Khong tim thay phong voi IdPhong: " << IdPhong << endl;
                    }
                    break;
                }
                case 6:
                    delete currentUser;
                    return 0;
                default:
                    cout << "Lua chon khong hop le. Vui long thu lai.\n";
                    break;
            }
        } else {
            switch (choice) {
                case 1: {
                    currentUser->display();
                    break;
                }
                case 2:
                    delete currentUser;
                    return 0;
                default:
                    cout << "Lua chon khong hop le. Vui long thu lai.\n";
                    break;
            }
        }
    }

    return 0;
}