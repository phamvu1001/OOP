#ifndef _TRANGTHAICUTHE_H
#define _TRANGTHAICUTHE_H
#include "TrangThai.h"
using namespace std;
class KhoiTao :public TrangThai {
public:
	KhoiTao(DonHang* DH);
	void doiTenNguoiNhan();
	void doiSDTNguoiNhan();
	void doiDiaChiNhan();
	void themSanPham();
	void huyBoDH();
	void thongtinTrangThai();
};
class XacNhan:public TrangThai {
public:
	XacNhan(DonHang* DH) :TrangThai(DH) {}
	void doiTenNguoiNhan(){}
	void doiSDTNguoiNhan(){}
	void doiDiaChiNhan(){}
	void themSanPham(){}
	void huyBoDH(){}
	void thongtinTrangThai() {
		cout << "Xac nhan\n";
	}
};
class DangGiao :public TrangThai {
public:
	DangGiao(DonHang* DH) :TrangThai(DH) {}
	void doiTenNguoiNhan();
	void doiSDTNguoiNhan();
	void doiDiaChiNhan();
	void themSanPham();
	void huyBoDH();
	void thongtinTrangThai();

};
class HoanThanh :public TrangThai {
public:
	HoanThanh(DonHang* DH) :TrangThai(DH) {}
	void doiTenNguoiNhan();
	void doiSDTNguoiNhan();
	void doiDiaChiNhan();
	void themSanPham();
	void huyBoDH();
	void thongtinTrangThai();
};
class DaHuyBo :public TrangThai {
public:
	DaHuyBo(DonHang* DH) :TrangThai(DH) {}
	void doiTenNguoiNhan();
	void doiSDTNguoiNhan();
	void doiDiaChiNhan();
	void themSanPham();
	void huyBoDH();
	void thongtinTrangThai();
};
#endif // !_TRANGTHAICUTHE_H
