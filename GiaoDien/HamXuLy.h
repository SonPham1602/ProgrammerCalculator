#pragma once
#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include "stdafx.h"
#include <fstream>
using namespace std;
namespace HamXuLy
{
	struct QInt
	{
		int data[4];
	};
	void XoaCacSoThua(string &a) // xóa các số 0 thừa ở đầu chuỗi
	{
		if (a[0] != '-')
		{
			for (int i = 0; i < a.length() - 1; i++)
			{
				if (a[i] == '0')
				{
					if (a[i + 1] == '0')
					{
						a.erase(i, 1);
						i--;
					}
					else
					{
						a.erase(i, 1);
						break;
					}
				}
				else
					break;
			}
		}
		else
		{
			for (int i = 1; i < a.length() - 1; i++)
			{
				if (a[i] == '0')
				{
					if (a[i + 1] == '0')
					{
						a.erase(i, 1);
						i--;
					}
					else
					{
						a.erase(i, 1);
						break;
					}
				}
				else
					break;
			}
		}
	}
	bool getBit(int x, int i) // lấy giá trị bit tại vị trí i
	{
		return (x >> i) & 1;
	}
	void setBit(int &x, int i) // bật bit 1 tại vị trí i
	{
		x = x | (1 << i);
	}
	void clearBit(int &x, int i) // gán giá trị 0 tại bit thứ i
	{
		x = x & !(1 << i);
	}
	void DaoBit(int &x, int i) // đảo bit của x tại vị trí i
	{
		x = x ^ (1 << i);
	}
	void Scan(QInt &a, string s)
	{

		a.data[0] = a.data[1] = a.data[2] = a.data[3] = 0;
		if (s.length() > 128)
			s = s.substr(s.length() - 128, 128);
		else
			s.insert(s.begin(), 128 - s.length(), '0');
		for (int i = 0; i < 128; i++)
		{
			if (s[i] == '1')
			{
				setBit(a.data[i / 32], 32 - i % 32 - 1);
			}
		}
	}
	string Print(QInt a)
	{
		string kq;
		for (int i = 0; i < 128; i++)
		{
			if (getBit(a.data[i / 32], 32 - i % 32 - 1)==true)
			{
				kq.push_back('1');
			}
			else
			{
				kq.push_back('0');
			}
			
		}
		XoaCacSoThua(kq);
		return kq;
	}
	string QInttoString(QInt a)
	{
		int vt;
		string KQ = "";
		for (int i = 0; i < 128; i++)
		{
			if (getBit(a.data[i / 32], 32 - i % 32 - 1) == 1)
			{
				vt = i;
				break;
			}
		}
		for (int i = vt; i < 128; i++)
		{
			if (getBit(a.data[i / 32], 32 - i % 32 - 1) == 1)
			{
				KQ += "1";
			}
			else
			{
				KQ += "0";
			}
		}
		return KQ;
	}
	string QInttoStringForPos(QInt a, int begin, int end)
	{
		string KQ = "";
		for (int i = begin; i <= end; i++)
		{
			if (getBit(a.data[i / 32], 32 - i % 32 - 1) == 1)
			{
				KQ += "1";
			}
			else
			{
				KQ += "0";
			}
		}
		return KQ;
	}
	
