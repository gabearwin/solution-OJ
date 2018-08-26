#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int expression_value();                     //一个表达式
int term_value();                           //一个项
int factor_value();                         //一个因子
int main(){
    cout << expression_value() << endl;
    return 0;
}
int expression_value(){                     //求一个表达式的值
    int result = term_value();              //求第一项的值
    bool more = true;
    while( more ){
        char op = cin.peek();               //看一个字符，不取走
        if( op == '+' || op == '-' ){
            cin.get();                      //从输入中取走一个字符
            int value = term_value();
            if( op == '+' ) result += value;
            else result -= value;
        }
        else more = false;
    }
    return result;
}
int term_value(){                           //求一个项的值
    int result = factor_value();            //求第一个因子的值
    while(true){
        char op = cin.peek();
        if( op == '*' || op == '/' ){
            cin.get();
            int value = factor_value();
            if( op == '*' ) result *= value;
            else result /= value;
        }
        else break;
    }
    return result;
}
int factor_value(){                         //求一个因子的值
    int result = 0;
    char c = cin.peek();
    if( c == '(' ){                         //括号'('包裹，当中是一个表达式
        cin.get();
        result = expression_value();
        cin.get();
    }
    else{                                   //是一个数字，求出该数
        while( isdigit(c) ){
            result = result*10 + c - '0';
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}

