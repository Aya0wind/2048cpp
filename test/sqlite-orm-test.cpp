#include <sqlite_orm/sqlite_orm.h>

#include <memory>
#include <string>

#include "gtest/gtest.h"

using namespace sqlite_orm;
struct Employee {
    int id;
    std::string name;
    int age;
    std::string address;  //  optional
    double salary;        //  optional
};

auto storage = make_storage(
    "select.sqlite", make_table(
                         "COMPANY", make_column("ID", &Employee::id, primary_key()),
                         make_column("NAME", &Employee::name), make_column("AGE", &Employee::age),
                         make_column("ADDRESS", &Employee::address), make_column("SALARY", &Employee::salary)));
class SqliteTest : public ::testing::Test {
    using storage_type = sqlite_orm::internal::storage_t<Employee>;

protected:
    void SetUp() override
    {
        storage.sync_schema();
        storage.remove_all<Employee>();
    }
};

TEST_F(SqliteTest, test_insert_example)
{
    using std::make_unique;
    using std::string;
    Employee paul{-1, "Paul", 32, "California", 20000.0};
    Employee allen{-1, "Allen", 25, "Texas", 15000.0};
    Employee teddy{-1, "Teddy", 23, "Norway", 20000.0};
    Employee mark{-1, "Mark", 25, "Rich-Mond", 65000.0};
    Employee david{-1, "David", 27, "Texas", 85000.0};
    Employee kim{-1, "Kim", 22, "South-Hall", 45000.0};
    Employee james{-1, "James", 24, "Houston", 10000.0};
    // store in vector
    std::vector<Employee> employees = {paul, allen, teddy, mark, david, kim, james};
    paul.id = storage.insert(paul);
    allen.id = storage.insert(allen);
    teddy.id = storage.insert(teddy);
    mark.id = storage.insert(mark);
    david.id = storage.insert(david);
    kim.id = storage.insert(kim);
    james.id = storage.insert(james);
    auto idsNamesSalarys = storage.select(
        columns(&Employee::id, &Employee::name, &Employee::salary), where(is_equal(&Employee::id, paul.id)));
    EXPECT_EQ(idsNamesSalarys.size(), 1);
    EXPECT_EQ(std::get<0>(idsNamesSalarys[ 0 ]), paul.id);
    EXPECT_EQ(std::get<1>(idsNamesSalarys[ 0 ]), paul.name);
    EXPECT_EQ(std::get<2>(idsNamesSalarys[ 0 ]), paul.salary);
    storage.remove_all<Employee>();
}
