#ifndef XDOptionsH
#define XDOptionsH

#include <System.hpp>
#include <vcl.h>
#include "PSKReporter.h"
//#include "ComLib.h"
#include "LogFile.h"
#include "UDPSender.h"

//#pragma comment(lib, "ws2_32.lib")

class XDOptions {

private:
	void __fastcall TemporaryMessageTimer(TObject *Sender);
	void ShowTemporaryMessage(String message, int milliseconds);
public:
	XDOptions();
	~XDOptions();
	void SendPSKReport(AnsiString myCall, AnsiString hisCall, AnsiString myLoc, AnsiString freq, AnsiString progVer, int reportType);
	void SendUDPLog();
};

#endif
