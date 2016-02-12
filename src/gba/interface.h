/* Copyright (c) 2013-2015 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef INTERFACE_H
#define INTERFACE_H

#include "util/common.h"

#include "core/interface.h"

enum GBASIOMode {
	SIO_NORMAL_8 = 0,
	SIO_NORMAL_32 = 1,
	SIO_MULTI = 2,
	SIO_UART = 3,
	SIO_GPIO = 8,
	SIO_JOYBUS = 12
};

struct GBA;
struct GBAAudio;
struct GBASIO;
struct GBAVideoRenderer;

extern const int GBA_LUX_LEVELS[10];

struct GBALuminanceSource {
	void (*sample)(struct GBALuminanceSource*);

	uint8_t (*readLuminance)(struct GBALuminanceSource*);
};

struct GBASIODriver {
	struct GBASIO* p;

	bool (*init)(struct GBASIODriver* driver);
	void (*deinit)(struct GBASIODriver* driver);
	bool (*load)(struct GBASIODriver* driver);
	bool (*unload)(struct GBASIODriver* driver);
	uint16_t (*writeRegister)(struct GBASIODriver* driver, uint32_t address, uint16_t value);
	int32_t (*processEvents)(struct GBASIODriver* driver, int32_t cycles);
};

#endif
