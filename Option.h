//Copyright+LGPL

//-----------------------------------------------------------------------------------------------------------------------------------------------
// Copyright 2000-2013 Makoto Mori, Nobuyuki Oba
//-----------------------------------------------------------------------------------------------------------------------------------------------
// This file is part of MMSSTV.

// MMSSTV is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
// as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// MMSSTV is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public License along with MMTTY.  If not, see 
// <http://www.gnu.org/licenses/>.
//-----------------------------------------------------------------------------------------------------------------------------------------------



//----------------------------------------------------------------------------
#ifndef OptionH
#define OptionH
//----------------------------------------------------------------------------
	//ja7ude 0428
#include <System.hpp>
#include <Windows.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Graphics.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Controls.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>

#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include "sstv.h"
#include "MMLink.h"
//----------------------------------------------------------------------------
class TOptionDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TTimer *Timer;
	TPageControl *Page;
	TTabSheet *TabDem;
	TGroupBox *GBCROSS;
	TGroupBox *GBCOI;
	TLabel *LCORDER;
	TLabel *Label18;
	TLabel *Label19;
	TSpeedButton *DispCrossOutLPF;
	TComboBox *crossOutOrder;
	TComboBox *crossOutFC;
	TRadioGroup *RGcrossType;
	TGroupBox *GBCOF;
	TLabel *Label17;
	TLabel *Label20;
	TComboBox *crossSmooz;
	TGroupBox *GBPLL;
	TLabel *Label1;
	TGroupBox *GroupBox17;
	TLabel *LLoopOrder;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *DispLoopLPF;
	TComboBox *pllLoopOrder;
	TComboBox *pllLoopFC;
	TComboBox *pllVCOGain;
	TGroupBox *GroupBox18;
	TLabel *LOutOrder;
	TLabel *Label44;
	TLabel *Label45;
	TSpeedButton *DispOutLPF;
	TComboBox *pllOutOrder;
	TComboBox *pllOutFC;
	TGroupBox *GB2;
	TSpeedButton *SBTest;
	TLabel *LOff;
	TLabel *L1500;
	TLabel *L2300;
	TEdit *Max1500;
	TEdit *Max2300;
	TEdit *Off1900;
	TCheckBox *CBCalWay;
	TRadioGroup *RGRBuf;
	TRadioGroup *RGMSync;
	TRadioGroup *RGRxBPF;
	TButton *RxBpfBtn;
	TGroupBox *GB4;
	TCheckBox *CBAStop;
	TCheckBox *CBARestart;
	TCheckBox *CBASlant;
	TCheckBox *CBASync;
	TCheckBox *IDDEC;
	TRadioGroup *RGSLvl;
	TRadioGroup *RGDemType;
	TCheckBox *CBDiff;
	TTrackBar *TBDiff;
	TTabSheet *TabTx;
	TGroupBox *GPTT;
	TLabel *Label13;
	TComboBox *PortName;
	TButton *RadioBtn;
	TCheckBox *PTTLock;
	TCheckBox *CBRTS;
	TGroupBox *GroupBox10;
	TLabel *Label25;
	TLabel *Label28;
	TLabel *Label29;
	TSpeedButton *DispTxBpf;
	TCheckBox *CBTXBPF;
	TComboBox *TxBpfTap;
	TCheckBox *CBTXLPF;
	TComboBox *TxLpfFreq;
	TGroupBox *GBOut;
	TTrackBar *TBOutLvl;
	TCheckBox *CBVari;
	TGroupBox *GBTemp;
	TLabel *Label2;
	TEdit *EditCall;
	TRadioGroup *RGLoopBack;
	TGroupBox *GroupBox4;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label12;
	TLabel *Label14;
	TComboBox *TuneFreq;
	TComboBox *TrigTXTime;
	TCheckBox *CBAT;
	TGroupBox *GB5;
	TLabel *L15;
	TLabel *L7;
	TLabel *L8;
	TEdit *CWIDText;
	TComboBox *CWIDFreq;
	TButton *CWIDMac;
	TTrackBar *TBCW;
	TRadioButton *IDOFF;
	TRadioButton *IDCW;
	TRadioButton *IDMMV;
	TEdit *MMVID;
	TGroupBox *GB7;
	TCheckBox *CBTxFixed;
	TCheckBox *IDFSK;
	TRadioGroup *RGV;
	TButton *VEdit;
	TTabSheet *TabMisc;
	TGroupBox *GSFont;
	TLabel *Label46;
	TLabel *L17;
	TEdit *WinFont;
	TButton *WinFontBtn;
	TButton *JaBtn;
	TButton *EngBtn;
	TComboBox *FontAdj;
	TGroupBox *GrpCard;
	TLabel *Label11;
	TLabel *Label6;
	TRadioGroup *SoundPriority;
	TGroupBox *GroupBox3;
	TSpeedButton *SBClockAdj;
	TLabel *Label5;
	TLabel *L21;
	TLabel *Label21;
	TComboBox *EditSamp;
	TUpDown *UDTxSamp;
	TEdit *TxSampOff;
	TComboBox *DevNo;
	TRadioGroup *Source;
	TGroupBox *GB1;
	TLabel *L27;
	TLabel *L6;
	TComboBox *RxFifo;
	TComboBox *TxFifo;
	TCheckBox *CBSTX;
	TComboBox *DevNoOut;
	TCheckBox *MemWin;
	TGroupBox *GBW;
	TLabel *Label37;
	TLabel *Label38;
	TPanel *PCLow;
	TPanel *PCHigh;
	TGroupBox *GBHMax;
	TComboBox *HistMax;
	TGroupBox *GB6;
	TLabel *Label16;
	TLabel *LJPEGQ;
	TComboBox *JPEGQ;
	TGroupBox *GBS;
	TLabel *LFFTB;
	TLabel *LFFT;
	TLabel *LFFTT;
	TLabel *LFFTS;
	TLabel *LFFTF;
	TPanel *PCFFTB;
	TPanel *PCFFT;
	TPanel *PCFFTStg;
	TPanel *PCSync;
	TPanel *PCFreq;
	TRadioGroup *AppPriority;
	TCheckBox *CB24;
	TTabSheet *TabSheet1;
	TGroupBox *Log4OMBox;
	TLabel *Label7;
	TEdit *AddressEdit;
	TLabel *Label8;
	TEdit *PortEdit;
	TCheckBox *Log4OMCheckBox;
	void __fastcall DispTxBpfClick(TObject *Sender);
	void __fastcall PortNameChange(TObject *Sender);
	
	void __fastcall WinFontBtnClick(TObject *Sender);
	void __fastcall JaBtnClick(TObject *Sender);
	void __fastcall EngBtnClick(TObject *Sender);
	
	
	

	void __fastcall DispLoopLPFClick(TObject *Sender);
	void __fastcall DispOutLPFClick(TObject *Sender);
	void __fastcall RadioBtnClick(TObject *Sender);



	
	void __fastcall SBClockAdjClick(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	
	void __fastcall SBTestClick(TObject *Sender);
	
	
	void __fastcall RxBpfBtnClick(TObject *Sender);
	void __fastcall PCFFTClick(TObject *Sender);
	void __fastcall UDTxSampClick(TObject *Sender, TUDBtnType Button);
	void __fastcall CWIDMacClick(TObject *Sender);
	void __fastcall RGDemTypeClick(TObject *Sender);
	void __fastcall DispCrossOutLPFClick(TObject *Sender);
	void __fastcall TxSampOffChange(TObject *Sender);
	void __fastcall CBCalWayClick(TObject *Sender);
	void __fastcall IDOFFClick(TObject *Sender);
	void __fastcall VEditClick(TObject *Sender);
	
	void __fastcall CBATClick(TObject *Sender);
	void __fastcall PortNameDropDown(TObject *Sender);
	void __fastcall SourceClick(TObject *Sender);
	void __fastcall SBTestMouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y);
	void __fastcall DevNoChange(TObject *Sender);

	void __fastcall PortEditKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall PortEditChange(TObject *Sender);
	void __fastcall AddressEditKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall AddressEditExit(TObject *Sender);
//	void __fastcall AddressEditChange(TObject *Sender);

private:
	int	m_DisEvent;

	CSSTVDEM	*pDem;
	double      m_TxSampOff;

	void __fastcall UpdateUI(void);
	void __fastcall SetCustomColor(void);


	BYTE	m_WinFontCharset;
	int		m_WinFontStyle;

	int     m_TestMode;
	int     m_TestCnt;
	int     m_SubCnt;
	CSmooz  m_Avg;
	double  m_DataList[17];
	double  m_DataList2[17];
	int     m_Off;
	int     m_Max1500;
	int     m_Max2300;
	double  m_OutGain;
	double  m_BuffCal;

	AnsiString  m_VOXSound;
    CMMList	m_MMList;
    CMMList	m_MMListW;
private:
	int __fastcall IsMMW(LPCSTR p);

public:
	virtual __fastcall TOptionDlg(TComponent* AOwner);

	int __fastcall Execute(CSSTVDEM *fp, CSSTVMOD *mp);
	int m_ColorChange;
	void __fastcall SetPageIndex(int n);
};
//----------------------------------------------------------------------------
//extern TAgcSetDlg *AgcSetDlg;
extern int PageIndex;
//----------------------------------------------------------------------------
#endif    
