/* Copyright 2015-2023 Jack Humbert
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

enum planck_layers { _QWERTY, _WASD, _LOWER, _RAISE, _ADJUST, _FUNCTION, _FUNCTIONMAC, _WORK, _GAME };

enum planck_keycodes { QWERTY = SAFE_RANGE, GAMING, BACKLIT };

/*
//Tap Dance Declarations
enum {
  TD_Q_UNDO = 0,
  TD_W_CUT = 1,
  TD_E_COPY = 2,
  TD_R_PASTE = 3
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_UNDO]  = ACTION_TAP_DANCE_DOUBLE(KC_Q, LCTL(KC_Z)),
    [TD_W_CUT]  = ACTION_TAP_DANCE_DOUBLE(KC_W, LCTL(KC_X)),
    [TD_E_COPY]  = ACTION_TAP_DANCE_DOUBLE(KC_E, LCTL(KC_C)),
    [TD_R_PASTE]  = ACTION_TAP_DANCE_DOUBLE(KC_R, LCTL(KC_V))
};
*/

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNK MO(_FUNCTION)
#define FUNKMAC MO(_FUNCTIONMAC) //currently not used
#define WORK MO(_WORK)
#define GAME MO(_GAME)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Tab/RS|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Sht/En|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FUNK | Ctrl | Alt  | GUI  |Lower | Space| Space|Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'

     KC_ESC,    KC_Q,    KC_W,    KC_E,          KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
TD(TD_Q_UNDO), TD(TD_W_CUT), TD(TD_E_COPY), TD(TD_R_PASTE),
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,    KC_Q,    KC_W,    KC_E,          KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(RAISE,  KC_TAB), MT(MOD_LSFT,KC_A),MT(MOD_LCTL, KC_S),    MT(MOD_LALT, KC_D), MT(MOD_LGUI, KC_F),    KC_G,    KC_H,    MT(MOD_RGUI,KC_J), MT(MOD_RALT,KC_K), MT(MOD_RCTL,KC_L), MT(MOD_RSFT,KC_SCLN), KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,          KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MT(MOD_RSFT, KC_ENT),
    OSL(FUNK), KC_LCTL, KC_LALT, OSM(MOD_LGUI), LOWER,   LT(WORK,KC_SPC), LT(GAME,KC_SPC),  RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),
/* Gaming WASD no mod tap for alphas
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Sht/En|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | FUNK | Ctrl | Alt  | GUI  |Lower |    Space    |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_WASD] = LAYOUT_planck_grid(
    KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    LT(RAISE,KC_TAB),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   MT(MOD_RSFT, KC_ENT),
    OSL(FUNK), KC_LCTL, KC_LALT, OSM(MOD_LGUI), LOWER,   LT(WORK,KC_SPC), LT(GAME,KC_SPC),  RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |  9   |      | DEL  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MacRT |MacUp |MacLt |      |      |   4  |   5  |  6   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  0   |   1  |   2  |  3   |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   .  |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,   KC_9,    _______, KC_DEL,   
    _______, _______, LCTL(KC_LEFT), LCTL(KC_UP), LCTL(KC_RGHT), _______, _______, KC_4,    KC_5,   KC_6,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,   KC_3,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT, _______, _______, _______
),
/* FUNK aka _Function
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Ctrl Z|Ctrl X|Ctrl C|Ctrl V|      |      |  F11 |  F12 |      | Pg Up|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home | Pg Dn| End  |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTION] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, 
    _______, _______, _______, _______, _______, _______, _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, KC_F11,  KC_F12,  _______, KC_PGUP, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END
//  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   (  |   )  |   {  |   }  |   [  |   ]  |      |      |      |      |      | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   \  |   !  |   *  |  -   |   +  |   =  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |   &  |   @  |   #  |   $  |   %  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  `   |   ~  |  _   |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, KC_DEL,
    KC_BSLS, KC_EXLM, KC_ASTR, KC_MINS, KC_PLUS, KC_EQL,  _______, _______, _______, _______, _______, _______,
    KC_CIRC, KC_AMPR, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, _______, _______, _______, _______, _______,
    _______, KC_GRV, KC_TILD, KC_UNDS, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
/* Work
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      ||Undo |Cut   |Copy  |Paste |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_WORK] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Game
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Gaming|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  GAMING,  _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
float imperial_march[][2]    = SONG(IMPERIAL_MARCH);
float ff_prelude[][2]    = SONG(FF_PRELUDE);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    //state = update_tri_layer_state(state, _LOWER, _FUNCTION, _ADJUST); zero key is fumbling things up
    return state;
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("Normal Layout!!! Work, work.\n");
// #ifdef AUDIO_ENABLE
//                 stop_all_notes();
//                 PLAY_SONG(imperial_march);
// #endif
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case GAMING:
            if (record->event.pressed) {
                print("Gaming Layout!!!! Pew Pew Pew!!!\n");
// #ifdef AUDIO_ENABLE
//                 stop_all_notes();
//                 PLAY_SONG(ff_prelude);
// #endif                
                set_single_persistent_default_layer(_WASD);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}}, 
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307	

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
/*
//custom tapping term TD(TD_Q_UNDO), TD(TD_W_CUT), TD(TD_E_COPY), TD(TD_R_PASTE)
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_Q_UNDO):
        case TD(TD_W_CUT):
        case TD(TD_E_COPY):
        case TD(TD_R_PASTE):
            return 150;
        default:
            return TAPPING_TERM;
    }
}
*/