/*
	Neutrino-GUI  -   DBoxII-Project
	
	$Id: filebrowser.h 2013/10/12 mohousch Exp $

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


#ifndef __FILEBROWSER_HPP__
#define __FILEBROWSER_HPP__

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <driver/file.h>
#include <driver/framebuffer.h>
#include <driver/fontrenderer.h>
#include <driver/rcinput.h>

#include <gui/color.h>
#include <gui/infoviewer.h>

#include <gui/widget/menue.h>
#include <gui/widget/progresswindow.h>

#include <system/settings.h>

#include <string>
#include <vector>


/**
 * Converts input of numeric keys to SMS style char input.
 */
class SMSKeyInput
{
	// time since last input
	timeval m_oldKeyTime;

	// last key input
	unsigned char m_oldKey;

	// keypresses within this period are taken as a sequence
	int m_timeout;
	public:
		SMSKeyInput();

		/**
		* Returns the SMS char calculated with respect to the new input.
		* @param msg the current RC input
		* @return the calculated SMS char
		*/
		unsigned char handleMsg(const neutrino_msg_t msg);

		/**
		* Resets the key history which is needed for proper calculation
		* of the SMS char by #handleMsg(neutrino_msg_t)
		*/
		void resetOldKey();

		/**
		* @return the last key calculated by #handleMsg(neutrino_msg_t)
		*/
		unsigned char getOldKey() const;
		
		/**
		* Returns time of last key push.
		* resolution: usecs
		*/
		const timeval* getOldKeyTime() const;

		/**
		* Returns time of last key push.
		* resolution: seconds
		*/
		time_t getOldKeyTimeSec() const;

		int getTimeout() const;

		/**
		* Sets the timeout.
		* @param timeout keypresses within this period are taken as a
		* sequence. unit: msecs
		*/
		void setTimeout(int timeout);
};

class CFileFilter
{
	std::vector<std::string> Filter;
	
	public:
		void addFilter(const std::string & filter){Filter.push_back(filter);};
		bool matchFilter(const std::string & name)
		{
			int ext_pos = 0;
			ext_pos = name.rfind('.');
			if( ext_pos > 0)
			{
				std::string extension;
				extension = name.substr(ext_pos + 1, name.length() - ext_pos);
				for(unsigned int i = 0; i < Filter.size();i++)
					if(strcasecmp(Filter[i].c_str(),extension.c_str()) == 0)
						return true;
			}
			return false;
		};
		void Clear(void) { Filter.clear();};
};

#define FILEBROWSER_NUMBER_OF_SORT_VARIANTS 5

class CFileBrowser
{
	private:
		CFrameBuffer * frameBuffer;

		CFileList selected_filelist;
		CFileList filelist;
		
		std::string Path;
		
		bool readDir(const std::string & dirname, CFileList* flist);
		void addRecursiveDir(CFileList * re_filelist, std::string path, bool bRootCall, CProgressWindow * progress = NULL);
		/**
		 * @param selection select the specified entry, ignored if selection == -1
		 */
		void ChangeDir(const std::string & filename, int selection = -1);
		
		void SMSInput(const neutrino_msg_t msg);

		unsigned int selected;
		unsigned int liststart;
		unsigned int listmaxshow;
		std::vector<unsigned int> selections;

		int fheight;	// Fonthoehe Filelist-Inhalt
		int theight;	// Fonthoehe Filelist-Titel
		int foheight;	// Hoehe der button leiste
		
		std::string name;
		std::string base;
		
		int width;
		int height;
		
		bool bCancel;

		int x;
		int y;

		SMSKeyInput m_SMSKeyInput;

		void paintItem(unsigned pos);
		void paint();
		void paintHead();
		void paintFoot();
		void recursiveDelete(const char* file);
		void hide();

	protected:
		void commonInit();

	public:
		bool Multi_Select;
		bool Dirs_Selectable;
		bool Dir_Mode;
		bool Hide_records;
		bool use_filter;
		
		CFileFilter * Filter;

		CFileBrowser();
		CFileBrowser(const char * const _base);
		~CFileBrowser();

		bool exec(const char * const dirname);
		CFile *getSelectedFile();
		
		inline const CFileList &getSelectedFiles(void) const
		{
			return selected_filelist;
		}

		inline const std::string & getCurrentDir(void) const
		{
			return Path;
		}
};

#endif