	string BinToHex(QInt a) // đổi từ nhị phân sang 16
	{
		string s;
		string KetQua;
		for (int i = 0; i < 128; i++)
		{
			if (getBit(a.data[i / 32], 32 - i % 32 - 1) == 1)
				s = s + "1";
			else
				s = s + "0";
			if (s.length() == 4)
			{
				if (s == "0000")
					KetQua += "0";
				else if (s == "0001")
					KetQua += "1";
				else if (s == "0010")
					KetQua += "2";
				else if (s == "0011")
					KetQua += "3";
				else if (s == "0100")
					KetQua += "4";
				else if (s == "0101")
					KetQua += "5";
				else if (s == "0110")
					KetQua += "6";
				else if (s == "0111")
					KetQua += "7";
				else if (s == "1000")
					KetQua += "8";
				else if (s == "1001")
					KetQua += "9";
				else if (s == "1010")
					KetQua += "A";
				else if (s == "1011")
					KetQua += "B";
				else if (s == "1100")
					KetQua += "C";
				else if (s == "1101")
					KetQua += "D";
				else if (s == "1110")
					KetQua += "E";
				else if (s == "1111")
					KetQua += "F";
				s = "";
			}
		}
		//xóa các số 0 thừa ở kết quả
		XoaCacSoThua(KetQua);
		return KetQua;
	}
	QInt HexToBin(string s) // đổi từ 16 sang nhị phân
	{
		QInt KetQua;
		string ChuoiNhiPhan;
		int n = s.length();
		for (int i = 0; i < n; i++)
		{
			switch (s[i])
			{
			case '0':
				ChuoiNhiPhan += "0000";
				break;
			case '1':
				ChuoiNhiPhan += "0001";
				break;
			case '2':
				ChuoiNhiPhan += "0010";
				break;
			case '3':
				ChuoiNhiPhan += "0011";
				break;
			case '4':
				ChuoiNhiPhan += "0100";
				break;
			case '5':
				ChuoiNhiPhan += "0101";
				break;
			case '6':
				ChuoiNhiPhan += "0110";
				break;
			case '7':
				ChuoiNhiPhan += "0111";
				break;
			case '8':
				ChuoiNhiPhan += "1000";
				break;
			case '9':
				ChuoiNhiPhan += "1001";
				break;
			case 'A':
				ChuoiNhiPhan += "1010";
				break;
			case 'B':
				ChuoiNhiPhan += "1011";
				break;
			case 'C':
				ChuoiNhiPhan += "1100";
				break;
			case 'D':
				ChuoiNhiPhan += "1101";
				break;
			case 'E':
				ChuoiNhiPhan += "1110";
				break;
			case 'F':
				ChuoiNhiPhan += "1111";
				break;
			default:
				break;
			}
		}
		Scan(KetQua, ChuoiNhiPhan);
		return KetQua;
	}
	bool CongHaiBit(bool &Remember, bool a, bool b)
	{
		bool KetQua;
		KetQua = a^b;
		if (Remember == 1)
		{
			if (KetQua == 0)
			{
				KetQua = 1;
				Remember = 0;
			}
			else
			{
				KetQua = 0;
				Remember = 1;
			}

		}
		if (a == 1 && b == 1)
			Remember = 1;
		return KetQua;
	}
	QInt operator+(QInt a, QInt b) // cộng hai số nhị phân
	{
		QInt c;
		c.data[0] = c.data[1] = c.data[2] = c.data[3] = 0;
		bool Remember = 0;
		int temp;
		for (int i = 127; i >= 0; i--)
		{
			temp = CongHaiBit(Remember, getBit(a.data[i / 32], 32 - i % 32 - 1), getBit(b.data[i / 32], 32 - i % 32 - 1));
			if (temp == 1)
			{
				setBit(c.data[i / 32], 32 - i % 32 - 1);
			}
		}
		return c;
	}
	QInt LayBuHai(QInt a)
	{
		for (int i = 0; i < 128; i++)
		{
			DaoBit(a.data[i / 32], i%32); // số bù 1
		}
		QInt temp;
		temp.data[0] = temp.data[1] = temp.data[2] = 0;
		temp.data[3] = 1;
		a = a + temp; // số bù 1 cộng cho 1 là số bù 2
		return a;
	}
	QInt operator-(QInt a, QInt b) // trừ hai số nhị phân
	{
		return a + LayBuHai(b);
	}
	QInt operator&(QInt a, QInt b) // AND hai chuỗi bit
	{
		QInt KetQua;
		KetQua.data[0] = a.data[0] & b.data[0];
		KetQua.data[1] = a.data[1] & b.data[1];
		KetQua.data[2] = a.data[2] & b.data[2];
		KetQua.data[3] = a.data[3] & b.data[3];
		return KetQua;
	}
	QInt operator|(QInt a, QInt b) //OR hai chuỗi bit
	{
		QInt KetQua;
		KetQua.data[0] = a.data[0] | b.data[0];
		KetQua.data[1] = a.data[1] | b.data[1];
		KetQua.data[2] = a.data[2] | b.data[2];
		KetQua.data[3] = a.data[3] | b.data[3];
		return KetQua;
	}
	QInt operator^(QInt a, QInt b) // XOR hai chuỗi bit
	{
		QInt KetQua;
		KetQua.data[0] = a.data[0] ^ b.data[0];
		KetQua.data[1] = a.data[1] ^ b.data[1];
		KetQua.data[2] = a.data[2] ^ b.data[2];
		KetQua.data[3] = a.data[3] ^ b.data[3];
		return KetQua;
	}
	QInt operator~(QInt a) // Phủ định một chuỗi bit 
	{
		QInt KetQua;
		KetQua.data[0] = ~a.data[0];
		KetQua.data[1] = ~a.data[1];
		KetQua.data[2] = ~a.data[2];
		KetQua.data[3] = ~a.data[3];
		return KetQua;
	}

