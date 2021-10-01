/*
  Grabs the GDM from the Internet :)
  Credit me if your going to use it.
*/

// Hi roblox why are you reading this?

#include <Windows.h>
#include <string>
#include <WinInet.h>
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "wininet.lib")

std::string replaceAll(std::string subject, const std::string& search,//cringy
	const std::string& replace) {
	size_t pos = 0;
	while ((pos = subject.find(search, pos)) != std::string::npos) {
		subject.replace(pos, search.length(), replace);
		pos += replace.length();
	}
	return subject;
}

std::string GrabStringFromURL(const char* URL) //cringy
{
	HINTERNET interwebs = InternetOpenA("Mozilla/5.0", INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, NULL);
	HINTERNET urlFile;
	std::string rtn;
	if (interwebs) {
		urlFile = InternetOpenUrlA(interwebs, URL, NULL, NULL, NULL, NULL);
		if (urlFile) {
			char buffer[2000];
			DWORD bytesRead;
			do {
				InternetReadFile(urlFile, buffer, 2000, &bytesRead);
				rtn.append(buffer, bytesRead);
				memset(buffer, 0, 2000);
			} while (bytesRead);
			InternetCloseHandle(interwebs);
			InternetCloseHandle(urlFile);
			std::string p = replaceAll(rtn, "|n", "\r\n");
			return p;
		}
	}
	InternetCloseHandle(interwebs);
	std::string p = replaceAll(rtn, "|n", "\r\n");
	return p;
}

#define Bypass(e) (e - 0x400000 + (DWORD)GetModuleHandleA(0))

string GDM = GrabStringFromURL("https://raw.githubusercontent.com/SpeedSterKawaii/Auto-GetDataModel/main/GDM.txt");//DO NOT CHANGE!
 
static bool Status;//;)

int GDM_Offset = 0; // let this be 0 dont update it.
#define GDM_Convention __thiscall // prob nevar updates

typedef DWORD(GDM_Convention* my_gdm)(DWORD g, DWORD a);
my_gdm GDM_Usage = (my_gdmc)(Bypass(GDM_Offset));

bool DidItReplace()//did it replace? nope!
{
  return GDM_Offset == NULL;
}

static int MY_MAIN()
{
   Status = true;
   MessageBoxA(NULL, "Grabbing latest get-data-model.", "Auto GDM", NULL);
   int GDM_Grabbed = std::stoi(GDM);
   GDM_Offset = GDM_Grabbed;//switch it up
   MessageBoxA(NULL, GDM_Offset, "Hehe-GDM", NULL);
   if (GDM_Offset == NULL && GDM_Grabbed == NULL)
   {
	MessageBoxA(NULL, "Returned a FALSE","FALSE", NULL);//obv didnt replace
        Status = false;
   }
   getchar(); exit(NULL);
	return NULL;
}
