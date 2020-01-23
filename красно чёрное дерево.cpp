#include<iostream>
#include<conio.h>

// ����� �.�. �8118-09.03.04������(2)////

/**
 * ������-������ ������, �������� �������� ���� (���� � �����),
 * ���� ����������� �� ������� �����*100+����,
 * � ������ ���� �������� ������, ������� �������� �������� ����, �� ������
 * ���� �� ��������� � ���������� ������
 * ��������:
 * 1. �������
 * 2. ��������
 * 3. ����������� �����
 * 4. ����� ������������ �����
 * 5. ������ ����������� �����
 * 6. �������� �����
 * 7. �������� �������
 * 8. ������� �������
 * 9. ����� ������������� ��������
 * 10. ����� ������������ ��������
 * 11. ��������� ������� ��������
 */

/**
 * ������� ������, �������� ���� (���� � �����)
 * � ����� ��������� �� ��������� ������� ������
 * ����:
 * month - �����
 * day - ����
 * next - ��������� �� ��������� ������� ������
 */
class elem
{
private:
	int month;
	int day;
	elem* next;
public:
	/**
	 * ������� ������: ������, ���� � �����
	 *
	 * �������� ������: ������� � ���������� ������, ����� �� ������ ����� ��������
	 *
	 * ����������� ����.
	 *
	 * @param day - ����, month - �����,
	 * next - ��������� �� ��������� ����.
	 */
	elem(int day, int month, elem* next = NULL)
	{
		this->day = day;
		this->month = month;
		this->next = next;
	}
	/**
	 * ������� ������: ������� ������
	 *
	 * �������� ������: ���� �� ����� ��������
	 *
	 * ���������� ���� �� �������� ������
	 *
	 * @return day - ���� �� ��������
	 */
	int getDay()
	{
		return this->day;
	}
	/**
	 * ������� ������: ������� ������
	 *
	 * �������� ������: ����� �� ����� ��������
	 *
	 * ���������� ����� �� �������� ������
	 *
	 * @return month - ����� �� ��������
	 */
	int getMonth()
	{
		return this->month;
	}
	/**
	 * ������� ������: ������� ������
	 *
	 * �������� ������: ��������� �� ��������� ������� ������
	 *
	 * ���������� ��������� �� ��������� ������� ������
	 *
	 * @return next - ��������� ������� ������
	 */
	elem* getNext()
	{
		return this->next;
	}
	/**
	 * ������� ������: ������� ������ � ����
	 *
	 * �������� ������: ������� ������ � ��������� ����
	 *
	 * �������� �������� ������ �� ����� ��������
	 *
	 * @param day - ����
	 */
	void setDay(int day)
	{
		this->day = day;
	}
	/**
	 * ������� ������: ������� ������ � �����
	 *
	 * �������� ������: ������� ������ � ��������� �������
	 *
	 * �������� �������� ������ �� ����� ��������
	 *
	 * @param month - �����
	 */
	void setMonth(int month)
	{
		this->month = month;
	}
	/**
	 * ������� ������: ������� ������ � ��������� �� ������ �������
	 *
	 * �������� ������: ������� ������ � ��������� ���������� �� ��������� �������
	 *
	 * �������� ��������� �� ��������� ������� ������
	 *
	 * @param next - ��������� �� ������� ������
	 */
	void setNext(elem* next)
	{
		this->next = next;
	}

};

/**
 * ���������� ��������� ������, �������� �������� - ���� (���� � �����). 
 * �������� ����� ������, �������� ��������� �� ��������, ������ � ������� ��������. 
 * � ����� �� ������ ������ ������ � ���� ���� (������� - 0, ����� �-1)
 * ��������:
 * 1. �������
 * 2. ��������
 * 3. ��������� ������ �� �������
 * 4. �������� ������� � ����� ������
 * 5. �������� ������ ������
 * 6. ������� ���� ������� ����
 * 7. ������� � ������� �������� ���� ��������� ����
 * 8. �������� ��������� �� ������ �������
 * 9. �������� ��������� �� ������� �������
 * 10.�������� ��������� �� ��������
 * 11.���������� ��������� �� ��������
 * 12.���������� ��������� �� ������� �������
 * 13.���������� ��������� �� ������ �������
 * 14.�������� �������� ����� ����
 * 15.�������� ���� ����
 * 16.���������� ���� ����
 */
