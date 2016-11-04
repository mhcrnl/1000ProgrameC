#include "stdafx.h"
#include <iostream>


FILE *filemain;
FILE *filetemp;
char aranan[30];
char cevap;
int cevap2;
int sayac=0;
using namespace std;

struct bilgiler 
{
char kisiAdi[30]; char kisiSoyad[50];
char tel[30];
char fax[30];
char eposta[30];
char webadres[30];
char adres[50];
char kisiAdiGecici[30]; char kisiSoyadGecici[50];
char GeciciTel[30];
};

int tusoku();
void GirisEkrani()
{
	system("Color 10");
	cout<<endl;
	cout<<"          **********   TELEFON REHBERİ   **********"<<endl;
	cout<<"          **          1.Kayıt Ekle               **"<<endl;
	cout<<"          **          2.Kayıtları Listele        **"<<endl;
	cout<<"          **          3.Kayıt Sil                **"<<endl;
	cout<<"          **          4.Kayıt Düzenle            **"<<endl;
	cout<<"          **          5.Kayıt Arama              **"<<endl;
	cout<<"          **          6.Çıkış                    **"<<endl;
	cout<<"          *****************************************"<<endl;
	cout<< "       Seçim yapmak için yön tuşlarını kullanabilirsiniz...";

}
void KayitEkle()
{
	struct bilgiler b;
	if((filemain=fopen("Rehber.csv","a"))==NULL)
	{
		cout<<"Dosya Açılamadı"<<endl;
		exit(0);
	}
	printf("             ------------------------------------");
	printf("\n                       Kayıt Ekleme         \n");
	printf("             ------------------------------------\n");

	 
	printf("\nKişi Adı :");
	scanf("%s",b.kisiAdi);
	printf("Kişi Soyadı	:");
	scanf("%s",b.kisiSoyad);
	printf("Telefon :");
	scanf("%s",b.tel);
	printf("Fax :");
	scanf("%s",b.fax);
	printf("E-posta : ");
	scanf("%s",b.eposta);
	printf("Web : ");
	scanf("%s",b.webadres);
	printf("Ev Adresi : ");
	scanf("%s",b.adres);

	fprintf(filemain,"%s %s %s %s %s %s %s\n",b.kisiAdi,b.kisiSoyad,b.tel,b.fax,b.eposta,b.webadres,b.adres);
	fclose(filemain);
	
	printf("Ekleme işlemi başarı ile tamamlandı.");
	printf("\n");	
} 
void Listeleme()
{
	struct bilgiler b;
	printf("             ------------------------------------");
	printf("\n                       Kayıt Listeleme         \n");
	printf("             ------------------------------------\n");

	if((filemain=fopen("Rehber.csv","r"))==NULL)
	{
		cout<<"Dosya Açılamadı"<<endl;
		exit(0);
	}
	
	printf("Kişi Adı\tKişi Soyadı  \tTelefon \tFax \tE-posta \tWeb\tAdres\n");
	printf("------- \t --------\t ------ \t----- \t------- \t----  \t ------");

	while (!feof(filemain))
	{
		fscanf(filemain,"%s %s %s %s %s %s %s",b.kisiAdi,b.kisiSoyad,b.tel,b.fax,b.eposta,b.webadres,b.adres);
		printf("\n %-15s",b.kisiAdi);
		printf("%-15s",b.kisiSoyad);
		printf("%s     ",b.tel);
		printf("%s     ",b.fax);
		printf("%s     ",b.eposta);
		printf("%s     ",b.webadres);
		printf("%s     ",b.adres);
		sayac++;
	}
	fclose(filemain);
	printf("\n");
	cout<<sayac<<" Adet kayıt listelendi.";
	printf("Listeleme işlemi sonuçlandı\n");
	sayac=0;
	_getch();
}
void KayitSilme()
{
	struct bilgiler b;
	printf("------------------------------------");
	printf("\n           Kayıt Silme           \n");
	printf("------------------------------------\n");

	printf("Silmek istediğiniz kaydın telefon numarasını giriniz : \n");
	scanf("%s",&aranan);

	if((filemain=fopen("Rehber.csv","r"))==NULL)
	{
		cout<<"Dosya Açılamadı"<<endl;
		exit(0);
	}

	if((filemain=fopen("GeciciRehber.csv","w"))==NULL)
	{
		cout<<"Dosya Açılamadı"<<endl;
		exit(0);
	}

	while (!feof(filemain))
	{
		fscanf(filemain,"%s %s %s %s %s %s %s",b.kisiAdi,b.kisiSoyad,b.tel,b.fax,b.eposta,b.webadres,b.adres);

		
		if (strstr(b.tel,aranan))
		{
			printf("\n      Kişi Bilgileri        ");
			printf("\nKişi Adı : %s",b.kisiAdi);
			printf("\nKişi Soyadı : %s",b.kisiSoyad);
			printf("\n\n Bu kaydı silmek istiyor musunuz ? (e/h)");
			scanf("%s",&cevap);

			if(cevap=='e')
				fscanf(filemain,"%s %s %s %s %s %s %s",&b.kisiAdi,&b.kisiSoyad,&b.tel,&b.fax,&b.eposta,&b.webadres,&b.adres);
			else
				fprintf(filetemp,"%s %s %s %s %s %s %s",b.kisiAdi,b.kisiSoyad,b.tel,b.fax,b.eposta,b.webadres,b.adres);
				
		}

		else
			fprintf(filetemp,"%s %s %s %s %s %s %s",b.kisiAdi,b.kisiSoyad,b.tel,b.fax,b.eposta,b.webadres,b.adres);

		
	} 
	fclose(filemain);
	fclose(filetemp);
	remove("Rehber.csv");
	rename("GeciciRehber.csv","Rehber.csv");
	printf("\n\n");
	printf("Silme İşlemi başarılı");
	
	fclose(filemain);
	fclose(filetemp);
	remove("Rehber.csv");
	rename("GeciciRehber.csv","Rehber.csv");
	printf("\n\n");
	printf("Silme işlemi başarılı \n");
	
}
void KayitDuzenleme()
{
	struct bilgiler b;
	printf("--------------------------------------");
	printf("\n           Kayıt Düzenleme         \n");
	printf("------------------------------------\n");

	printf("\n Telefon : ");
	scanf("%s",aranan);

	if ((filemain=fopen("Rehber.csv","r"))==NULL)
	{
		printf("Dosya açılmadı\n");
		exit(0);
	}
	if ((filetemp=fopen("GeciciRehber.csv","w"))==NULL)
	{
		printf("Dosya açılmadı\n");
		exit(0);
	}
	do
	{
		fscanf(filemain,"%s\n",b.tel);
		if (strstr(b.tel,aranan))
		{
			printf("\nKişi Bilgileri");
			printf("------------------------------------\n");
			printf("\nKişi Adı: %s",b.kisiAdi);
			printf("\nKişi Soyadı : %s",b.kisiSoyad);

			printf("\nKaydı Düzeltme");
			printf("------------------------------------\n");
			printf("Düzeltmek istediğiniz bilgi : \n İsim için 1 \n Soyad için 2\n Telefon için 3\n Fax için 4\n adres için 5\n Web adresi için 6\n  Seçiminiz ? :");
			cin>>cevap2;
			switch (cevap2)
			{
			case 1: printf("\nKişi Adı : ");
			scanf("%s",b.kisiAdiGecici);
				break;
			case 2:printf("\nKişi Soyadı : ");
			scanf("%s",b.kisiSoyadGecici);
			break;
			}
			printf("\n\n Yapılan değişiklikleri kaydetmek istiyor musunuz ?(e/h)");
			scanf("%s",&cevap);
			if(cevap=='e')
				fprintf(filetemp,"%s %s\n",b.kisiAdiGecici,b.kisiSoyadGecici);
			else
				fprintf(filetemp,"%s %s\n",b.kisiAdi,b.kisiSoyad);

		}
		else
			fprintf(filetemp,"%s %s\n",b.kisiAdi,b.kisiSoyad);
	} while (!feof(filemain));
	fclose(filemain);
	fclose(filetemp);
	remove("Rehber.csv");
	rename("GeciciRehber.csv","Rehber.csv");
	printf("\n\n");
	printf("Güncelleme işlemi başarılı");
}
void KayitArama()
{
	struct bilgiler b;
	printf("\nKayıt Arama ");
	printf("\n------------------------------");

	printf("\n Telefon No gir : ");
	scanf("%s",aranan);
	if ((filemain=fopen("Rehber.csv","r"))==NULL)
	{
		printf("Dosya açılmadı\n");
		exit(0);
	}

	do
	{
		fscanf(filemain,"%s %s %s %s %s %s %s",b.kisiAdi,b.kisiSoyad,b.tel,b.fax,b.eposta,b.webadres,b.adres);
		if (strcmp(b.tel,aranan)==0)
		{
			printf("\n Kişi Bilgileri ");
			printf("\n------------------------------");

			printf("\n Kişi Adı : %s",b.kisiAdi);
			printf("\n Kişi Soyadı : %s",b.kisiSoyad);
			printf("\n\n");

			printf("Arama işlemi tamamlandı ");
		}
		else
		{
			/*printf("\n\n");
			printf("Aradığınız kayıt bulunamadı");*/
		}
	} while (!feof(filemain));
	fclose(filemain);
}
void Anamenu()
{
	int pos=1;
    int opt; 
    char c;
    
    while(true)
    {
        int tus_=0;
        Sleep(1);// Menüler arası gezinirken hız ayarı 
        tus_=tusoku();
        if(tus_ == 5) break; //Enter basılmışsa
        if(tus_ == 4 && pos<7) pos++; //aşağı ok
        else if(tus_ == 3 && pos>2) pos--; // yukarı ok
			
        if(tus_ != 0)
			{
			system("cls");
			
			cout<<endl;
            
			 if(pos == 1)
            {
				
               cout<<"          **********   TELEFON REHBERİ   **********"<<endl;
			   
            }else
            {
				
                cout<<"          **********   TELEFON REHBERİ   **********"<<endl;
            }
            if(pos == 2)
            {
				
                cout<<"          **";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
				cout<<"   -->    1.Kayıt Ekle               ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				cout<<"**"<<endl;
				
            }else
            {
				cout<<"          ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
                cout<<"**          1.Kayıt Ekle               **"<<endl;

            }
            if(pos == 3)
            {
				cout<<"          **";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
               cout<<"   -->    2.Kayıtları Listele        ";
			   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
			   cout<<"**"<<endl;
            }else
            {
				cout<<"          ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
                cout<<"**          2.Kayıtları Listele        **"<<endl;
            }
            if(pos == 4)
            {
				cout<<"          **";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
                cout<<"   -->    3.Kayıt Sil                ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				cout<<"**"<<endl;
            }else
            {
				cout<<"          ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
                cout<<"**          3.Kayıt Sil                **"<<endl;
            }
			if(pos == 5)
            {
				cout<<"          **";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
                cout<<"   -->    4.Kayıt Düzenle            ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				cout<<"**"<<endl;
            }else
            {
				cout<<"          ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
                cout<<"**          4.Kayıt Düzenle            **"<<endl;
            }
			if(pos == 6)
            {
				cout<<"          **";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
                cout<<"   -->    5.Kayıt Arama              ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				cout<<"**"<<endl;
            }else
            {
				cout<<"          ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
                cout<<"**          5.Kayıt Arama              **"<<endl;
            }
			if(pos == 7)
            {
				cout<<"          **";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
                cout<<"   -->    6.Çıkış                    ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				cout<<"**"<<endl;
            }else
            {
				cout<<"          ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
                cout<<"**          6.Çıkış                    **"<<endl;
            }
			if(pos == 8)
            {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY);
                cout<<"          *****************************************"<<endl;
            }else
            {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
                cout<<"          *****************************************"<<endl;
            }
        }
				
    }
	
  opt = pos;
	char secim;
	int sec;
	switch (opt)
	{
	case 2 : 
		KayitEkle(); 
		while (true)
		{
			cout<<"Ana menüye dönmek icin 1\nYeni kayıt eklemek için 2 ye basınız "; 
			cin>>sec;
			if (sec==1)
			{
			system("cls");
			GirisEkrani();
			Anamenu();
			}
		else if(sec==2)
			{
			KayitEkle();
			}
		}
		break;
	case 3 :
		Listeleme();
		while (true)
		{
			cout<<"\nAna menüye dönmek istiyor musunuz ? (e/h) :"; 
			cin>>secim;
			if (secim=='e')
			{
			system("cls");
			GirisEkrani();
			Anamenu();
			}
			else if(secim=='h')
			{
				cout<<"Programdan çıkılıyor ";
				Sleep(700);
				exit(0);
			}
		}
		break;
	case 4 : 
		KayitSilme();
		while (true)
		{
			cout<<"\nAna menüye dönmek icin 1\nBaşka kayıt Silme için 2 ye basınız "; 
			cin>>sec;
			if (sec==1)
			{
			system("cls");
			GirisEkrani();
			Anamenu();
			}
		else if(sec==2)
			{
			KayitSilme();
			}
		}
		break;
	case 5 : 
		KayitDuzenleme();
		while (true)
		{
			cout<<"\nAna menüye dönmek icin 1\nBaşka bir kayıt üzerinde düzenleme yapma için 2 ye basınız "; 
			cin>>sec;
			if (sec==1)
			{
			system("cls");
			GirisEkrani();
			Anamenu();
			}
		else if(sec==2)
			{
			KayitDuzenleme();
			}
		}
		break;
	case 6: 
		KayitArama(); 
		while (true)
		{
			cout<<"\nAna menüye dönmek icin 1\nBaşka bir kayıt aramak için 2 ye basınız "; 
			cin>>sec;
			if (sec==1)
			{
			system("cls");
			GirisEkrani();
			Anamenu();
			}
		else if(sec==2)
			{
			KayitArama();
			}
		}
		break;
	case 7 : cout<<"Programdan çıkılıyor.Emin misiniz ? (e/h) :" ;
		cin>>secim;
		if(secim=='e') exit(0);
		else if(secim=='h') system("cls"); GirisEkrani(); Anamenu();
		break;
	}
    
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	setlocale(LC_ALL,"Turkish");
	GirisEkrani();
	Anamenu();

	system("pause");
	return 0;
}
int tusoku(void)
{
    if( GetAsyncKeyState(VK_LEFT)  ) // SOL OK
    {
        return 1;
    }else if( GetAsyncKeyState(VK_RIGHT) & 0x8000 ) // SAĞ OK
    {
        return 2;
    }else if( GetAsyncKeyState(VK_UP) & 0x8000 ) // YUKARI OK
    {
        return 3;
    }else if( GetAsyncKeyState(VK_DOWN) & 0x8000 ) // AŞAĞI OK
    {
        return 4;
    }else if( GetAsyncKeyState(VK_RETURN) & 0x8000 ) // ENTER
    {
        return 5;
    }
    return 0;
}  
