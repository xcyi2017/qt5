#include <stdio.h>
#include "sqlite3.h"

// 声明回调函数
int callback(void*, int, char**, char**);
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
    ret = sqlite3_exec(ppdb, sql,NULL, NULL, &error);
    if (ret != SQLITE_OK)
    {
        printf("%s\n", error);
    }

    //2.查询语句操作 -- 利用回调函数查询
//    const char* data = "callback function called.";
//    sql = "select * from apitext";
//    ret = sqlite3_exec(ppdb, sql, callback, (void*)data, &error);
//    if (ret != SQLITE_OK)
//    {
//        printf("%s\n", error);
//    }

    // 非回调查询
    char** res = NULL;
    int row = 0;
    int cols = 0;
    sql = "select * from apitext";
    ret = sqlite3_get_table(ppdb, sql, &res,&row,&cols, &error);
    if (SQLITE_OK != 0)
    {
        printf("%s\n", error);
    }
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%s\t", res[j+i*j]);
        }
        printf("\n");
    }
    sqlite3_free(error);
    sqlite3_free_table(res);

    //3.关闭数据库
    sqlite3_close(ppdb);
    return 0;
}

/*
  实现回调函数
*/

/*
   para: 主调函数sqlite_exec传递过来的参数
   column_num: 查询表的列数
   column_values: 表的每列的值
   column_names: 表头的值
   调用的次数与表的行数目一致，返回值必须为0
 */
int callback(void* para, int column_num, char** column_values, char** column_names)

{
     printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
     char* data = (char*) para;
     printf("%s\n", data);
     printf("cols = %d\n", column_num);
     for (int i = 0; i < column_num; ++ i)
     {
         printf("%s\t", column_names[i]);
     }
     printf("\n");
     for (int i = 0; i < column_num; ++ i)
     {
         printf("%s\t", column_values[i]);
     }
     printf("\n");
     printf("++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
     return 0;
}
