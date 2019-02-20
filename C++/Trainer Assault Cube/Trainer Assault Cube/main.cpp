#include <iostream>
#include <Windows.h>
#include <string>
#include <ctime>

DWORD FindDmaAddy(int PointerLevel, HANDLE hProcHandle, DWORD Offsets[], DWORD BaseAddress);
void WriteToMemory(HANDLE hProcHandle);



using namespace std;

std::string GameName = "AssaultCube";
LPCSTR LGameWindow = "AssaultCube";
std::string GameStatus = "NULL";

bool b_GameAvailable = false;
bool b_UpdateAmmoNextRun = false;

//AMMO VARS
bool AmmoStatus = false;
BYTE AmmoValue[] = { 0xA3, 0x1C, 0x0, 0x0 };
DWORD AmmoBaseAddress = { 0x0051E20C };
DWORD AmmoOffsets[] = { 0x378, 0x14, 0x0 };

// Health VARS
bool HealthStatus = false;
BYTE HealthValue[] = { 0x39, 0x5, 0x0, 0x0 };
DWORD HealthAddress = { 0x0051E20C };
DWORD HealthOffsets[] = { 0xF8 };

int main ()
{
	HWND hGameWindow = nullptr;
	int timeSinceLastUpdate = clock();
	int GameAvailTMR = clock();
	int onePressTMR = clock();
	DWORD dwProcID = NULL;
	HANDLE hProcHandle = nullptr;

	bool UpdateOnRun = true;
	b_UpdateAmmoNextRun = true;
	string sAmmoStatus = "NULL";
	string sHealthStatus = "NULL";

	while(!GetAsyncKeyState((VK_INSERT)))
	{
		if (clock() - GameAvailTMR > 100)
		{
			GameAvailTMR = clock();
			b_GameAvailable = false;

			hGameWindow = FindWindow(nullptr, LGameWindow);
			if (hGameWindow)
			{
				GetWindowThreadProcessId(hGameWindow, &dwProcID);
				if (dwProcID != 0)
				{
					hProcHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcID);
					if(hProcHandle == INVALID_HANDLE_VALUE || hProcHandle == nullptr)
					{
						GameStatus = "Failed to open process for valid handle";
					}
					else
					{
						GameStatus = "Game ready to Hack!";
						b_GameAvailable = true;
					}
				}
				else
				{
					GameStatus = "Failed to get process ID";
				}
			}
			else
			{
				GameStatus = "Game NOT FOUND!";
			}
		}

		if (UpdateOnRun || clock() - timeSinceLastUpdate > 5000)
		{
			system("cls");
			cout << "--------------------------------------------------------" << endl;
			cout << "      Assault Cube Hacker Trainer + 2 by: TheVoid       " << endl;
			cout << "--------------------------------------------------------" << endl;

			cout << "Game Status: " << GameStatus << endl << endl;
			cout << "[F1] Unlimited Ammo -> " << sAmmoStatus << endl << endl;
			cout << "[F2] Unlimited Health -> " << sHealthStatus << endl << endl;
			cout << "[INSERT] Exit Hack" << endl;
			UpdateOnRun = false;
			timeSinceLastUpdate = clock();
		}

		if (b_GameAvailable)
		{
			WriteToMemory(hProcHandle);
		}

		if (clock() - onePressTMR > 400)
		{
			if (b_GameAvailable)
			{
				if (GetAsyncKeyState(VK_F1))
				{
					onePressTMR = clock();
					AmmoStatus = !AmmoStatus;
					UpdateOnRun = true;

					if (AmmoStatus)
						sAmmoStatus = "ON";
					else
					sAmmoStatus = "OFF";
				}

				else if (GetAsyncKeyState(VK_F2))
				{
					onePressTMR = clock();
					HealthStatus = !HealthStatus;
					UpdateOnRun = true;

					if (HealthStatus)
						sHealthStatus = "ON";
					else
					sHealthStatus = "OFF";
				}
			}
		}
	}

	CloseHandle(hProcHandle);
	CloseHandle(hGameWindow);

	return ERROR_SUCCESS;
}

DWORD FindDmaAddy(int PointerLevel, HANDLE hProcHandle, DWORD Offsets[], DWORD BaseAddress)
{
	DWORD pointer = BaseAddress;
	DWORD pTemp = NULL;

	DWORD pointerAddr = NULL;

	for (int c = 0; c < PointerLevel; c++)
	{
		
		if ( c == 0)
		{
			ReadProcessMemory(hProcHandle, (LPCVOID)pointer, &pTemp, sizeof(pTemp), nullptr);
		}

		pointerAddr = pTemp + Offsets[c];
		ReadProcessMemory(hProcHandle, (LPCVOID)pointerAddr, &pTemp, sizeof(pTemp), nullptr);
	}
	return pointerAddr;
}

void WriteToMemory(HANDLE hProcHandle)
{
	if (AmmoStatus)
	{
		DWORD AmmoAddressToWrite = FindDmaAddy(sizeof(AmmoOffsets) / sizeof(int), hProcHandle, AmmoOffsets, AmmoBaseAddress);
		WriteProcessMemory(hProcHandle, reinterpret_cast<BYTE*>(AmmoAddressToWrite), &AmmoValue, sizeof(AmmoValue), nullptr);
	}

	if (HealthStatus)
	{
		DWORD HealthAddressToWrite = FindDmaAddy(sizeof(HealthOffsets) / sizeof(int), hProcHandle, HealthOffsets, AmmoBaseAddress);
		WriteProcessMemory(hProcHandle, reinterpret_cast<BYTE*>(HealthAddressToWrite), &HealthValue, sizeof(HealthValue), nullptr);
	}
}