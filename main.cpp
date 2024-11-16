#include <iostream>
#include "Node.h"
#include "FNode.h"
#include "User.h"
#include "Admin.h"

void showMenu(User* user) {
    // Hiển thị menu tùy thuộc vào quyền
    if (dynamic_cast<Admin*>(user)) {
        std::cout << "Menu Admin:\n";
        std::cout << "1. Thêm phòng\n";
        std::cout << "2. Cập nhật số điện\n";
        std::cout << "3. Cập nhật số nước\n";
        std::cout << "4. Xóa phòng\n";
        std::cout << "5. Thoát\n";
    } else {
        std::cout << "Menu User:\n";
        std::cout << "1. Xem thông tin phòng\n";
        std::cout << "2. Thoát\n";
    }
}

int main() {
    FNode fnode;
    fnode.loadfile("phongtro.txt"); // Đọc từ file

    std::string taikhoan, matkhau;
    std::cout << "Nhap tai khoan: ";
    std::cin >> taikhoan;
    std::cout << "Nhap mat khau: ";
    std::cin >> matkhau;

    Node* userNode = fnode.dangnhap(taikhoan, matkhau);
    if (!userNode) {
        std::cout << "Dang nhap khong thanh cong!" << std::endl;
        return 1;
    }

    User* user;
    if (userNode->quyen == "admin") {
        user = new Admin(userNode);
    } else {
        user = new User(userNode);
    }

    while (true) {
        showMenu(user);
        int choice;
        std::cin >> choice;

        if (dynamic_cast<Admin*>(user)) {
            Admin* adminUser = dynamic_cast<Admin*>(user); // Chuyển đổi sang Admin

            switch (choice) {
                case 1: {
                    int IdPhong, sodiensau, sonuocsau;
                    std::string name, quyen, SDT, taikhoan, matkhau;
                    std::cout << "Nhap IdPhong, Ten, Quyen, SDT, So dien sau, So nuoc sau, Tai khoan, Mat khau: ";
                    std::cin >> IdPhong >> name >> quyen >> SDT >> sodiensau >> sonuocsau >> taikhoan >> matkhau;
                    adminUser->them(fnode, IdPhong, name, quyen, SDT, sodiensau, sonuocsau, taikhoan, matkhau);
                    break;
                }
                case 2: {
                    int IdPhong, sodiensau;
                    std::cout << "Nhap IdPhong va So dien sau: ";
                    std::cin >> IdPhong >> sodiensau;
                    adminUser->capnhatsodien(fnode, IdPhong, sodiensau);
                    break;
                }
                case 3: {
                    int IdPhong, sonuocsau;
                    std::cout << "Nhap IdPhong va So nuoc sau: ";
                    std::cin >> IdPhong >> sonuocsau;
                    adminUser->capnhatsonuoc(fnode, IdPhong, sonuocsau);
                    break;
                }
                case 4: {
                    int IdPhong;
                    std::cout << "Nhap IdPhong de xoa: ";
                    std::cin >> IdPhong;
                    adminUser->remove(fnode, IdPhong);
                    break;
                }
                case 5:
                    delete user;
                    return 0;
            }
        } else {
            switch (choice) {
                case 1:
                    user->display();
                    break;
                case 2:
                    delete user;
                    return 0;
            }
        }
    }

    delete user; // Giải phóng bộ nhớ
    return 0;
}