class myList
{
private:
	bool color;
	myList* left;
	myList* right;
	myList* parent;
	elem* head;
public:

	/**
	 * ������� ������: ����, ������� ����� ������� ����� ���� ������.
	 *
	 * �������� ������: ���� ������, ���������� ��������� ������ �� ������ ��������.
	 *
	 * ����������� ���� ������. ���������� ���� ������ �� ����� �������� � ��������,
	 * ������� ��� ��������� �������� ����� ����.
	 */
	myList()
	{
		head = NULL;
	}

	/**
	 * ������� ������: ���� ������.
	 *
	 * �������� ������: ������ ����.
	 *
	 * ���������� ���� ������, ������� ��������� ������, ������������ � ����.
	 */
	~myList()
	{
			elem* temp = head;
			elem* buffer = head;
			while (temp->getNext() != buffer)
			{
				head = (temp->getNext());
				delete temp;
				temp = head;
			}
			delete(head);
	}

	/**
	 * ������� ������: ���� ������.
	 *
	 * �������� ������: �� ��� ��� (�������� �� ���� ������)
	 *
	 * ��������� ������ ���� �� �������
	 * 
	 * @return - true (������ ���� ����� false)
	 */
	bool isEmpty()
	{
		if (head == NULL)
			return 1;
		return 0;
	}

	/**
	 * ���������� �������� � ����� ������.
	 * 1) ���� ������ ����, �� ������ ��������� ���������� ������.
	 * 2) ���� ����� ������� ������ �� ������, �� ������ ����� �������.
	 * 3) � ��������� ������� ������ ����� ������� � ����� ������.
	 *
	 * ������� ������:
	 * ������ �� ������ ������� ������.
	 * �������� ��� ������ �������� ������.
	 *
	 * �������� ������: ���������� ������, � ����� ���������.
	 *
	 * @param day- ���� , month - �����
	 */
	void push(int day, int month)
	{
		/**
		 * ���� ������ ����, �� _data ��������� � ������ ������, � ������ � ���� ������� ��������� �� ���� ����.
		 */
		if (isEmpty())
		{
			head = new elem(day, month);
			head->setNext(head);
		}
		/**
		 *  ���� ������ ��������� �� ���� ����, �� ������ ����� ������� ��
		 * ��������� _data � ������� ������ �� ����� �������, � ����� ������� �� ������.
		 */
		else if (head == head->getNext())
		{
			elem* temp = head;
			head = new elem(day, month);
			head->setNext(temp);
			temp->setNext(head);
			head->setDay(temp->getDay());
			head->setMonth(temp->getMonth());
			temp->setDay(day);
			temp->setMonth(month);
		}
		/**
		 * � ��������� ������� ������ ����� ������� � ����� ������.
		 */
		else
		{
			elem* temp = head; //���������� ������ �� ������ ������ ������
			head = new elem(day, month); // ������ ����� ������ �� ��������� day, month
			head->setNext(temp->getNext()); //������� ������ �� ������ ������� ������
			int day_buffer = temp->getDay(); // ��������� ���� �� ������ ������ ������ ������
			int month_buffer = temp->getMonth(); // ��������� ����� �� ������ ������ ������ ������
			temp->setDay(head->getDay()); //�������� ��������, ���������� � ������ ������ ������ ������..
			temp->setMonth(head->getMonth()); // ..�� ��������� day � month
			head->setDay(day_buffer); // ���������� � ����� ������ �������� ������
			head->setMonth(month_buffer); // ���������� � ����� ������ �������� ������
			temp->setNext(head); // ������� ������ ������ ������ �� ����� ������
		}
	}

