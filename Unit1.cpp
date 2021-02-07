//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"

#include <math.h>
#define pi 3.1415926

#define Hpl 6.58122e-16
#define E0 0.511
#define CLe 3.861593e-11
#define Re 2.81794e-15
#define Naw 6.02214e23
#define C 2.99793e8
#define alpha 7.29735e-3
#define sv 1.5e-4
#define ndel 300
#define ee -1.06e-19
#define mikron 1.0e-6
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
double Aw,zet,Plot,a,R0,AN,wph1,wph,Gam,Ee,R,k[1000];
double tetx[600],tety,tetex[1000],tetey[1000],sigx,sigy,d,ddd,tet,tetg[1000],tetg2[1000],tetgx[1000],tetgy[1000],tetxx[1000],tetyy[1000];
double dell1,dell2,dell3,f1,f2,f3,f4,f5,omega,fg,fg1,fg2,fg3,fg4,fg42,gam2,ww;
double shagx,shagy,ne,sxm,sxp;
int shagd,shags;

	 f5=0.0;
	 sigx=0.0;
	 sigy=0.0;
	 Ee=200000.0;
	 Aw= 28.09;
	 zet= 14.0;
	 Plot= 2.33;
	 a= 1406.1;
	 AN=1.e6*Plot*Naw/Aw;
	 wph=C*sqrt(4.*pi*Re*AN*zet)*Hpl;
	 Gam=Ee/E0;
	 omega=16552.0;

	 sigx=StrToFloat(Edit1->Text);
	 sigy=StrToFloat(Edit2->Text);
	 shagd=StrToInt(Edit3->Text);
	 shags=StrToInt(Edit4->Text);

	 sigx=sigx*mikron;
	 sigy=sigy*mikron;
	 d=mikron;
	 shagy=10*sigy/shags;
	 shagx=10*sigx/shags;
	 gam2=1.0/(Gam*Gam);
	 ww=wph*wph/(omega*omega);

	 AnsiString ssigx = FormatFloat("0.000000",sigx);
	 AnsiString ssigy = FormatFloat("0.000000",sigy);

	 Memo1->Lines->Add(ssigx+"x"+ssigy);
	 Memo1->Text = Memo1->Text+"shagx "+FloatToStr(shagx);
	 Memo1->Lines->Add(" ");
	 Memo1->Text = Memo1->Text+"wph "+FloatToStr(wph);
	 Memo1->Lines->Add(" ");
	 Memo1->Text = Memo1->Text+"Gam "+FloatToStr(Gam);
	 Memo1->Lines->Add(" ");
	 Memo1->Text = Memo1->Text+"omega "+FloatToStr(omega);
	 Memo1->Lines->Add(" ");
	 Memo1->Text = Memo1->Text+"ww "+FloatToStr(ww);
	 Memo1->Lines->Add(" ");
	 Memo1->Text = Memo1->Text+"gam-2 "+FloatToStr(gam2);
	 Memo1->Lines->Add(" ");
	 Memo1->Text = Memo1->Text+"START COUNTING";
	 Memo1->Lines->Add(" ");

 float ttxm,ttxp,b[1000],rangesx,rangesy,ranged;
 int q,w,f,t,r;
 a=-300*d;
 ranged=-0.5*d;
 rangesx=-5.0*sigx;
 rangesy=-5.0*sigy;


  for (w = 0; w < 600; w++)
 {
	 f4=0;
	 tetx[w]=a+w*d;
	 b[w]=tetx[w]-0.5*d;
	for (q = 0; q < shagd; q++)
   {
	  f3=0;
	  tetxx[q]=b[w]+d*q/shagd;
	 for (r = 0; r < shagd; r++)
	 {
	  tetyy[r]=ranged+d*r/shagd;
	  f2=0;
	   for (f = 0; f < shags; f++)
	   {
	  f1=0;
	  tetey[f]=rangesy+shagy*f;
	  tetgy[f]=tetyy[r]-tetey[f];
		 for (t = 0; t < shags; t++)
		 {
		   tetex[t]=rangesx+shagx*t;
		   fg=0;

		   tetgx[t]=tetxx[q]-tetex[t];
		   tetg2[t]=tetgx[t]*tetgx[t]+tetgy[f]*tetgy[f];
		   k[t]=sqrt(tetg2[t]);
		  if(k[t]<(20.0/Gam))
		   {
		   fg1=tetg2[t];
		   fg2=1.0/(tetg2[t]+gam2);
		   fg3=1.0/(tetg2[t]+gam2+ww);
		   fg4=fg2-fg3;
		   fg42=fg4*fg4;
		   fg=fg1*fg42;
		   f1=fg*exp(-tetex[t]*tetex[t]/(2.0*sigx*sigx))+f1;
		   }

		 }
		   if(f1!=0)
		   {
		   f2=f1*exp(-tetey[f]*tetey[f]/(2.0*sigy*sigy))+f2;
		   }
	  }
		   if (f2!=0)
		   {
		   f3=f2+f3;
		   }
	 }
		   if (f3!=0)
		   {
		   f4=f3+f4;
		   }
	}
  f5=f4*1e4*alpha*d*d*shagy*shagx/(shagd*shagd*sigx*sigy);
  AnsiString ff5 = FormatFloat("0.000000",f5);
  ProgressBar1->Min=0;
  ProgressBar1->Max=600;
  ProgressBar1->StepBy(1);
  Memo2->Lines->Add(f5);
  }
	 Memo1->Text = Memo1->Text+"DONE";
	 Memo1->Lines->Add(" ");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
Memo1->Clear();
Memo2->Clear();
Edit1->Clear();
Edit2->Clear();
Edit3->Clear();
Edit4->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Memo1->Clear();
Memo2->Clear();
Edit1->Clear();
Edit2->Clear();
ProgressBar1->Position=0;
}
//---------------------------------------------------------------------------


