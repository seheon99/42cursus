<?php
define( 'DB_NAME', 'wordpress' );
define( 'DB_USER', 'seyu' );
define( 'DB_PASSWORD', 'seyumysql' );
define( 'DB_HOST', 'mysql.ft-services' );
define( 'DB_CHARSET', 'utf8mb4' );
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         'c4}6AzEg~8&KCMpb>mrj^K:-l/el0;|qzvfbtAj,KFTnSv,=h,gPW#[j/d;I(iq.' );
define( 'SECURE_AUTH_KEY',  'hSeW})f*.f8SxXXhPJJerf)lIzZg$>KJ_]WupX^m.1&@3`~&SpzgT/<JJ7Q{37Q<' );
define( 'LOGGED_IN_KEY',    'lm=R_7~I4 $Q>p gIqeA~Wqb(|-@y9KGy29)L?%U[o%V%S`}VI^%1Da+1/4M|,jS' );
define( 'NONCE_KEY',        '%69tVV*,OA%%TPjLXI9e[#+V^zwZ1/!])#7AnO8Fix@e]4= vyv^?<trCj|q#A0]' );
define( 'AUTH_SALT',        'L&e75+7m/-?/;04Y)Y1)zN`(j;z_uWb_cWKRYxM|D|)%OC3E1slj9Mntby+<$e&5' );
define( 'SECURE_AUTH_SALT', 'lE!o1.yK!T~KPZ~>da(!;(]O+3+o?{$NV?e^9;1x~N9l3pxJCV(|rdgj2>taDx.%' );
define( 'LOGGED_IN_SALT',   '=K3DRq)D2MR0v;gugds*Xs8z=)/R0#GU~O:;8p(zKdcfqOpr+5JmWp:zNC!k*0#d' );
define( 'NONCE_SALT',       'H5a[{$H@rsv?T;3?+8/#:p$xY#k}_4]>n?ngR_op[AQj:6n;.HZyf}6x|wOw4^?d' );

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';

