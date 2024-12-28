#ifndef XDOptionsH
#define XDOptionsH

#include "PSKReporter.h"
#include <System.hpp>

//#pragma comment(lib, "ws2_32.lib")



class SendPSKReport {

private:
	void __fastcall SendPSKReport::TemporaryMessageTimer(TObject *Sender);
	void ShowTemporaryMessage(String message, int milliseconds);
public:
	SendPSKReport();
	~SendPSKReport();

	void Send(AnsiString myCall, AnsiString hisCall, AnsiString myLoc, AnsiString freq, AnsiString progVer, int reportType);

};

#endif
