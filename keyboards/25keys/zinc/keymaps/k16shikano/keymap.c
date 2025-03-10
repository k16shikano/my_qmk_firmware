#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
rgblight_config_t RGB_current_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  BACKLIT,
  KANA,
  EISU,
  IME_TOGGLE,
  RGBRST
};

bool ime_on = false;

#define QWERTY PDF(_QWERTY)
#define COLEMAK PDF(_COLEMAK)
#define DVORAK PDF(_DVORAK)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return 175;
        case LCTL_T(KC_Z):
            return 225;
        case LCTL_T(KC_S):
            return 225;
        case LSFT_T(KC_X):
            return 150;
        case LSFT_T(KC_G):
            return 225;
        case LT(4,KC_F):
            return 225;
        case LALT_T(KC_C):
            return 225;
        case LT(4,KC_V):
            return 225;
        case LT(3,KC_ENT):
            return 130;
        case LT(2,KC_B):
            return 90;
        case LT(1,KC_N):
            return 200;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return false;
        case LCTL_T(KC_Z):
            return false;
        case LCTL_T(KC_S):
            return false;
        case LSFT_T(KC_X):
            return false;
        case LSFT_T(KC_G):
            return false;
        case LALT_T(KC_C):
            return false;
        case LT(4,KC_V):
            return false;
        case LT(2,KC_B):
            return false;
        case LT(1,KC_N):
            return false;
        default:
            return true;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return 0;
        case LT(3,KC_ENT):
            return 0;
        case LT(2,KC_B):
            return 0;
        case LSFT_T(KC_X):
            return 0;
        case LT(1,KC_N):
            return 0;
        case LCTL_T(KC_S):
            return 0;
        default:
            return QUICK_TAP_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_A):
            return false;
        case LCTL_T(KC_Z):
            return false;
        case LCTL_T(KC_S):
            return false;
        case LSFT_T(KC_X):
            return false;
        case LSFT_T(KC_G):
            return false;
        case LALT_T(KC_C):
            return false;
        case LT(4,KC_V):
            return false;
        case LT(2,KC_B):
            return false;
        case LT(1,KC_N):
            return false;
        default:
            return false;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_S):
            return true;
        default:
            return false;
    }
}

// Tap Dance declarations
enum {
      TD_Q_ESC,
      TD_CD,
      TD_ST,
      TD_QT_DQ,
      TD_SC_CL,
};

void dance_q_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_Q);
    } else {
        register_code(KC_ESCAPE);
    }
}

void dance_q_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_Q);
    } else {
        unregister_code(KC_ESCAPE);
    }
}

void dance_cd_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_COMMA);
    } else {
      register_code(KC_DOT);
    }
}

void dance_cd_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_COMMA);
    } else {
        unregister_code(KC_DOT);
    }
}

void dance_st_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_SPACE);
    } else {
      register_code(KC_TAB);
    }
}

void dance_st_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_SPACE);
    } else {
        unregister_code(KC_TAB);
    }
}

void dance_qtdq_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_QUOT);
    } else {
      register_code16(KC_DQUO);
    }
}

void dance_qtdq_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_QUOT);
    } else {
        unregister_code16(KC_DQUO);
    }
}

void dance_sccl_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_SCLN);
    } else {
      register_code16(KC_COLN);
    }
}

void dance_sccl_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_SCLN);
    } else {
        unregister_code16(KC_COLN);
    }
}

