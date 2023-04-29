#include "TrangThaiCuThe.h"
KhoiTao::KhoiTao(DonHang* DH):TrangThai(DH){}
void KhoiTao::doiTenNguoiNhan() {
	cout << "Nhap vao ten nguoi nhan: \n";
	string ten;
	cin.ignore();
	getline(cin, ten, '\n');
	this->dh->datTenNguoiNhan(ten);
}
void KhoiTao::doiSDTNguoiNhan() {
	cout << "Nhap vao sdt nguoi nhan: \n";
	string sdt;
	cin.ignore();
	getline(cin, sdt, '\n');
	this->dh->datSDTNguoiNhan(sdt);
	this->dh->tuChuyenTT();
}
void KhoiTao::doiDiaChiNhan() {
	cout << "Nhap vao dia chi nhan: \n";
	string dchi;
	cin.ignore();
	getline(cin, dchi, '\n');
	this->dh->datDiaChiNhan(dchi);
	this->dh->tuChuyenTT();
}
void KhoiTao::themSanPham() {
	cout << "Nhap vao so luong san pham muon mua: \n";
	int sl;
	cin >> sl;
	this->dh->datsoSanPham(sl);
	this->dh->tuChuyenTT();
}
void KhoiTao::huyBoDH() {
	cout << "Khong the huy bo do don hang chua hoan tat khoi tao\n";
}
void KhoiTao::thongtinTrangThai() {
	cout << "Trang thai KhoiTao\nDon hang can co toi thieu cac thong tin SDT,"
		<<"DIACHI nguoi nhan va SOLUONG SAN PHAM de hoan tat khoi tao\n";
}
void KhoiTao::tuChuyenTT(){
	if (this->dh->layDiaChiNhan() != "" && this->dh->laySDTNguoiNhan() != "" && this->dh->laysoSanPham() > 0) {
		this->dh->datTrangThai(new XacNhan(this->dh));
	}
}

void XacNhan::doiTenNguoiNhan() {
	cout << "Nhap vao ten nguoi nhan: \n";
	string ten;
	cin.ignore();
	getline(cin, ten, '\n');
	this->dh->datTenNguoiNhan(ten);
}
void XacNhan::doiSDTNguoiNhan() {
	cout << "Nhap vao sdt nguoi nhan: \n";
	string sdt;
	cin.ignore();
	getline(cin, sdt, '\n');
	this->dh->datSDTNguoiNhan(sdt);
}
void XacNhan::doiDiaChiNhan() {
	cout << "Nhap vao dia chi nhan: \n";
	string dchi;
	cin.ignore();
	getline(cin, dchi, '\n');
	this->dh->datDiaChiNhan(dchi);
}
void XacNhan::themSanPham() {
	cout << "Nhap vao so luong san pham muon mua: \n";
	int sl;
	cin >> sl;
	this->dh->datsoSanPham(sl);
}
void XacNhan::huyBoDH() {
	this->dh->datTrangThai(new DaHuyBo(this->dh));
}
void XacNhan::thongtinTrangThai() {
	cout << "Trang thai: Xac nhan" << endl;
}
void XacNhan::tuChuyenTT() {
	this->dh->datTrangThai(new DangGiao(this->dh));
}


void DangGiao::doiTenNguoiNhan() {
	cout << "Khong the thay doi ten nguoi nhan\n";
}
void DangGiao::doiSDTNguoiNhan() {
	cout << "Khong the thay doi sdt nguoi nhan\n";
}
void DangGiao::doiDiaChiNhan() {
	cout << "Khong the doi dia chi !!!" << endl;
}
void DangGiao::themSanPham() {
	cout << "Khong the them san pham , don hang dang duoc giao !!! " << endl;
}
void DangGiao::huyBoDH() {
	cout << "Khong the huy bo don hang!\n";
}
void DangGiao::thongtinTrangThai() {
	cout << "Trang thai: Dang giao" << endl;
}
void DangGiao::tuChuyenTT() {
	cout << "Dang giao don hang......\n";
	Sleep(500);
	this->dh->datTrangThai(new HoanThanh(this->dh));
	cout << "Giao thanh cong! Don hang da toi\n";
}


void HoanThanh::doiTenNguoiNhan() {
	cout << "Don hang da giao thanh cong" << endl;
}
void HoanThanh::doiSDTNguoiNhan() {
	cout << "Don hang da giao thanh cong" << endl;
}
void HoanThanh::doiDiaChiNhan() {
	cout << "Don hang da giao thanh cong" << endl;
}
void HoanThanh::themSanPham() {
	cout << "Don hang da giao thanh cong" << endl;
}
void HoanThanh::huyBoDH() {
	this->dh->datTrangThai(new DaHuyBo(this->dh));
}
void HoanThanh::thongtinTrangThai() {
	cout << "Trang thai: Da hoan thanh " << endl;
}
void HoanThanh::tuChuyenTT() {}


void DaHuyBo::doiTenNguoiNhan() {
	cout << "Don hang da huy bo" << endl
		<< "moi khach hang co the dat lai don khac" << endl;
}
void DaHuyBo::doiSDTNguoiNhan() {
	cout << "Don hang da huy bo"
		<< "moi khach hang co the dat lai don khac" << endl;
}
void DaHuyBo::doiDiaChiNhan() {
	cout << "Don hang da huy bo"
		<< "moi khach hang co the dat lai don khac" << endl;
}
void DaHuyBo::themSanPham() {
	cout << "Don hang da huy bo"
		<< "moi khach hang co the dat lai don khac" << endl;
}
void DaHuyBo::huyBoDH() {
	cout << "Don hang da huy bo"
		<< "moi khach hang co the dat lai don khac" << endl;
}
void DaHuyBo::thongtinTrangThai() {
	cout << "Trang thai: Da Huy Bo" << endl;
}
void DaHuyBo::tuChuyenTT() {}