	/**
	 * ������� ������: ��������� �� ���� ������.
	 *
	 * �������� ������: ���������� ���������� ��������� � ���� ����.
	 *
	 * @return - ������������� �������� - ���������� ���������.
	 */
	int getSize()
	{
		int result(1);
		elem* temp = head;
		while (temp->getNext() != head)
		{
			result++;
			temp = temp->getNext();
		}
		return result;

	}
	/**
	 * ������� ������: ���� ������.
	 *
	 * �������� ������: ���� �� ������� ��� ������ ��������.
	 *
	 * ������� ���� ������� �� ����
	 */
	void deleteOne()
	{
		elem* temp = head->getNext();
		head->setNext(head->getNext()->getNext());
		delete(temp);
	}
	/**
	 * ������� ������: ��������� �� ���� ������.
	 *
	 * �������� ������: ������� � ������� ����� ������ ������ ������� �� ������� �� ������ � ������� ��.��
	 *
	 * @return - ������ � �������.
	 */
	void getAllData()
	{
		for (int i = 0; i < this->getSize(); i++)
			std::cout << ' ' << head->getDay() / 10 << head->getDay() % 10 << '.' << head->getMonth() / 10 << head->getMonth()% 10;
	}
	/**
	 * ������� ������: ���� ������
	 *
	 * �������� ������: ��������� �� ����� ������� ����
	 *
	 * @return left - ����� �������
	 */
	myList *getLeft()
	{
		return this->left;
	}
	/**
	 * ������� ������:  ���� ������
	 *
	 * �������� ������: ��������� �� ������ ������� ����
	 *
	 * @return right - ������ �������
	 */
	myList *getRight()
	{
		return this->right;
	}
	/**
	 * ������� ������:  ���� ������
	 *
	 * �������� ������: ��������� �� �������� ����
	 *
	 * @return parent - ��������
	 */
	myList *getParent()
	{
		return this->parent;
	}
	/**
	 * ������� ������:  ���� ������, ��������� �� ������ ���� ������
	 *
	 * �������� ������: ���� ������ � ���������� ����� ��������� �� ��������
	 *
	 * @param x- ��������� �� ���� ������
	 */
	void setParent(myList *x)
	{
		this->parent = x;
	}
	/**
	 * ������� ������: ���� ������, ��������� �� ������ ���� ������
	 *
	 * �������� ������: ���� ������ � ���������� ����� ��������� �� ������ �������
	 *
	 * @param x- ��������� �� ���� ������
	 */
	void setLeft(myList *x)
	{
		this->left = x;
	}
	/**
	 * ������� ������: ���� ������, ��������� �� ������ ���� ������
	 *
	 * �������� ������: ���� ������ � ���������� ����� ��������� �� ������� �������
	 *
	 * @param x- ��������� �� ���� ������
	 */
	void setRight(myList *x)
	{
		this->right = x;
	}
	
	/**
	 * ������� ������: ���� ������
	 * 
	 * �������� ������: ���� ���� ������
	 *
	 * ������� ��� ����������� ����� ���� ������
	 * ���� ��������� � ���� ����
	 * �.�. ���� ����� = 1, � ���� = 21, �� ����� 0121 = 121
	 *
	 * @return - ���� ���� ������
	 */
	int getKey()
	{
		return (head->getMonth() * 100 + head->getDay());
	}
	/**
	 * ������� ������: ���� ������, ���� (0 ��� 1)
	 *
	 * �������� ������: ���� ������ � ���������� ����� �����
	 *
	 * @param x- ���� 
	 */
	void setColor(bool x)
	{
		this->color = x;
	}
	/**
	 * ������� ������: ���� ������
	 *
	 * �������� ������: ���� ����� ���� (0 ��� 1)
	 *
	 * @param x- ���� ����
	 */
	bool getColor()
	{
		return color;
	}
};

class redBlackTree
{
private:
	
