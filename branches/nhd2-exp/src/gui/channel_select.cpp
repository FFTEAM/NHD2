/*
	* $Id: channel_select.cpp 2015/07/26 11:23:30 mohousch Exp $
	
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

/*zapit includes*/
#include <bouquets.h>

#include "gui/channel_select.h"

#include <global.h>
#include <neutrino.h>

#include <gui/bouquetlist.h>

#include <system/debug.h>


t_channel_id CSelectChannelWidget_TVChanID;
std::string CSelectChannelWidget_TVChanName;
t_channel_id CSelectChannelWidget_RadioChanID;
std::string CSelectChannelWidget_RadioChanName;

extern CBouquetList * bouquetList;

//select menu
CSelectChannelWidget::CSelectChannelWidget()
{
	CSelectChannelWidget_TVChanID = 0;
	CSelectChannelWidget_TVChanName.clear();
	
	CSelectChannelWidget_RadioChanID = 0;
	CSelectChannelWidget_RadioChanName.clear();
}

CSelectChannelWidget::~CSelectChannelWidget()
{
	CSelectChannelWidget_TVChanID = 0;
	CSelectChannelWidget_TVChanName.clear();
	
	CSelectChannelWidget_RadioChanID = 0;
	CSelectChannelWidget_RadioChanName.clear();
}

int CSelectChannelWidget::exec(CMenuTarget *parent, const std::string &actionKey)
{
	int   res = menu_return::RETURN_REPAINT;
	
	dprintf(DEBUG_NORMAL, "CSelectChannelWidget::exec: actionKey:%s\n", actionKey.c_str());

	if (parent)
		parent->hide();

	if(actionKey == "tv")
	{
		InitZapitChannelHelper(CZapitClient::MODE_TV);
		return res;
	}
	else if(actionKey == "radio")
	{
		InitZapitChannelHelper(CZapitClient::MODE_RADIO);
		return res;
	}

	return res;
}

void CSelectChannelWidget::InitZapitChannelHelper(CZapitClient::channelsMode mode)
{
	// set channel mode
	if(mode == CZapitClient::MODE_TV)
	{
		CNeutrinoApp::getInstance()->SetChannelMode(g_settings.channel_mode, NeutrinoMessages::mode_tv);
	}
	else if(mode == CZapitClient::MODE_RADIO)
	{
		CNeutrinoApp::getInstance()->SetChannelMode(g_settings.channel_mode, NeutrinoMessages::mode_radio);
	}
	
	int nNewChannel;
	int nNewBouquet;
	
	nNewBouquet = bouquetList->show(true);
			
	if (nNewBouquet > -1)
	{
		nNewChannel = bouquetList->Bouquets[nNewBouquet]->channelList->show();
		
		if (nNewChannel > -1)
		{
			if(mode == CZapitClient::MODE_TV)
			{
				CSelectChannelWidget_TVChanID = bouquetList->Bouquets[nNewBouquet]->channelList->getActiveChannel_ChannelID();
				CSelectChannelWidget_TVChanName = g_Zapit->getChannelName(CSelectChannelWidget_TVChanID);
			}
			else if(mode == CZapitClient::MODE_RADIO)
			{
				CSelectChannelWidget_RadioChanID = bouquetList->Bouquets[nNewBouquet]->channelList->getActiveChannel_ChannelID();
				CSelectChannelWidget_RadioChanName = g_Zapit->getChannelName(CSelectChannelWidget_RadioChanID);
			}
		}
	}
	
	// set channel mode
	if( (CNeutrinoApp::getInstance()->getMode() == NeutrinoMessages::mode_tv) && (mode == CZapitClient::MODE_RADIO) )
	{
		CNeutrinoApp::getInstance()->SetChannelMode( g_settings.channel_mode, NeutrinoMessages::mode_tv);
	}
	else if( (CNeutrinoApp::getInstance()->getMode() == NeutrinoMessages::mode_radio) && (mode == CZapitClient::MODE_TV) )
	{
		CNeutrinoApp::getInstance()->SetChannelMode( g_settings.channel_mode, NeutrinoMessages::mode_radio);
	}
}
