#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class VeMayBay {
    string tenChuyen;
    string ngayBay;
    double giaVe;
public:
    VeMayBay() : tenChuyen(""), ngayBay(""), giaVe(0.0) {}
    VeMayBay(string tc, string nb, double gv) : tenChuyen(tc), ngayBay(nb), giaVe(gv) {}
    ~VeMayBay() {}

    friend istream& operator>>(istream& in, VeMayBay& ve) {
        cout << "Nhap ten chuyen: ";
        in.ignore();
        getline(in, ve.tenChuyen);
        cout << "Nhap ngay bay: ";
        getline(in, ve.ngayBay);
        cout << "Nhap gia ve: ";
        in >> ve.giaVe;
        return in;
    }

    friend ostream& operator<<(ostream& out, const VeMayBay& ve) {
        out << "Ten chuyen: " << ve.tenChuyen << ", Ngay bay: " << ve.ngayBay << ", Gia ve: " << ve.giaVe;
        return out;
    }

    double getGiaVe() const {
        return giaVe;
    }
};

class Nguoi {
    string hoTen;
    string gioiTinh;
    int tuoi;
public:
    Nguoi() : hoTen(""), gioiTinh(""), tuoi(0) {}
    Nguoi(string ht, string gt, int t) : hoTen(ht), gioiTinh(gt), tuoi(t) {}
    virtual ~Nguoi() {}

    friend istream& operator>>(istream& in, Nguoi& nguoi) {
        cout << "Nhap ho ten: ";
        in.ignore();
        getline(in, nguoi.hoTen);
        cout << "Nhap gioi tinh: ";
        getline(in, nguoi.gioiTinh);
        cout << "Nhap tuoi: ";
        in >> nguoi.tuoi;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Nguoi& nguoi) {
        out << "Ho ten: " << nguoi.hoTen << ", Gioi tinh: " << nguoi.gioiTinh << ", Tuoi: " << nguoi.tuoi;
        return out;
    }
};

class HanhKhach : public Nguoi {
    VeMayBay* ve;
    int soLuong;
public:
    HanhKhach() : ve(nullptr), soLuong(0) {}
    HanhKhach(string ht, string gt, int t, int sl) : Nguoi(ht, gt, t), soLuong(sl) {
        ve = new VeMayBay[soLuong];
    }

    ~HanhKhach() {
        delete[] ve;
    }

    friend istream& operator>>(istream& in, HanhKhach& khach) {
        in >> static_cast<Nguoi&>(khach);
        cout << "Nhap so luong ve: ";
        in >> khach.soLuong;
        khach.ve = new VeMayBay[khach.soLuong];
        for (int i = 0; i < khach.soLuong; ++i) {
            cout << "Nhap thong tin ve thu " << i + 1 << ":" << endl;
            in >> khach.ve[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const HanhKhach& khach) {
        out << static_cast<const Nguoi&>(khach) << endl;
        for (int i = 0; i < khach.soLuong; ++i) {
            out << "Thong tin ve thu " << i + 1 << ": " << endl;
            out << khach.ve[i] << endl;
        }
        out << "Tong tien: " << khach.tongTien() << endl;
        out << "\n";
        return out;
    }

    double tongTien() const {
        double sum = 0;
        for (int i = 0; i < soLuong; ++i) {
            sum += ve[i].getGiaVe();
        }
        return sum;
    }
};

bool compareHanhKhach(const HanhKhach& a, const HanhKhach& b) {
    return a.tongTien() > b.tongTien();
}

int main() {
    int n;
    cout << "Nhap so luong hanh khach: ";
    cin >> n;
    vector<HanhKhach> danhSachHanhKhach(n);

    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin hanh khach thu " << i + 1 << ":" << endl;
        cin >> danhSachHanhKhach[i];
    }

    sort(danhSachHanhKhach.begin(), danhSachHanhKhach.end(), compareHanhKhach);

    cout << "Danh sach hanh khach sau khi sap xep theo tong tien giam dan:" << endl;
    for (const auto& khach : danhSachHanhKhach) {
        cout << khach;
    }

    return 0;

}
