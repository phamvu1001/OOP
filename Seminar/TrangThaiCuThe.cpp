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

DangGiao::DangGiao(DonHang* DH) :TrangThai(DH) {}
void DangGiao::doiTenNguoiNhan() {
	cout << "Nhap vao ten nguoi nhan: \n";
	string ten;
	cin.ignore();
	getline(cin, ten, '\n');
	this->dh->datTenNguoiNhan(ten);
}
void DangGiao::doiSDTNguoiNhan() {
	cout << "Nhap vao sdt nguoi nhan: \n";
	string sdt;
	cin.ignore();
	getline(cin, sdt, '\n');
	this->dh->datSDTNguoiNhan(sdt);
}
void DangGiao::doiDiaChiNhan() {
	cout << "Khong the doi dia chi !!!" << endl; 
}
void DangGiao::themSanPham() {
	cout << "Khong the them san pham , don hang dang duoc giao !!! " << endl; 
}
void DangGiao::huyBoDH() {
	dh.huyBoDH();
}
void DangGiao::thongtinTrangThai() {
	cout << "Trang thai dang giao" << endl; 
}
HoanThanh::HoanThanh(DonHang* DH) :TrangThai(DH) {}
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
	cout << "Don hang da giao thanh cong, khong the huy bo" << endl;
}
void HoanThanh::thongtinTrangThai() {
	cout << "Trang thai: Da hoan thanh " << endl;
}
DaHuyBo::DaHuyBo(DonHang* DH) :TrangThai(DH) {}
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
		<< "moi khach hang co the dat lai don khac"<< endl;
}
void DaHuyBo::huyBoDH() {
	cout << "Don hang da huy bo" 
		<< "moi khach hang co the dat lai don khac" << endl;
}
void DaHuyBo::thongtinTrangThai() {
	cout << "Don hang da huy bo" << endl; 
}


