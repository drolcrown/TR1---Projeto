/** @file escape.hpp
  @author
    Luigi Minardi Ferreira Maia
  @date
    07/17/2017
  @brief
    Header to deal with escpe codes in terminal.
  @copyright
    GNU Public License.
*/

#ifndef SCAPE_HPP_
#define SCAPE_HPP_

#include <string>

namespace esc {

const std::string ESC = "\033";  // Esc character.

const std::string RESET = ESC + "[0m"; ///< Reset escape codes.

namespace text {
const std::string BOLD = ESC + "[1m";  ///< Incrise intensity.
const std::string BOLD_OFF = ESC + "[21m";  ///< Turn off incrise off intensity.
const std::string FAINT = ESC + "[2m";  ///< Decreased intensity.
const std::string FAINT_OFF = ESC + "[22m";  ///< Turn off decreased intensity.
const std::string ITALIC = ESC + "[3m";  ///< Italic text.
const std::string ITALIC_OFF = ESC + "[23m";  ///< Turn off italic text.
const std::string UNDERLINE = ESC + "[4m";  ///< Underline the text.
const std::string UNDERLINE_OFF = ESC + "[24m";  ///< Turn off underline the text.
const std::string SLOW_BLINK = ESC + "[5m"; ///< Less than 150 blinks/minute.
const std::string RAPID_BLINK = ESC + "[6m"; ///< More than 150 blinks/minute.
const std::string BLINK_OFF = ESC + "[26m"; ///< Turn off blink.
const std::string INVERSE_COLORS = ESC + "[7m";  ///< Swap foreground and background colors.
const std::string INVERSE_COLORS_OFF = ESC + "[27m";  ///< Swap foreground and background colors.
const std::string CONCEAL = ESC + "[8m";  ///< Hide text.
const std::string CONCEAL_OFF = ESC + "[28m";  ///< Turn off hide text.
const std::string CROSSED = ESC + "[9m";  ///< Characters legible, but marked for deletion.
const std::string CROSSED_OFF = ESC + "[29m";  ///< Turn off crossed-out characters.
const std::string FRAMED = ESC + "[51m";
const std::string ENCIRCLED = ESC + "[52m";
const std::string FRAMED_AND_ENCIRCLED_OFF = ESC + "[54m";
const std::string OVERLINED = ESC + "[53m";
const std::string OVERLINED_OFF = ESC + "[55m";
} // namespace text
/** Return the escape command to change the font.
@param option
  Number of the font option.
@pre
  \var option must be in [0, 10], where 0 is the defalt font.
@Return
  Scape command to change the font.
*/
inline std::string font(int option = 0) {
  return ESC + "[" + std::to_string(10 + option) + "m";
} // font()

/** Namespace destineted for colors escape codes. */
namespace color {
/** Namespace destinated for escape codes that change foreground colors. */
namespace foreground {
const std::string DEFAULT = ESC + "[39m";
const std::string BLACK = ESC + "[30m";
const std::string RED = ESC + "[31m";
const std::string GREEN = ESC + "[32m";
const std::string YELLOW = ESC + "[33m";
const std::string BLUE = ESC + "[34m";
const std::string MAGENTA = ESC + "[35m";
const std::string CYAN = ESC + "[36m";
const std::string WHITE = ESC + "[37m";
const std::string BRIGHT_BLACK = ESC + "[90m";
const std::string BRIGHT_RED = ESC + "[91m";
const std::string BRIGHT_GREEN = ESC + "[92m";
const std::string BRIGHT_YELLOW = ESC + "[93m";
const std::string BRIGHT_BLUE = ESC + "[94m";
const std::string BRIGHT_MAGENTA = ESC + "[95m";
const std::string BRIGHT_CYAN = ESC + "[96m";
const std::string BRIGHT_WHITE = ESC + "[97m";
}  // namespace foreground
/** Namespace destinated for escape codes that change background colors. */
namespace background {
const std::string DEFAULT = ESC + "[49m";
const std::string BLACK = ESC + "[40m";
const std::string RED = ESC + "[41m";
const std::string GREEN = ESC + "[42m";
const std::string YELLOW = ESC + "[43m";
const std::string BLUE = ESC + "[44m";
const std::string MAGENTA = ESC + "[45m";
const std::string CYAN = ESC + "[46m";
const std::string WHITE = ESC + "[47m";
const std::string BRIGHT_BLACK = ESC + "[100m";
const std::string BRIGHT_RED = ESC + "[101m";
const std::string BRIGHT_GREEN = ESC + "[102m";
const std::string BRIGHT_YELLOW = ESC + "[103m";
const std::string BRIGHT_BLUE = ESC + "[104m";
const std::string BRIGHT_MAGENTA = ESC + "[105m";
const std::string BRIGHT_CYAN = ESC + "[106m";
const std::string BRIGHT_WHITE = ESC + "[107m";
} // namespace background
}  // namespace color

/** Return a escape code to change foreground text color given an option color.
@details
  See the 8 bit table at https://en.wikipedia.org/wiki/ANSI_escape_code
@param option
  Number to the collor wanted.
@return
  Scape code to change the foreground color to the color wanted.
@pre
  \var option must be in [0; 255]
*/
inline std::string foregroundColor(int option) {
  return ESC + "[38;5;" + std::to_string(option) + "m";
} // foregroundColor()

/** Return a escape code to change foreground text color given an  color
  specification.
@details
  See the 24 bit table at https://en.wikipedia.org/wiki/ANSI_escape_code
@param r
  Red intensity.
@param g
  Green intensity.
@param b
  Blue intensity.
@return
  Scape code to change the foreground color to the color wanted.
@pre
  Input varibles must be in [0; 255]
*/
inline std::string foregroundColor(int r, int g, int b) {
  return ESC + "[38;2;" + std::to_string(r) + ";"
                        + std::to_string(g) + ";"
                        + std::to_string(b) + "m";
} // foregroundColor()

/** Return a escape code to change background text color given an option color.
@details
  See the 8 bit table at https://en.wikipedia.org/wiki/ANSI_escape_code
@param option
  Number to the collor wanted.
@return
  Scape code to change the background color to the color wanted.
@pre
  option must be in [0; 255]
*/
inline std::string backgroundColor(int option) {
  return ESC + "[48;5;" + std::to_string(option) + "m";
} // backgroundColor()

/** Return a escape code to change background text color given an  color
  specification.
@details
  See the 24 bit table at https://en.wikipedia.org/wiki/ANSI_escape_code
@param r
  Red intensity.
@param g
  Green intensity.
@param b
  Blue intensity.
@return
  Scape code to change the background color to the color wanted.
@pre
  Input varibles must be in [0; 255]
*/
inline std::string backgroundColor(int r, int g, int b) {
  return ESC + "[48;2;" + std::to_string(r) + ";"
                        + std::to_string(g) + ";"
                        + std::to_string(b) + "m";
} // foregroundColor()

/** Namespace destined to handle with the terminal ideogram. */
namespace ideogram {
const std::string DEFAULT = ESC + "[65m";
const std::string UNDERLINE = ESC + "[60m";
const std::string RIGHT_SIDE_LINE = ESC + "[60m"; ///< UNDERLINE has the same escape code.
const std::string DOUBLE_UNDERLINE = ESC + "[61m";
const std::string DOUBLE_LINE_RIGHT_SIDE = ESC + "[61m"; ///< DOUBLE_UNDERLINE has the same escape code.
const std::string OVERLINE = ESC + "[62m";
const std::string LEFT_SIDE_LINE = ESC + "[62m"; ///< OVERLINE has the same escape code.
const std::string DOUBLE_OVERLINE = ESC + "[63m";
const std::string DOUBLE_LINE_LEFT_SIDE = ESC + "[63m"; ///< DOUBLE_OVERLINE has the same escape code.
const std::string STRESS_MARKING = ESC + "[64m";
} // namespace ideogram

/** Namespace destinated to cursor escape codes. */
namespace cursor {

const std::string SAVE_POSITION = ESC + "[s"; ///< Save cursor position in memory.
const std::string LOAD_POSITION = ESC + "[u"; ///< Returns the cursor to the position stored by the SAVE escape code.
const
/** Move the cursor to the specified position (coordinates).
@details
  If you do not specify a position, the cursor moves to the home position at the
upper-left corner of the screen (line 0, column 0). This escape sequence works
the same way as the following Cursor Position escape sequence.
@param line
  line position of the cursor.
@ṕaram column
  column position of the cursor.
@return
  Scape code to position cursor at the line and column wanted.
@pre
  Line and Column must be positive numbers.
*/
inline std::string position(int line = 0, int column = 0) {
  return ESC + "[" + std::to_string(line) + ";" + std::to_string(column) + "H";
} // position()

/** Moves the cursor up by the specified number of lines without changing
columns. If the cursor is already on the top line, ANSI.SYS ignores this
sequence.
@param n
  Number of lines.
@return
  Scape code to move the cursor \var n lines up.
@pre
  \var n must be an positive number.
*/
inline std::string up(int n = 1) {
  return ESC + "[" + std::to_string(n) + "A";
} // up()


/** Moves the cursor down by the specified number of lines without changing
columns. If the cursor is already on the bottom line, ANSI.SYS ignores this
sequence.
@param n
  Number of lines.
@return
  Scape code to move the cursor \var n lines down.
@pre
  \var n must be an positive number.
*/
inline std::string down(int n = 1) {
  return ESC + "[" + std::to_string(n) + "B";
} // down()

/** Moves the cursor forward by the specified number of columns without changing
lines. If the cursor is already in the rightmost column, ANSI.SYS ignores this
sequence.
@param n
  Number of columns.
@return
  Scape code to move the cursor \var n  forward.
@pre
  \var n must be an positive number.
*/
inline std::string forward(int n = 1) {
  return ESC + "[" + std::to_string(n) + "C";
} // foward()

/** Moves the cursor backward by the specified number of columns without
changing lines. If the cursor is already in the leftmost column, ANSI.SYS
ignores this sequence.
@param n
  Number of columns.
@return
  Scape code to move the cursor \var n backward.
@pre
  \var n must be an positive number.
*/
inline std::string backward(int n = 1) {
  return ESC + "[" + std::to_string(n) + "D";
} // backward()
} // namespace cursor

/** Namespace destinated for display escape codes. */
namespace display {
const std::string CLEAR = ESC + "[2J";  ///< Clears the screen and moves the cursor to the home position (line 0, column 0).
const std::string ERASE_LINE = ESC + "[K";  ///< Clears all characters from the cursor position to the end of the line (including the character at the cursor position).

/** ScreenResolution types */
enum ScreenResolution {
  MONOCHROME_TEXT_40x25 = 0,  ///< 40 x 25 monochrome (text)
  COLOR_TEXT_40x25 = 1,  ///< 40 x 25 color (text)
	MONOCHROME_TEXT_80x25 = 2,  /// 80 x 25 monochrome (text)
  COLOR_TEXT_80x25 = 3,  ///< 80 x 25 color (text)
  COLOR4_GRAPHICS_320x200 = 4,  ///< 320 x 200 4-color (graphics)
  MONOCHROME_GRAPHICS_320x200 = 5,  ///< 320 x 200 monochrome (graphics)
  MONOCHROME_GRAPHICS_640x200 = 6,  ///< 640 x 200 monochrome (graphics)
  LINE_WRAPPING = 7,  ///< Enables line wrapping
  COLOR_GRAPHICS_320x200 = 13,  ///< 320 x 200 color (graphics)
  COLOR16_GRAPHICS_640x200 = 14,  ///< 640 x 200 color (16-color graphics)
  MONOCHROME_GRAPHICS_640x350 = 15,  ///< 640 x 350 monochrome (2-color graphics)
  COLOR16_GRAPHICS_640x350 = 16,  ///< 640 x 350 color (16-color graphics)
  MONOCHROME_GRAPHICS_640x480 = 17,  ///< 640 x 480 monochrome (2-color graphics)
  COLOR16_GRAPHICS_640x480 = 18,  ///< 640 x 480 color (16-color graphics)
  COLOR256_GRAPHICS_320x200 = 19  ///< 320 x 200 color (256-color graphics)
}; // enum class ScreenResolution

/** Changes the screen width or type to the mode specified by one of the option.
@param option
  Screen resolution option.
@return
  Scape code to change screen  width or type.
*/
inline std::string setMode(ScreenResolution option) {
  return ESC + "[=" + std::to_string(option) + "h";
} // set mode

} // namespace display

} // namespace escape
#endif // SCAPE_HPP_
