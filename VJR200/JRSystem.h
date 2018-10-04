﻿// license:BSD-3-Clause
// copyright-holders:FIND
#ifndef __JRSYSTEM_H__
#define __JRSYSTEM_H__
#include "Crtc.h"
#include "Address.h"
#include "Mn1271.h"
#include "Mn1544.h"
#include "m6800.h"
#ifdef _WIN32
#include "Printer.h"
#include "ImagePrinter.h"
#include "TextPrinter.h"
#include "RawPrinter.h"
#endif

class JRSystem
{
public:
	JRSystem();
	~JRSystem();
	int Init();
	void Dispose();
	void Reset();
	void StepRun();
	void SetSaveState(int idx);
	void SetLoadState(int idx);
	Address* pAddress = nullptr;
	Crtc* pCrtc = nullptr;
	Mn1271* pMn1271 = nullptr;
	Mn1544* pMn1544 = nullptr;
	m6800_cpu_device* pCpu = nullptr;
#ifdef _WIN32
	Printer* pPrinter;
#endif
	void Save();
	void Load();
protected:
	int step;
	int stateSave = -1;
	int stateLoad = -1;
};

#endif