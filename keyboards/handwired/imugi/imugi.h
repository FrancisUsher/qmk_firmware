#pragma once

#include "quantum.h"

#define LAYOUT( \
	K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
	K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
	K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
	K30,      K32,      K34, K35,      K37, K38, K39,           K3C \
	) \
	{ \
		{ K00, K01,   K02, K03,   K04, K05, K06,   K07, K08, K09, K0A,   K0B,   K0C }, \
		{ K10, K11,   K12, K13,   K14, K15, K16,   K17, K18, K19, K1A,   K1B,   K1C }, \
		{ K20, K21,   K22, K23,   K24, K25, K26,   K27, K28, K29, K2A,   K2B,   K2C }, \
		{ K30, KC_NO, K32, KC_NO, K34, K35, KC_NO, K37, K38, K39, KC_NO, KC_NO, K3C } \
	}
