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
	void tuChuyenTT();
};
class XacNhan :public TrangThai {
public:
	XacNhan(DonHang* DH) :TrangThai(DH) {}
	void doiTenNguoiNhan();
	void doiSDTNguoiNhan();
	void doiDiaChiNhan();
	void themSanPham();
	void huyBoDH();
	void thongtinTrangThai();
	void tuChuyenTT();
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
	void tuChuyenTT();
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
	void tuChuyenTT();
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
	void tuChuyenTT();
};
#endif // !_TRANGTHAICUTHE_H
