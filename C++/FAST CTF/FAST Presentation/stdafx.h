// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <shlobj.h> // Needed to use the SHGetFolderPath function.
#include <string>
#include <stdio.h>
#include <windows.h>
#include "C:\Users\MuscleNerd\curl\builds\libcurl-vc-x64-release-dll-ipv6-sspi-winssl\include\curl/curl.h"
#pragma comment(lib, "urlmon.lib")

std::string sz_get_user_name();
std::string sz_get_password();
void print_Console(std::string text);
void print_FASTCTF();
std::string XOR(std::string data, char * key);
std::string encryptDecrypt(std::string toEncrypt);
void print_hacked(std::string text);
std::wstring s2ws(const std::string& s);
void download_files();
PTCHAR GetDesktopfilePath(PTCHAR filePath);
BOOL IsElevated();
inline bool exists_test1(const std::string& name);
std::wstring s2ws(const std::string& s);


// TODO: reference additional headers your program requires here
