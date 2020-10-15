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
#ifndef	__MP4PROCESSOR__
#define	__MP4PROCESSOR__
/*
 * 	Handling superframes for DAB+ and delivering
 * 	frames into the ffmpeg or faad decoding library
 */
//
#include	"dab-constants.h"
#include	<stdio.h>
#include	<stdint.h>
#include	"backend-base.h"
#include	"dab-api.h"
#include	"firecode-checker.h"
#include	"reed-solomon.h"
#include	"faad-decoder.h"
#include	"pad-handler.h"


class	mp4Processor : public backendBase {
public:
			mp4Processor	(int16_t,
	                                 callbacks	*,
	                                 void	*);
			~mp4Processor	(void);
	void		addtoFrame	(uint8_t *);
private:
	bool		processSuperframe (uint8_t [], int16_t);
	callbacks	*the_callBacks;
	void		*ctx;
	padHandler	my_padHandler;
	int16_t		superFramesize;
	int16_t		blockFillIndex;
	int16_t		blocksInBuffer;
	int16_t		bitRate;
	std::vector<uint8_t> frameBytes;
	std::vector<uint8_t> outVector;
	int16_t		RSDims;
	int16_t		au_start	[10];

	firecode_checker	fc;
	reedSolomon	my_rsDecoder;
//	and for the aac decoder
	faadDecoder	aacDecoder;

	int16_t		frameCount;
	int16_t		successFrames;
	int16_t		frameErrors;
	int16_t		rsErrors;
	int16_t		aacErrors;
	int16_t		aacFrames;

	int16_t		frame_quality;
	int16_t		rs_quality;
	int16_t		aac_quality;

	void            show_frameErrors        (int);
        void            show_rsErrors           (int);
        void            show_aacErrors          (int);

	void		isStereo		(bool);
};

#endif


