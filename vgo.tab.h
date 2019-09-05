#ifndef VGO_TAB_H
#define VGO_TAB_H

#define YY_BUFFER_SIZE 16384

#define KEYWORD_NOT_SUPPORTED -1
#define OPERATOR_NOT_SUPPORTED -2
#define UNTERMINATED_STRING -3
#define CCOMMENT_NOT_ALLOWED -4
#define UNTERMINATED_CCOMMENT -5

/* adapted from the go 1.2.2 distribution */

/* Tokens.  */
#define LLITERAL 258 /* string literal */
#define LASOP 259    /* = */
#define LCOLAS 260   /* := */
#define LBREAK 261
#define LCASE 262
#define LCHAN 263
#define LCONST 264
#define LCONTINUE 265
#define LDDD 266 /* ... */ // TODO: add to flex file
#define LDEFAULT 267
#define LDEFER 268
#define LELSE 269
#define LFALL 270 /* fallthrough */
#define LFOR 271
#define LFUNC 272
#define LGO 273
#define LGOTO 274
#define LIF 275
#define LIMPORT 276
#define LINTERFACE 277
#define LMAP 278
#define LNAME 279
#define LPACKAGE 280
#define LRANGE 281
#define LRETURN 282
#define LSELECT 283
#define LSTRUCT 284
#define LSWITCH 285
#define LTYPE 286
#define LVAR 287
#define LANDAND 288       /* && */
#define LANDNOT 289       /* &^ */
#define LBODY 290 /* { */ // TODO: add to flex file
#define LCOMM 291         /* <- */
#define LDEC 292 /* -- */ // ask about vgo support
#define LEQ 293           /* == */
#define LGE 294           /* >= */
#define LGT 295           /* > */
#define LIGNORE 296       /* */
#define LINC 297 /* ++ */ // ask about vgo support
#define LLE 298           /* <= */
#define LLSH 299          /* << */
#define LLT 300           /* < */
#define LNE 301           /* != */
#define LOROR 302         /* || */
#define LRSH 303          /* >> */

#define LINVALIDOP 304
#define LOP 305
#define LCOMPOP 306
#define LCOMMENT 307
#define LCCOMMENT 308
#define LSTRING 309

#endif