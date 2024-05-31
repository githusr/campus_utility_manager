#include "tui/menu_build.h"
#include "tui/menu.h"
#include "tui/menu_item.h"
#include "tui/action.h"

void buildMenu()
{
    Menu main_menu("主菜单");
    Menu query_bill("账单查询");
    Menu admin_login("管理员登录", adminLogin);
    MenuItem query_student_bill("学生账单", queryStudentBill);
}