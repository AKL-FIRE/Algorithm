#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#define MAXDEP 100
using namespace std;
class NineNode{
public: 
	 int nine[3][3];//�Ź���
     int parent;//���ڵ㣬���ڵ�ĸ��ڵ�Ϊ-1
	 int i;//�հ�������
	 int j;//�հ�������
	 string step;//����һ�ڵ��ƶ����˽ڵ��������
	 int dep;//�ڵ����
};
bool match(NineNode node1,NineNode node2);
bool ishave(deque<NineNode> openStack,vector<NineNode> closedList,NineNode node);
int main()
{
	int i,j;
	deque<NineNode> openStack;//openջ����dequeģ��ջ
	vector<NineNode> closedList;//closed�б�
	stack<string> movepath;//�ƶ�����ջ
	NineNode initilNode,lastNode;//��ʼ�ڵ��Ŀ��ڵ�
	cout<<"�������ʼ�ڵ�״̬:";
	/*�����ʼ�ڵ�״̬ ��ʼ*/
    for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			cin>>initilNode.nine[i][j];
			if(0==initilNode.nine[i][j])
			{
                 initilNode.i=i; 
				 initilNode.j=j;
			}
		}
	initilNode.parent=-1;
	initilNode.dep=0;//��ʼ�ڵ����Ϊ0
	/*�����ʼ�ڵ�״̬ ����*/
	cout<<"������Ŀ��ڵ�״̬:";
	/*����Ŀ��ڵ�״̬ ��ʼ*/
    for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			cin>>lastNode.nine[i][j];
			if(0==lastNode.nine[i][j])
			{
                 lastNode.i=i; 
				 lastNode.j=j;
			}
		}
	lastNode.parent=-1;
	/*����Ŀ��ڵ�״̬ ����*/
	int parent=-1;//parentָʾ���ڵ��±�
	bool depflag=false;//ָʾ�������
	bool flag=false;//�����־
	openStack.push_back(initilNode);
	while((!openStack.empty())&&(!flag))
	{
		NineNode temp;
		temp=openStack.back();
		openStack.pop_back();
		closedList.push_back(temp);
        parent=closedList.size()-1;
		if(match(temp,lastNode))
		{
			flag=true;
			break;
		}
		if((temp.dep<=MAXDEP)&&(!depflag))
		{
			if(temp.j>0)//�����ƶ�
			{
			NineNode left=temp;	
			left.nine[temp.i][temp.j]=left.nine[temp.i][temp.j-1];
			left.nine[temp.i][temp.j-1]=0;
			left.parent=parent;
			left.i=temp.i;
			left.j=temp.j-1;
			left.step="�����ƶ�";
			left.dep=temp.dep+1;
  	        if(!ishave(openStack,closedList,left))
		     	openStack.push_back(left);
			}
	    	if(temp.i>0)//�����ƶ�
			{
			NineNode up=temp;	
			up.nine[temp.i][temp.j]=up.nine[temp.i-1][temp.j];
			up.nine[temp.i-1][temp.j]=0;
		    up.parent=parent;
			up.i=temp.i-1;
			up.j=temp.j;
			up.step="�����ƶ�";
			up.dep=temp.dep+1;
			if(!ishave(openStack,closedList,up))
			    openStack.push_back(up);

			}
		    if(temp.j<2)//�����ƶ�
			{
			NineNode right=temp;
			right.nine[temp.i][temp.j]=right.nine[temp.i][temp.j+1];
			right.nine[temp.i][temp.j+1]=0;
			right.parent=parent;
			right.i=temp.i;
			right.j=temp.j+1;
			right.step="�����ƶ�";
			right.dep=temp.dep+1;
			if(!ishave(openStack,closedList,right))
			  openStack.push_back(right);
			}
		    if(temp.i<2)//�����ƶ�
			{
			NineNode down=temp;
			down.nine[temp.i][temp.j]=down.nine[temp.i+1][temp.j];
			down.nine[temp.i+1][temp.j]=0;
			down.parent=parent;
			down.i=temp.i+1;
			down.j=temp.j;
			down.step="�����ƶ�";
			down.dep=temp.dep+1;
			if(!ishave(openStack,closedList,down))
			   openStack.push_back(down);
			}
		}
		else
		{
			depflag=true;
		}
		
	}

	if(!flag)//�޷��ƶ���Ŀ��ڵ�
	{
		cout<<"�޷��ӳ�ʼ�ڵ��ƶ���Ŀ��ڵ�"<<endl;
	}
	else//�����ƶ���Ŀ��ڵ㣬�����н�
	{
		NineNode last=closedList.back();//�����ڵ��ظ�ָ��������
		while(last.parent!=-1)
		{
			movepath.push(last.step);
			last=closedList[last.parent];
		}
		cout<<"Ŀ��ɽ�,�ƶ���������:"<<endl;
		string step;
		while(!movepath.empty())
		{
			step=movepath.top();
	        movepath.pop();
			cout<<step<<endl;
		}
		cout<<"�õ���"<<endl;
	}
	system("pause");
	return 0;

}

/*�ж������ڵ��Ƿ���ͬ����ͬ����true�����򷵻�false*/
bool match(NineNode node1,NineNode node2)
{
	int i,j;
	bool result=true;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			if(node1.nine[i][j]!=node2.nine[i][j])
			{
				result=false;
				break;
			}

		}
    return result;
}
/*�ж��½ڵ��Ƿ��Ѿ����ڣ����ж��Ƿ������open���к�closed�б���*/
bool ishave(deque<NineNode> openStack,vector<NineNode> closedList,NineNode node)
{
	bool result=false;
	deque<NineNode>::iterator qit=openStack.begin();
	vector<NineNode>::iterator vit=closedList.begin();
	while(qit!=openStack.end())
	{
		if(match(*qit++,node))
		{
			result=true;
			break;
		}
	}
	while(vit!=closedList.end())
	{
		if(match(*vit++,node))
		{
			result=true;
			break;
		}
	}

	return result;
}
