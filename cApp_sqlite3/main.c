#include <stdio.h>
#include "sqlite3.h"

int main()
{
    //1.打开数据库
    sqlite3 *ppdb = NULL;
    /*
     * 如果存在就打开，如果不存在就创建
    */
    int ret = sqlite3_open("C:\\Users\\xcy\\Desktop\\database_exercise\\test.db", &ppdb);
    if (ret != SQLITE_OK)
    {
        perror("open db fail");
        return -1;
    }
    //2.创建表格
    char *error = NULL;//保存错误
    char *sql = "create table if not exists apitext(id int, name text)";
    ret = sqlite3_exec(ppdb, sql, NULL, NULL,&error);
    if (ret != SQLITE_OK)
    {
        printf("%s\n", error);
    }

    //2.执行插入语句
    sql = "insert into apitext values(0, 'hqd')";
    ret = sqlite3_exec(ppdb, sql, NULL, NULL,&error);
    if (ret != SQLITE_OK)
    {
        printf("%s\n", error);
    }

    //2.执行更新语句操作
    sql = "update apitext set id = 1 where id = 0";
    ret = sqlite3_exec(ppdb, sql, NULL, NULL,&error);
    if (ret != SQLITE_OK)
    {
        printf("%s\n", error);
    }


    //2.执行删除语句操作
    sql = "delete from apitext where id = 1";
    ret = sqlite3_exec(ppdb, sql, NULL, NULL,&error);
    if (ret != SQLITE_OK)
    {
        printf("%s\n", error);
    }


    //3.关闭数据库
    sqlite3_close(ppdb);
    return 0;
}
