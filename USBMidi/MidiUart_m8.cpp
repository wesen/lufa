#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <MidiUart.h>
#include <midi-common.h>
#include <MidiUartParent.h>

#include <helpers.h>

#define UART_BAUDRATE 31250
#define UART_BAUDRATE_REG (((F_CPU / 16)/(UART_BAUDRATE)) - 1)

#define UART_CHECK_EMPTY_BUFFER() IS_BIT_SET8(UCSRA, UDRE)
#define UART_CHECK_RX() IS_BIT_SET8(UCSRA, RXC)
#define UART_WRITE_CHAR(c) (UDR = (c))
#define UART_READ_CHAR() (UDR)

#include <avr/io.h>

void MidiUartClass::initSerial() {
  running_status = 0;
  UBRRH = (UART_BAUDRATE_REG >> 8);
  UBRRL = (UART_BAUDRATE_REG & 0xFF);
  //  UBRRH = 0;
  //  UBRRL = 15;

  UCSRC = (3<<UCSZ0); 
  
}

void MidiUartClass::putByte_immediate(uint8_t c) {
#ifdef TX_IRQ
  while (!UART_CHECK_EMPTY_BUFFER())
    ;
  UART_WRITE_CHAR(c);
#else
  putByte(c);
#endif
}

void MidiUartClass::putByte(uint8_t c) {
#ifdef TX_IRQ
 again:
  if (txRb.isEmpty() && UART_CHECK_EMPTY_BUFFER()) {
    UART_WRITE_CHAR(c);
  } else {
    if (txRb.isFull()) {
      while (txRb.isFull()) {
	uint8_t tmp = SREG;
	sei();
	delayMicroseconds(10);
	SREG = tmp;
      }
      goto again;
    } else {
      txRb.put(c);
    }
  }
#else
  while (!UART_CHECK_EMPTY_BUFFER())
    ;
  UART_WRITE_CHAR(c);
#endif
}

void MidiUartClass::enable() {
  /** enable receive, transmit and receive and transmit interrupts. **/
  UCSRB = _BV(RXEN) | _BV(TXEN) | _BV(RXCIE);
#ifdef TX_IRQ
  UCSRB |= _BV(TXCIE);
#endif
}

void MidiUartClass::disable() {
  /** disable receive, transmit and receive and transmit interrupts. **/
  UCSRB = 0;
}

bool MidiUartClass::isAvailable() {
  return !rxRb.isEmpty();
}

uint8_t MidiUartClass::getByte() {
  return rxRb.get();
}

SIGNAL(USART_RXC_vect) {
  uint8_t c = UART_READ_CHAR();

  MidiUart.rxRb.put(c);

#if 0
    // show overflow debug
    if (MidiUart.rxRb.overflow) {
      //      setLed();
    }
#endif
}

#ifdef TX_IRQ
SIGNAL(USART_TXC_vect) {
  if (!MidiUart.txRb.isEmpty()) {
    UART_WRITE_CHAR(MidiUart.txRb.peek());
    MidiUart.txRb.get();
  }
}
#endif
