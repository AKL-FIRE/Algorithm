

/*
 * main.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: apple
 */

#include <iostream>
#include <queue>
#include <stack>

enum Action {Top,Bottom,Left,Right,Init};

class Data
{

public:
	int data[3][3];
	Data(int pdata[3][3],int px,int py,Action act) : x(px), y(py), Last_act(act)
	{
		//data = new int[3][3];
		for(int i = 0;i < 3; i++)
			for(int j = 0;j < 3; j++)
				data[i][j] = pdata[i][j];
	}
	Action getAction() const {return Last_act;}
	int getX() const {return x;}
	int getY() const {return y;}
	Data operator=(Data &src)
	{
		Data data(src.data,src.x,src.y,src.Last_act);
		return data;
	}
	void move(Action act)
	{
		switch(act)
		{
		case Top:
			std::swap(data[x][y],data[--x][y]);
			Last_act = Top;
			break;
		case Bottom:
			std::swap(data[x][y],data[++x][y]);
			Last_act = Bottom;
			break;
		case Left:
			std::swap(data[x][y],data[x][--y]);
			Last_act = Left;
			break;
		case Right:
			std::swap(data[x][y],data[x][++y]);
			Last_act = Right;
			break;
		}
	}
private:

	int x,y;
	Action Last_act;


};

struct Node
{
	Node *parent;
	int depth;
	int pathcost;
	Data data;

	Node(Node *pparent,int pdepth,int ppathcost,Data &pdata) : data(pdata)
	{
		parent = pparent;
		depth = pdepth;
		pathcost = ppathcost;
	}

};

void print(Node *aim)
{
	if(aim == nullptr)
		return;
	for(int i = 0;i < 3;i++)
	{
		std::cout << std::endl;
		for(int j =0;j < 3;j++)
			std::cout << aim->data.data[i][j] << "  ";
	}
	std::cout << std::endl << "````````````````````````````" << std::endl;
	print(aim->parent);
}

bool equal(Node &a,Node &b)
{
	for(int i = 0;i < 3; i++)
		for(int j = 0;j < 3; j++)
			if(a.data.data[i][j] != b.data.data[i][j])
				return false;
	return true;
}

bool Expand(Node &source,std::stack<Node> &open,Node &goal)
{
	for(int i = 0; i < 4; i++)
	{
		Node temp(&source,source.depth + 1,source.pathcost + 1,source.data);
		switch(i)
		{
		case Top:
			if(temp.data.getAction() != Bottom && temp.data.getX() != 0)
			{
				temp.data.move(Top);
				open.push(temp);
				if(equal(temp,goal))
				{
					print(&temp);
					return true;
				}
			}
			break;
		case Bottom:
			if(temp.data.getAction() != Top && temp.data.getX() != 2)
			{
				temp.data.move(Bottom);
				open.push(temp);
				if(equal(temp,goal))
				{
					print(&temp);
					return true;
				}
			}
			break;
		case Left:
			if(temp.data.getAction() != Right && temp.data.getY() != 0)
			{
				temp.data.move(Left);
				open.push(temp);
				if(equal(temp,goal))
				{
					print(&temp);
					return true;
				}
			}
			break;
		case Right:
			if(temp.data.getAction() != Left && temp.data.getY() != 2)
			{
				temp.data.move(Right);
				open.push(temp);
				if(equal(temp,goal))
				{
					print(&temp);
					return true;
				}
			}
			break;
		}
	}
	return false;
}

void DFS(Node &First,Node &goal)
{
	std::stack<Node> open;
	std::queue<Node> closed;
	open.push(First);
	while(!open.empty())
	{
		//Node temp = open.front();
		closed.push(open.top());
		open.pop();
		if(closed.back().depth <= 5 && Expand(closed.back(),open,goal))
		{
			std::cout << "Succesful!";
			return;
		}
	}
	std::cout << "Faile";
}


int main()
{
	int first[3][3] = {{2,8,3},{1,0,4},{7,6,5}};
	int last[3][3] = {{1,2,3},{8,0,4},{7,6,5}};
	Data c(first,1,1,Init);
	Data d(last,1,1,Init);
	Node a(nullptr,0,0,c);
	Node b(nullptr,0,0,d);
	DFS(a,b);
}


