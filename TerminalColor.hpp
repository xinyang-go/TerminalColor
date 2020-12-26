//
// Created by xinyang on 2020/12/26.
//

#ifndef _TERMINAL_COLOR_HPP_
#define _TERMINAL_COLOR_HPP_

#include <string_view>

namespace tc {

    enum class ColorCode {
        none = -1,
        black = 0,
        red = 1,
        green = 2,
        yellow = 3,
        blue = 4,
        purple = 5,
        cyan = 6,
        white = 7,
    };

    class ColorString {
        friend std::ostream &operator<<(std::ostream &out, const ColorString &str);

    public:

        constexpr ColorString(const char *str, size_t len,
                              ColorCode text = ColorCode::none, ColorCode back = ColorCode::none)
                : _str(str, len), _text_color(text), _back_color(back) {}

        constexpr ColorString &text(ColorCode color) {
            _text_color = color;
            return *this;

        }

        constexpr ColorString &back(ColorCode color) {
            _back_color = color;
            return *this;
        }

        constexpr ColorString &highlight() {
            _highlight = true;
            return *this;
        }

        constexpr ColorString &underline() {
            _underline = true;
            return *this;
        }

        constexpr ColorString &blink() {
            _blink = true;
            return *this;
        }

        constexpr ColorString &inverse() {
            _reverse = true;
            return *this;
        }

        constexpr ColorString &invisible() {
            _invisible = true;
            return *this;
        }


    private:
        std::string_view _str;
        ColorCode _text_color;
        ColorCode _back_color;
        bool _highlight = false;
        bool _underline = false;
        bool _blink = false;
        bool _reverse = false;
        bool _invisible = false;
    };

    std::ostream &operator<<(std::ostream &out, const ColorString &str) {
        out << "\033[0";
        if (str._highlight) out << ";1";
        if (str._underline) out << ";4";
        if (str._blink) out << ";5";
        if (str._reverse) out << ";7";
        if (str._invisible) out << ";8";
        if (str._text_color != ColorCode::none)
            out << ";" << "3" << static_cast<char>(static_cast<char>(str._text_color) + '0');
        if (str._back_color != ColorCode::none)
            out << ";" << "4" << static_cast<char>(static_cast<char>(str._back_color) + '0');
        out << "m" << str._str << "\033[0m";
        return out;
    }

    constexpr ColorString operator ""_c(const char *str, size_t len) {
        return ColorString(str, len);
    }

    constexpr ColorString operator ""_black(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::black);
    }

    constexpr ColorString operator ""_red(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::red);
    }

    constexpr ColorString operator ""_green(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::green);
    }

    constexpr ColorString operator ""_yellow(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::yellow);
    }

    constexpr ColorString operator ""_blue(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::blue);
    }

    constexpr ColorString operator ""_purple(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::purple);
    }

    constexpr ColorString operator ""_cyan(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::cyan);
    }

    constexpr ColorString operator ""_white(const char *str, size_t len) {
        return ColorString(str, len, ColorCode::white);
    }

}

#endif
