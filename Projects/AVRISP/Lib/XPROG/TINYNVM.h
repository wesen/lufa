/*
             LUFA Library
     Copyright (C) Dean Camera, 2009.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2009  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, and distribute this software
  and its documentation for any purpose and without fee is hereby
  granted, provided that the above copyright notice appear in all
  copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for TINYNVM.c.
 */

#ifndef _TINY_NVM_
#define _TINY_NVM_

	/* Includes: */
		#include <avr/io.h>
		#include <avr/interrupt.h>
		#include <stdbool.h>
		
		#include <LUFA/Common/Common.h>
		
		#include "XPROGProtocol.h"
		#include "XPROGTarget.h"
	
	/* Preprocessor Checks: */
		#if ((BOARD == BOARD_XPLAIN) || (BOARD == BOARD_XPLAIN_REV1))
			#undef ENABLE_ISP_PROTOCOL
			
			#if !defined(ENABLE_XPROG_PROTOCOL)
				#define ENABLE_XPROG_PROTOCOL
			#endif
		#endif

	/* Defines: */
		#define TINY_NVM_BUSY_TIMEOUT_MS       100

	/* Function Prototypes: */
		bool TINYNVM_WaitWhileNVMControllerBusy(void);
		bool TINYNVM_ReadMemory(const uint32_t ReadAddress, uint8_t* ReadBuffer, const uint16_t ReadSize);
		bool TINYNVM_WriteMemory(const uint8_t WriteCommand, const uint32_t WriteAddress, const uint8_t* WriteBuffer);
		bool TINYNVM_EraseMemory(const uint8_t EraseCommand, const uint32_t Address);
		bool TINYNVM_WaitWhileNVMBusBusy(void);

#endif
