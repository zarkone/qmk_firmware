/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#define GUI_EQ MT(MOD_LGUI, KC_EQL)
#define GUI_SPC MT(MOD_LGUI, KC_SPC)
#define GUI_TT MT(MOD_LGUI, KC_T)
#define GUI_QT MT(MOD_RGUI, KC_QUOT)
#define GUI_N MT(MOD_RGUI, KC_N)

#define SFT_EQ MT(MOD_LSFT, KC_EQL)
#define SFT_QT MT(MOD_RSFT, KC_QUOT)

#define SFT_A MT(MOD_LSFT, KC_A)
#define CTL_Z MT(MOD_LCTL, KC_Z)

#define SFT_O MT(MOD_RSFT, KC_O)
#define CTL_SLSH MT(MOD_RCTL, KC_SLSH)

#define LOW_SPC LT(1, KC_SPC)
#define RAI_EQ LT(2, KC_EQL)
#define ADJ_TAB LT(3, KC_TAB)
#define RAI_SPC LT(2, KC_SPC)
#define RAI_ENT LT(2, KC_ENT)
#define LOW_BSP LT(1, KC_BSPC)
#define LOW_DEL LT(1, KC_DEL)
#define ADJ_GRV LT(_ADJUST, KC_GRV)
#define KC_ANGL LSFT(KC_COMM)
#define KC_ANGR LSFT(KC_DOT)

#define ALT_ENT LALT_T(KC_ENT)
#define ALT_SPC LALT_T(KC_SPC)


#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
#    include "rgb.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
    //|-----------------------------------------------------|                    |-----------------------------------------------------|
     ADJ_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_SCLN,  KC_GRV,
      //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI, KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                          KC_M,    KC_N,    KC_E,  KC_I,    KC_O,  KC_RGUI,
  //---------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_D,    KC_V,                          KC_K,    KC_H,    KC_COMM, KC_DOT,  CTL_SLSH, KC_RSFT,
   //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         RAI_EQ, LOW_SPC, ALT_SPC,     ALT_ENT, LOW_BSP, RAI_SPC
                                      //|--------------------------|  |--------------------------|
  ),

    [1] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC, KC_UNDS, KC_COLN,  KC_EQUAL, KC_MINS, KC_PLUS,                     KC_INS,   KC_VOLD, KC_MPLY,  KC_VOLU,  KC_COLN, KC_CAPS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, KC_ANGL, KC_ANGR, KC_LPRN, KC_RPRN, KC_PGUP,                      KC_DQUO, KC_LEFT, KC_UP,   KC_RIGHT,KC_QUOT, KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PGDN,                    KC_UNDS, KC_HOME, KC_DOWN, KC_END,  KC_BSLS, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, KC_ESC,   _______,    _______, LOW_DEL, _______
                                      //|--------------------------|  |--------------------------|

  ),

    [2] = LAYOUT_split_3x6_3(
   //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_TAB, KC_DLR,  KC_LCBR, KC_AMPR, KC_ASTR,                      CW_TOGG, KC_7,    KC_8,    KC_9,    KC_ASTR, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR, KC_CIRC,                      KC_CAPS, KC_4,    KC_5,    KC_6,    KC_PLUS,  _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_PERC, KC_CIRC, KC_LBRC, KC_PERC, KC_PIPE,                      KC_PSCR, KC_1,    KC_2,    KC_3,    KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_0,   KC_DOT, _______
                                      //|--------------------------|  |--------------------------|
  ),

    [3] = LAYOUT_split_3x6_3(
 //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        _______, KC_F7,   KC_F8,   KC_F9, KC_F10,   _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       _______, KC_F4,   KC_F5,   KC_F6, KC_F11,  QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        _______, KC_F1,   KC_F2,   KC_F3,  KC_F12,  _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,    _______, _______, _______
  )
};

#if defined(RGBLIGHT_ENABLE) || defined(RGB_MATRIX_ENABLE)
layer_state_t layer_state_set_user(layer_state_t state) {
    /* For any layer other than default, save current RGB state and switch to layer-based RGB */
    if (layer_state_cmp(state, 0)) {
        restore_rgb_config();
        rgblight_sethsv_noeeprom(HSV_PURPLE);
    } else {
        uint8_t layer = get_highest_layer(state);
        if (layer_state_cmp(layer_state, 0)) save_rgb_config();
        rgb_by_layer_evil(layer);
        ///rgb_constantly();
    }
    return state;
}
#endif
