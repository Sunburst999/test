#include<string>
#include<queue>
#include<mutex>
#include<atomic>
#include<thread>
#include<memory>
#include<functional>
#include<condition_variable>
#include"Connection.h"
using namespace std;



/*
 ʵ�����ӳع���ģ��
 */ 

class ConnectionPool
{
public:
	//��ȡ���ӳض���ʵ��
	static ConnectionPool* getConnectionPool();
	//���ⲿ�ṩ�ӿڣ������ӳ��л�ȡһ�����õĿ�������
	shared_ptr<Connection> getConnection();
private:
	//����#1 ���캯��˽�л�
	ConnectionPool();
	//�������ļ��м���������
	bool loadConfigFile();
	//�����ڶ������߳��У�ר�Ÿ�������������
	void produceConnectionTask();
	//����һ���µĶ�ʱ�̣߳�ɨ�賬��maxIdleTimeʱ��Ŀ������ӣ����ж�������ӻ���
	void scannerConnectionTask();

	string _ip;  //mysql��ip��ַ
	unsigned short _port; //mysql�Ķ˿ں�3306
	string _username; //mysql�ĵ�¼�û���
	string _password; //mysql�ĵ�½����
	string _dbname; //���ӵ����ݿ�����
	int _initSize;   //���ӳصĳ�ʼ������
	int _maxSize;  //���ӳص����������
	int _maxIdleTime; //���ӳص�������ʱ��
	int _connectionTimeout; //���ӳػ�ȡ���ӵĳ�ʱʱ��

	queue<Connection*> _connectionQue; //�洢mysql���ӵĶ���
	mutex _queueMutex; //ά�����а�ȫ�Ļ�����
	atomic_int _connectionCnt; //��¼������������connection��������
	condition_variable cv; //���������������������������̺߳������̵߳�ͨ��
};