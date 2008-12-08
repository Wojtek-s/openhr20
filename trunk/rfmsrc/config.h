/*
 *  Open HR20
 *
 *  target:     ATmega169 @ 4 MHz in Honnywell Rondostat HR20E
 *
 *  compiler:    WinAVR-20071221
 *              avr-libc 1.6.0
 *              GCC 4.2.2
 *
 *  copyright:  2008 Juergen Sachs (juergen-sachs-at-gmx-dot-de)
 *				2008 Jiri Dobry (jdobry-at-centrum-dot-cz)
 *
 *  license:    This program is free software; you can redistribute it and/or
 *              modify it under the terms of the GNU Library General Public
 *              License as published by the Free Software Foundation; either
 *              version 2 of the License, or (at your option) any later version.
 *
 *              This program is distributed in the hope that it will be useful,
 *              but WITHOUT ANY WARRANTY; without even the implied warranty of
 *              MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *              GNU General Public License for more details.
 *
 *              You should have received a copy of the GNU General Public License
 *              along with this program. If not, see http:*www.gnu.org/licenses
 */

/*!
 * \file       config.h
 * \brief      This headerfile only contains information about the configuration of the HR20E and its functionality
 * \author     Juergen Sachs (juergen-sachs-at-gmx-dot-de) Jiri Dobry <jdobry-at-centrum-dot-cz>
 * \date       $Date$
 * $Rev$
 */

/*
In this file we define only configuration parameters, for example what kind of control port we have.
*/

#ifndef CONFIG_H
#define CONFIG_H

// AVR LibC includes 
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <avr/version.h>


#define LANG_uni 1
#define LANG_de 2
#define LANG_cs 3
//! language
#define LANG LANG_uni
//#define LANG LANG_de
//#define LANG LANG_cs

// our Version
#define REVHIGH  0  //! Revision number high
#define REVLOW   92 //! Revision number low
#define VERSION_N 0xA092 //! Version as HEX value F0.92 (F as free)  (A is for mArio's internal experiments)

#define DEVICE_ADDRESS 0x01 //! Individual Device Adress for each HR20 for addressing in Networks (e.g. RFM Radio)

#ifndef REVISION
 #define REVISION "$Rev$"
#endif 
#define VERSION_STRING  "V: OpenHR20 SW version 0.92 build " __DATE__ " " __TIME__ " " REVISION

// Parameters for the COMM-Port
#define COM_BAUD_RATE 9600
// Note we should only enable of of the following at one time
/* we support RS232 */
#define COM_RS232 1
/* we support RS485 */
/* #define COM_RS485  */
/* Our default Adress, if not set or invalid */
/* #define COM_DEF_ADR 1 */

#define DEFAULT_TEMPERATURE 2000 

#define RFM 1 //!< define RFM to 1 if you want to have support for the RFM Radio Moodule in the Code

#ifdef RFM
	#define RFM12 1 // just a synonym
	#define RFM_DEVICE_ADDRESS 0x04
#else
	#undef RFM12
#endif


// Some default Values
#define BOOT_DD         1  //!< Boot-Up date: day
#define BOOT_MM        10  //!< Boot-Up date: month
#define BOOT_YY         8  //!< Boot-Up date: year
#define BOOT_hh        12  //!< Boot-Up time: hour
#define BOOT_mm        00  //!< Boot-Up time: minutes

/**********************/
/* code configuration */
/**********************/

// enable D part of PID controller
#define CONFIG_ENABLE_D 0


/* compiler compatibility */
#ifndef ISR_NAKED
#   define ISR_NAKED      __attribute__((naked))
#endif


/* revision remarks
 **************
 */ 


// some handy macros

#define	ELEMCNT(A)							(sizeof(A) / ELEMSIZE(A))
#define	OFFSETOF(TYPE, ELEM)				((size_t)((char *)&((TYPE *) 0)->ELEM - (char*)((TYPE*)NULL)))
#define CMP(X,Y)							(((X) == (Y)) ? 0 : (((X) < (Y)) ? -1 : +1))
#define LITERAL_STRLEN(S)					(sizeof(S) - sizeof('\0'))
#define ARRAY(TYPE, PTR, INDEX)				((TYPE*)(PTR))[INDEX]

#define INDEX_TO_MASK(INDEX)				(1 << (INDEX))
#define BV(INDEX)							INDEX_TO_MASK(INDEX)

#define BIT_GET(VAR, INDEX)					((VAR) & INDEX_TO_MASK(INDEX))
#define BIT_SET(VAR, INDEX)					(VAR) |= INDEX_TO_MASK(INDEX)
#define BIT_TOG(VAR, INDEX)					(VAR) ^= INDEX_TO_MASK(INDEX)
#define BIT_CLR(VAR, INDEX)					(VAR) &= ~INDEX_TO_MASK(INDEX)
#define BIT_CLEAR(VAR, INDEX)				BIT_CLR(VAR, INDEX)

#define DDR_OUT(DDR, BITPOS)				BIT_SET(DDR, BITPOS)
#define DDR_IN(DDR, BITPOS)					BIT_CLR(DDR, BITPOS)

#endif /* CONFIG_H */
