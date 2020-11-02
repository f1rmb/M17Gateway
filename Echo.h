/*
*   Copyright (C) 2016,2020 by Jonathan Naylor G4KLX
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation; either version 2 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program; if not, write to the Free Software
*   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#if !defined(Echo_H)
#define	Echo_H

#include "StopWatch.h"
#include "Timer.h"

enum ECHO_STATUS {
	ES_NONE,
	ES_RECORDING,
	ES_WAITING,
	ES_PLAYING
};

class CEcho
{
public:
	CEcho(unsigned int timeout);
	~CEcho();

	bool write(const unsigned char* data);

	bool read(unsigned char* data);

	void end();

	void clear();

	void clock(unsigned int ms);

private:
	unsigned char* m_data;
	unsigned int   m_length;
	unsigned int   m_used;
	unsigned int   m_ptr;
	ECHO_STATUS    m_status;
	CTimer         m_timer;
	CStopWatch     m_stopWatch;
	unsigned int   m_sent;
};

#endif
