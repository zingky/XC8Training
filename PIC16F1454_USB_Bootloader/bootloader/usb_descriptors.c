/*
    this variant of code is based on:

    M-Stack USB Device Stack Implementation
    Copyright (C) 2013 Alan Ott <alan@signal11.us>
    Copyright (C) 2013 Signal 11 Software

    rather than Microchip's USB Framework
*/

/*
    USB HID bootloader for PIC16F1454/PIC16F1455/PIC16F1459 microcontroller

    Copyright (C) 2013,2014,2015 Peter Lawrence

    Permission is hereby granted, free of charge, to any person obtaining a 
    copy of this software and associated documentation files (the "Software"), 
    to deal in the Software without restriction, including without limitation 
    the rights to use, copy, modify, merge, publish, distribute, sublicense, 
    and/or sell copies of the Software, and to permit persons to whom the 
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in 
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
    DEALINGS IN THE SOFTWARE.
*/

#include "usb_config.h"
#include "usb.h"
#include "usb_ch9.h"
#include "usb_hid.h"

#ifdef __C18
#define ROMPTR rom
#else
#define ROMPTR
#endif

struct configuration_1_packet
{
	struct configuration_descriptor  config;
	struct interface_descriptor      interface;
	struct hid_descriptor            hid;
	struct endpoint_descriptor       ep1_in;
	struct endpoint_descriptor       ep1_out;
};

/* Device Descriptor for bootloader */
const ROMPTR struct device_descriptor this_device_descriptor =
{
	sizeof(struct device_descriptor), // bLength
	DESC_DEVICE, // bDescriptorType
	0x0200, // 0x0200 = USB 2.0, 0x0110 = USB 1.1
	0x00, // Device class
	0x00, // Device Subclass
	0x00, // Protocol.
	EP_0_LEN, // bMaxPacketSize0
	0x1D50, // Vendor
	0x609D, // Product
	0x0200, // device release (2.0)
	0, // Manufacturer
	1, // Product
	2, // Serial
	1, // NumConfigurations
};

/* HID Report descriptor. See the HID specification for more details. */
static const ROMPTR uint8_t hid_report_descriptor[] @ 0xD00 =
{
        0x06, 0x00, 0xFF,       // Usage Page = 0xFF00 (Vendor Defined Page 1)
        0x09, 0x01,             // Usage (Vendor Usage 1)
        0xA1, 0x01,             // Collection (Application)
        0x19, 0x01,             //      Usage Minimum 
        0x29, 0x40,             //      Usage Maximum 	//64 input usages total (0x01 to 0x40)
        0x15, 0x01,             //      Logical Minimum (data bytes in the report may have minimum value = 0x00)
        0x25, 0x40,      	//      Logical Maximum (data bytes in the report may have maximum value = 0x00FF = unsigned 255)
        0x75, 0x08,             //      Report Size: 8-bit field size
        0x95, 0x40,             //      Report Count: Make sixty-four 8-bit fields (the next time the parser hits an "Input", "Output", or "Feature" item)
        0x81, 0x00,             //      Input (Data, Array, Abs): Instantiates input packet fields based on the above report size, count, logical min/max, and usage.
        0x19, 0x01,             //      Usage Minimum 
        0x29, 0x40,             //      Usage Maximum 	//64 output usages total (0x01 to 0x40)
        0x91, 0x00,             //      Output (Data, Array, Abs): Instantiates output packet fields.  Uses same report size and count as "Input" fields, since nothing new/different was specified to the parser since the "Input" item.
        0xC0
};

static const ROMPTR struct configuration_1_packet configuration_1 @ 0x800 =
{
	{
	// Members from struct configuration_descriptor
	sizeof(struct configuration_descriptor),
	DESC_CONFIGURATION,
	sizeof(configuration_1), // wTotalLength (length of the whole packet)
	1, // bNumInterfaces
	1, // bConfigurationValue
	0, // iConfiguration (index of string descriptor)
	0b10000000, // attributes
	100/2,   // 100/2 indicates 100mA
	},

	{
	// Members from struct interface_descriptor
	sizeof(struct interface_descriptor), // bLength;
	DESC_INTERFACE,
	0x0, // InterfaceNumber
	0x0, // AlternateSetting
	0x2, // bNumEndpoints (num besides endpoint 0)
	HID_INTERFACE_CLASS, // bInterfaceClass 3=HID, 0xFF=VendorDefined
	0x00, // bInterfaceSubclass (0=NoBootInterface for HID)
	0x00, // bInterfaceProtocol
	0x00, // iInterface (index of string describing interface)
	},

	{
	// Members from struct hid_descriptor
	sizeof(struct hid_descriptor),
	DESC_HID,
	0x0101, // bcdHID
	0x0, // bCountryCode
	1,   // bNumDescriptors
	DESC_REPORT, // bDescriptorType2
	sizeof(hid_report_descriptor), // wDescriptorLength
	},

	{
	// Members of the Endpoint Descriptor (EP1 IN)
	sizeof(struct endpoint_descriptor),
	DESC_ENDPOINT,
	0x01 | 0x80, // endpoint #1 0x80=IN
	EP_INTERRUPT, // bmAttributes
	EP_1_IN_LEN, // wMaxPacketSize
	1, // bInterval in ms.
	},

	{
	// Members of the Endpoint Descriptor (EP1 OUT)
	sizeof(struct endpoint_descriptor),
	DESC_ENDPOINT,
	0x01 /*| 0x00*/, // endpoint #1 0x00=OUT
	EP_INTERRUPT, // bmAttributes
	EP_1_OUT_LEN, // wMaxPacketSize
	1, // bInterval in ms.
	},
};

