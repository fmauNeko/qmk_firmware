/* Copyright 2019
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

enum custom_keycodes {
  CHERRY = SAFE_RANGE,
  PUTAIN,
  N
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CHERRY:
      if (record->event.pressed) {
        SEND_STRING("BORDEL");
      }
      break;
    case PUTAIN:
      if (record->event.pressed) {
        SEND_STRING("PUTAIN");
      }
      break;
    case N:
      if (record->event.pressed) {
        SEND_STRING("MERDE");
      }
      break;
  }
  return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_3x3(
        CHERRY,  PUTAIN,  N,       \
        MO(1),   KC_UP,   KC_MPLY, \
        KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [1] = LAYOUT_ortho_3x3(
        _______, RESET,   _______, \
        _______, _______, _______, \
        KC_MPRV, _______, KC_MNXT  \
    ),
};
