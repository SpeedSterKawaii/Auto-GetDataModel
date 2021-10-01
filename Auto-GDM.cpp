/*
  Grabs the GDM from the Internet :)
  Credit me if your going to use it.
*/

// Hi roblox why are you reading this?

#define Bypass(e) (e - 0x400000 + (DWORD)GetModuleHandleA(0))

int GDM_Offset = 0; // let this be 0 dont update it.
#define GDM_Convention __thiscall // prob nevar updates

typedef DWORD(GDM_Convention* my_gdm)(DWORD g, DWORD a);
my_gdm GDM_Usage = (my_gdmc)(Bypass(GDM_Offset));

bool DidItReplace()
{
  return GDM_Offset == NULL;
}

static int MY_MAIN()
{
   MessageBoxA(NULL, "Grabbing latest get-data-model.", "Auto GDM", NULL);
   GDM_Offset = 0;//hahahhahfahfafh U THOUGHT U SKID
   std::cout << "Ok, GDM is "<< GDM_Offset << endl; //std 
}
