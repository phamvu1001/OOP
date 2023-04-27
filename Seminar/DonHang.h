#ifndef _DONHANG_H
#define _DONHANG_H
#include <iostream>
#include <string>
#include "TrangThai.h"
#include "TrangThaiCuThe.h"
using namespace std;
class TrangThai;
class DonHang {
	string MaDH;
	int SoLuongSP;
	string TenNguoiNhan;
	string DiaChiNhan;
	string SDTNguoiNhan;
	TrangThai* trangthai;
public:
	DonHang();
	~DonHang();
	void huyBoDH();
	void xuatThongTin();
	void datTrangThai(TrangThai* tt);
	int tinhGiaTien();
	void thongtinTrangThai();

	void doiTenNguoiNhan();
	void doiSDTNguoiNhan();
	void doiDiaChiNhan();
	void themSanPham();

	string layTenNguoiNhan();
	string laySDTNguoiNhan();
	string layDiaChiNhan();
	int laysoSanPham();

	void datTenNguoiNhan(string ten);
	void datSDTNguoiNhan(string dthoai);
	void datDiaChiNhan(string dchi);
	void datsoSanPham(int soluong);

	void thaoTacThayDoi();
};
#endif