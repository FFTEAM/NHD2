/*
	Neutrino-GUI  -   DBoxII-Project
	
	$Id: messagebox.h 2013/10/12 mohousch Exp $

	Copyright (C) 2001 Steffen Hehn 'McClean'
	Homepage: http://dbox.cyberphoria.org/

	Kommentar:

	Diese GUI wurde von Grund auf neu programmiert und sollte nun vom
	Aufbau und auch den Ausbaumoeglichkeiten gut aussehen. Neutrino basiert
	auf der Client-Server Idee, diese GUI ist also von der direkten DBox-
	Steuerung getrennt. Diese wird dann von Daemons uebernommen.


	License: GPL

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/


#ifndef __messagebox__
#define __messagebox__

#include <system/settings.h>
#include <gui/widget/hintboxext.h>

#include <stdint.h>
#include <string>


class CMessageBox : public CHintBoxExt
{
	private:
		int  showbuttons;
		bool returnDefaultOnTimeout;

		void paintButtons();

	public:
		enum result_
		{
			mbrYes    = 0,
			mbrNo     = 1,
			mbrCancel = 2,
			mbrBack   = 3,
			mbrOk     = 4
		} result;
	
		enum buttons_
		{
			mbYes= 0x01,
			mbNo = 0x02,
			mbCancel = 0x04,
			mbAll = 0x07,
			mbBack = 0x08,
			mbOk = 0x10
		} buttons;
	
		// Text & Caption are always UTF-8 encoded
		CMessageBox(const neutrino_locale_t Caption, const char * const Text, const int Width = HINTBOX_WIDTH, const char * const Icon = NULL, const CMessageBox::result_ Default = mbrYes, const uint32_t ShowButtons = mbAll);
		CMessageBox(const neutrino_locale_t Caption, ContentLines& Lines, const int Width = HINTBOX_WIDTH, const char * const Icon = NULL, const CMessageBox::result_ Default = mbrYes, const uint32_t ShowButtons = mbAll);
		CMessageBox(const char * const Caption, const char * const Text, const int Width = HINTBOX_WIDTH, const char * const Icon = NULL, const CMessageBox::result_ Default = mbrYes, const uint32_t ShowButtons = mbAll);
		CMessageBox(const char * const Caption, ContentLines& Lines, const int Width = HINTBOX_WIDTH, const char * const Icon = NULL, const CMessageBox::result_ Default = mbrYes, const uint32_t ShowButtons = mbAll);

		int exec(int timeout = -1);
		void returnDefaultValueOnTimeout(bool returnDefault);
};

// Text is always UTF-8 encoded
int MessageBox(const neutrino_locale_t Caption, const neutrino_locale_t Text, const CMessageBox::result_ Default, const uint32_t ShowButtons, const char * const Icon = NULL, const int Width = MENU_WIDTH, const int timeout = -1, bool returnDefaultOnTimeout = false);
int MessageBox(const neutrino_locale_t Caption, const char * const Text, const CMessageBox::result_ Default, const uint32_t ShowButtons, const char * const Icon = NULL, const int Width = MENU_WIDTH, const int timeout = -1, bool returnDefaultOnTimeout = false); // UTF-8
int MessageBox(const neutrino_locale_t Caption, const std::string & Text, const CMessageBox::result_ Default, const uint32_t ShowButtons, const char * const Icon = NULL, const int Width = MENU_WIDTH, const int timeout = -1, bool returnDefaultOnTimeout = false); // UTF-8
int MessageBox(const char * const Caption, const neutrino_locale_t Text, const CMessageBox::result_ Default, const uint32_t ShowButtons, const char * const Icon = NULL, const int Width = MENU_WIDTH, const int timeout = -1, bool returnDefaultOnTimeout = false);
int MessageBox(const char * const Caption, const char * const Text, const CMessageBox::result_ Default, const uint32_t ShowButtons, const char * const Icon = NULL, const int Width = MENU_WIDTH, const int timeout = -1, bool returnDefaultOnTimeout = false); // UTF-8
int MessageBox(const char * const Caption, const std::string & Text, const CMessageBox::result_ Default, const uint32_t ShowButtons, const char * const Icon = NULL, const int Width = MENU_WIDTH, const int timeout = -1, bool returnDefaultOnTimeout = false); // UTF-8

#endif
