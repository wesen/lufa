#ifndef MIDIUARTPARENT_H__
#define MIDIUARTPARENT_H__

#include <midi-common.h>
#include <Vector.h>
#include <Callback.h>
#include <helpers.h>

class MidiUartParent {
public:
  uint8_t running_status;
  uint8_t currentChannel;
  bool useRunningStatus;
  
  MidiUartParent() {
    useRunningStatus = false;
    running_status = 0;
    currentChannel = 0x0;
  }

  virtual void initSerial() {
    running_status = 0;
  }
  
  virtual void puts(uint8_t *data, uint16_t cnt) {
    while (cnt--)
      putByte(*(data++));
  }
  
  virtual void putByte(uint8_t c) { }
  virtual void putByte_immediate(uint8_t c) { putByte(c); }
  virtual bool isAvailable() { return false; }

  virtual uint8_t getByte() {
    return 0;
  }

  virtual void sendMessage(uint8_t cmdByte) {
    sendCommandByte(cmdByte);
  }
  virtual void sendMessage(uint8_t cmdByte, uint8_t byte1) {
    sendCommandByte(cmdByte);
    putByte(byte1);
  }
  
  virtual void sendMessage(uint8_t cmdByte, uint8_t byte1, uint8_t byte2) {
    sendCommandByte(cmdByte);
    putByte(byte1);
    putByte(byte2);
  }

  void sendCommandByte(uint8_t byte) {
    if (MIDI_IS_REALTIME_STATUS_BYTE(byte) || MIDI_IS_SYSCOMMON_STATUS_BYTE(byte)) {
      if (!MIDI_IS_REALTIME_STATUS_BYTE(byte)) {
				running_status = 0;
				putByte(byte);
      } else {
				putByte_immediate(byte);
			}
    } else {
      if (useRunningStatus) {
				if (running_status != byte) 
					putByte(byte);
				running_status = byte;
      } else {
				putByte(byte);
      }
    }
  }
  
  inline void resetRunningStatus() {
    running_status = 0;
  }

  inline void sendNoteOn(uint8_t note, uint8_t velocity) {
    sendNoteOn(currentChannel, note, velocity);
  }
  inline void sendNoteOff(uint8_t note, uint8_t velocity) {
    sendNoteOff(currentChannel, note, velocity);
  }
  inline void sendNoteOff(uint8_t note) {
    sendNoteOff(currentChannel, note, 0);
  }
  inline void sendCC(uint8_t cc, uint8_t value) {
    sendCC(currentChannel, cc, value);
  }
  inline void sendProgramChange(uint8_t program) {
    sendProgramChange(currentChannel, program);
  }

  inline void sendPolyKeyPressure(uint8_t note, uint8_t pressure) {
    sendPolyKeyPressure(currentChannel, note, pressure);
  }

  inline void sendChannelPressure(uint8_t pressure) {
    sendChannelPressure(currentChannel, pressure);
  }

  inline void sendPitchBend(int16_t pitchbend) {
    sendPitchBend(currentChannel, pitchbend);
  }

  inline void sendNRPN(uint16_t parameter, uint8_t value) {
    sendNRPN(currentChannel, parameter, value);
  }
  inline void sendNRPN(uint16_t parameter, uint16_t value) {
    sendNRPN(currentChannel, parameter, value);
  }

  inline void sendRPN(uint16_t parameter, uint8_t value) {
    sendRPN(currentChannel, parameter, value);
  }
  inline void sendRPN(uint16_t parameter, uint16_t value) {
    sendRPN(currentChannel, parameter, value);
  }

  void sendNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    uint8_t msg[3] = {
      MIDI_NOTE_ON | channel,
      note,
      velocity
    };
    sendMessage(msg[0], msg[1], msg[2]);
  }

  void sendNoteOff(uint8_t channel, uint8_t note, uint8_t velocity) {
    uint8_t msg[3] = {
      MIDI_NOTE_OFF | channel,
      note,
      velocity
    };
    sendMessage(msg[0], msg[1], msg[2]);
  }

  void sendCC(uint8_t channel, uint8_t cc, uint8_t value) {
    uint8_t msg[3] = {
      MIDI_CONTROL_CHANGE | channel,
      cc,
      value
    };
    sendMessage(msg[0], msg[1], msg[2]);
  }

  void sendProgramChange(uint8_t channel, uint8_t program) {
    sendMessage(MIDI_PROGRAM_CHANGE | channel, program);
  }

  void sendPolyKeyPressure(uint8_t channel, uint8_t note, uint8_t pressure) {
    sendMessage(MIDI_AFTER_TOUCH | channel, note, pressure);
  }

  void sendChannelPressure(uint8_t channel, uint8_t pressure) {
    sendMessage(MIDI_CHANNEL_PRESSURE | channel, pressure);
  }

  void sendPitchBend(uint8_t channel, int16_t pitchbend) {
    pitchbend += 8192;
    sendMessage(MIDI_PITCH_WHEEL | channel, pitchbend & 0x7F, (pitchbend >> 7) & 0x7F);
  }

  void sendNRPN(uint8_t channel, uint16_t parameter, uint8_t value) {
    sendCC(channel, 99, (parameter >> 7) & 0x7F);
    sendCC(channel, 98, (parameter & 0x7F));
    sendCC(channel, 6, value);
  }
  void sendNRPN(uint8_t channel, uint16_t parameter, uint16_t value) {
    sendCC(channel, 99, (parameter >> 7) & 0x7F);
    sendCC(channel, 98, (parameter & 0x7F));
    sendCC(channel, 6, (value >> 7) & 0x7F);
    sendCC(channel, 38, (value & 0x7F));
  }

  void sendRPN(uint8_t channel, uint16_t parameter, uint8_t value) {
    sendCC(channel, 101, (parameter >> 7) & 0x7F);
    sendCC(channel, 100, (parameter & 0x7F));
    sendCC(channel, 6, value);
  }
  void sendRPN(uint8_t channel, uint16_t parameter, uint16_t value) {
    sendCC(channel, 101, (parameter >> 7) & 0x7F);
    sendCC(channel, 100, (parameter & 0x7F));
    sendCC(channel, 6, (value >> 7) & 0x7F);
    sendCC(channel, 38, (value & 0x7F));
  }

  virtual void sendSysex(uint8_t *data, uint8_t cnt) {
    sendCommandByte(0xF7);
    puts(data, cnt);
    sendCommandByte(0xF0);
  }
  inline void sendRaw(uint8_t *msg, uint16_t cnt) {
    puts(msg, cnt);
  }
  inline void sendRaw(uint8_t byte) {
    putByte(byte);
  }

	void sendString(const char *data) {
		sendString(data, m_strlen(data) + 1);
	}

	void sendString(const char *data, uint16_t cnt) {
		sendCommandByte(0xF0);
		uint8_t _data[4] = { MIDIDUINO_SYSEX_VENDOR_1, MIDIDUINO_SYSEX_VENDOR_2,
												 0x41, CMD_STRING };
		puts(_data, 4);
		puts((uint8_t *)data, cnt);
		sendCommandByte(0xF7);
	}

	void printfString(const char *fmt, ...) {
		va_list lp;
		va_start(lp, fmt);
		char buf[32];
		uint16_t len = m_vsnprintf(buf, sizeof(buf), fmt, lp);
		va_end(lp);
		sendString(buf, len);
	}


#ifdef HOST_MIDIDUINO
  virtual ~MidiUartParent() {
  }
#endif
  
};

#endif /* MIDIUARTPARENT_H__ */
