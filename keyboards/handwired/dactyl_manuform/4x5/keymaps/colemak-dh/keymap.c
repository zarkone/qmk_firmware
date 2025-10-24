#include QMK_KEYBOARD_H
#include "quantum/process_keycode/process_unicode.h"

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _FUNC  3

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)
#define SFT_SPC  SFT_T(KC_SPC)

#define KC_ML  KC_MS_LEFT
#define KC_MR  KC_MS_RIGHT
#define KC_MU  KC_MS_UP
#define KC_MD  KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define FUNC  MO(_FUNC)

// -------------
#define GUI_TT  MT(MOD_LGUI, KC_T)
#define GUI_N   MT(MOD_RGUI, KC_N)
#define SFT_G   MT(MOD_RSFT, KC_G)
#define SFT_M   MT(MOD_RSFT, KC_M)
#define LOW_SPC LT(_LOWER, KC_SPC)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define LOW_ENT LT(_LOWER, KC_ENT)
#define ALT_ENT RALT_T(KC_ENT)
#define CTL_SPC CTL_T(KC_SPC)
#define CTL_ENT CTL_T(KC_ENT)
#define CTL_BSP CTL_T(KC_BSPC)
#define KC_ANGL LSFT(KC_COMM)
#define KC_ANGR LSFT(KC_DOT)

/* ---------- Emoji keycodes (send raw UTF-8) ---------- */
enum custom_keycodes {
    EMOJI_SMILE = SAFE_RANGE, // 😄
    EMOJI_ROFL,               // 🤣
    EMOJI_FIRE,               // 🔥
    EMOJI_PRAY,               // 🙏
    EMOJI_HEART,              // 💗  (single code point; avoids VS-16 pair issues)

    EMOJI_BLUSH,              // 😊
    EMOJI_WAVE,               // 👋
    EMOJI_CLAP,               // 👏
    EMOJI_TADA,               // 🎉
    EMOJI_LSMILE,              // 🙂

    EMOJI_TEAR,               // 😢
    EMOJI_CRY,                // 😭
    EMOJI_MINDBLOW,           // 🤯
    EMOJI_OOO,                // 😮
    EMOJI_ANGER,              // 😡
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    switch (keycode) {
        case EMOJI_SMILE:     send_unicode_string("😄"); return false;
        case EMOJI_ROFL:      send_unicode_string("🤣"); return false;
        case EMOJI_FIRE:      send_unicode_string("🔥"); return false;
        case EMOJI_PRAY:      send_unicode_string("🙏"); return false;
        case EMOJI_HEART:     send_unicode_string("💗"); return false;

        case EMOJI_BLUSH:     send_unicode_string("😊"); return false;
        case EMOJI_WAVE:      send_unicode_string("👋"); return false;
        case EMOJI_CLAP:      send_unicode_string("👏"); return false;
        case EMOJI_TADA:      send_unicode_string("🎉"); return false;
        case EMOJI_LSMILE:     send_unicode_string("🙂"); return false;

        case EMOJI_TEAR:      send_unicode_string("😢"); return false;
        case EMOJI_CRY:       send_unicode_string("😭"); return false;
        case EMOJI_MINDBLOW:  send_unicode_string("🤯"); return false;
        case EMOJI_OOO:       send_unicode_string("😮"); return false;
        case EMOJI_ANGER:     send_unicode_string("😡"); return false;
    }
    return true;
}

/* ---------- Keymaps ---------- */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(
       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,  KC_SCLN,
       KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,  KC_O,
       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,KC_SLSH,
       KC_QUOT, KC_DQT,                                                          KC_EQL,   KC_GRV,

                                           CTL_SPC, SFT_SPC,   SFT_ENT,  CTL_BSP,
                                           KC_LALT, LOWER,     LOWER,    KC_LALT,
                                           KC_LGUI, RAISE,     RAISE,    KC_LGUI
   ),

   [_RAISE] = LAYOUT(
     KC_ESC,  KC_DLR,  KC_LCBR, KC_AMPR, KC_ASTR,                        CW_TOGG, KC_7,    KC_8,    KC_9,    QK_BOOT,
     KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_CIRC,                        KC_CAPS, KC_4,    KC_5,    KC_6,    KC_PLUS,
     KC_PERC, KC_CIRC, KC_LBRC, KC_PERC, KC_PIPE,                        KC_PSCR, KC_1,    KC_2,    KC_3,    KC_MINS,
                       _______, _______,                                                    KC_MB1,  KC_DOT,

                                            _______, _______,   KC_0,    _______,
                                            _______, FUNC,      FUNC,    _______,
                                            _______, _______,   _______, _______
   ),

   /* FUNC: left 3x5 = emojis (raw UTF-8); right = F-keys */
   [_FUNC] = LAYOUT(
     EMOJI_CLAP,  EMOJI_WAVE, EMOJI_FIRE,     EMOJI_PRAY,   EMOJI_BLUSH,     KC_J, KC_F7, KC_F8, KC_F9,  KC_F10,
     EMOJI_MINDBLOW, EMOJI_LSMILE, EMOJI_SMILE,     EMOJI_TADA,    EMOJI_OOO,     KC_M, KC_F4, KC_F5, KC_F6,  KC_F11,
     EMOJI_TEAR,  EMOJI_ROFL,  EMOJI_CRY, EMOJI_HEART,   EMOJI_ANGER,     KC_K, KC_F1, KC_F2, KC_F3,  KC_F12,
                                _______, _______,                                                    _______, _______,

                                            _______, _______,   KC_RSFT, _______,
                                            _______, _______,   _______, KC_RALT,
                                            _______, _______,   _______, _______
   ),

   [_LOWER] = LAYOUT(
     KC_UNDS, KC_COLN, KC_EQUAL, KC_MINS, KC_PLUS,                      KC_MUTE, KC_VOLD, KC_MPLY, KC_VOLU, KC_BSLS,
     KC_ANGL, KC_ANGR, KC_LPRN,  KC_RPRN, KC_PGUP,                      KC_DQUO, KC_LEFT, KC_UP,   KC_RIGHT, KC_QUOT,
     KC_LCBR, KC_RCBR, KC_LBRC,  KC_RBRC, KC_PGDN,                      KC_UNDS, KC_HOME, KC_DOWN, KC_END,   _______,
                 KC_F11, KC_F12,                                                                 _______, _______,

                                   KC_TAB, KC_ESC,                       KC_ENT,  KC_DEL,
                                   _______, _______,                     _______, _______,
                                   _______, FUNC,                        FUNC,    _______
   )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}