	myList *nil;
	myList* root;
	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� ����� ������������ �������
	 *
	 * ������� ������� ��� �������� ������ ����� ������������ �������
	 *
	 * @param x - ��������� �� ������ ���������
	 *
	 * @return NULL - ������ ������ ��������
	 */
	myList* LNRPrintData(myList* x)
	{
		if (x != nil)
		{
			if (x->getLeft() != nil)
				LNRPrintData(x->getLeft());
			x->getAllData();
			if (x->getRight() != nil)
				LNRPrintData(x->getRight());
			
		}
		return NULL;
	}
	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� ������ ������������ �������
	 *
	 * ������� ������� ��� �������� ������ ������ ������������ �������
	 *
	 * @param x - ��������� �� ������ ���������
	 *
	 * @return NULL - ������ ������ ��������
	 */
	myList* RNLPrintData(myList* x)
	{
		if (x != nil)
		{
			if (x->getRight() != nil)
				RNLPrintData(x->getRight());
			x->getAllData();
			if (x->getLeft() != nil)
				RNLPrintData(x->getLeft());
		}
		return NULL;
	}

	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� �������� �������
	 *
	 * ������� ������� ��� �������� ������ �������� �������
	 *
	 * @param x - ��������� �� ������ ���������
	 *
	 * @return NULL - ������ ������ ��������
	 */
	myList *LRNPrintData(myList *x)
	{
		if (x != nil)
		{
			if (x->getLeft() != nil)
				LRNPrintData(x->getLeft());
			if (x->getRight() != nil)
				LRNPrintData(x->getRight());
			x->getAllData();
		}
		return NULL;
	}
	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� ������ �������
	 *
	 * ������� ������� ��� �������� ������ ������ �������
	 *
	 * @param x - ��������� �� ������ ���������
	 *
	 * @return NULL - ������ ������ ��������
	 */
	myList* NLRPrintData(myList* x)
	{
		if (x != nil)
		{
			x->getAllData();
			if (x->getLeft() != nil)
				NLRPrintData(x->getLeft());
			if (x->getRight() != nil)
				NLRPrintData(x->getRight());
		}
		return NULL;
	}

	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ���������� ��������� � �������� ������ � ������� ������ ��������
	 *
	 * ��������� ������ ����� ������� ���������� ���������
	 *
	 * @param x - ��������� �� ������ ���������
	 */
	void LeftRotate(myList* x)
	{
		myList* y = x->getRight();
		x->setRight(y->getLeft());
		if (y->getLeft() != nil)
			y->getLeft()->setParent(x);
		y->setParent(x->getParent());
		if (x->getParent() == nil)
			root = y;
		else if (x == x->getParent()->getLeft())
			x->getParent()->setLeft(y);
		else x->getParent()->setRight(y);
		y->setLeft(x);
		x->setParent(y);
	}
	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ���������� ��������� � �������� ������ � ������� ������� ��������
	 *
	 * ��������� ������ ������ ������� ���������� ���������
	 *
	 * @param x - ��������� �� ������ ���������
	 */
	void RightRotate(myList * x)
	{
		myList* y = x->getLeft();
		x->setLeft(y->getRight());
		if (y->getRight() != nil)
			y->getRight()->setParent(x);
		y->setParent(x->getParent());
		if (x->getParent() == nil)
			root = y;
		else if (x == x->getParent()->getRight())
			x->getParent()->setRight(y);
		else x->getParent()->setLeft(y);
		y->setRight(x);
		x->setParent(y);
	}
	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ��������� �� ���� ��������� � ����������� ������ 
	 *
	 * ������� ���� ���� � ��������� � ����������� ������
	 *
	 * @param x - ��������� �� ������ ���������
	 */
	myList* TreeMin(myList* x)
	{
		while (x->getLeft() != nil)
			x = x->getLeft();
		return x;
	}
	/**
	 * ������� ������: ��������� �� ������ ��������� � �������� ������
	 *
	 * �������� ������: ��������� �� ���� ��������� � ������������ ������
	 *
	 * ������� ���� ���� � ��������� � ������������ ������
	 *
	 * @param x - ��������� �� ������ ���������
	 */
	myList* TreeMax(myList* x)
	{
		while (x->getRight() != nil)
			x = x->getRight();
		return x;
	}
	/**
	 * ������� ������: ��������� �� ��� ����� ����������� � �������� ������
	 *
	 * �������� ������: ��������� ������ � �������������� ���������� �� ������ �����
	 *
	 * ����������� ��������� �� ������ �����
	 *
	 * @param x - ��������� �� ������ ���������
	 */
	void transplant(myList* u,myList* v)
	{
		if (u->getParent() == nil)
			root = v;
		else if (u == u->getParent()->getLeft())
			u->getParent()->setLeft(v);
		else u->getParent()->setRight(v);
		v->setParent(u->getParent());
	}

