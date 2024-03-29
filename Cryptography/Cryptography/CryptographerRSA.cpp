///////////////////////////////////////////////////////////////////////////
// Workfile : CryptographerRSA.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Implementation of class CryptographerRSA
///////////////////////////////////////////////////////////////////////////

#include "CryptographerRSA.h"

void CryptographerRSA::Decrypt()
{
	std::string::iterator itor;
	for(itor = mData.begin();itor != mData.end();++itor)
	{
		DecryptRSA(*itor);
	}
}

void CryptographerRSA::Encrypt()
{
	std::string::iterator itor;
	for(itor = mData.begin();itor != mData.end();++itor)
	{
		EncryptRSA(*itor);
	}
}

void CryptographerRSA::EncryptRSA(char& ch)
{
	unsigned char tmp = ch;
	tmp = PowerModulo(int(tmp),e);
	ch = tmp;
}

void CryptographerRSA::DecryptRSA(char& ch)
{
	unsigned char tmp = ch;
	tmp = PowerModulo(int(tmp),d);
	ch = tmp;
}

//calculate x^(e|d) mod n
int CryptographerRSA::PowerModulo(int x, int ed)
{ 
	int result = 1;
	for (int i = 0; i < ed; ++i)
	{
		result = (result * x) % n;
	}
	return result; 
}

