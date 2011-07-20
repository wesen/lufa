/* avr/iom8.h - definitions for ATmega8 */

#ifndef _AVR_IOM8CXX_H_
#define _AVR_IOM8CXX_H_ 1

#include "ioxxx_cpp_macros.h"

/* I/O registers */

/* TWI stands for "Two Wire Interface" or "TWI Was I2C(tm)" */
#define CXX_TWBR	_SFR_IO8_CXX(0x00)
#define CXX_TWSR	_SFR_IO8_CXX(0x01)
#define CXX_TWAR	_SFR_IO8_CXX(0x02)
#define CXX_TWDR	_SFR_IO8_CXX(0x03)

/* ADC */
#define CXX_ADCW	_SFR_IO16_CXX(0x04)
#ifndef __ASSEMBLER__
#define CXX_ADC	_SFR_IO16_CXX(0x04)
#endif
#define CXX_ADCL	_SFR_IO8_CXX(0x04)
#define CXX_ADCH	_SFR_IO8_CXX(0x05)
#define CXX_ADCSR	_SFR_IO8_CXX(0x06)
#define CXX_ADCSRA	_SFR_IO8_CXX(0x06)  /* Changed in 2486H-AVR-09/02 */
#define CXX_ADMUX	_SFR_IO8_CXX(0x07)

/* analog comparator */
#define CXX_ACSR	_SFR_IO8_CXX(0x08)

/* USART */
#define CXX_UBRRL	_SFR_IO8_CXX(0x09)
#define CXX_UCSRB	_SFR_IO8_CXX(0x0A)
#define CXX_UCSRA	_SFR_IO8_CXX(0x0B)
#define CXX_UDR	_SFR_IO8_CXX(0x0C)

/* SPI */
#define CXX_SPCR	_SFR_IO8_CXX(0x0D)
#define CXX_SPSR	_SFR_IO8_CXX(0x0E)
#define CXX_SPDR	_SFR_IO8_CXX(0x0F)

/* Port D */
#define CXX_PIND	_SFR_IO8_CXX(0x10)
#define CXX_DDRD	_SFR_IO8_CXX(0x11)
#define CXX_PORTD	_SFR_IO8_CXX(0x12)

/* Port C */
#define CXX_PINC	_SFR_IO8_CXX(0x13)
#define CXX_DDRC	_SFR_IO8_CXX(0x14)
#define CXX_PORTC	_SFR_IO8_CXX(0x15)

/* Port B */
#define CXX_PINB	_SFR_IO8_CXX(0x16)
#define CXX_DDRB	_SFR_IO8_CXX(0x17)
#define CXX_PORTB	_SFR_IO8_CXX(0x18)

/* EEPROM Control Register */
#define CXX_EECR	_SFR_IO8_CXX(0x1C)

/* EEPROM Data Register */
#define CXX_EEDR	_SFR_IO8_CXX(0x1D)

/* EEPROM Address Register */
#define CXX_EEAR	_SFR_IO16_CXX(0x1E)
#define CXX_EEARL	_SFR_IO8_CXX(0x1E)
#define CXX_EEARH	_SFR_IO8_CXX(0x1F)

#define CXX_UCSRC	_SFR_IO8_CXX(0x20)
#define CXX_UBRRH	_SFR_IO8_CXX(0x20)

#define CXX_WDTCR	_SFR_IO8_CXX(0x21)
#define CXX_ASSR	_SFR_IO8_CXX(0x22)

/* Timer 2 */
#define CXX_OCR2	_SFR_IO8_CXX(0x23)
#define CXX_TCNT2	_SFR_IO8_CXX(0x24)
#define CXX_TCCR2	_SFR_IO8_CXX(0x25)

/* Timer 1 */
#define CXX_ICR1	_SFR_IO16_CXX(0x26)
#define CXX_ICR1L	_SFR_IO8_CXX(0x26)
#define CXX_ICR1H	_SFR_IO8_CXX(0x27)
#define CXX_OCR1B	_SFR_IO16_CXX(0x28)
#define CXX_OCR1BL	_SFR_IO8_CXX(0x28)
#define CXX_OCR1BH	_SFR_IO8_CXX(0x29)
#define CXX_OCR1A	_SFR_IO16_CXX(0x2A)
#define CXX_OCR1AL	_SFR_IO8_CXX(0x2A)
#define CXX_OCR1AH	_SFR_IO8_CXX(0x2B)
#define CXX_TCNT1	_SFR_IO16_CXX(0x2C)
#define CXX_TCNT1L	_SFR_IO8_CXX(0x2C)
#define CXX_TCNT1H	_SFR_IO8_CXX(0x2D)
#define CXX_TCCR1B	_SFR_IO8_CXX(0x2E)
#define CXX_TCCR1A	_SFR_IO8_CXX(0x2F)

#define CXX_SFIOR	_SFR_IO8_CXX(0x30)

#define CXX_OSCCAL	_SFR_IO8_CXX(0x31)

/* Timer 0 */
#define CXX_TCNT0	_SFR_IO8_CXX(0x32)
#define CXX_TCCR0	_SFR_IO8_CXX(0x33)

#define CXX_MCUCSR	_SFR_IO8_CXX(0x34)
#define CXX_MCUSR   _SFR_IO8_CXX(0x34)  /* Defined as an alias for MCUCSR. */

#define CXX_MCUCR	_SFR_IO8_CXX(0x35)

#define CXX_TWCR	_SFR_IO8_CXX(0x36)

#define CXX_SPMCR	_SFR_IO8_CXX(0x37)

#define CXX_TIFR	_SFR_IO8_CXX(0x38)
#define CXX_TIMSK	_SFR_IO8_CXX(0x39)

#define CXX_GIFR	_SFR_IO8_CXX(0x3A)
#define CXX_GIMSK	_SFR_IO8_CXX(0x3B)
#define CXX_GICR	_SFR_IO8_CXX(0x3B)   /* Changed in 2486H-AVR-09/02 */

#endif /* _AVR_IOM8CXX_H_ */