	char TruHaiChuSo(char a, char b, int& Remember)
	{
		int temp = 10 + (a - 48) - (b - 48) - Remember;
		Remember = 1 - temp / 10;
		return (temp % 10 + 48);
	}
	string TruHaiChuoiSoThapPhan(string a, string b, string &KetQua)
	{
		int n, m;
		int Remember = 0;
		char temp;
		KetQua = "";
		XoaCacSoThua(a);
		XoaCacSoThua(b);
		n = a.length();
		m = b.length();
		for (int i = m - 1; i >= 0; i--)
		{
			temp = TruHaiChuSo(a[n - 1], b[i], Remember);
			KetQua.insert(0, 1, temp);
			n--;
		}
		n = a.length();
		for (int i = n - m - 1; i >= 0; i--)
		{
			temp = TruHaiChuSo(a[i], '0', Remember);
			KetQua.insert(0, 1, temp);
		}
		XoaCacSoThua(KetQua);
		return KetQua;
	}
	int SoSanhHaiSo(string a, string b) // so sánh hai chuỗi số thập phân, nếu a> b trả về 1, bằng trả về 0, nhỏ hơn trả về -1
	{
		XoaCacSoThua(a);
		XoaCacSoThua(b);
		int n = a.length();
		int m = b.length();
		if (n > m)
			return 1;
		if (n < m)
			return -1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] < b[i])
				return -1;
			else if (a[i] > b[i])
				return 1;
		}
		return 0;
	}
	string ChiaHaiChuoiSoThapPhan(string a, string b, string& KetQua, string& Du)
	{
		int n = a.length();
		int m = b.length();
		int i = b.length();
		string p = a.substr(0, i);

		Du = "";
		KetQua = "";
		while (i - 1<n)
		{
			KetQua += '0';
			while (SoSanhHaiSo(p, b) >= 0)
			{
				KetQua[KetQua.length() - 1]++;
				TruHaiChuoiSoThapPhan(p, b, Du);
				p = Du;
			}
			Du = p;
			i++;
			if (i - 1 < n)
				p += a[i - 1];
		}
		XoaCacSoThua(Du);
		XoaCacSoThua(KetQua);
		return KetQua;
	}


	QInt DecToBin(string s)
	{
		bool CheckDauAm = false;
		string temp;
		QInt KetQua;
		string Thuong; // Thương
		string Du; // Dư
		stack<string> StackBin;
		int dem = 0;
		if (s[0] == '-')
		{
			s.erase(0, 1);
			CheckDauAm = true;
		}
		while (s != "0")
		{
			ChiaHaiChuoiSoThapPhan(s, "2", Thuong, Du);
			StackBin.push(Du);
			s = Thuong;
			XoaCacSoThua(s);
			dem++;
		}
		while (!StackBin.empty())
		{
			temp += StackBin.top();
			StackBin.pop();
		}
		Scan(KetQua, temp);
		if (CheckDauAm == true)
			return LayBuHai(KetQua);
		return KetQua;
	}
	char CongHaiChuSo(char a, char b, int& Remember)
	{
		int temp = (a - 48) + (b - 48) + Remember;
		Remember = temp / 10;
		return (temp % 10 + 48);
	}
	string CongHaiChuoiSoThapPhan(string a, string b, string& KetQua)
	{
		int n, m;
		int pos;
		int Remember = 0;
		char temp;
		KetQua = "";
		XoaCacSoThua(a);
		XoaCacSoThua(b);
		n = a.length();
		m = b.length();
		for (int i = m - 1; i >= 0; i--)
		{
			temp = CongHaiChuSo(a[n - 1], b[i], Remember);
			KetQua.insert(0, 1, temp);
			n--;
			if (n == 0)
				break;
		}
		n = a.length();
		m = b.length();
		if (n > m)
		{
			pos = n - m - 1;
			for (int i = pos; i >= 0; i--)
			{
				temp = CongHaiChuSo(a[i], '0', Remember);
				KetQua.insert(0, 1, temp);
			}
			KetQua.insert(0, 1, Remember + 48);
		}
		else if (n < m)
		{
			pos = m - n - 1;
			for (int i = pos; i >= 0; i--)
			{
				temp = CongHaiChuSo(b[i], '0', Remember);
				KetQua.insert(0, 1, temp);
			}
			KetQua.insert(0, 1, Remember + 48);
		}
		else
			KetQua.insert(0, 1, Remember + 48);
		XoaCacSoThua(KetQua);
		return KetQua;
	}
	string DecToHex(string s) // 10 sang 16
	{
		QInt a = DecToBin(s);
		return BinToHex(a);
	}
	string BinaryToStringBinary(QInt a) // data[4] sang chuỗi nhị nhân
	{
		string ChuoiNhiPhan;
		for (int i = 0; i < 128; i++)
		{
			if (getBit(a.data[i / 32], 32 - i % 32 - 1) == 1)
				ChuoiNhiPhan = ChuoiNhiPhan + "1";
			else
				ChuoiNhiPhan = ChuoiNhiPhan + "0";
		}
		return ChuoiNhiPhan;
	}
	string BinToDec(QInt a) // 2 sang 10
	{
		string KetQua = "0";
		string Bufffer[128];
		string temp;
		string ChuoiNhiPhan;
		Bufffer[0] = "1";
		for (int i = 1; i < 128; i++)
			Bufffer[i] = CongHaiChuoiSoThapPhan(Bufffer[i - 1], Bufffer[i - 1], temp);
		if (getBit(a.data[0], 31) == 0)
		{
			ChuoiNhiPhan = BinaryToStringBinary(a);
			for (int i = 0; i < 128; i++)
			{
				if (ChuoiNhiPhan[i] == '1')
				{
					CongHaiChuoiSoThapPhan(KetQua, Bufffer[127 - i], temp);
					KetQua = temp;
				}
			}
		}
		else
		{
			ChuoiNhiPhan = BinaryToStringBinary(LayBuHai(a));
			for (int i = 0; i < 128; i++)
			{
				if (ChuoiNhiPhan[i] == '1')
				{
					CongHaiChuoiSoThapPhan(KetQua, Bufffer[127-i], temp);
					KetQua = temp;
				}
			}
			KetQua.insert(0, 1, '-');
		}
		return KetQua;
	}
	string HexToDex(string s) // 16 sang 10
	{
		QInt a = HexToBin(s); //16 sang 2
		return BinToDec(a); // 2 sang 10
	}

	QInt operator >> (QInt a, int k) // Hàm dịch phải k bit
	{
		if (k>=128)
			return (DecToBin("0"));
		string str=BinaryToStringBinary(a);
		string temp = str;
		temp.erase(temp.length() - k);
		if (temp[0] == '0') {
			temp.insert(0, k, '0');
		}
		else
			temp.insert(0, k, '1');
		QInt KQ;
		Scan(KQ, temp);
		return KQ;
	}

	QInt operator << (QInt a, int k) // Hàm dịch trái k bit
	{
		if (k>=128)
			return (DecToBin("0"));
		string str=BinaryToStringBinary(a);
		string temp = str;
		temp.erase(0, k);
		temp.insert(temp.length(), k, '0');
		QInt KQ;
		Scan(KQ, temp);
		return KQ;
	}
	string shift_right(string str, int k){
		string temp = str;
		temp.erase(temp.length() - k);
		if (temp[0] == '0') {
			temp.insert(0, k, '0');
		}
		else
			temp.insert(0, k, '1');
		return temp;
	}
	QInt operator * (QInt M, QInt Q)
	{
		int check = 0;
		string m_ = BinToDec(M);
		string q_ = BinToDec(Q);
		if (m_[0] == '-' && q_[0] == '-')
		{
			M = LayBuHai(M);
			Q = LayBuHai(Q);
		}
		else if (m_[0] == '-')
		{
			M = LayBuHai(M);
			check = 1;
		}
		else if (q_[0] == '-')
		{
			Q = LayBuHai(Q);
			check = 1;
		}

		string shift_temp;
		int n1;
		int k, temp;
		string A = "";
		string C = "0";
		string shift = "";
		for (int i = 0; i < 128; i++)
		{
			if (getBit(Q.data[i / 32], 32 - i % 32 - 1) == 1)
			{
				k = 128 - i;
				break;
			}
		}
		for (int i = 0; i < 128; i++)
		{
			if (getBit(M.data[i / 32], 32 - i % 32 - 1) == 1)
			{
				temp = 128 - i;
				break;
			}
		}
		int q1, m1;
		string q = QInttoString(Q);
		string m = QInttoString(M);
		q1 = q.length();
		m1 = m.length();
		if (k< temp)
			k = temp;// cập nhập số bit 
		for (int i = 0; i<k; i++)
			A += "0"; // khởi tạo A bằng k bit 0
		n1 = A.length();
		int count = k;
		while (k>0)
		{
			if (getBit(Q.data[127 / 32], 32 - 127 % 32 - 1) == 1)
			{
				QInt A_temp;
				Scan(A_temp, A);
				A_temp = M + A_temp;
				A = QInttoString(A_temp);
				if (A.length() < count)
				{
					A.insert(0, count - A.length(), '0');
				}
			}
			string Q_temp = QInttoString(Q);
			if (Q_temp.length()<count) {
				Q_temp.insert(0, count - Q_temp.length(), '0');
			}
			shift = C + A + Q_temp;
			shift_temp = shift_right(shift, 1);
			if (shift_temp.length() > 2 * count + 1) {
				shift_temp.erase(0, 1);
			}
			A = shift_temp.substr(1, count);
			Q_temp = shift_temp.substr(count + 1, count);
			Scan(Q, Q_temp);
			C = shift_temp[0];
			k--;
			if (k == 1)
			{
				shift_temp = shift_temp.erase(0, 1);
			}
		}
		if (shift_temp.length() > 128)
			return (DecToBin("-1"));
		QInt KQ;
		Scan(KQ, shift_temp);
		if (check == 1) {
			KQ = LayBuHai(KQ);
		}
		return KQ;
	}
	QInt operator/(QInt a, QInt b)// hàm operator phép chia 2 Qnit
	{
		QInt KQ;
		QInt temp1;
		string A;
		bool CheckDauAm_1 = false;
		bool CheckDauAm_2 = false;
		A.insert(0, 128, '0');
		int k = 128;
		if (getBit(a.data[0], 31) == 1)
		{
			a=LayBuHai(a);
			CheckDauAm_1 = true;
		}
		if (getBit(b.data[0], 31) == 1)
		{
			b=LayBuHai(b);
			CheckDauAm_2 = true;
		}
		string Q = BinaryToStringBinary(a);
		while (k > 0)
		{
			for (int i = 0; i < A.length() - 1; i++)
				A[i] = A[i + 1];
			A[A.length() - 1] = Q[0];
			Q.erase(0, 1);
			Q = Q + '0';
			Scan(temp1, A);
			temp1 = temp1 - b;
			if (getBit(temp1.data[0], 31) == 1)
			{
				Q[Q.length() - 1] = '0';
				temp1 = temp1 + b;
			}
			else
				Q[Q.length() - 1] = '1';
			A = BinaryToStringBinary(temp1);
			k--;
		}
		Scan(KQ, Q);
		if (CheckDauAm_1==true)
		{
			if (CheckDauAm_2==false)
				return LayBuHai(KQ);
			else
				return KQ;
		}
		if (CheckDauAm_2==true)
		{
			if (CheckDauAm_1==false)
				return LayBuHai(KQ);
			else
				return KQ;
		}
		return KQ;
	}
	int SoSanhChuoi(string str1,string str2)// Hàm tìm chuỗi str1 trong chuỗi str2
		//str1 là chuỗi cha,srt2 là chuỗi con
		//trả về -1 nếu ko thấy, trả về vị trí bắt đầu cửa str2 trong str1 nếu tìm thấy
	{
		int j=0;
		for(int i=0;i<str1.length();i++)
		{
			if(str1[i]!=str2[j])
			{
				j=0;
			}
			else
				j++;
			if(j==str2.length())
			{
				return i;
			}
		}
		return -1;
	}
	string XoaChuoi(string str,int k, int n)// hàm xóa string từ vị trí k , n ký tự
		//k là vị trí bắt đầu xóa
		//m là số ký tự cần xóa
	{
		string resultString;
		resultString=str;
		resultString.erase(k,n);
		return resultString;
	}// str la chuoi, k la vi tri can xoa, n la so luong ky tu can xoa
	string CopyChuoi(string str,int s,int e)// hàm copy string từ vị trí s và e
	{
		string kq;
		for(int i=s;i<e;i++)
		{
			kq.push_back(str[i]);
		}
		return kq;
	}
	string XuLyTinhToan(string str)// hàm xử lý câu lệnh trong file txt
		//str là câu lệnh trong file
	{
		string tempString;
		if(SoSanhChuoi(str,"2 10 ")!=-1)
		{
			tempString=XoaChuoi(str,0,5);
			QInt qTemp;
			Scan(qTemp,tempString);
			return BinToDec(qTemp) ;
		}
		else if(SoSanhChuoi(str,"10 2 ")!=-1)
		{
			tempString=XoaChuoi(str,0,5);
			return Print(DecToBin(tempString));
		}
		else if(SoSanhChuoi(str,"10 16 ")!=-1)
		{
			tempString=XoaChuoi(str,0,6);
			return DecToHex(tempString);
		}
		else if(SoSanhChuoi(str,"16 10 ")!=-1)
		{
			tempString=XoaChuoi(str,0,6);
			return HexToDex(tempString);
		}
		else if(SoSanhChuoi(str,"2 16 ")!=-1)
		{
			tempString=XoaChuoi(str,0,5);
			QInt temp;
			Scan(temp,tempString);
			return BinToHex(temp);
		}
		else if(SoSanhChuoi(str,"16 2 ")!=-1)
		{
			tempString=XoaChuoi(str,0,5);
			return Print(HexToBin(tempString));
		}
		else if(str[0]=='2' && str[1]==' ')
		{
			QInt temp1Qnit,temp2Qnit,kq;
			tempString=XoaChuoi(str,0,2);
			if(SoSanhChuoi(tempString," + ")!=-1)
			{
				int n=SoSanhChuoi(tempString," + ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-2));
				Scan(temp2Qnit,CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit+temp2Qnit;
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," - ")!=-1)
			{
				int n=SoSanhChuoi(tempString," - ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-2));
				Scan(temp2Qnit,CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit-temp2Qnit;
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," * ")!=-1)
			{
				int n=SoSanhChuoi(tempString," * ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-2));
				Scan(temp2Qnit,CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit*temp2Qnit;
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," / ")!=-1)
			{
				int n=SoSanhChuoi(tempString," / ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-2));
				Scan(temp2Qnit,CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit/temp2Qnit;
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," << ")!=-1)
			{
				QInt temp;
				int n=SoSanhChuoi(tempString," << ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-3));
				string number=CopyChuoi(tempString,n+1,tempString.length());
				Scan(temp,number);
				kq=temp1Qnit<<stoi(BinToDec(temp));
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," >> ")!=-1)
			{
				QInt temp;
				int n=SoSanhChuoi(tempString," >> ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-3));
				string number=CopyChuoi(tempString,n+1,tempString.length());
				Scan(temp,number);
				kq=temp1Qnit>>stoi(BinToDec(temp));
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," & ")!=-1)
			{
				int n=SoSanhChuoi(tempString," & ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-2));
				Scan(temp2Qnit,CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit&temp2Qnit;
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," | ")!=-1)
			{
				int n=SoSanhChuoi(tempString," | ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-2));
				Scan(temp2Qnit,CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit|temp2Qnit;
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," ~")!=-1)
			{
				int n=SoSanhChuoi(tempString," ~");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-1));
				kq=~temp1Qnit;
				return Print(kq);
			}
			else if(SoSanhChuoi(tempString," ^ ")!=-1)
			{
				int n=SoSanhChuoi(tempString," ^ ");
				Scan(temp1Qnit,CopyChuoi(tempString,0,n-2));
				Scan(temp2Qnit,CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit^temp2Qnit;
				return Print(kq);
			}
		}
		else if(str[0]=='1' && str[1]=='0' && str[2]==' ')
		{
			QInt temp1Qnit,temp2Qnit,kq;
			tempString=XoaChuoi(str,0,3);
			if(SoSanhChuoi(tempString," + ")!=-1)
			{
				int n=SoSanhChuoi(tempString," + ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=DecToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit+temp2Qnit;
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," - ")!=-1)
			{
				int n=SoSanhChuoi(tempString," - ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=DecToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit-temp2Qnit;
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," * ")!=-1)
			{
				int n=SoSanhChuoi(tempString," * ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=DecToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit*temp2Qnit;
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," / ")!=-1)
			{
				int n=SoSanhChuoi(tempString," / ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=DecToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit/temp2Qnit;
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," << ")!=-1)
			{
				int n=SoSanhChuoi(tempString," << ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-3));
				kq=temp1Qnit<<stoi(CopyChuoi(tempString,n+1,tempString.length()));
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," >> ")!=-1)
			{
				int n=SoSanhChuoi(tempString," >> ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-3));
				kq=temp1Qnit>>stoi(CopyChuoi(tempString,n+1,tempString.length()));
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," & ")!=-1)
			{
				int n=SoSanhChuoi(tempString," & ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=DecToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit&temp2Qnit;
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," | ")!=-1)
			{
				int n=SoSanhChuoi(tempString," | ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=DecToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit|temp2Qnit;
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," ~")!=-1)
			{
				int n=SoSanhChuoi(tempString," ~");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-1));
				kq=~temp1Qnit;
				return BinToDec(kq);
			}
			else if(SoSanhChuoi(tempString," ^ ")!=-1)
			{
				int n=SoSanhChuoi(tempString," ^ ");
				temp1Qnit=DecToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=DecToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit^temp2Qnit;
				return BinToDec(kq);
			}
		}
		else if(str[0]=='1' && str[1]=='6' && str[2]==' ')
		{
			QInt temp1Qnit,temp2Qnit,kq;
			tempString=XoaChuoi(str,0,3);
			if(SoSanhChuoi(tempString," + ")!=-1)
			{
				int n=SoSanhChuoi(tempString," + ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=HexToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit+temp2Qnit;
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," - ")!=-1)
			{
				int n=SoSanhChuoi(tempString," - ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=HexToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit-temp2Qnit;
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," * ")!=-1)
			{
				int n=SoSanhChuoi(tempString," * ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=HexToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit*temp2Qnit;
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," / ")!=-1)
			{
				int n=SoSanhChuoi(tempString," / ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=HexToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit/temp2Qnit;
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," << ")!=-1)
			{
				int n=SoSanhChuoi(tempString," << ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-3));
				string str=CopyChuoi(tempString,n+1,tempString.length());
				kq=temp1Qnit<<stoi(HexToDex(str));
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," >> ")!=-1)
			{
				int n=SoSanhChuoi(tempString," >> ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-3));
				string str=CopyChuoi(tempString,n+1,tempString.length());
				kq=temp1Qnit>>stoi(HexToDex(str));
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," & ")!=-1)
			{
				int n=SoSanhChuoi(tempString," & ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=HexToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit&temp2Qnit;
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," | ")!=-1)
			{
				int n=SoSanhChuoi(tempString," | ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=HexToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit|temp2Qnit;
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," ~ ")!=-1)
			{
				int n=SoSanhChuoi(tempString," ~");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-1));
				kq=~temp1Qnit;
				return BinToHex(kq);
			}
			else if(SoSanhChuoi(tempString," ^ ")!=-1)
			{
				int n=SoSanhChuoi(tempString," ^ ");
				temp1Qnit=HexToBin(CopyChuoi(tempString,0,n-2));
				temp2Qnit=HexToBin(CopyChuoi(tempString,n+1,tempString.length()));
				kq=temp1Qnit^temp2Qnit;
				return BinToHex(kq);
			}

		}
		
	}
	bool OpenFile(string location_file,string &dataSave)//hàm mở file và xử lí dữ liệu trong file.
		//location_file là dường dẫn 
		// dataSave là dữ liệu lưu
		// hàm trả về true nếu thành công, trả về false nếu ko thành công
	{
		fstream file;
		string temp;
		file.open(location_file);
		if(file.is_open())
		{
			while(!file.eof())
			{
				getline(file,temp);
				dataSave= dataSave+XuLyTinhToan(temp)+"\r\n";
			}
		}
		else
		{
			return false;
		}
		file.close();
		return true;
	}
	void SaveFile(string location_file,string dataSave)// hàm xuất file txt 
		//location_file là đường dẫn
		//dataSave là dữ liệu để save
	{
		ofstream saveFile;
		saveFile.open(location_file);
		saveFile<<dataSave;
		saveFile.close();
	}
	string XuLyChuoi(string str)
	{
		string temp=str;
		int n=str.length()/50;
		for(int i=0;i<n;i++)
		{
			temp.insert(50*(i+1)+i,"\r");
		}
		return temp;
	}
}