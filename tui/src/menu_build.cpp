#include "tui/action.h"
#include "tui/menu_item.h"

std::shared_ptr<MenuItem> main_menu = std::make_shared<MenuItem>("主菜单");

void menuBuild()
{
    auto bill_query = std::make_shared<MenuItem>("账单查询");
    auto admin_login = std::make_shared<MenuItem>("管理员登录", adminLogin);
    main_menu->addSubItem(bill_query);
    main_menu->addSubItem(admin_login);

    auto query_student_bill = std::make_shared<MenuItem>("学生账单查询", queryStudentBill);
    auto query_faculty_bill = std::make_shared<MenuItem>("教工账单查询", queryFacultyBill);
    bill_query->addSubItem(query_student_bill);
    bill_query->addSubItem(query_faculty_bill);

    auto student_module = std::make_shared<MenuItem>("学生模块");
    auto faculty_module = std::make_shared<MenuItem>("教工模块");
    auto reset_password = std::make_shared<MenuItem>("重置密码", resetPassword);

    admin_login->addSubItem(student_module);
    admin_login->addSubItem(faculty_module);
    admin_login->addSubItem(reset_password);

    auto su_bill_query_student = std::make_shared<MenuItem>("账单查询");
    auto su_bill_query_faculty = std::make_shared<MenuItem>("账单查询");
    auto pay_bill_student = std::make_shared<MenuItem>("缴费", payBillStudent);
    auto pay_bill_faculty = std::make_shared<MenuItem>("缴费", payBillFaculty);
    auto add_data_student = std::make_shared<MenuItem>("添加数据", addDataStudent);
    auto add_data_faculty = std::make_shared<MenuItem>("添加数据", addDataFaculty);
    auto add_user_student = std::make_shared<MenuItem>("添加用户", addUserStudent);
    auto add_user_faculty = std::make_shared<MenuItem>("添加用户", addUserFaculty);
    auto remove_user_student = std::make_shared<MenuItem>("移除用户", removeUserStudent);
    auto remove_user_faculty = std::make_shared<MenuItem>("移除用户", removeUserFaculty);
    auto process_and_export_data_student =
        std::make_shared<MenuItem>("数据处理与导出", processAndExportDataStudent);
    auto process_and_export_data_faculty =
        std::make_shared<MenuItem>("数据处理与导出", processAndExportDataFaculty);
    auto set_rate_student = std::make_shared<MenuItem>("设置费用", setRateStudent);
    auto set_rate_faculty = std::make_shared<MenuItem>("设置费用", setRateFaculty);

    student_module->addSubItem(su_bill_query_student);
    student_module->addSubItem(pay_bill_student);
    student_module->addSubItem(add_data_student);
    student_module->addSubItem(add_user_student);
    student_module->addSubItem(remove_user_student);
    student_module->addSubItem(process_and_export_data_student);
    student_module->addSubItem(set_rate_student);

    faculty_module->addSubItem(su_bill_query_faculty);
    faculty_module->addSubItem(pay_bill_faculty);
    faculty_module->addSubItem(add_data_faculty);
    faculty_module->addSubItem(add_user_faculty);
    faculty_module->addSubItem(remove_user_faculty);
    faculty_module->addSubItem(process_and_export_data_faculty);
    faculty_module->addSubItem(set_rate_faculty);

    auto bill_detail_student = std::make_shared<MenuItem>("账单明细", billDetailStudent);
    auto bill_detail_faculty = std::make_shared<MenuItem>("账单明细", billDetailFaculty);
    auto history_data_student = std::make_shared<MenuItem>("历史数据", historyDataStudent);
    auto history_data_faculty = std::make_shared<MenuItem>("历史数据", historyDataFaculty);

    su_bill_query_student->addSubItem(bill_detail_student);
    su_bill_query_student->addSubItem(history_data_student);
    su_bill_query_faculty->addSubItem(bill_detail_faculty);
    su_bill_query_faculty->addSubItem(history_data_faculty);
}