	/**
	 * ������� ������: ��������� �� ���� ������ � ���� ������.
	 *
	 * �������� ������: ��������� ���� � � ����� ��������� ��������� ������.
	 *
	 * ������� ���� ������ ����� �������� �����
	 * 
	 * @param x - ��������� �� ������ ���������
	 *
	 * @return NULL - ������ ������ ��������
	 */
	myList* LRNDestructor(myList* x)
	{
		if (x->getLeft() != nil)
			LRNDestructor(x->getLeft());
		if (x->getRight() != nil)
			LRNDestructor(x->getRight());
		delete(x);
		return NULL;
	}
	/**
	 * ������� ������: ��������� �� ���� ������ � ���� ������.
	 *
	 * �������� ������: ���������������� ������.
	 *
	 * ����������� ������ ����� ���������� ������ ��������
	 *
	 * @param x - ��������� �� ������ ���������
	 */
	void RBFixup(myList* z)
	{
		myList* y = z->getParent();
		while (z->getParent()->getColor() == 0)
		{
			if (z->getParent() == z->getParent()->getParent()->getLeft())
			{
				y = z->getParent()->getParent()->getRight();
				if (y->getColor() == 0)
				{
					z->getParent()->setColor(1);
					y->setColor(1);
					z->getParent()->getParent()->setColor(0);
					z = z->getParent()->getParent();
				}
				else
				{
					if (z == z->getParent()->getRight())
					{
						z = z->getParent();
						LeftRotate(z);
					}
					z->getParent()->setColor(1);
					z->getParent()->getParent()->setColor(0);
					RightRotate(z->getParent()->getParent());
				}
			}
			else
			{
				y = z->getParent()->getParent()->getLeft();
				if (y->getColor() == 0)
				{
					z->getParent()->setColor(1);
					y->setColor(1);
					z->getParent()->getParent()->setColor(0);
					z = z->getParent()->getParent();
				}
				else
				{
					if (z == z->getParent()->getLeft())
					{
						z = z->getParent();
						RightRotate(z);
					}
					z->getParent()->setColor(1);
					z->getParent()->getParent()->setColor(0);
					LeftRotate(z->getParent()->getParent());
				}
			}
		}
		root->setColor(1);
	}
	/**
	 * ������� ������: ��������� �� ���� ������ � ���� ������.
	 *
	 * �������� ������: ���������������� ������.
	 *
	 * ����������� ������ ����� �������� ����
	 *
	 * @param x - ��������� �� ������ ���������
	 */
	void RBDeleteFixup(myList* x)
	{
		myList* w;
		while ((x != root) && (x->getColor() == 1))
		{
			if (x == x->getParent()->getLeft())
			{
				w = x->getParent()->getRight();
				if (w->getColor() == 0)
				{
					w->setColor(1);
					w->getParent()->setColor(0);
					LeftRotate(w->getParent());
					w = x->getParent()->getRight();
				}
				if ((w->getRight()->getColor() == 1) && (w->getLeft()->getColor() == 1))
				{
					w->setColor(0);
					x = x->getParent();
				}
				else
				{
					if (w->getRight()->getColor() == 1)
					{
						w->getRight()->setColor(1);
						w->setColor(0);
						RightRotate(w);

					}
					w->setColor(w->getParent()->getColor());
					w->getRight()->setColor(1);
					w->getParent()->setColor(1);
					LeftRotate(x->getParent());
					x = root;
				}
			}
			else
			{
				w = x->getParent()->getLeft();
				if (w->getColor() == 0)
				{
					w->setColor(1);
					w->getParent()->setColor(0);
					RightRotate(w->getParent());
					w = x->getParent()->getLeft();
				}
				if ((w->getLeft()->getColor() == 1) && (w->getRight()->getColor() == 1))
				{
					w->setColor(0);
					x = x->getParent();
				}
				else
				{
					if (w->getLeft()->getColor() == 1)
					{
						w->getLeft()->setColor(1);
						w->setColor(0);
						LeftRotate(w);
					}
					w->setColor(w->getParent()->getColor());
					w->getLeft()->setColor(1);
					w->getParent()->setColor(1);
					RightRotate(x->getParent());
					x = root;
				}
			}
		}
		x->setColor(1);
	}
	/**
	 * ������� ������: ������
	 *
	 * �������� ������: ��������� �� ���� ������ � ������������ ������
	 *
	 * ������� ���� ���� � ������ � ������������ ������
	 *
	 * @return - ��������� �� ���� ������ ��� NULL ���� ������ ���
	 */
	myList* getMaxPointer()
	{
		if (root != nil)
		{
			myList* temp = root;
			while (temp->getRight() != nil)
				temp = temp->getRight();
			return temp;
		}
		else return NULL;
	}
	/**
	 * ������� ������: ������
	 *
	 * �������� ������: ��������� �� ���� ������ � ����������� ������
	 *
	 * ������� ���� ���� � ������ � ����������� ������
	 *
	 * @return - ��������� �� ���� ������ ��� NULL ���� ������ ���
	 */
	myList* getMinPointer()
	{
		if (root != nil)
		{
			myList* temp = root;
			while (temp->getLeft() != nil)
				temp = temp->getLeft();
			return temp;
		}
		else return NULL;
	}
	/**
	 * ������� ������: ������
	 *
	 * �������� ������: ��������� �� ���� ������ � ���������� �����������
	 *
	 * ������� ���� ���� ������ � ��������� ��������� ��� ���������� NULL
	 *
	 * @param - day - ����, month - �����
	 *
	 * @return - ��������� �� ���� ������ ��� NULL ���� ������ ���
	 */
	myList* getListPointer(int day, int month)
	{
		int key = month * 100 + day;
		myList* temp = root;
		while (temp->getKey() != key)
		{
			if (key < temp->getKey())
				if (temp->getLeft() != nil)
					temp = temp->getLeft();
				else return NULL;
			else if (key > temp->getKey())
				if (temp->getRight() != nil)
					temp = temp->getRight();
				else return NULL;
		}
		return (temp);
	}
public:
	
	
	/**
	 * ������� ������: ��� ������ ������.
	 *
	 * �������� ������: ������ ������ � �������� ������.
	 *
	 * ����������� ������. ���������� ������ ������.
	 */
	redBlackTree()
	{
		
		myList* z = new myList();
		nil = z;
		nil->setColor(1);
		root = nil;
	}

