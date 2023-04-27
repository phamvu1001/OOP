#include "TrangThaiCuThe.h"
KhoiTao::KhoiTao(DonHang* DH):TrangThai(DH){}
void KhoiTao::doiTenNguoiNhan() {
	cout << "Nhap vao ten nguoi nhan: \n";
	string ten;
	cin.ignore();
	getline(cin, ten, '\n');
	this->dh->datTenNguoiNhan(ten);
	if (this->dh->layDiaChiNhan() != "" && this->dh->laySDTNguoiNhan() != "" && this->dh->laysoSanPham() > 0) {
		this->dh->datTrangThai(new XacNhan(this->dh));
	}
}
void KhoiTao::doiSDTNguoiNhan() {
	cout << "Nhap vao sdt nguoi nhan: \n";
	string sdt;
	cin.ignore();
	getline(cin, sdt, '\n');
	this->dh->datSDTNguoiNhan(sdt);
}
void KhoiTao::doiDiaChiNhan() {
	cout << "Nhap vao dia chi nhan: \n";
	string dchi;
	cin.ignore();
	getline(cin, dchi, '\n');
	this->dh->datDiaChiNhan(dchi);
	if (this->dh->layDiaChiNhan() != "" && this->dh->laySDTNguoiNhan() != "" && this->dh->laysoSanPham() > 0) {
		this->dh->datTrangThai(new XacNhan(this->dh));
	}
}
void KhoiTao::themSanPham() {
	cout << "Nhap vao so luong san pham muon mua: \n";
	int sl;
	cin >> sl;
	this->dh->datsoSanPham(sl);
	if (this->dh->layDiaChiNhan() != "" && this->dh->laySDTNguoiNhan() != "" && this->dh->laysoSanPham() > 0) {
		this->dh->datTrangThai(new XacNhan(this->dh));
	}
}
void KhoiTao::huyBoDH() {
	cout << "Khong the huy bo do don hang chua hoan tat khoi tao\n";
}
void KhoiTao::thongtinTrangThai() {
	cout << "Trang thai KhoiTao\nDon hang can co toi thieu cac thong tin SDT,"
		<<"DIACHI nguoi nhan va SOLUONG SAN PHAM de hoan tat khoi tao\n";
}