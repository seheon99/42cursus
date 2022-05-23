/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_define.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:44:52 by seyu              #+#    #+#             */
/*   Updated: 2020/11/02 18:32:40 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DEFINE_H
# define MLX_DEFINE_H

/*
**	-----------------------------------
**	Event Definitions
**	-----------------------------------
*/

/*
**	Input Event Masks.
**	Used as event-mask window attribute and as arguments to Grab requests.
**	Not to be confused with event names.
*/

# define NOEVENTMASK				0
# define KEYPRESSMASK				1
# define KEYRELEASEMASK				2
# define BUTTONPRESSMASK			4
# define BUTTONRELEASEMASK			8
# define ENTERWINDOWMASK			16
# define LEAVEWINDOWMASK			32
# define POINTERMOTIONMASK			64
# define POINTERMOTIONHINTMASK		128
# define BUTTON1MOTIONMASK			256
# define BUTTON2MOTIONMASK			512
# define BUTTON3MOTIONMASK			1024
# define BUTTON4MOTIONMASK			2048
# define BUTTON5MOTIONMASK			4096
# define BUTTONMOTIONMASK			8192
# define KEYMAPSTATEMASK			16384
# define EXPOSUREMASK				32768
# define VISIBILITYCHANGEMASK		65536
# define STRUCTURENOTIFYMASK		131072
# define RESIZEREDIRECTMASK			262144
# define SUBSTRUCTURENOTIFYMASK		524288
# define SUBSTRUCTUREREDIRECTMASK	1048576
# define FOCUSCHANGEMASK			2097152
# define PROPERTYCHANGEMASK			4194304
# define COLORMAPCHANGEMASK			8388608
# define OWNERGRABBUTTONMASK		16777216

/*
**	Event names.
**	Used in "type" field in XEvent structures.
**	Not to be confused with event masks above.
**	They start from 2
**		because 0 and 1 are reserved in the protocol for errors and replies.
*/

# define KEYPRESS			2
# define KEYRELEASE			3
# define BUTTONPRESS		4
# define BUTTONRELEASE		5
# define MOTIONNOTIFY		6
# define ENTERNOTIFY		7
# define LEAVENOTIFY		8
# define FOCUSIN			9
# define FOCUSOUT			10
# define KEYMAPNOTIFY		11
# define EXPOSE				12
# define GRAPHICSEXPOSE		13
# define NOEXPOSE			14
# define VISIBILITYNOTIFY	15
# define CREATENOTIFY		16
# define DESTROYNOTIFY		17
# define UNMAPNOTIFY		18
# define MAPNOTIFY			19
# define MAPREQUEST			20
# define REPARENTNOTIFY		21
# define CONFIGURENOTIFY	22
# define CONFIGUREREQUEST	23
# define GRAVITYNOTIFY		24
# define RESIZEREQUEST		25
# define CIRCULATENOTIFY	26
# define CIRCULATEREQUEST	27
# define PROPERTYNOTIFY		28
# define SELECTIONCLEAR		29
# define SELECTIONREQUEST	30
# define SELECTIONNOTIFY	31
# define COLORMAPNOTIFY		32
# define CLIENTMESSAGE		33
# define MAPPINGNOTIFY		34
# define GENERICEVENT		35
# define LASTEVENT			36

/*
**	-----------------------------------
**	Keycode Definitions
**	-----------------------------------
*/

/*
**	Letters Keycodes
*/

# define KEYCODE_A	97
# define KEYCODE_B	11
# define KEYCODE_C	8
# define KEYCODE_D	100
# define KEYCODE_E	14
# define KEYCODE_F	3
# define KEYCODE_G	5
# define KEYCODE_H	4
# define KEYCODE_I	34
# define KEYCODE_J	38
# define KEYCODE_K	40
# define KEYCODE_L	37
# define KEYCODE_M	46
# define KEYCODE_N	45
# define KEYCODE_O	31
# define KEYCODE_P	35
# define KEYCODE_Q	12
# define KEYCODE_R	15
# define KEYCODE_S	115
# define KEYCODE_T	17
# define KEYCODE_U	32
# define KEYCODE_V	9
# define KEYCODE_W	119
# define KEYCODE_X	7
# define KEYCODE_Y	16
# define KEYCODE_Z	6

/*
**	Numbers (not numeric keypad ones)
*/

# define KEYCODE_K1 18
# define KEYCODE_K2 19
# define KEYCODE_K3 20
# define KEYCODE_K4 21
# define KEYCODE_K5 23
# define KEYCODE_K6 22
# define KEYCODE_K7 26
# define KEYCODE_K8 28
# define KEYCODE_K9 25
# define KEYCODE_K0 29

/*
**	Numbers (numeric keypad)
*/

# define KEYCODE_N1 83
# define KEYCODE_N2 84
# define KEYCODE_N3 85
# define KEYCODE_N4 86
# define KEYCODE_N5 87
# define KEYCODE_N6 88
# define KEYCODE_N7 89
# define KEYCODE_N8 91
# define KEYCODE_N9 92
# define KEYCODE_N0 82

/*
**	Special Letters Keycodes
*/

# define KEYCODE_SPACE	49
# define KEYCODE_BQ		50
# define KEYCODE_MN		27
# define KEYCODE_PL		24
# define KEYCODE_SBO	33
# define KEYCODE_SBC	30
# define KEYCODE_BSL	42
# define KEYCODE_SC		41
# define KEYCODE_SQ		39
# define KEYCODE_CM		43
# define KEYCODE_PT		47
# define KEYCODE_SL		44

/*
**	Special Keycodes
*/

# define KEYCODE_ESC	53
# define KEYCODE_TAB	48
# define KEYCODE_CL		272
# define KEYCODE_LSFT	65505
# define KEYCODE_LCTRL	256
# define KEYCODE_LOPT	261
# define KEYCODE_LCMD	259
# define KEYCODE_LDEL	51
# define KEYCODE_RTN	36
# define KEYCODE_RSFT	258
# define KEYCODE_RCTRL	269
# define KEYCODE_ROPT	262
# define KEYCODE_RCMD	260
# define KEYCODE_FN		279
# define KEYCODE_RDEL	117
# define KEYCODE_HOME	115
# define KEYCODE_END	119
# define KEYCODE_PUP	116
# define KEYCODE_PDOWN	121
# define KEYCODE_CLR	71

/*
** Arrow keys
*/

# define KEYCODE_UP		126
# define KEYCODE_DOWN	125
# define KEYCODE_RIGHT	65363
# define KEYCODE_LEFT	65361

#endif