	/**
	 * ������� ������: ���  ������.
	 *
	 * �������� ������: ������ ������ .
	 *
	 * ���������� ������. ������� ������.
	 */
	~redBlackTree()
	{
		if (root!=nil)
		LRNDestructor(root);
	}
	/**
	 * ������� ������: ������ ������ ������������ ������
	 *
	 * �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� �������� �������
	 *
	 * ������� ������� ��� �������� ������ �������� �������
	 */
	void LRN()
	{
			LRNPrintData(root);
	}
	/**
	 * ������� ������: ������ ������ ������������ ������
	 *
	 * �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� ����� ������������ �������
	 *
	 * ������� ������� ��� �������� ������ ����� ������������ �������
	 */
	void LNR()
	{
		LNRPrintData(root);
	}
	/**
	 * ������� ������: ������ ������ ������������ ������
	 *
	 * �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� ������ ������������ �������
	 *
	 * ������� ������� ��� �������� ������ ������ ������������ �������
	 */
	void RNL()
	{
		RNLPrintData(root);
	}
	/**
	* ������� ������: ������ ������ ������������ ������
	*
	* �������� ������: ������ � ������� - ��� �������� ������ ����� ������, ���������� ������ �������
	*
	* ������� ������� ��� �������� ������ ������ ������ �������
	*/
	void NLR()
	{
		NLRPrintData(root);
	}
	/**
	 * ������� ������: ������, ���� - ���� � �����
	 *
	 * �������� ������: ������ � ����� ����� ��� � ���������� ������� ������ �� �����
	 *
	 * ������� ��������� � ������ ���� � ���������� ����������� ���
	 * ���� ���� � ������ ����������� ��� ����, 
	 * �� ������ �������� � ������ ����� ���� ����� �������
	 *
	 * @param - day - ����, month - �����
	 */
	void RBInsert(int day, int month)
	{
		myList* z = new myList();
		z->push(day, month);
		myList* y = nil;
		myList* x = root;
		while (x != nil && (z->getKey() != x->getKey()))
		{
				y = x;
				if (z->getKey() < x->getKey())
					x = x->getLeft();
				else x = x->getRight();
		}
		if (root == nil)
		{
			root = z;
			root->setColor(1);
			root->setLeft(nil);
			root->setRight(nil);
			root->setParent(nil);
		}
		else 
			if (y == nil && x!= nil)
			{
				x->push(day, month);
				delete(z);
			}
			else 
				if (x != nil)
				{
					x->push(day, month);
					delete(z);
				} 
				else
				{
					if (z->getKey() < y->getKey())
						y->setLeft(z);
					else
						y->setRight(z);
					z->setLeft(nil);
					z->setRight(nil);
					z->setColor(0);
					z->setParent(y);
					RBFixup(z);
				}
	}
	/**
	 * ������� ������: ������, ���� - ���� � �����
	 *
	 * �������� ������: ������ ��� ���� � ��������� ������ ��� ���
	 * ������ �������� � ������ ���� � ��������� ���������
	 *
	 * ������� ������� �� ������ ���� � ���������� ����������� ���
	 * ������� �������� �� ������ ����, ���� � �� ������ ������ ��������
	 *
	 * @param - day - ����, month - �����
	 */
	void RBDelete(int day, int month)
	{
		myList* z;
		z = this->getListPointer(day, month);
		if (z != NULL)
		{
			if (z->getSize() == 1)
			{
				myList* x;
				myList* y = z;
				bool orig_color = y->getColor();
				if (z->getLeft() == nil)
				{
					x = z->getRight();
					transplant(z, z->getLeft());
				}
				else
					if (z->getRight() == nil)
					{
						x = z->getLeft();
						transplant(z, z->getLeft());
					}
					else
					{
						y = TreeMin(z->getRight());
						orig_color = y->getColor();
						x = y->getRight();
						if (y->getParent() == z)
							x->setParent(y);
						else
						{
							transplant(y, y->getRight());
							y->setRight(z->getRight());
							y->getRight()->setParent(y);
						}
						transplant(z, y);
						y->setLeft(z->getLeft());
						y->getLeft()->setParent(y);
						y->setColor(z->getColor());
					}
				z->~myList();
				if (orig_color == 1)
					RBDeleteFixup(x);
			}
			else
			{
				z->deleteOne();
			}
		}
	}
	/**
	 * ������� ������: ������, ���� - ���� � �����
	 *
	 * �������� ������: true ��� false, ���� ���� � ���������� ����������� ��� ��� ��������������
	 *
	 * ������� ��������� ������� ���� � ���������� �����������
	 *
	 * @param - day - ����, month - �����
	 *
	 * @return - true ��� false////
	 */
	bool checkElem(int day, int month)
	{
		int key = 100 * month + day;
		if (this->getListPointer(day, month) != NULL)
			return 1;
		else return 0;
	}
	/**
	 * ������� ������: ������
	 *
	 * �������� ������: ������������ ������� ������ � �������
	 *
	 * ������ ������� ������������ ������� ������
	 */
	void printMax()
	{
		this->getMaxPointer()->getAllData();
	}
	/**
	 * ������� ������: ������
	 *
	 * �������� ������: ����������� ������� ������ � �������
	 *
	 * ������ ������� ����������� ������� ������
	 */
	void printMin()
	{
		this->getMinPointer()->getAllData();
	}
};

