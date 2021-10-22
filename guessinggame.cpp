#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

int taoSoNgauNhien(int max)
{
	return rand() % max;
}
int main()
{
	const int DONG_XU = 2;
	const int XUC_XAC = 6;
	const int XO_SO = 100;
    srand(time(0));
	
	//rule
	int selection;
	cout<<"Quy tac: thang = x2 so tien cuoc, thua = mat toan bo so tien cuoc."<<endl
		<<"Ban da san sang chua? Co (1) Khong (0) ";
	cin>>selection;
	if(selection == 0)
	{
		cout<<"Hen gap lai ban trong tro choi khac";
		return 0;
	}
	else
	{
		//player wallet
		int value; int choose;
		cout<<"\nNhap so tien ban dang co: "; cin>>value;
		cout<<"Ban dang co "<<value<<" dong"<<endl;
		while(value>0)
		{
			//dat cuoc
			int bet;
			cout<<"Nhap so tien dat cuoc: ";
			cin>>bet;
			if(bet>value)
			{
				cout<<"Ban khong du tien de dat cuoc\n";
			}
			else
			{
				cout<<"Ban da dat cuoc "<<bet<<" dong\n";
			
				//game selection
				int mode, ket_qua, du_doan;
				cout<<"\nMoi ban chon tro choi Du doan dong xu (1) Du doan xuc xac (2) Du doan xo so (3): ";
				cin>>mode;
				switch(mode)
				{
					//du doan dong xu
					case 1: cout<<"Ban da chon tro choi du doan dong xu xap ngua"<<endl;
						cout<<"Hay du doan dong xu xap (1) hay ngua (0): ";
						cin>>du_doan;

						ket_qua = taoSoNgauNhien(DONG_XU);
    					if(ket_qua == du_doan)
    					{
    						value = value + bet;
    						sleep(2);
    						cout<<"xin chuc mung, ban da doan DUNG\n"
    						<<"Ban hien dang co: "<<value<<" dong\n\n";
    					}
    					else
    					{
    						value = value - bet;
    						sleep(2);
    						cout<<"rat tiec, ban da doan SAI\n";
    						if(ket_qua) cout<<"dong xu xap, ban doan la ngua\n";
    						else cout<<"dong xu ngua, ban doan la xap\n";
    						cout<<"Ban hien dang co: "<<value<<" dong\n\n";
    					};
    					cout<<"Ban co muon choi tiep khong? Co (1) Khong (0): ";
    					cin>>choose;
    					if(choose==0){
    						cout<<"Hen gap lai ban trong tro choi khac";
    						return 0;
						}
    					break;
    		
    				//du doan xuc xac
    				case 2: cout<<"Ban da chon tro choi du doan con so xuc xac"<<endl;
    					cout<<"Hay du doan con so cua xuc xac tu 1 den 6: ";
    					cin>>du_doan;
    		
    					ket_qua = taoSoNgauNhien(XUC_XAC);
    					if(ket_qua+1 == du_doan)
    					{
    						value = value + bet;
    						sleep(2);
    						cout<<"Xin chuc mung, ban da doan DUNG\n";
    						cout<<"Ban doan so "<<du_doan<<endl;
							cout<<"Xuc xac co so "<<ket_qua+1<<endl
							<<"Ban hien dang co: "<<value<<" dong\n";
						}	
						else
						{
							value = value - bet;
							sleep(2);
							cout<<"Rat tiec, ban da doan SAI\n";
							cout<<"Ban doan so "<<du_doan<<endl;
							cout<<"Xuc xac co so "<<ket_qua+1<<endl;
							cout<<"Ban hien dang co: "<<value<<" dong\n";
						}
						cout<<"Ban co muon choi tiep khong? Co (1) Khong (0): ";
    					cin>>choose;
    					if(choose==0){
    						cout<<"Hen gap lai ban trong tro choi khac";
    						return 0;
						}
						break;
			
					//du doan xo so
					case 3: cout<<"Ban da chon tro choi xo so"<<endl;
						cout<<"Hay du doan con so tu 0 den 99: ";
						cin>>du_doan;
					
						ket_qua = taoSoNgauNhien(XO_SO);
						if(ket_qua == du_doan)
						{
							value = value + bet;
							sleep(2);
							cout<<"Xin chuc mung, ban da doan DUNG\n";
							cout<<"Ket qua la: "<<du_doan<<endl;
							cout<<"Ban hien dang co: "<<value<<" dong\n";
						}
						else
						{
							value = value - bet;
							sleep(2);
							cout<<"Rat tiec, ban da doan SAI\n";
							cout<<"Ban doan so: "<<du_doan<<endl
							<<"Ket qua la: "<<ket_qua<<endl;
							cout<<"Ban hien dang co: "<<value<<" dong\n";
						}
						cout<<"Ban co muon choi tiep khong? Co (1) Khong (0): ";
    					cin>>choose;
    					if(choose==0){
    						cout<<"Hen gap lai ban trong tro choi khac";
    						return 0;
						}
						break;
				}
			}
		}
		cout<<"Ban khong du tien de choi tro nay";
		return 0;
	}
}


