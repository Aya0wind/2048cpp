#include "Color.hpp"

namespace Color {
const char* end = "\033[0m";
const char* Colors[] = {"\033[0m",    "\033[0;30m", "\033[1;30m", "\033[0;34m", "\033[1;34m", "\033[0;32m",
                        "\033[1;32m", "\033[0;36m", "\033[1;36m", "\033[0;31m", "\033[1;31m", "\033[0;35m",
                        "\033[1;35m", "\033[0;33m", "\033[1;33m", "\033[0;37m", "\033[1;37m"};
std::string none(const std::string& str)
{
    return Colors[ 0 ] + str + end;
}
std::string black(const std::string& str)
{
    return Colors[ 1 ] + str + end;
}
std::string dark_gray(const std::string& str)
{
    return Colors[ 2 ] + str + end;
}
std::string blue(const std::string& str)
{
    return Colors[ 3 ] + str + end;
}
std::string light_blue(const std::string& str)
{
    return Colors[ 4 ] + str + end;
}
std::string green(const std::string& str)
{
    return Colors[ 5 ] + str + end;
}
std::string light_green(const std::string& str)
{
    return Colors[ 6 ] + str + end;
}
std::string cyan(const std::string& str)
{
    return Colors[ 7 ] + str + end;
}
std::string light_cyan(const std::string& str)
{
    return Colors[ 8 ] + str + end;
}
std::string red(const std::string& str)
{
    return Colors[ 9 ] + str + end;
}
std::string light_red(const std::string& str)
{
    return Colors[ 10 ] + str + end;
}
std::string purple(const std::string& str)
{
    return Colors[ 11 ] + str + end;
}
std::string light_purple(const std::string& str)
{
    return Colors[ 12 ] + str + end;
}
std::string brown(const std::string& str)
{
    return Colors[ 13 ] + str + end;
}
std::string yellow(const std::string& str)
{
    return Colors[ 14 ] + str + end;
}
std::string light_gray(const std::string& str)
{
    return Colors[ 15 ] + str + end;
}
std::string white(const std::string& str)
{
    return Colors[ 16 ] + str + end;
}
std::string GetRandomColor(size_t num)
{
    switch (num) {
        case 0:
            return dark_gray(std::to_string(num));
        case 2:
            return blue(std::to_string(num));
        case 4:
            return green(std::to_string(num));
        case 8:
            return cyan(std::to_string(num));
        case 16:
            return red(std::to_string(num));
        case 32:
            return purple(std::to_string(num));
        case 64:
            return brown(std::to_string(num));
        case 128:
            return yellow(std::to_string(num));
        case 256:
            return light_gray(std::to_string(num));
        case 512:
            return white(std::to_string(num));
        case 1024:
            return light_green(std::to_string(num));
        case 2048:
            return light_red(std::to_string(num));
        default:
            return GetRandomColor(num % 2048);
    }
}
}  // namespace Color