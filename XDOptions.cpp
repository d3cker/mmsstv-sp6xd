#include "XDOptions.h"
#pragma hdrstop

#include <Vcl.Dialogs.hpp>
#include <vcl.h>
#include <System.hpp>
SendPSKReport::SendPSKReport() {

}

void SendPSKReport::Send(AnsiString myCall, AnsiString hisCall, AnsiString myLoc,AnsiString freq,AnsiString progVer,int reportType) {
//	AnsiString hzString = ConvertMHzToHzString(freq);

	TFormatSettings formatSettings;
	formatSettings.DecimalSeparator = '.';
	double zm = StrToFloat(freq,formatSettings);

	long long hzValue = static_cast<long long>(zm * 1000000);

	AnsiString hzString = IntToStr(hzValue);

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

	int rc = ReporterSeenCallsign(remoteInformation.c_str(),localInformation.c_str(), reportType);

	if(rc) {
		ShowMessage("Error sending data to PSKReporter");
	}

}

SendPSKReport::~SendPSKReport() {


}

/*
AnsiString SendPSKConvertMHzToHzString(const AnsiString& mhzString) {
	try {
		if (mhzString.IsEmpty()) {
			return "";
		}

		AnsiString result = mhzString;

		// If there's no decimal point, add ".0"
		if (result.Pos(".") == 0) {
			result = result + ".0";
		}

		// Remove the decimal point
		result = StringReplace(result, ".", "", TReplaceFlags());

		// Calculate how many zeros we need to add
		// Count digits after decimal in original string
		int decimalPos = mhzString.Pos(".");
		int digitsAfterDecimal = decimalPos > 0 ?
			mhzString.Length() - decimalPos : 0;

		// Add remaining zeros to reach Hz (need 6 zeros total for MHz to Hz)
		int zerosNeeded = 6 - digitsAfterDecimal;
		for(int i = 0; i < zerosNeeded; i++) {
			result = result + "0";
		}

		return result;
	}
	catch (...) {
		ShowMessage("Error in conversion");
		return "";
	}
}
*/