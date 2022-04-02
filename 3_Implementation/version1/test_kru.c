/**
 * @file test_kru.c
 * @author Aditi S
 * @brief Implements automated testing code and calls manual testing function
 * @version 1.0
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "../unity/unity.h"
#include "../unity/unity.c"

extern void manual_test_krucal();
extern int krucal(int n,int ecost[][n]) ;

void setUp(void)
{
}

void tearDown(void)
{
}

void automated_test_krucal()
{
    int n=5;
    int cost[5][5] = {{0,0,2,1,0}, {0,0,5,0,0}, {2,5,0,0,3}, {1,0,0,0,0}, {0,0,3,0,0}};
    int mincost = krucal(n,cost) ;
    TEST_ASSERT_EQUAL(11, mincost);

    /*int n1=4;
    int cost1[4][4] = {{0,1,4,3}, {1,0,0,2}, {4,0,0,5},{3,2,5,0}};
    TEST_ASSERT_EQUAL(7, krucal(n1,cost1));
    */
    
}

void automated_test_krucal_overflow()
{
    int n1=4;
    int cost1[4][4] = {{0,INT_MAX,4,3}, {1,0,0,2}, {4,0,0,5},{3,2,5,0}};
    int mincost = krucal(n1,cost1) ;
    TEST_ASSERT_EQUAL(11, mincost);
}

void automated_test_krucal_underflow()
{
    int n1=4;
    int cost1[4][4] = {{0,INT_MIN,4,3}, {-1,0,0,-2}, {-4,0,0,-5},{-3,-2,-5,0}};
    int mincost = krucal(n1,cost1) ;
    TEST_ASSERT_EQUAL(11, mincost);
}

/**
 * @brief This is the main function 
 * 
 * 
 * @return int  Returns 0 for success
 */
int main(void)
{
   // simplemain(); // Simple version
   
  //  manual_test_krucal();

    UnityBegin(NULL);

    RUN_TEST(automated_test_krucal);
    RUN_TEST(automated_test_krucal_overflow);
    RUN_TEST(automated_test_krucal_underflow);

    return (UnityEnd());
 }
