/* Copyright (c) 2007 Anatoly Sokolov 
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id: iousbxx2.h,v 1.3 2007/05/12 11:40:46 aesok Exp $ */

/* iousbxx2.h - definitions for AT90USB82 and AT90USB162.  */

#ifndef _AVR_IOUSBXX2CXX_H_
#define _AVR_IOUSBXX2CXX_H_ 1

#include "ioxxx_cpp_macros.h"

/* Registers and associated bit numbers */

/* Reserved [0x00..0x02] */

#define CXX_PINB    _SFR_IO8_CXX(0X03)
#define CXX_DDRB    _SFR_IO8_CXX(0x04)

#define CXX_PORTB   _SFR_IO8_CXX(0x05)
#define CXX_PINC    _SFR_IO8_CXX(0x06)
#define CXX_DDRC    _SFR_IO8_CXX(0x07)
#define CXX_PORTC   _SFR_IO8_CXX(0x08)

#define CXX_PIND    _SFR_IO8_CXX(0x09)
#define CXX_DDRD    _SFR_IO8_CXX(0x0A)
#define CXX_PORTD   _SFR_IO8_CXX(0x0B)

/* Reserved [0xC..0x14] */

#define CXX_TIFR0   _SFR_IO8_CXX(0x15)
#define CXX_TIFR1   _SFR_IO8_CXX(0x16)

/* Reserved [0x17..0x1A] */

#define CXX_PCIFR   _SFR_IO8_CXX(0x1B)
#define CXX_EIFR    _SFR_IO8_CXX(0x1C)
#define CXX_EIMSK   _SFR_IO8_CXX(0x1D)
#define CXX_GPIOR0  _SFR_IO8_CXX(0x1E)

#define CXX_EECR    _SFR_IO8_CXX(0x1F)
#define CXX_EEDR    _SFR_IO8_CXX(0x20)

#define CXX_EEAR    _SFR_IO16_CXX(0x21)
#define CXX_EEARL   _SFR_IO8_CXX(0x21)
#define CXX_EEARH   _SFR_IO8_CXX(0x22)

#define CXX_GTCCR   _SFR_IO8_CXX(0x23)
#define CXX_TCCR0A  _SFR_IO8_CXX(0x24)
#define CXX_TCCR0B  _SFR_IO8_CXX(0x25)
#define CXX_TCNT0   _SFR_IO8_CXX(0X26)

#define CXX_OCR0A   _SFR_IO8_CXX(0x27)

#define CXX_OCR0B   _SFR_IO8_CXX(0X28)

#define CXX_PLLCSR  _SFR_IO8_CXX(0x29)

#define CXX_GPIOR1  _SFR_IO8_CXX(0x2A)

#define CXX_GPIOR2  _SFR_IO8_CXX(0x2B)

#define CXX_SPCR    _SFR_IO8_CXX(0x2C)

#define CXX_SPSR    _SFR_IO8_CXX(0x2D)
#define CXX_SPDR    _SFR_IO8_CXX(0x2E)

/* Reserved [0x2F] */

#define CXX_ACSR    _SFR_IO8_CXX(0x30)

#define CXX_DWDR    _SFR_IO8_CXX(0x31)

/* Reserved [0x32] */

#define CXX_SMCR    _SFR_IO8_CXX(0x33)
#define CXX_MCUSR   _SFR_IO8_CXX(0x34)
#define CXX_MCUCR   _SFR_IO8_CXX(0x35)
/* Reserved [0x36] */

#define CXX_SPMCSR  _SFR_IO8_CXX(0x37)
/* Reserved [0x38..0x3C] */

/* SP [0x3D..0x3E] */
/* SREG [0x3F] */

#define CXX_WDTCSR  _SFR_MEM8_CXX(0x60)
#define CXX_CLKPR   _SFR_MEM8_CXX(0x61)

#define CXX_WDTCKD  _SFR_MEM8_CXX(0x62)

#define CXX_REGCR   _SFR_MEM8_CXX(0x63)

#define CXX_PRR0    _SFR_MEM8_CXX(0x64)
#define CXX_PRR1    _SFR_MEM8_CXX(0x65)

#define CXX_OSCCAL  _SFR_MEM8_CXX(0x66)

/* Reserved [0x67] */

#define CXX_PCICR   _SFR_MEM8_CXX(0x68)

#define CXX_EICRA   _SFR_MEM8_CXX(0x69)

#define CXX_EICRB   _SFR_MEM8_CXX(0x6A)

#define CXX_PCMSK0  _SFR_MEM8_CXX(0x6B)

#define CXX_PCMSK1  _SFR_MEM8_CXX(0x6C)

/* Reserved [0x6D] */

#define CXX_TIMSK0  _SFR_MEM8_CXX(0x6E)

#define CXX_TIMSK1  _SFR_MEM8_CXX(0x6F)

/* Reserved [0x70..0x7F] */

#define CXX_TCCR1A  _SFR_MEM8_CXX(0x80)

#define CXX_TCCR1B  _SFR_MEM8_CXX(0x81)

