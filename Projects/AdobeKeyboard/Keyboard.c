/**
 * Adobe illustrator action keyboard
 *
 * (c) Dean Camera (LUFA)
 * (c) Manuel Odendahl <wesen@ruinwesen.com> <- contact for support
 **/

#include "Keyboard.h"

static uint8_t PrevKeyboardHIDReportBuffer[sizeof(USB_KeyboardReport_Data_t)];

/**
 * HID Class driver interface.
 **/
USB_ClassInfo_HID_Device_t Keyboard_HID_Interface =
  {
    .Config =
    {
      .InterfaceNumber              = 0,

      .ReportINEndpointNumber       = KEYBOARD_EPNUM,
      .ReportINEndpointSize         = KEYBOARD_EPSIZE,
      .ReportINEndpointDoubleBank   = false,

      .PrevReportINBuffer           = PrevKeyboardHIDReportBuffer,
      .PrevReportINBufferSize       = sizeof(PrevKeyboardHIDReportBuffer),
    },
  };

int main(void)
{
  SetupHardware();

  LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
  sei();

  for (;;)
    {
      HID_Device_USBTask(&Keyboard_HID_Interface);
      USB_USBTask();
    }
}

void SetupHardware()
{
  /* Disable watchdog if enabled by bootloader/fuses */
  MCUSR &= ~(1 << WDRF);
  wdt_disable();

  /* Disable clock division */
  clock_prescale_set(clock_div_1);

  /* Hardware Initialization */
  LEDs_Init();

  /* pullups on PORTF */
  PORTF = 0xFF;
  
  USB_Init();
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
  LEDs_SetAllLEDs(LEDMASK_USB_ENUMERATING);
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
  LEDs_SetAllLEDs(LEDMASK_USB_NOTREADY);
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
  bool ConfigSuccess = true;

  ConfigSuccess &= HID_Device_ConfigureEndpoints(&Keyboard_HID_Interface);

  USB_Device_EnableSOFEvents();

  LEDs_SetAllLEDs(ConfigSuccess ? LEDMASK_USB_READY : LEDMASK_USB_ERROR);
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
  HID_Device_ProcessControlRequest(&Keyboard_HID_Interface);
}

/** Event handler for the USB device Start Of Frame event. */
void EVENT_USB_Device_StartOfFrame(void)
{
  HID_Device_MillisecondElapsed(&Keyboard_HID_Interface);
}

/** HID class driver callback function for the creation of HID reports to the host.
 *
 *  \param[in]     HIDInterfaceInfo  Pointer to the HID class interface configuration structure being referenced
 *  \param[in,out] ReportID    Report ID requested by the host if non-zero, otherwise callback should set to the generated report ID
 *  \param[in]     ReportType  Type of the report to create, either HID_REPORT_ITEM_In or HID_REPORT_ITEM_Feature
 *  \param[out]    ReportData  Pointer to a buffer where the created report should be stored
 *  \param[out]    ReportSize  Number of bytes written in the report (or zero if no report is to be sent
 *
 *  \return Boolean true to force the sending of the report, false to let the library determine if it needs to be sent
 */
bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo, uint8_t* const ReportID,
                                         const uint8_t ReportType, void* ReportData, uint16_t* const ReportSize)
{
  USB_KeyboardReport_Data_t* KeyboardReport = (USB_KeyboardReport_Data_t*)ReportData;
  uint8_t UsedKeyCodes = 0;

  static uint8_t prev_buttons = 0;
  uint8_t buttons = PINF;

  /* HID_KEYBOARD_SC_LEFT_SHIFT, HID_KEYBOARD_SC_LEFT_ALT,
     HID_KEYBOARD_MODIFER_LEFTGUI
   */

  static const uint8_t F_OFFSETS[6] = {0, 1, 4, 5, 6, 7};

  for (uint8_t i = 0; i < 4; i++) {
    if (!IS_BIT_SET(buttons, PF0 + F_OFFSETS[i])) {
      KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_F1 + i;
    }
  }
  if (!IS_BIT_SET(buttons, PF6)) {
    KeyboardReport->Modifier = HID_KEYBOARD_MODIFER_LEFTSHIFT;
  }
    /*
  if (!IS_BIT_SET(buttons, PF1)) {
    KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_A;
  }
  if (UsedKeyCodes) {
    KeyboardReport->Modifier = HID_KEYBOARD_MODIFER_LEFTSHIFT;
  }
    */

  /*
    if (JoyStatus_LCL & JOY_UP)
    KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_A;
    else if (JoyStatus_LCL & JOY_DOWN)
    KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_B;

    if (JoyStatus_LCL & JOY_LEFT)
    KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_C;
    else if (JoyStatus_LCL & JOY_RIGHT)
    KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_D;

    if (JoyStatus_LCL & JOY_PRESS)
    KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_E;

    if (ButtonStatus_LCL & BUTTONS_BUTTON1)
    KeyboardReport->KeyCode[UsedKeyCodes++] = HID_KEYBOARD_SC_F;

  */

  *ReportSize = sizeof(USB_KeyboardReport_Data_t);
  prev_buttons = buttons;

  return false;
}

/** HID class driver callback function for the processing of HID reports from the host.
 *
 *  \param[in] HIDInterfaceInfo  Pointer to the HID class interface configuration structure being referenced
 *  \param[in] ReportID    Report ID of the received report from the host
 *  \param[in] ReportType  The type of report that the host has sent, either HID_REPORT_ITEM_Out or HID_REPORT_ITEM_Feature
 *  \param[in] ReportData  Pointer to a buffer where the received report has been stored
 *  \param[in] ReportSize  Size in bytes of the received HID report
 */
void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                          const uint8_t ReportID,
                                          const uint8_t ReportType,
                                          const void* ReportData,
                                          const uint16_t ReportSize)
{
  uint8_t  LEDMask   = LEDS_NO_LEDS;
  uint8_t* LEDReport = (uint8_t*)ReportData;

  if (*LEDReport & HID_KEYBOARD_LED_NUMLOCK)
    LEDMask |= LEDS_LED1;

  if (*LEDReport & HID_KEYBOARD_LED_CAPSLOCK)
    LEDMask |= LEDS_LED3;

  if (*LEDReport & HID_KEYBOARD_LED_SCROLLLOCK)
    LEDMask |= LEDS_LED4;

  LEDs_SetAllLEDs(LEDMask);
}