// All tap dance functions would go here. Only showing this one.
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_q_finished, dance_q_reset),
    [TD_CD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cd_finished, dance_cd_reset),
    [TD_ST] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_st_finished, dance_st_reset),
    [TD_QT_DQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_qtdq_finished, dance_qtdq_reset),
    [TD_SC_CL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_sccl_finished, dance_sccl_reset),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { \
  [0] = LAYOUT_ortho_4x12( \
      KC_ESC,       KC_1,         KC_2,         KC_3,       KC_4,       KC_5,              KC_6,   KC_7, KC_8, KC_9,   KC_0,          KC_BSPC, \
      KC_Q,         KC_W,         KC_E,         KC_R,       KC_T,       UG_TOGG,           UG_TOGG, KC_Y, KC_U, KC_I,   KC_O,          KC_BSPC, \
      LCTL_T(KC_A), LCTL_T(KC_S), KC_D,         KC_F,       KC_G,       ADJUST,            KC_TRNS, KC_H, KC_J, KC_K,   KC_L,          LT(5,KC_P), \
      LCTL_T(KC_Z), LSFT_T(KC_X), LALT_T(KC_C), LT(2,KC_V), LT(2,KC_B), IME_TOGGLE,        LT(1,KC_SPC), LT(1,KC_N), KC_M,  KC_COMM,LSFT_T(KC_DOT),LT(3,KC_ENT) \
      ),

  [1] = LAYOUT_ortho_4x12( \
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
      KC_TAB,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_BSPC, \
      KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_SPC,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5, LALT(KC_GRV), \
      KC_LCTL, KC_LSFT, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,          KC_SPC,  KC_SPC,  KC_SPC,  KC_TAB,  KC_TAB, LALT(KC_GRV) \
      ),

  [2] = LAYOUT_ortho_4x12( \
      KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, KC_BSPC, \
      KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, KC_BSLS, \
      KC_LCTL, KC_LCTL, KC_GRV,  KC_TILD, LALT(KC_GRV), LALT(KC_GRV),         KC_LPRN, KC_RPRN, TD(TD_SC_CL), TD(TD_QT_DQ), KC_BSLS, KC_BSLS, \
      KC_LCTL, KC_LSFT, KC_LALT, LALT(KC_GRV), LALT(KC_GRV), LT(2,KC_NO),     KC_LBRC, KC_RBRC, KC_LT, KC_GT, KC_SLSH      ,LT(3,KC_SLSH) \
      ),

  [3] = LAYOUT_ortho_4x12( \
    KC_ESC,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_LEFT, KC_LEFT,     KC_UP,   KC_UP,   KC_UP,          KC_DEL, \
    KC_ESC,       KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_LEFT, KC_LEFT,     KC_UP,   KC_UP,   KC_UP,          KC_DEL, \
    KC_LCTL,      KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,   KC_LEFT, KC_LEFT,     KC_LEFT, KC_UP,   KC_RGHT,        KC_TRNS, \
    KC_LCTL,      KC_LSFT,      KC_LALT,      KC_TRNS,      KC_LSFT,  KC_LSFT,   KC_LEFT, KC_LEFT,     KC_LEFT, KC_DOWN, KC_RGHT,        LT(3,KC_NO) \
    ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      | Reset|RGBRST|Aud on|Audoff|      |             |      |Qwerty|Colemk|Dvorak|      | Ins  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |RGB ON| HUE+ | SAT+ | VAL+ | Mac  |             | Win  |  -   |   =  |Print |ScLock|Pause |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |MODE R| MODE | HUE- | SAT- | VAL- |      |             |      |      |      |      |PageUp|      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      | EISU | EISU | EISU |             | KANA | KANA | Home |PageDn|PageUp| End  |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] =  LAYOUT_ortho_4x12( \
      _______, QK_BOOT, RGBRST,  _______, _______, _______,                   _______, QWERTY,  COLEMAK, DVORAK,  _______, KC_INS,
      _______, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, AG_NORM,                   AG_SWAP, KC_MINS, KC_EQL,  KC_PSCR, KC_SCRL, KC_PAUS,
      UG_PREV, UG_NEXT, UG_HUED, UG_SATD, UG_VALD, _______,                   _______, _______, _______, _______, KC_PGUP, _______,
      _______, _______, _______, EISU,    EISU,    EISU,                      KANA,    KANA,    KANA,    KC_HOME, KC_PGDN, KC_END
      )
};

// define variables for reactive RGB
bool TOG_STATUS = false;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_mode_noeeprom(RGB_current_config.mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
           rgblight_mode_noeeprom(16);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            rgblight_mode_noeeprom(15);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode_noeeprom(RGB_current_config.mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case ADJUST:
        if (record->event.pressed) {
          layer_on(_ADJUST);
        } else {
          layer_off(_ADJUST);
        }
        return false;
        break;

      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case QK_UNDERGLOW_MODE_PREVIOUS:
      #if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step_reverse();
          RGB_current_config.mode = rgblight_config.mode;
        }
      return false;
      #endif
      break;

    case QK_UNDERGLOW_MODE_NEXT:
      #if defined(RGBLIGHT_ENABLE)
        if (record->event.pressed) {
          rgblight_mode_noeeprom(RGB_current_config.mode);
          rgblight_step();
          RGB_current_config.mode = rgblight_config.mode;
        }
      return false;
      #endif
      break;

    case EISU:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LNG2);
        }else{
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LNG2);
      }
      return false;
      break;
    case KANA:
      if (record->event.pressed) {
        if(keymap_config.swap_lalt_lgui==false){
          register_code(KC_LNG1);
        }else{
         SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LNG1);
      }
      return false;
      break;

    case IME_TOGGLE:
      if (record->event.pressed) {
        if (ime_on) {
          tap_code(KC_LNG1); // IMEオフ（英数）
        } else {
          tap_code(KC_LNG2); // IMEオン（かな）
        }
        ime_on = !ime_on; // 状態をトグル
      }
      return false;
      break;

    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_config = rgblight_config;
        }
      #endif
      break;
  }
  return true;
}


void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
      RGB_current_config = rgblight_config;
    #endif
}
