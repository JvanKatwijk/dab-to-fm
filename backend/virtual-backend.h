#
/*
 *    Copyright (C) 2020
 *    Jan van Katwijk (J.vanKatwijk@gmail.com)
 *    Lazy Chair Computing
 *
 *    This file is part of pluto-dab-fm
 *
 *    pluto-dab-fm is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    pluto-dab-fm is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with pluto-dab-fm; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#
#ifndef __VIRTUAL_BACKEND__
#define	__VIRTUAL_BACKEND__

#include	<stdint.h>
#include	<stdio.h>


#define	CUSize	(4 * 16)

class	virtualBackend {
public:
		virtualBackend	(int16_t, int16_t);
virtual		~virtualBackend	(void);
virtual int32_t	process		(int16_t *, int16_t);
virtual void	stopRunning	(void);
virtual	void	stop		(void);
	int16_t	startAddr	(void);
	int16_t	Length		(void);
protected:
	int16_t startAddress;
	int16_t	segmentLength;
};
#endif