/**
 * ������� ������: ��������� �� ������ ������, ���� � �����
 *
 * �������� ������: ���������� ������ � ����� ����� ��� ��������� � ����
 *
 * @param tree - ��������� �� ������
 */
void Enter(redBlackTree *tree)
{
	int day, month;
	system("cls");
	
	std::cout << "������� ���� \n";
	std::cin >> day;
	std::cout << "������� ����� \n";
	std::cin >> month;
	if (month < 1 || month > 12)
		goto m1;
	else
	{
		switch (month)
		{
		case 1: if (day < 1 || day>31) goto m1; 
		case 2: if (day < 1 || day>29) goto m1; 
		case 3: if (day < 1 || day>31) goto m1; 
		case 4: if (day < 1 || day>30) goto m1; 
		case 5: if (day < 1 || day>31) goto m1; 
		case 6: if (day < 1 || day>30) goto m1; 
		case 7: if (day < 1 || day>31) goto m1; 
		case 8: if (day < 1 || day>31) goto m1; 
		case 9: if (day < 1 || day>30) goto m1; 
		case 10: if (day < 1 || day>31) goto m1; 
		case 11: if (day < 1 || day>30) goto m1; 
		case 12: if (day < 1 || day>31) goto m1; 
		default: goto m2;
		}
	}
	m1:
	system("cls");
	std::cout << "������ ������� ������";
	_getch();
	return;
	m2: 
	tree->RBInsert(day, month);
}
/**
 * ������� ������: ��������� �� ������ ������, ���� � �����
 *
 * �������� ������: ���������� ������ � �������� ����� ��� ��������� �� ����
 *
 * @param tree - ��������� �� ������
 */
