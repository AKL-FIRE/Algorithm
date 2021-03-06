#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<stack>
#include<string>
using namespace std;
class NineNode{
public: 
	 int nine[3][3];//九宫格
     int parent;//父节点，根节点的父节点为-1
	 int i;//空白所在行
	 int j;//空白所在列
	 string step;//从上一节点移动至此节点所需操作
	 int qifa;//启发函数值
};
bool havesolution(NineNode start,NineNode end);
int getQF(NineNode node,NineNode des);
bool match(NineNode node1,NineNode node2);
bool ishave(deque<NineNode> openQueue,vector<NineNode> closedList,NineNode node);
bool lesss(const NineNode& node1, const NineNode& node2)
{
	return node1.qifa<node2.qifa;
}
int main()
{
	int i,j;
	deque<NineNode> openQueue;//open队列
	vector<NineNode> closedList;//closed列表
	stack<string> movepath;//移动步骤栈
	NineNode initilNode,lastNode;//初始节点和目标节点
	cout<<"请输入初始节点状态:";
	/*输入初始节点状态 开始*/
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
	/*输入初始节点状态 结束*/
	cout<<"请输入目标节点状态:";
	/*输入目标节点状态 开始*/
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
	/*输入目标节点状态 结束*/
	initilNode.qifa=getQF(initilNode,lastNode);
    if(havesolution(initilNode,lastNode))
	{
 	   int parent=-1;//parent指示父节点下标
	   bool flag=false;//找到标志
   	   openQueue.push_back(initilNode);


	   while((!openQueue.empty())&&(!flag))
	   {
		  NineNode temp;
		  temp=openQueue.front();//取启发值最小的节点
		  openQueue.pop_front();
		  closedList.push_back(temp);
          parent=closedList.size()-1;
		//  cout << "parent:_"<<parent << endl;
		  if(match(temp,lastNode))
		  {
			flag=true;
			break;
		  }
		 /* if(temp.j>0)//向左移动
		  {
			NineNode left=temp;	
			left.nine[temp.i][temp.j]=left.nine[temp.i][temp.j-1];
			left.nine[temp.i][temp.j-1]=0;
			left.parent=parent;
			left.i=temp.i;
			left.j=temp.j-1;
			left.step="向左移动";
			left.qifa=getQF(left,lastNode);
  	        if(!ishave(openQueue,closedList,left))
		     	openQueue.push_back(left);
		  }
		  if(temp.i>0)//向上移动
		  {
			NineNode up=temp;	
			up.nine[temp.i][temp.j]=up.nine[temp.i-1][temp.j];
			up.nine[temp.i-1][temp.j]=0;
		    up.parent=parent;
			up.i=temp.i-1;
			up.j=temp.j;
			up.step="向上移动";
			up.qifa=getQF(up,lastNode);
			if(!ishave(openQueue,closedList,up))
			    openQueue.push_back(up);
		  }
		  if(temp.j<2)//向右移动
		  {
			NineNode right=temp;
			right.nine[temp.i][temp.j]=right.nine[temp.i][temp.j+1];
			right.nine[temp.i][temp.j+1]=0;
			right.parent=parent;
			right.i=temp.i;
			right.j=temp.j+1;
			right.step="向右移动";
			right.qifa=getQF(right,lastNode);
			if(!ishave(openQueue,closedList,right))
			  openQueue.push_back(right);
		  }
		  if(temp.i<2)//向下移动
		  {
			NineNode down=temp;
			down.nine[temp.i][temp.j]=down.nine[temp.i+1][temp.j];
			down.nine[temp.i+1][temp.j]=0;
			down.parent=parent;
			down.i=temp.i+1;
			down.j=temp.j;
			down.step="向下移动";
			down.qifa=getQF(down,lastNode);
			if(!ishave(openQueue,closedList,down))
			   openQueue.push_back(down);
		  }*/
          sort(openQueue.begin(),openQueue.end(),lesss);//排序,调整队列
	   }
 	   NineNode last=closedList.back();//从最后节点沿父指针向上找
  	   while(last.parent!=-1)
	   {
			movepath.push(last.step);
			last=closedList[last.parent];
	   }
	   cout<<"目标可解,移动步骤如下:"<<endl;
 	   string step;
	   while(!movepath.empty())
	   {
			step=movepath.top();
	        movepath.pop();
			cout<<step<<endl;
	   }
	   cout<<"得到解"<<endl;
	}
	else
	{
		cout<<"目标节点不可达!"<<endl;
	}
    system("pause");
	return 0;

}

/*判断两个节点是否相同，相同返回true，否则返回false*/
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
/*判断新节点是否已经存在，即判断是否存在于open队列和closed列表中*/
bool ishave(deque<NineNode> openQueue,vector<NineNode> closedList,NineNode node)
{
	bool result=false;
	deque<NineNode>::iterator qit=openQueue.begin();
	vector<NineNode>::iterator vit=closedList.begin();
	while(qit!=openQueue.end())
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
/*判断给定的八数码问题是否有解*/
bool havesolution(NineNode start,NineNode end)
{
	bool result=false;
	int i,j,count1=0,count2=0;
	int a[3*3];
	int b[3*3];
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			if(start.nine[i][j]!=0)
				a[count1++]=start.nine[i][j];
		    if(end.nine[i][j]!=0)
				b[count2++]=end.nine[i][j];
		}
    int rsum=0,tsum=0;
    for(i=0;i<8;i++)
		for(j=0;j<i;j++)
		{
			if(a[j]<a[i])
				rsum++;
			if(b[j]<b[i])
				tsum++;
		}
	if(rsum%2==tsum%2)
		result=true;
	return result;
	
}
/*计算启发函数值*/

int getQF(NineNode node,NineNode des)
{
	int i,j;
	int result=0;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			if(node.nine[i][j]!=des.nine[i][j])
				result++;
		}
	return result;

}
