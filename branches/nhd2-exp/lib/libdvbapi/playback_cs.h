/*
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#ifndef __PLAYBACK_CS_H
#define __PLAYBACK_CS_H

#include <string>
#include <stdint.h>

#include <config.h>


class cPlayback
{
	private:
		int mSpeed;
		int mAudioStream;

	public:
		bool playing;
		
		bool Open();
		void Close(void);
		bool Start(char * filename);
		
		bool Play(void);
		bool SyncAV(void);
		
		bool Stop(void);
		bool SetAPid(unsigned short pid);

#if ENABLE_GSTREAMER
		void trickSeek(int ratio);
#endif		
		bool SetSpeed(int speed);
		bool SetSlow(int slow);
		bool GetSpeed(int &speed) const;
		void GetDuration(int &duration);
		bool GetPosition(int &position);
		bool SetPosition(int position);
		void FindAllPids(uint16_t *apids, unsigned short *ac3flags, uint16_t *numpida, std::string *language);

		cPlayback(int num = 0);
		~cPlayback();
		void getMeta();		
};

#endif