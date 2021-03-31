#include <array>
namespace Resources {

constexpr char horizontal_line[] = "��";

constexpr char vertical_line[] = "��";

constexpr char border_left_up[] = "��";

constexpr char border_left_down[] = "��";

constexpr char border_right_up[] = "��";

constexpr char border_right_down[] = "��";

constexpr char border_middle[] = "��";

constexpr char border_middle_up[] = "��";

constexpr char border_left[] = "��";

constexpr char border_right[] = "��";

constexpr char border_middle_down[] = "��";

constexpr std::array<const char*, 4> ScoreBoardItems = {"  ����:", "  �߷�:", "  ����:"};
constexpr std::array<const char*, 3> MainMenuItems = {
    "1--��ʼ��Ϸ",
    "2--�߷ְ�",
    "3--�˳���Ϸ",
};
constexpr char Prompts[] = R"(
  WASD���������ƶ�
  P����ͣ
  I��������Ϸ
  E���˻����˵�
)";

constexpr char OptionMenuTitle[] = "ѡ�������Ĭ��4X4��С��";

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