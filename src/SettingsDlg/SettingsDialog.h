//this file is part of Hex Edit Plugin for Notepad++
//Copyright (C)2006 Jens Lorenz <jens.plugin.npp@gmx.de>
//
//This program is free software; you can redistribute it and/or
//modify it under the terms of the GNU General Public License
//as published by the Free Software Foundation; either
//version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program; if not, write to the Free Software
//Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


#pragma once


#include "StaticDialog.h"
#include "resource.h"
#include "Compare.h"
#include "ColorCombo.h"
#include <vector>
#include <string>

using namespace std;

class SettingsDialog : public StaticDialog
{

public:
	SettingsDialog() : StaticDialog() {};

	void init(HINSTANCE hInst, NppData nppDataParam)
	{
		_nppData = nppDataParam;
		Window::init(hInst, nppDataParam._nppHandle);
	};

	UINT doDialog(UserSettings* settings);

	virtual void destroy() {};

protected :
	INT_PTR CALLBACK run_dlgProc(UINT Message, WPARAM wParam, LPARAM lParam);

	void SetParams(UserSettings* settings = nullptr);
	void GetParams();

private:
	/* Handles */
	NppData			_nppData;
	HWND			_HSource;

	// Combo color picker
	ColorCombo _ColorComboAdded;
	ColorCombo _ColorComboMoved;
	ColorCombo _ColorComboRemoved;
	ColorCombo _ColorComboChanged;
	ColorCombo _ColorComboBlank;
	ColorCombo _ColorComboHighlight;

	struct UserSettings* _Settings;
};
