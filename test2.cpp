#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
//����һ��������Դ�ź���,�������ٽ�������
mutex mtx;
//Ϊ���򿪱��ĸ��߳���������
thread threads[4];
//����һ���࣬�������Ե���ģʽ
class GlobalClass{

	//����һ��˽�б�����������¼����
	int m_value;
	//����һ����̬����,һ������
	static GlobalClass *s_instance;
	//����һ����̬��������������new�˶��ٴζ���
	static int count;
public:
	//���췽��
	GlobalClass(int v = 0){
		m_value = v;
	}
	//��ȡ����ֵ
	int get_value() const{

		return m_value;
	}
	//���ñ���ֵ
	void set_value(int v){
		m_value = v;
	}
	//�����ȡ��̬����Ľӿ�
	static GlobalClass *instance(){
		//Ϊ�ٽ�������
		//mtx.lock();
		//���s_instanceû�б���ʼ��������һ������
		if (!s_instance){
			count++;
			s_instance = new GlobalClass;
		}
			
		//�ͷ���
		//mtx.unlock();
		return s_instance;
	}
	//��ȡ���ü�������ֵ
	static int getCount(){
		return count;
	}
};
//�����еĶ����ʼ������ֵһ����ָ��
GlobalClass *GlobalClass::s_instance = 0;
//count��ʼ��
int GlobalClass::count = 0;
//����һ��������������������ȫ�ֶ���global_ptr
void foo(void){
	
	//����һ��ֵ
	GlobalClass::instance()->set_value(1);

	//����������
	cout << "\nfoo:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
//����һ��������������������ȫ�ֶ���global_ptr
void bar(void){

	//����һ��ֵ
	GlobalClass::instance()->set_value(2);

	//����������
	cout << "\nbar:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
int main(){

	cout << "main:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();


	/*
	//Ϊÿһ���̷߳�������
	for (int i = 0; i < 4; i++){
		threads[i] = thread(foo);
	}
	//�߳̿�ʼִ��
	for (int j = 0; j < 4; j++){
		threads[j].join();
	}
	*/

	cout << "\nһ��new��" << GlobalClass::getCount()<<"��GlobalClass����"<< endl;

	getchar();
	return 0;
}