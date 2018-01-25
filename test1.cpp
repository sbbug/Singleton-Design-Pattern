#include<iostream>
using namespace std;

//定义一个类，用来测试单列模式
class GlobalClass{

	//定义一个私有变量，用来记录数据
	int m_value;
	//定义一个静态对象,一个单例
	static GlobalClass *s_instance;
public:
	//构造方法
	GlobalClass(int v = 0){
		m_value = v;
	}
	//获取变量值
	int get_value() const{

		return m_value;
	}
	//设置变量值
	void set_value(int v){
		m_value = v;
	}
	//定义获取静态对象的接口
	static GlobalClass *instance(){
		
		//如果s_instance没有被初始化，申请一个对象
		if (!s_instance)
			s_instance = new GlobalClass;

		return s_instance;
	}
};
//对类中的对象初始化，赋值一个空指针
GlobalClass *GlobalClass::s_instance = 0;
//定义一个方法，用来操作访问全局对象global_ptr
void foo(void){
	
	//设置一个值
	GlobalClass::instance()->set_value(1);

	//输出结果测试
	cout << "foo:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
//定义一个方法，用来操作访问全局对象global_ptr
void bar(void){

	//设置一个值
	GlobalClass::instance()->set_value(2);

	//输出结果测试
	cout << "bar:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
int main(){

	cout << "main:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();

	getchar();
	return 0;
}