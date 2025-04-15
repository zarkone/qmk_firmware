#include QMK_KEYBOARD_H

#define CTL_Z    CTL_T(KC_Z)
#define CTL_SLSH CTL_T(KC_SLSH)
#define ALT_ENT  ALT_T(KC_ENT)
#define ALT_SPC  ALT_T(KC_SPC)
#define KC_ANGL  LSFT(KC_COMM)
#define KC_ANGR  LSFT(KC_DOT)
#define LOW_BSP  LT(1, KC_BSPC)
#define LOW_DEL  LT(1, KC_DEL)
#define LOW_SPC LT(1, KC_SPC)

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    CLN_EQ = SAFE_RANGE,
    EXCL_EQ,
    // ... other custom keycodes
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  KC_ESC, KC_UNDS, CLN_EQ, EXCL_EQ,KC_MINS, KC_PLUS,                    _______, KC_VOLD, KC_MPLY, KC_VOLU, _______, KC_TILD,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_GRV,
  KC_LGUI,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_LGUI,
  KC_LSFT,  CTL_Z,   KC_X,    KC_C,    KC_D,    KC_V, CW_TOGG,   KC_CAPS,  KC_K,    KC_H,    KC_COMM, KC_DOT,  CTL_SLSH,  KC_LSFT,
                     KC_DQUO, MO(_RAISE),LOW_SPC, ALT_SPC,   ALT_ENT, LOW_BSP, MO(_RAISE), KC_QUOT
),

 [_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______,  _______,
  _______, KC_UNDS, KC_COLN, KC_EQUAL,KC_MINS, KC_PLUS,                    _______, KC_VOLD, KC_MPLY, KC_VOLU, _______, _______,
  _______, KC_ANGL, KC_ANGR, KC_LPRN, KC_RPRN, KC_PGUP,                   KC_DQUO, KC_LEFT, KC_UP,   KC_RIGHT,KC_QUOT, _______,
  _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PGDN, _______, _______, _______, KC_HOME, KC_DOWN, KC_END,  KC_BSLS, KC_TILD,
                             _______, _______, _______, _______, _______, LOW_DEL, _______, _______
),

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, QK_BOOT,
  _______, _______, KC_CIRC, KC_LCBR, KC_AMPR, KC_ASTR,                     _______, KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_CIRC,                     _______, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
  _______, _______, _______, _______, KC_PERC, KC_PIPE,   _______, _______, KC_PSCR, KC_1,    KC_2,    KC_3,    KC_DOT, _______,
                             _______, _______, _______,  _______, KC_0,     KC_DOT, _______, _______
),
[3] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, KC_F10, KC_F11, KC_F12, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, KC_F7,   KC_F8, KC_F9,  _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, KC_F4,   KC_F5, KC_F6,  _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2, KC_F3,  _______, _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void rgb_set_zrkn(void) {
  #ifdef RGBLIGHT_ENABLE
  rgblight_setrgb(173,235,179);
  /* rgblight_setrgb(255, 102, 204); */

  #endif
}

bool oled_task_user(void) {
  rgb_set_zrkn();
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
  case CLN_EQ:
    if (record->event.pressed) {
      SEND_STRING(":=");
    }
    return false; // Skip further processing of this key
  case EXCL_EQ:
    if (record->event.pressed) {
      SEND_STRING("!=");
    }
    return false;
  }
  return true;
}