#define CXX_TCCR1C  _SFR_MEM8_CXX(0x82)

/* Reserved [0x83] */

/* Combine TCNT1L and TCNT1H */
#define CXX_TCNT1   _SFR_MEM16_CXX(0x84)

#define CXX_TCNT1L  _SFR_MEM8_CXX(0x84)
#define CXX_TCNT1H  _SFR_MEM8_CXX(0x85)

/* Combine ICR1L and ICR1H */
#define CXX_ICR1    _SFR_MEM16_CXX(0x86)

#define CXX_ICR1L   _SFR_MEM8_CXX(0x86)
#define CXX_ICR1H   _SFR_MEM8_CXX(0x87)

/* Combine OCR1AL and OCR1AH */
#define CXX_OCR1A   _SFR_MEM16_CXX(0x88)

#define CXX_OCR1AL  _SFR_MEM8_CXX(0x88)
#define CXX_OCR1AH  _SFR_MEM8_CXX(0x89)

/* Combine OCR1BL and OCR1BH */
#define CXX_OCR1B   _SFR_MEM16_CXX(0x8A)

#define CXX_OCR1BL  _SFR_MEM8_CXX(0x8A)
#define CXX_OCR1BH  _SFR_MEM8_CXX(0x8B)

/* Combine OCR1CL and OCR1CH */
#define CXX_OCR1C   _SFR_MEM16_CXX(0x8C)

#define CXX_OCR1CL  _SFR_MEM8_CXX(0x8C)
#define CXX_OCR1CH  _SFR_MEM8_CXX(0x8D)

/* Reserved [0x8E..0xC7] */

#define CXX_UCSR1A  _SFR_MEM8_CXX(0xC8)

#define CXX_UCSR1B  _SFR_MEM8_CXX(0XC9)

#define CXX_UCSR1C  _SFR_MEM8_CXX(0xCA)
#define CXX_UCSR1D  _SFR_MEM8_CXX(0xCB)

/* Combine UBRR1L and UBRR1H */
#define CXX_UBRR1   _SFR_MEM16_CXX(0xCC)

#define CXX_UBRR1L  _SFR_MEM8_CXX(0xCC)
#define CXX_UBRR1H  _SFR_MEM8_CXX(0xCD)

#define CXX_UDR1    _SFR_MEM8_CXX(0XCE)

/* Reserved [0xCF] */

#define CXX_CKSEL0  _SFR_MEM8_CXX(0XD0)

#define CXX_CKSEL1  _SFR_MEM8_CXX(0XD1)

#define CXX_CKSTA   _SFR_MEM8_CXX(0XD2)

/* Reserved [0xD3..0xD7] */

#define CXX_USBCON  _SFR_MEM8_CXX(0XD8)

/* Reserved [0xD9..0xDA] */

/* Combine UDPADDL and UDPADDH */
#define CXX_UDPADD  _SFR_MEM16_CXX(0xDB)

#define CXX_UDPADDL _SFR_MEM8_CXX(0xDB)
#define CXX_UDPADDH _SFR_MEM8_CXX(0xDC)

/* Reserved [0xDD..0xDF] */

#define CXX_UDCON   _SFR_MEM8_CXX(0XE0)
#define CXX_UDINT   _SFR_MEM8_CXX(0XE1)
#define CXX_UDIEN   _SFR_MEM8_CXX(0XE2)
#define CXX_UDADDR  _SFR_MEM8_CXX(0XE3)

/* Combine UDFNUML and UDFNUMH */
#define CXX_UDFNUM  _SFR_MEM16_CXX(0xE4)

#define CXX_UDFNUML _SFR_MEM8_CXX(0xE4)
#define CXX_UDFNUMH _SFR_MEM8_CXX(0xE5)

#define CXX_UDMFN   _SFR_MEM8_CXX(0XE6)

/* Reserved [0xE7] */

#define CXX_UEINTX  _SFR_MEM8_CXX(0XE8)

#define CXX_UENUM   _SFR_MEM8_CXX(0XE9)

#define CXX_UERST   _SFR_MEM8_CXX(0XEA)
#define CXX_UECONX  _SFR_MEM8_CXX(0XEB)
#define CXX_UECFG0X _SFR_MEM8_CXX(0XEC)
#define CXX_UECFG1X  _SFR_MEM8_CXX(0XED)
#define CXX_UESTA0X _SFR_MEM8_CXX(0XEE)
#define CXX_UESTA1X _SFR_MEM8_CXX(0XEF)
#define CXX_UEIENX  _SFR_MEM8_CXX(0XF0)
#define CXX_UEDATX  _SFR_MEM8_CXX(0XF1)

#define CXX_UEBCLX  _SFR_MEM8_CXX(0xF2)

/* Reserved [0xF3] */

#define CXX_UEINT   _SFR_MEM8_CXX(0XF4)
/* Reserved [0xF5..0xF9] */

#define CXX_PS2CON  _SFR_MEM8_CXX(0XFA)

#define CXX_UPOE    _SFR_MEM8_CXX(0XFB)


#endif  /* _AVR_IOUSBXX2_H_ */