static const ROMPTR struct { uint8_t bLength;uint8_t bDescriptorType; uint16_t lang; } str00 =
{
	sizeof(str00),
	DESC_STRING,
	0x0409 // US English
};

static const ROMPTR struct { uint8_t bLength;uint8_t bDescriptorType; uint16_t chars[10]; } product_string =
{
	sizeof(product_string),
	DESC_STRING,
	{'b','o','o','t','l','o','a','d','e','r'}
};

static const ROMPTR struct { uint8_t bLength;uint8_t bDescriptorType; uint16_t chars[8]; } serialnumber_string @ 0xF80 =
{
	sizeof(serialnumber_string),
	DESC_STRING,
	{
		/*
		Microchip's SQTP program only allows eight instruction words to be modified.
		So, infrequently update these four most significant hex digits (eight words) 
		after exhausting the 2^16 of the four least significant digits
		*/
		'0','0','0','0',
#if 1
#warning Serial Number Descriptor is NOT VALID FOR FACTORY PRODUCTION
		'0','0','0','0'
#else
		/* equivalent to RETLW 0xFF, as specified in "SQTP Specification for PIC16/17" */
		0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF
#endif
	}
};

int16_t usb_application_get_string(uint8_t string_number, const void **ptr)
{
	if (0 == string_number)
        {
		*ptr = &str00;
		return sizeof(str00);
	}
	else if (1 == string_number)
	{
		*ptr = &product_string;
		return sizeof(product_string);
	}
	else if (2 == string_number)
	{
		*ptr = &serialnumber_string;
		return sizeof(serialnumber_string);
	}

	return -1;
}

const struct configuration_descriptor *usb_application_config_descs[] =
{
	(struct configuration_descriptor*) &configuration_1,
};

/* compile-time checks used in Signal 11 example code */
STATIC_SIZE_CHECK_EQUAL(USB_ARRAYLEN(USB_CONFIG_DESCRIPTOR_MAP), NUMBER_OF_CONFIGURATIONS);
STATIC_SIZE_CHECK_EQUAL(sizeof(USB_DEVICE_DESCRIPTOR), 18);

int16_t usb_application_get_hid_descriptor(uint8_t interface, const void **ptr)
{
	/* Only one interface in this demo. The two-step assignment avoids an
	 * incorrect error in XC8 on PIC16. */
	const void *p = &configuration_1.hid;
	*ptr = p;
	return sizeof(configuration_1.hid);
}

int16_t usb_application_get_hid_report_descriptor(uint8_t interface, const void **ptr)
{
	*ptr = hid_report_descriptor;
	return sizeof(hid_report_descriptor);
}

struct bootloader_struct_type
{
	uint16_t ptr;
	uint16_t size;
};

/*
the Microchip XC8 compiler has a litany of limitations:

1) only simple integers may be used for the "@" operator
   so, the "@" value must be manually set to: 0x1000 - sizeof(bootloader_table)
2) it errors out with "(712) can't generate code for this expression" unless 
   the structs have fixed locations via "@", so using @ for anything cited below is mandatory
*/

/*
The intention of this bootloader_table structure is to allow private data 
structures made available in the bootloader to be found in an automated fashion.

This discover can be achieved both by the user app and/or the host PC when 
the device is in bootloader mode.
*/

const ROMPTR struct bootloader_struct_type bootloader_table[] @ 0xFF8 =
{
	{ 0, 0 },
	{ 0x8000 | (uint16_t)&serialnumber_string, sizeof(serialnumber_string) },
};

STATIC_SIZE_CHECK_EQUAL(0x1000, (uint16_t)&bootloader_table + sizeof(bootloader_table));
