#include "DonHang.h"
DonHang::DonHang() {
	this->MaDH = "00001";
	this->DiaChiNhan = "";
	this->SDTNguoiNhan = "";
	this->SoLuongSP = 0;
	this->TenNguoiNhan = "";
	this->trangthai = new KhoiTao(this);
}
DonHang::~DonHang() {
	delete this->trangthai;
}
void DonHang::huyBoDH() {
	this->trangthai->huyBoDH();
}
void DonHang::thongtinTrangThai() {
	this->trangthai->thongtinTrangThai();
}

void DonHang::xuatThongTin() {
	cout << "MaDH: " << this->MaDH << endl;
	cout << "Ten nguoi nhan: " << this->TenNguoiNhan << endl;
	cout << "Dia chi nhan: " << this->DiaChiNhan << endl;
	cout << "SDT nguoi nhan: " << this->SDTNguoiNhan << endl;
	cout << "So luong SP: " << this->SoLuongSP << endl;
	cout << "Gia tien: " << this->tinhGiaTien() << endl;
	this->trangthai->thongtinTrangThai();
}
void DonHang::datTrangThai(TrangThai* tt) {
	delete this->trangthai;
	this->trangthai = tt;
}
int DonHang::tinhGiaTien() {
	return this->SoLuongSP * 100;
}

void DonHang::doiTenNguoiNhan() {
	this->trangthai->doiTenNguoiNhan();
}
void DonHang::doiSDTNguoiNhan() {
	this->trangthai->doiSDTNguoiNhan();
}
void DonHang::doiDiaChiNhan() {
	this->trangthai->doiDiaChiNhan();
}
void DonHang::themSanPham() {
	this->trangthai->themSanPham();
}

string DonHang::layTenNguoiNhan() {
	return this->TenNguoiNhan;
}
string DonHang::laySDTNguoiNhan() {
	return this->SDTNguoiNhan;
}
string DonHang::layDiaChiNhan() {
	return this->DiaChiNhan;
}

int DonHang::laysoSanPham() {
	return this->SoLuongSP;
}

void DonHang::datTenNguoiNhan(string ten) {
	this->TenNguoiNhan = ten;
}
void DonHang::datSDTNguoiNhan(string dthoai) {
	this->SDTNguoiNhan = dthoai;
}
void DonHang::datDiaChiNhan(string dchi) {
	this->DiaChiNhan = dchi;
}
void DonHang::datsoSanPham(int soluong) {
	this->SoLuongSP = soluong;
}

void DonHang::thaoTacThayDoi() {
	while (true) {
		this->xuatThongTin();
		int lc;
		cout << "1-Nhap ten nguoi nhan\n";
		cout << "2-Nhap sdt nguoi nhan\n";
		cout << "3-Nhap dia chi nhan hang\n";
		cout << "4-Nhap so luong san pham muon mua\n";
		cout << "5-Huy bo don hang\n";
		do {
			cout << "Moi nhap lua chon: ";
			cin >> lc;
		} while (lc > 5 || lc < 1);
		switch(lc){
			case 1:
				this->doiTenNguoiNhan();
				break;
			case 2:
				this->doiSDTNguoiNhan();
				break;
			case 3:
				this->doiDiaChiNhan();
				break;
			case 4:
				this->themSanPham();
				break;
			case 5:
				this->huyBoDH();
				break;
		}
		system("pause");
		system("cls");
	}
}
