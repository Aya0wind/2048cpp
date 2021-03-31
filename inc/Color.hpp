#pragma once
#include <sstream>
#include <string>
namespace Color {
/*
 * 设置字符串颜色，使用ANSI转义序列实现
 */
enum class ColorNum {
    none,
    black,
    dark_gray,
    blue,
    light_blue,
    green,
    light_green,
    cyan,
    light_cyan,
    red,
    light_red,
    purple,
    light_purple,
    brown,
    yellow,
    light_gray,
    white
};
std::string none(const std::string& str);
std::string black(const std::string& str);
std::string dark_gray(const std::string& str);
std::string blue(const std::string& str);
std::string light_blue(const std::string& str);
std::string green(const std::string& str);
std::string light_green(const std::string& str);
std::string cyan(const std::string& str);
std::string light_cyan(const std::string& str);
std::string red(const std::string& str);
std::string light_red(const std::string& str);
std::string purple(const std::string& str);
std::string light_purple(const std::string& str);
std::string brown(const std::string& str);
std::string yellow(const std::string& str);
std::string light_gray(const std::string& str);
std::string white(const std::string& str);
std::string GetRandomColor(size_t num);
};  // namespace Color
