/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"


enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _PLOVER,
  _ADJUST,
  _MOD
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  BACKLIT,
  EXT_PLV,
  M0,
  M1,
  M2,
  M3,
  M4,
  M5
};


#define LOWER TT(_LOWER)
#define RAISE MO(_RAISE)
#define MOD MO(_MOD)
#define TASK LCTL(LSFT(KC_ESC))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |Bksp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Win  | Alt  | Del  |Lower |    Space    |Raise | Left |  Up  | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, KC_DEL,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DQUO,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_QUOT,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),


/* Mod
 * ,-----------------------------------------------------------------------------------.
 * |      |  M0  |  M1  |  M2  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  M3  |  M4  |  M5  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  <   |  ||  |   >  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOD] = LAYOUT_planck_grid(
    _______, M0,      M1,      M2,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______, M3,      M4,      M5,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______, _______, _______, _______, _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
)

};




uint8_t encoder_state = 0;
/*
0 - Volume
1 - Scroll
2 - Horiz Scroll
3 - Zoom
4 - Text Scroll
5 - Text Scroll Select
*/

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M0:
      if (record->event.pressed) {
        encoder_state = 0;
      }
      return false;
      break;
    case M1:
      if (record->event.pressed) {
        encoder_state = 1;

      }
      return false;
      break;
    case M2:
      if (record->event.pressed) {
        encoder_state = 2;
      }
      return false;
      break;
    case M3:
      if (record->event.pressed) {
        encoder_state = 3;
      }
      return false;
      break;
    case M4:
      if (record->event.pressed) {
        encoder_state = 4;
      }
      return false;
      break;
    case M5:
      if (record->event.pressed) {
        encoder_state = 5;
      }
      return false;
      break;
  }
  return true;
}

#define MEDIA_KEY_DELAY 10

/*
void encoder_update_kb(uint8_t index, bool clockwise) {
  uint16_t held_keycode_timer = timer_read();
  switch(encoder_state){
    case 0:
      if (clockwise) { 
		register_code(KC_VOLU); 
	  	while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY); 
		unregister_code(KC_VOLU); 
		} 
	  else { 
		register_code(KC_VOLD); 
		while (timer_elapsed(held_keycode_timer) < MEDIA_KEY_DELAY);
		unregister_code(KC_VOLD); 
		} 
      break;
    case 1:
      if (clockwise) {
        tap_code(KC_WH_U);
      }
      else {
        tap_code(KC_WH_D);
      }
      break;
    case 2:
      if (clockwise) {
        tap_code(KC_WH_R);
      }
      else {
        tap_code(KC_WH_L);
      }
      break;
    case 3:
      if (clockwise) {
        register_code(KC_LCTL);
        tap_code(KC_EQL);
        unregister_code(KC_LCTL);
      }
      else {
        register_code(KC_LCTL);
        tap_code(KC_MINS);
        unregister_code(KC_LCTL);
      }
      break;
    case 4:
      if (clockwise) {
        tap_code(KC_RGHT);
      }
      else {
        tap_code(KC_LEFT);
      }
      break;
    case 5:
      if (clockwise) {
        register_code(KC_LSFT);
        tap_code(KC_RGHT);
        unregister_code(KC_LSFT);
      }
      else {
        register_code(KC_LSFT);
        tap_code(KC_LEFT);
        unregister_code(KC_LSFT);
      }
      break;
  }
}
*/
