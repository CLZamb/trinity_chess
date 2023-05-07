#ifndef KEYBOARD_KEY_H
#define KEYBOARD_KEY_H

enum class ASCIICharEncoding {
  NUL         = 0,
  ESC         = 27,
  ARROW_UP    = 'A',
  ARROW_DOWN  = 'B',
  ARROW_RIGHT = 'C',
  ARROW_LEFT  = 'D',
  ENTER       = 10,
  q           = 'q',
  Q           = 'Q',
  W           = 'w',
  A           = 'a',
  S           = 's',
  D           = 'd',
  LEFT_BRACKET  = '[',
};
  // namespace Keyboard
/*
    Arrow keys, Page Up, Page Down, Home, 
    and End all input 3 or 4 bytes to the terminal: 27, '[', 
    and then one or two other characters. 
    This is known as an escape sequence. 
    All escape sequences start with a 27 byte. 
    Pressing Escape sends a single 27 byte as input.

    Backspace is byte 127. 

    Delete is a 4-byte escape sequence.

    Enter is byte 10, which is a newline character, also known as '\n'.

NUL  (null)                       0
SOH  (start of heading)           1
STX  (start of text)              2
ETX  (end of text)                3
EOT  (end of transmission)        4
ENQ  (enquiry)                    5
ACK  (acknowledge)                6
BEL  (bell)                       7
BS   (backspace)                  8
TAB  (horizontal tab)             9
LF   (line feed, newline)        10
VT   (vertical tab)              11
FF   (form feed, page break)     12
CR   (carriage return)           13
SO   (shift out)                 14
SI   (shift in)                  15
DLE  (data link escape)          16
DC1  (device control 1)          17
DC2  (device control 2)          18
DC3  (device control 3)          19
DC4  (device control 4)          20
NAK  (negative acknowledge)      21
SYN  (synchronous idle)          22
ETB  (end of transmission block) 23
CAN  (cancel)                    24
EM   (end of medium)             25
SUB  (substitute)                26
ESC  (escape)                    27
FS   (file separator)            28
GS   (group separator)           29
RS   (record separator)          30
US   (unit separator)            31
     (space)                     32
!    (exclamation mark)           33
"    (double quote)               34
#    (number sign)                35
$    (dollar sign)                36
%    (percent)                    37
&    (ampersand)                  38
'    (single quote)               39
(    (left parenthesis)           40
)    (right parenthesis)          41
*    (asterisk)                   42
+    (plus)                       43
,    (comma)                      44
-    (minus)                      45
.    (period)                     46
/    (slash)                      47
0-9  (digits)                     48-57
:    (colon)                      58
;    (semicolon)                  59
<    (less than)                  60
=    (equals)                     61
>    (greater than)               62
?    (question mark)              63
@    (at symbol)                  64
A-Z  (uppercase letters)          65-90
[    (left bracket)               91
\    (backslash)                  92
]    (right bracket)              93
^    (caret)                      94
_    (underscore)                 95
`    (grave accent)               96
a-z  (lowercase letters)          97-122
{    (left brace)                 123
|    (vertical bar)               124
}    (right brace)                125
~    (tilde)                      126
DEL  (delete)                     127
*/

#endif // KEYBOARD_KEY_H
