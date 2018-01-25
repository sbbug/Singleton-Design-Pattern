#include<iostream>
using namespace std;

//����һ���࣬�������Ե���ģʽ
class GlobalClass{

	//����һ��˽�б�����������¼����
	int m_value;
	//����һ����̬����,һ������
	static GlobalClass *s_instance;
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
		
		//���s_instanceû�б���ʼ��������һ������
		if (!s_instance)
			s_instance = new GlobalClass;

		return s_instance;
	}
};
//�����еĶ����ʼ������ֵһ����ָ��
GlobalClass *GlobalClass::s_instance = 0;
//����һ��������������������ȫ�ֶ���global_ptr
void foo(void){
	
	//����һ��ֵ
	GlobalClass::instance()->set_value(1);

	//����������
	cout << "foo:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
//����һ��������������������ȫ�ֶ���global_ptr
void bar(void){

	//����һ��ֵ
	GlobalClass::instance()->set_value(2);

	//����������
	cout << "bar:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
}
int main(){

	cout << "main:global_ptr is" << GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();

	getchar();
	return 0;
}