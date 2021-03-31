#include <array>
/*
 * 游戏所需字符
 */
namespace Resources {

constexpr char horizontal_line[] = "─";

constexpr char vertical_line[] = "│";

constexpr char border_left_up[] = "┌";

constexpr char border_left_down[] = "└";

constexpr char border_right_up[] = "┐";

constexpr char border_right_down[] = "┘";

constexpr char border_middle[] = "┼";

constexpr char border_middle_up[] = "┬";

constexpr char border_left[] = "├";

constexpr char border_right[] = "┤";

constexpr char border_middle_down[] = "┴";

constexpr std::array<const char*, 4> ScoreBoardItems = {"  分数:", "  高分:", "  步数:"};
constexpr std::array<const char*, 3> MainMenuItems = {
    "1--开始游戏",
    "2--高分榜",
    "3--退出游戏",
};
constexpr char Prompts[] = R"(
  WASD上下左右移动
  P键暂停
  I键保存游戏
  E键退回主菜单
)";

constexpr char OptionMenuTitle[] = "选择格数（默认4X4大小）";

constexpr char title_2048[] = R"(
   /\\\\\\\\\          /\\\\\\\                /\\\         /\\\\\\\\\
  /\\\///////\\\      /\\\/////\\\            /\\\\\       /\\\///////\\\
  \///      \//\\\    /\\\    \//\\\         /\\\/\\\      \/\\\     \/\\\
             /\\\/    \/\\\     \/\\\       /\\\/\/\\\      \///\\\\\\\\\/
           /\\\//      \/\\\     \/\\\     /\\\/  \/\\\       /\\\///////\\\
         /\\\//         \/\\\     \/\\\   /\\\\\\\\\\\\\\\\   /\\\      \//\\\
        /\\\/            \//\\\    /\\\   \///////////\\\//   \//\\\      /\\\
        /\\\\\\\\\\\\\\\   \///\\\\\\\/              \/\\\      \///\\\\\\\\\/
        \///////////////      \///////                \///         \/////////
  )";
}  // namespace Resources