#include "XDOptions.h"
#pragma hdrstop

#include <Vcl.Dialogs.hpp>
#include <vcl.h>
#include <System.hpp>

void ShowTemporaryMessage(String message, int milliseconds);


void __fastcall SendPSKReport::TemporaryMessageTimer(TObject *Sender)
{
	// Retrieve the timer
	TTimer *timer = dynamic_cast<TTimer *>(Sender);
	if (timer)
	{
		// Retrieve the form using the stored Tag value
		TForm *msgForm = reinterpret_cast<TForm *>(timer->Tag);
		if (msgForm)
		{
			// Close and delete the form
			msgForm->Close();
			delete msgForm;
		}

		// Stop and delete the timer
		timer->Enabled = false;
		delete timer;
	}
}


void SendPSKReport::ShowTemporaryMessage(String message, int milliseconds)
{
	// Create a temporary form
	TForm *msgForm = new TForm(Application);
	msgForm->BorderStyle = bsDialog;
	msgForm->Position = poScreenCenter;
	msgForm->Caption = "XDOptions"; // Optional title

	// Add a label to display the message
	TLabel *msgLabel = new TLabel(msgForm);
	msgLabel->Parent = msgForm;
	msgLabel->Caption = message;
	msgLabel->AutoSize = true;

	// Center the label and resize the form
	msgForm->ClientWidth = msgLabel->Width + 20; // Add padding
	msgForm->ClientHeight = msgLabel->Height + 20; // Add padding
	msgLabel->Left = (msgForm->ClientWidth - msgLabel->Width) / 2;
	msgLabel->Top = (msgForm->ClientHeight - msgLabel->Height) / 2;

	// Show the form
	msgForm->Show();

	// Create a timer to close the form after the specified duration
	TTimer *timer = new TTimer(NULL);
	timer->Interval = milliseconds;
	timer->Enabled = true;
	timer->OnTimer = TemporaryMessageTimer;

	// Store the form pointer in the Tag property
	timer->Tag = reinterpret_cast<int>(msgForm);
}



SendPSKReport::SendPSKReport() {

}

void SendPSKReport::Send(AnsiString myCall, AnsiString hisCall, AnsiString myLoc,AnsiString freq,AnsiString progVer,int reportType) {
	TFormatSettings formatSettings;
	formatSettings.DecimalSeparator = '.';
	double zm = StrToFloat(freq,formatSettings);
	long long hzValue = static_cast<long long>(zm * 1000000);
	AnsiString hzString = IntToStr(hzValue);

	// station_callsign,SP6XD,my_gridsquare,JO81ih,programid,MMSSTV,programversion,v113a
//  call,SP6PWS,mode,SSTV,freq,14233000,snr,8
/*	UnicodeString localInformation =
		"station_callsign," +
		AnsiString(sys.m_Call) +
		",my_gridsquare," +
		AnsiString(sys.m_PSKMyLocator) +
		",programid,MMSSTV-XD,programversion," +
		AnsiString(VERID) + AnsiString(VERBETA);

	UnicodeString remoteInformation =
		"call," +
		HisCall->Text +
		",mode,SSTV,freq," +
		hzString.c_str() +
		",snr,0";
 */

	UnicodeString localInformation =
		"station_callsign," +
		myCall +
		",my_gridsquare," +
		myLoc +
		",programid,MMSSTV-XD,programversion," +
		progVer;

	UnicodeString remoteInformation =
		"call," +
		hisCall +
		",mode,SSTV,freq," +
		hzString.c_str() +
		",snr,0";

//	ShowMessage(localInformation);
//	ShowMessage(remoteInformation);
	ShowTemporaryMessage("Report to PSKReporter sent",3000);

	int rc = ReporterSeenCallsign(remoteInformation.c_str(),localInformation.c_str(), reportType);

	if(rc) {
		ShowMessage("Error sending data to PSKReporter");
	}

}

SendPSKReport::~SendPSKReport() {


}


