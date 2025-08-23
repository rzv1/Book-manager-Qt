//
// Created by Razvan Andrei on 23.08.2025.
//

#ifndef TEST_H
#define TEST_H
class Tests{
private:
    static void run_test_domain();
    static void run_test_repo();
    static void run_test_service();
    static void run_test_validation();
public:
    void run();
};
#endif //TEST_H
