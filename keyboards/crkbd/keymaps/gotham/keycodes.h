#pragma once

enum layers {
    _COLEMAK_DH,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { COLEMAK_DH = SAFE_RANGE, LOWER, RAISE, ADJUST, RGBRST };
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

#define LOW_SPC LT(_LOWER, KC_SPC)
#define RAI_EQ LT(_RAISE, KC_EQL)
#define RAI_SPC LT(_RAISE, KC_SPC)
#define RAI_ENT LT(_RAISE, KC_ENT)
#define LOW_BSP LT(_LOWER, KC_BSPC)
#define LOW_DEL LT(_LOWER, KC_DEL)
#define ADJ_GRV LT(_ADJUST, KC_GRV)
#define KC_ANGL LSFT(KC_COMM)
#define KC_ANGR LSFT(KC_DOT)

#define ALT_ENT LALT_T(KC_ENT)
#define ALT_SPC LALT_T(KC_SPC)
