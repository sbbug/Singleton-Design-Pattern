#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
//定义一个互斥资源信号量,用来给临界区枷锁
mutex mtx;
//为程序开辟四个线程用来测试
thread threads[4];
//定义一个类，用来测试单列模式
class GlobalClass{

	//定义一个私有变量，用来记录数据
	int m_value;
	//定义一个静态对象,一个单例
	static GlobalClass *s_instance;
	//定义一个静态变量，用来计算new了多少次对象
	static int count;
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
		//为临界区加锁
		//mtx.lock();
		//如果s_instance没有被初始化，申请一个对象
		if (!s_instance){
			count++;
			s_instance = new GlobalClass;
		}
			
		//释放锁
		//mtx.unlock();
		return s_instance;
	}
	//获取引用计数器的值
	static int getCount(){
		return count;
	}
};
//对类中的对象初始化，赋值一个空指针
GlobalClass *GlobalClass::s_instance = 0;
//count初始化
int GlobalClass::count = 0;
//定义一个方法，用来操作访问全局对象global_ptr
void foo(void){
	
	//设置一个值
	GlobalClass::instance()->set_value(1);

	//输出结果测试
	cout << "\nfoo:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
//定义一个方法，用来操作访问全局对象global_ptr
void bar(void){

	//设置一个值
	GlobalClass::instance()->set_value(2);

	//输出结果测试
	cout << "\nbar:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
int main(){

	cout << "main:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();


	/*
	//为每一个线程分配任务
	for (int i = 0; i < 4; i++){
		threads[i] = thread(foo);
	}
	//线程开始执行
	for (int j = 0; j < 4; j++){
		threads[j].join();
	}
	*/

	cout << "\n一共new了" << GlobalClass::getCount()<<"个GlobalClass对象"<< endl;

	getchar();
	return 0;
}