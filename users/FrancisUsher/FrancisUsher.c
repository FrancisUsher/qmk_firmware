/*
Copyright 2019 Francis Usher

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "FrancisUsher.h"

bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed) {
    static uint16_t this_timer;
    if (pressed) {
        this_timer = timer_read();
    } else {
        if (timer_elapsed(this_timer) < TAPPING_TERM) {
            tap_code(code);
        } else {
            register_code(mod_code);
            tap_code(code);
            unregister_code(mod_code);
        }
    }
    return false;
}

bool mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer) {
    if (pressed) {
        this_timer = timer_read();
    } else {
        if (timer_elapsed(this_timer) < TAPPING_TERM) {
            tap_code(code);
        } else {
            register_code(mod_code);
            tap_code(code);
            unregister_code(mod_code);
        }
    }
    return false;
}

void bootmagic_lite(void) {
    matrix_scan();
#if defined(DEBOUNCING_DELAY) && DEBOUNCING_DELAY > 0
    wait_ms(DEBOUNCING_DELAY * 2);
#elif defined(DEBOUNCE) && DEBOUNCE > 0
    wait_ms(DEBOUNCE * 2);
#else
    wait_ms(30);
#endif
    matrix_scan();
    if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) {
        bootloader_jump();
    }
}

// Add reconfigurable functions here, for keymap customization
// This allows for a global, userspace functions, and continued
// customization of the keymap.  Use _keymap instead of _user
// functions in the keymaps
__attribute__((weak))
void matrix_init_keymap(void) {}

// Call user matrix init, set default RGB colors and then
// call the keymap's init function
void matrix_init_user(void) {

#ifdef BOOTLOADER_CATERINA
    DDRD &= ~(1 << 5);
    PORTD &= ~(1 << 5);

    DDRB &= ~(1 << 0);
    PORTB &= ~(1 << 0);
#endif
    matrix_init_keymap();
}

__attribute__((weak))
void keyboard_post_init_keymap(void) {}

void keyboard_post_init_user(void) {
    keyboard_post_init_keymap();
}

__attribute__((weak))
void shutdown_keymap(void) {}

 void rgb_matrix_update_pwm_buffers(void);

void shutdown_user(void) {
    shutdown_keymap();
}

__attribute__((weak))
void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) {
    suspend_power_down_keymap();
}

__attribute__((weak))
void suspend_wakeup_init_keymap(void) {}

void suspend_wakeup_init_user(void) {
    suspend_wakeup_init_keymap();
}

__attribute__((weak))
void matrix_scan_keymap(void) {}

// No global matrix scan code, so just run keymap's matrix
// scan function
void matrix_scan_user(void) {
    static bool has_ran_yet;
    if (!has_ran_yet) {
        has_ran_yet = true;
        startup_user();
    }
    matrix_scan_keymap();
}

__attribute__((weak))
layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }

// on layer change, no matter where the change was initiated
// Then runs keymap's layer change check
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return layer_state_set_keymap(state);
}

__attribute__((weak))
void eeconfig_init_keymap(void) {}

void eeconfig_init_user(void) {
    eeconfig_init_keymap();
    keyboard_init();
}

bool hasAllBitsInMask(uint8_t value, uint8_t mask) {
    value &= 0xF;
    mask &= 0xF;

    return (value & mask) == mask;
}