void delet(redBlackTree* tree)
{
	int day, month;
	system("cls");

	std::cout << "������� ���� \n";
	std::cin >> day;
	std::cout << "������� ����� \n";
	std::cin >> month;
	tree->RBDelete(day, month);
}
/**
 * ������� ������: ��������� �� ������ ������, ���� � �����
 *
 * �������� ������: �� ��� ��� - ����� �� ������ ���� �� ����� ���� � ������
 * ��������� � �������
 *
 * @param tree - ��������� �� ������
 */
void check(redBlackTree* tree)
{
	int day, month;
	system("cls");

	std::cout << "������� ���� \n";
	std::cin >> day;
	std::cout << "������� ����� \n";
	std::cin >> month;
	if (tree->checkElem(day, month) == 1)
		std::cout << "true";
	else std::cout << "false";
}

int main()
{
	redBlackTree T;
	setlocale(LC_ALL, "Rus");
	std::cout << "press enter to start";
	while (_getch() != 27)
	{
		system("cls");
		std::cout << "������� 1 ����� �������� ������� � ������" << '\n';
		std::cout << "������� 2 ����� ������� ������� ��������� �������" << '\n';
		std::cout << "������� 3 ����� ������� ������ �������� �������" << '\n';
		std::cout << "������� 4 ����� ������� ������ ������������ ������� � ���� �� �����" << '\n';
		std::cout << "������� 5 ����� ������� ������ ������������ ������� � ����� �� ����" << '\n';
		std::cout << "������� 6 ����� ������� ������ ������ �������" << '\n';
		std::cout << "������� 7 ����� ������� ������������ ��������" << '\n';
		std::cout << "������� 8 ����� ������� ����������� ��������" << '\n';
		std::cout << "������� 9 ����� ��������� ������� ��������" << '\n';
		std::cout << "������� esc ����� ���������" << '\n';
		switch (_getch())
		{
		case '1': Enter(&T); break;
		case '2': delet(&T); break;
		case '3': T.LRN(); break;
		case '4': T.LNR(); break;
		case '5': T.RNL(); break;
		case '6': T.NLR(); break;
		case '7': T.printMax(); break;
		case '8': T.printMin(); break;
		case '9': check(&T); break;
		case 27: return 0;
		}
		std::cout << "\n������� ����� ������� ����� ����������";
	}
	_getch();
	return 0;
} 
