#ifndef _TRANGTHAI_H
#define _TRANGTHAI_H
#include<iostream>
#include "DonHang.h"
class DonHang;
class TrangThai {
protected:
	DonHang* dh;
public:
	TrangThai(DonHang* don) {
		this->dh = don;
	}
	virtual void doiTenNguoiNhan()=0;
	virtual void doiSDTNguoiNhan()=0;
	virtual void doiDiaChiNhan()=0;
	virtual void themSanPham()=0;
	virtual void huyBoDH()=0;
	virtual void thongtinTrangThai() = 0;
};
#endif
