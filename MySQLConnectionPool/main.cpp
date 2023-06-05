#include<iostream>
#include"Connection.h"
#include"CommonConnectionPool.h"
using namespace std;
int main()
{
    /*Connection conn;
    char sql[1024] = {};
    sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');",
        "张三", 20,"male");
    conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
    conn.update(sql);*/

 /*   ConnectionPool* cp = ConnectionPool::getConnectionPool();
    cp->loadConfigFile();*/

    clock_t begin = clock();

    //单线程测试
    //ConnectionPool* cp = ConnectionPool::getConnectionPool();
    //for (int i = 0; i < 10000; ++i)
    //{
    //    /*Connection conn;
    //    char sql[1024] = {0};
    //    sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');",
    //        "张三", 20, "male");
    //    conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
    //    conn.update(sql);*/


    //    shared_ptr<Connection> sp = cp->getConnection();
    //    char sql[1024] = {};
    //    sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');",
    //        "张三", 20, "male");
    //    sp->update(sql);
    //}


    //四线程测试
   /* Connection conn;
    conn.connect("127.0.0.1", 3306, "root", "123456", "chat");*/
    thread t1([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i)
        {
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');",
                "张三", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
         /*   Connection conn;
            char sql[1024] = {0};
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');","张三", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
            conn.update(sql);*/
        }
        });
    thread t2([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i)
        {
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');",
                "张三", 20, "male");
            shared_ptr<Connection> sp = cp->getConnection();
            sp->update(sql);
            /*Connection conn;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');", "张三", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
            conn.update(sql);*/
        }
        });
    thread t3([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i)
        {
            char sql[1024] = { 0 };
             sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');",
                 "张三", 20, "male");
             shared_ptr<Connection> sp = cp->getConnection();
             sp->update(sql);
           /* Connection conn;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');", "张三", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
            conn.update(sql);*/
        }
        });
    thread t4([]() {
        ConnectionPool* cp = ConnectionPool::getConnectionPool();
        for (int i = 0; i < 2500; ++i)
        {
            char sql[1024] = { 0 };
             sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');",
                 "张三", 20, "male");
             shared_ptr<Connection> sp = cp->getConnection();
             sp->update(sql);
            /*Connection conn;
            char sql[1024] = { 0 };
            sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s');", "张三", 20, "male");
            conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
            conn.update(sql);*/
        }
        });
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    clock_t end = clock();
    std::cout << (end - begin) << "ms" << endl;
    return 0;
}