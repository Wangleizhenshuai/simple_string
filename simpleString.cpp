#include<iostream>
#include <string.h> 
//该字符串头文件是c的文件，c++ 的字符串头文件是#include<string>
 
class simpleString
{
private:
    char * m_data;//string 的大小由用户指定，所以采用指针 根据具体大小进行创建
public:
    //类的定义遵从 类内定义成员函数 类外具体化 规则
    //所有的构造和析构函数没有返回值 

    simpleString(const char* c_str = 0); //- 初始化 
    //simpleString：构造函数应该和class 同名
    //const：不改变传进来对象
    //char*：希望传进来的是指向char的指针，可以用户自定义
    //c_str = 0 ：如果用户不赋值，默认为0;

    simpleString(const simpleString & a); //- 拷贝构造  
    //const simpleString：因为是拷贝和自己一样的类型，所以用simpleString
    // &；使用引用传值减少内存开销 
    // a：拷贝的simpleString对象
    
    simpleString& operator=(const simpleString & a); //- 拷贝赋值 
    //simpleString&：返回的是赋值完成的对象的引用
    //operator=：操作符= 的重载
    
    ~simpleString();//- 析构 在对像调用完对其所在的内存进行释放 ，调用free函数

    char* get_c_char() {//- 获得首地址指针 方便对simpleString对象进行操作
        return m_data;
    }; 
    
};
//类外进行函数具体定义
inline //内联函数，与恒定义作用类似，在编译器编译的过程中将函数替换掉
        //一般短小函数都进行内联，但是该函数只是给编译器提供建议，具体还是要靠编译器进行识别，所以可以放心加
simpleString::simpleString(const char* c_str = 0)//- 初始化
{
    // 考虑分配多少空间放初值
    if (c_str) { //如果c_str不是0 进行分配空间
        m_data = new char[strlen(c_str) + 1];
        //new: 使用new来调用malloc分配空间 注意new和delete需要成对使用 防止内存泄漏
        //char[]:字符串的本质是char数组 
        //c_str：该指针指向字符串首地址
        //strlen(c_str): 从字符串的开头位置依次向后计数，直到遇见'\0'，然后返回计时器的值。最终统计的字符串长度不包括'\0'
        //+ 1: 字符串以'\0'为结尾，但是统计长度并不统计'\0'，所以要加1
        //m_data =：将本身的指针指向新开辟的内存字符数组空间的首地址，方便后续对内存空间进行操作
        strcpy(m_data,c_str);
        //strcpy(char *dest, const char *src) 把 src 所指向的字符串复制到 dest指针   
    } else { // 如果c_str为0
        m_data = new char[1]; //只分配长度为1的内存空间
        *m_data = '\0';
        //*m_data:取m_data指针所指向的地址
        //'\0'：赋值为空字符串
    }
  
}
inline
simpleString::simpleString(const simpleString & a)//- 拷贝构造
{
    if (a) {
        new simpleString(strlen(a) + 1);
    }
}

simpleString::simpleString& operator=(const simpleString & a){//- 拷贝赋值

} 

simpleString::~simpleString()//正常函数 不需要重写 析构函数
{
    delete[] m_data;
}
