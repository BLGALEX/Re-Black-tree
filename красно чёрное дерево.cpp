#include<iostream>
#include<conio.h>

// Лепёха А.А. Б8118-09.03.04прогин(2)

/**
 * Красно-черное дерево, элементы которого даты (день и месяц),
 * ключ вычисляется по формуле месяц*100+день,
 * в каждом узле хранится список, котррый содержит элементы узла, на случай
 * если их несколько с одинаковым ключём
 * Операции:
 * 1. Создать
 * 2. Очистить
 * 3. Центральный обход
 * 4. Левый симметричный обход
 * 5. Правый симметричнй обход
 * 6. Обратный обход
 * 7. Добавить элемент
 * 8. Удалить элемент
 * 9. Вывод максимального элемента
 * 10. Вывод минимального элемента
 * 11. Проверить наличие элемента
 */

/**
 * Элемент списка, содержит дату (день и месяц)
 * А также указатель на следующий элемент списка
 * Поля:
 * month - месяц
 * day - день
 * next - указатель на следующий элемент списка
 */
class elem
{
private:
	int month;
	int day;
	elem* next;
public:
	/**
	 * Входные данные: список, день и месяц
	 *
	 * Выходные данные: элемент с указанными полями, адрес на ячейку этого элемента
	 *
	 * Конструктор узла.
	 *
	 * @param day - день, month - месяц,
	 * next - указатель на следующий узел.
	 */
	elem(int day, int month, elem* next = NULL)
	{
		this->day = day;
		this->month = month;
		this->next = next;
	}
	/**
	 * Входные данные: элемент списка
	 *
	 * Выходные данные: день из этого элемента
	 *
	 * Возвращает день из элемента списка
	 *
	 * @return day - день из элемента
	 */
	int getDay()
	{
		return this->day;
	}
	/**
	 * Входные данные: элемент списка
	 *
	 * Выходные данные: месяц из этого элемента
	 *
	 * Возвращает месяц из элемента списка
	 *
	 * @return month - месяц из элемента
	 */
	int getMonth()
	{
		return this->month;
	}
	/**
	 * Входные данные: элемент списка
	 *
	 * Выходные данные: указатель на следующий элемент списка
	 *
	 * Возвращает указатель на следующий элемент списка
	 *
	 * @return next - следующий элемент списка
	 */
	elem* getNext()
	{
		return this->next;
	}
	/**
	 * Входные данные: элемент списка и день
	 *
	 * Выходные данные: элемент списка с изменённым днем
	 *
	 * Изменяет значение одного из полей элемента
	 *
	 * @param day - день
	 */
	void setDay(int day)
	{
		this->day = day;
	}
	/**
	 * Входные данные: элемент списка и месяц
	 *
	 * Выходные данные: элемент списка с изменённым месяцем
	 *
	 * Изменяет значение одного из полей элемента
	 *
	 * @param month - месяц
	 */
	void setMonth(int month)
	{
		this->month = month;
	}
	/**
	 * Входные данные: элемент списка и указатель на другой элемент
	 *
	 * Выходные данные: элемент списка с изменнёным указателем на следующий элемент
	 *
	 * Изменяет указатель на следующий элемент списка
	 *
	 * @param next - указатель на элемент списка
	 */
	void setNext(elem* next)
	{
		this->next = next;
	}

};

/**
 * Одновязный кольцевой список, элементы которого - даты (день и месяц). 
 * Является узлом дерева, содержит указатели на родителя, левого и правого потомков. 
 * А также на голову самого списка и цвет узла (красный - 0, черны й-1)
 * Операции:
 * 1. Создать
 * 2. Очистить
 * 3. Проверить список на пустоту
 * 4. Добавить элемент в конец списка
 * 5. Получить размер списка
 * 6. Удалить один элемент узла
 * 7. Вывести в консоль значения всех элементов узла
 * 8. Получить указатель на левого потомка
 * 9. Получить указатель на правого потомка
 * 10.Получить указатель на родителя
 * 11.Установить указатель на родителя
 * 12.Установить указатель на правого потомка
 * 13.Установить указатель на левого потомка
 * 14.Получить значение ключа узла
 * 15.Получить цвет узла
 * 16.Установить цвет узла
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
	 * Входные данные: дата, которую будет хранить новый узел дерева.
	 *
	 * Выходные данные: узел дерева, содержащий кольцевой список из одного элемента.
	 *
	 * Конструктор узла дерева. Изначально узел дерева не имеет потомков и родителя,
	 * поэтому все указатели полагаем равны нулю.
	 */
	myList()
	{
		head = NULL;
	}

	/**
	 * Входные данные: узел дерева.
	 *
	 * Выходные данные: пустой узел.
	 *
	 * Деструктор узла дерева, очищает кольцевой список, содержащийся в узле.
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
	 * Входные данные: узел дерева.
	 *
	 * Выходные данные: да или нет (является ли узел пустым)
	 *
	 * Проверяет список узла на пустоту
	 * 
	 * @return - true (список пуст иначе false)
	 */
	bool isEmpty()
	{
		if (head == NULL)
			return 1;
		return 0;
	}

	/**
	 * Добавление элемента в конец списка.
	 * 1) Если список пуст, то первым элементом становится голова.
	 * 2) Если спиок состоит только из головы, то создаём новый элемент.
	 * 3) В остальных случаях создаём новый элемент в конце списка.
	 *
	 * Входные данные:
	 * Ссылка на первый элемент списка.
	 * Значение для нового элемента списка.
	 *
	 * Выходные данные: обновлённый список, с новым элементом.
	 *
	 * @param day- день , month - месяц
	 */
	void push(int day, int month)
	{
		/**
		 * Если список пуст, то _data заносится в голову списка, и голова в свою очередь ссылается на саму себя.
		 */
		if (isEmpty())
		{
			head = new elem(day, month);
			head->setNext(head);
		}
		/**
		 *  Если голова ссылается на саму себя, то создаём новый элемент со
		 * значением _data и ссылаем голову на новый элемент, а новый элемент на голову.
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
		 * В остальных случаях создаём новый элемент в конце списка.
		 */
		else
		{
			elem* temp = head; //запоминаем ссылку на ячейку памяти головы
			head = new elem(day, month); // создаём новую голову со значением day, month
			head->setNext(temp->getNext()); //ссылаем голову на второй элемент списка
			int day_buffer = temp->getDay(); // сохраняем день из старой ячейки памяти головы
			int month_buffer = temp->getMonth(); // сохраняем месяц из старой ячейки памяти головы
			temp->setDay(head->getDay()); //изменяем значение, хранящееся в старой ячейке памяти головы..
			temp->setMonth(head->getMonth()); // ..на введенные day и month
			head->setDay(day_buffer); // записываем в новую голову значение старой
			head->setMonth(month_buffer); // записываем в новую голову значение старой
			temp->setNext(head); // ссылаем старую ячейку головы на новую голову
		}
	}

	/**
	 * Входные данные: указатель на узел дерева.
	 *
	 * Выходные данные: количество одинаковых элементов в этом узле.
	 *
	 * @return - целочисленное значение - количество элементов.
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
	 * Входные данные: узел дерева.
	 *
	 * Выходные данные: узел со списком без одного элемента.
	 *
	 * Удаляет один элемент из узла
	 */
	void deleteOne()
	{
		elem* temp = head->getNext();
		head->setNext(head->getNext()->getNext());
		delete(temp);
	}
	/**
	 * Входные данные: указатель на узел дерева.
	 *
	 * Выходные данные: выводит в консоль через пробел каждый элемент по порядку из списка в формате дд.мм
	 *
	 * @return - строка в консоли.
	 */
	void getAllData()
	{
		for (int i = 0; i < this->getSize(); i++)
			std::cout << ' ' << head->getDay() / 10 << head->getDay() % 10 << '.' << head->getMonth() / 10 << head->getMonth()% 10;
	}
	/**
	 * Входные данные: узел дерева
	 *
	 * Выходные данные: указатель на левый потомок узла
	 *
	 * @return left - левый потомок
	 */
	myList *getLeft()
	{
		return this->left;
	}
	/**
	 * Входные данные:  узел дерева
	 *
	 * Выходные данные: указатель на правый потомок узла
	 *
	 * @return right - правый потомок
	 */
	myList *getRight()
	{
		return this->right;
	}
	/**
	 * Входные данные:  узел дерева
	 *
	 * Выходные данные: указатель на родителя узла
	 *
	 * @return parent - родитель
	 */
	myList *getParent()
	{
		return this->parent;
	}
	/**
	 * Входные данные:  узел дерева, указатель на другой узел дерева
	 *
	 * Выходные данные: узел дерева с обновлённым полем указателя на родителя
	 *
	 * @param x- указатель на узел дерева
	 */
	void setParent(myList *x)
	{
		this->parent = x;
	}
	/**
	 * Входные данные: узел дерева, указатель на другой узел дерева
	 *
	 * Выходные данные: узел дерева с обновлённым полем указателя на левого потомка
	 *
	 * @param x- указатель на узел дерева
	 */
	void setLeft(myList *x)
	{
		this->left = x;
	}
	/**
	 * Входные данные: узел дерева, указатель на другой узел дерева
	 *
	 * Выходные данные: узел дерева с обновлённым полем указателя на правого потомка
	 *
	 * @param x- указатель на узел дерева
	 */
	void setRight(myList *x)
	{
		this->right = x;
	}
	
	/**
	 * Входные данные: узел дерева
	 * 
	 * Выходные данные: Ключ узла дерева
	 *
	 * Функция для определения ключа узла дерева
	 * Ключ выводится в виде ммдд
	 * т.е. если месяц = 1, а день = 21, то будет 0121 = 121
	 *
	 * @return - ключ узла дерева
	 */
	int getKey()
	{
		return (head->getMonth() * 100 + head->getDay());
	}
	/**
	 * Входные данные: узел дерева, цвет (0 или 1)
	 *
	 * Выходные данные: узел дерева с обновлённым полем цвета
	 *
	 * @param x- цвет 
	 */
	void setColor(bool x)
	{
		this->color = x;
	}
	/**
	 * Входные данные: узел дерева
	 *
	 * Выходные данные: цвет этого узла (0 или 1)
	 *
	 * @param x- цвет узла
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
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: строка в консоли - все элементы дерева через пробел, полученные левым симметричным обходом
	 *
	 * Функция выводит все элементы дерева левым симметричным обходом
	 *
	 * @param x - указатель на корень поддерева
	 *
	 * @return NULL - просто пустое значение
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
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: строка в консоли - все элементы дерева через пробел, полученные правым симметричным обходом
	 *
	 * Функция выводит все элементы дерева правым симметричным обходом
	 *
	 * @param x - указатель на корень поддерева
	 *
	 * @return NULL - просто пустое значение
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
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: строка в консоли - все элементы дерева через пробел, полученные обратным обходом
	 *
	 * Функция выводит все элементы дерева обратным обходом
	 *
	 * @param x - указатель на корень поддерева
	 *
	 * @return NULL - просто пустое значение
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
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: строка в консоли - все элементы дерева через пробел, полученные прямым обходом
	 *
	 * Функция выводит все элементы дерева прямым обходом
	 *
	 * @param x - указатель на корень поддерева
	 *
	 * @return NULL - просто пустое значение
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
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: измененное поддерево в основном дереве с помощью левого поворота
	 *
	 * Процедура делает левый поворот указанного поддерева
	 *
	 * @param x - указатель на корень поддерева
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
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: измененное поддерево в основном дереве с помощью правого поворота
	 *
	 * Процедура делает правый поворот указанного поддерева
	 *
	 * @param x - указатель на корень поддерева
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
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: указатель на узел поддерева с минимальным ключём 
	 *
	 * Функция ищет узел в поддереве с минимальным ключом
	 *
	 * @param x - указатель на корень поддерева
	 */
	myList* TreeMin(myList* x)
	{
		while (x->getLeft() != nil)
			x = x->getLeft();
		return x;
	}
	/**
	 * Входные данные: указатель на корень поддерева и основное дерево
	 *
	 * Выходные данные: указатель на узел поддерева с максимальным ключём
	 *
	 * Функция ищет узел в поддереве с максимальным ключом
	 *
	 * @param x - указатель на корень поддерева
	 */
	myList* TreeMax(myList* x)
	{
		while (x->getRight() != nil)
			x = x->getRight();
		return x;
	}
	/**
	 * Входные данные: указатель на два корня поддеревьев и основное дерево
	 *
	 * Выходные данные: изменённое дерево с переставленным поддеревом на другое место
	 *
	 * Перествялет поддерево на другое место
	 *
	 * @param x - указатель на корень поддерева
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
	 * Входные данные: указатель на узел дерева и само дерево.
	 *
	 * Выходные данные: очищенный узел и в итоге полностью очищенное дерево.
	 *
	 * Удаляет узлы дерева через обратный обход
	 * 
	 * @param x - указатель на корень поддерева
	 *
	 * @return NULL - просто пустое значение
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
	 * Входные данные: указатель на узел дерева и само дерево.
	 *
	 * Выходные данные: Сбалансированное дерево.
	 *
	 * Балансирует дерево после добавления нового элемента
	 *
	 * @param x - указатель на корень поддерева
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
	 * Входные данные: указатель на узел дерева и само дерево.
	 *
	 * Выходные данные: Сбалансированное дерево.
	 *
	 * Балансирует дерево после удаления узла
	 *
	 * @param x - указатель на корень поддерева
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
	 * Входные данные: дерево
	 *
	 * Выходные данные: указатель на узел дерева с максимальным ключём
	 *
	 * Функция ищет узел в дереве с максимальным ключом
	 *
	 * @return - указатель на узел дерева или NULL если такого нет
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
	 * Входные данные: дерево
	 *
	 * Выходные данные: указатель на узел дерева с минимальным ключём
	 *
	 * Функция ищет узел в дереве с минимальным ключом
	 *
	 * @return - указатель на узел дерева или NULL если такого нет
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
	 * Входные данные: дерево
	 *
	 * Выходные данные: указатель на узел дерева с указанными параметрами
	 *
	 * Функция ищет узел дерева с указанным значением или возвращает NULL
	 *
	 * @param - day - день, month - месяц
	 *
	 * @return - указатель на узел дерева или NULL если такого нет
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
	 * Входные данные: имя нового дерева.
	 *
	 * Выходные данные: пустое дерево с заданным именем.
	 *
	 * Конструктор дерева. Изначально дерево пустое.
	 */
	redBlackTree()
	{
		
		myList* z = new myList();
		nil = z;
		nil->setColor(1);
		root = nil;
	}

	/**
	 * Входные данные: имя  дерева.
	 *
	 * Выходные данные: пустое дерево .
	 *
	 * Деструктор дерева. очищает дерево.
	 */
	~redBlackTree()
	{
		if (root!=nil)
		LRNDestructor(root);
	}
	/**
	 * Входные данные: объект класса красночерное дерево
	 *
	 * Выходные данные: строка в консоли - все элементы дерева через пробел, полученные обратным обходом
	 *
	 * Функция выводит все элементы дерева обратным обходом
	 */
	void LRN()
	{
			LRNPrintData(root);
	}
	/**
	 * Входные данные: объект класса красночерное дерево
	 *
	 * Выходные данные: строка в консоли - все элементы дерева через пробел, полученные левым симметричным обходом
	 *
	 * Функция выводит все элементы дерева левым симметричным обходом
	 */
	void LNR()
	{
		LNRPrintData(root);
	}
	/**
	 * Входные данные: объект класса красночерное дерево
	 *
	 * Выходные данные: строка в консоли - все элементы дерева через пробел, полученные правым симметричным обходом
	 *
	 * Функция выводит все элементы дерева правым симметричным обходом
	 */
	void RNL()
	{
		RNLPrintData(root);
	}
	/**
	* Входные данные: объект класса красночерное дерево
	*
	* Выходные данные: строка в консоли - все элементы дерева через пробел, полученные прямым обходом
	*
	* Функция выводит все элементы дерева правым прямым обходом
	*/
	void NLR()
	{
		NLRPrintData(root);
	}
	/**
	 * Входные данные: дерево, дата - день и месяц
	 *
	 * Выходные данные: дерево с новым узлом или с обновлённым списком одного из узлов
	 *
	 * Функция добавляет в дерево узел с указанными параметрами или
	 * если узел с такими параметрами уже есть, 
	 * то просто добавлет в список этого узла новый элемент
	 *
	 * @param - day - день, month - месяц
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
	 * Входные данные: дерево, дата - день и месяц
	 *
	 * Выходные данные: дерево без узла с указанным ключём или без
	 * одного элемента в списке узла с указанным значением
	 *
	 * Функция удаляет из дерева узел с указанными параметрами или
	 * удаляет эелемент из списка узла, если в нём больше одного элемента
	 *
	 * @param - day - день, month - месяц
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
	 * Входные данные: дерево, дата - день и месяц
	 *
	 * Выходные данные: true или false, есть узел с указанными параметрами или нет соответственно
	 *
	 * Функция проверяет наличие узла с указанными параметрами
	 *
	 * @param - day - день, month - месяц
	 *
	 * @return - true или false
	 */
	bool checkElem(int day, int month)
	{
		int key = 100 * month + day;
		if (this->getListPointer(day, month) != NULL)
			return 1;
		else return 0;
	}
	/**
	 * Входные данные: дерево
	 *
	 * Выходные данные: максимальный элемент дерева в консоль
	 *
	 * Функия выводит максимальный элемент дерева
	 */
	void printMax()
	{
		this->getMaxPointer()->getAllData();
	}
	/**
	 * Входные данные: дерево
	 *
	 * Выходные данные: минимальный элемент дерева в консоль
	 *
	 * Функия выводит минимальный элемент дерева
	 */
	void printMin()
	{
		this->getMinPointer()->getAllData();
	}
};

/**
 * Входные данные: указатель на корень дерева, день и месяц
 *
 * Выходные данные: обновлённое дерево с новым узлом или элементом в узле
 *
 * @param tree - указатель на дерево
 */
void Enter(redBlackTree *tree)
{
	int day, month;
	system("cls");
	
	std::cout << "Введите день \n";
	std::cin >> day;
	std::cout << "Введите месяц \n";
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
	std::cout << "Ошибка входных данных";
	_getch();
	return;
	m2: 
	tree->RBInsert(day, month);
}
/**
 * Входные данные: указатель на корень дерева, день и месяц
 *
 * Выходные данные: обновлённое дерево с удалённым узлом или элементом из узла
 *
 * @param tree - указатель на дерево
 */
void delet(redBlackTree* tree)
{
	int day, month;
	system("cls");

	std::cout << "Введите день \n";
	std::cin >> day;
	std::cout << "Введите месяц \n";
	std::cin >> month;
	tree->RBDelete(day, month);
}
/**
 * Входные данные: указатель на корень дерева, день и месяц
 *
 * Выходные данные: да или нет - ответ на вопрос есть ли такой ключ в дереве
 * Выводится в консоль
 *
 * @param tree - указатель на дерево
 */
void check(redBlackTree* tree)
{
	int day, month;
	system("cls");

	std::cout << "Введите день \n";
	std::cin >> day;
	std::cout << "Введите месяц \n";
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
		std::cout << "Нажмите 1 чтобы добавить элемент в дерево" << '\n';
		std::cout << "Нажмите 2 чтобы вывести удалить выбранный элемент" << '\n';
		std::cout << "Нажмите 3 чтобы вывести дерево обратным обходом" << '\n';
		std::cout << "Нажмите 4 чтобы вывести дерево симметричным обходом с лева на право" << '\n';
		std::cout << "Нажмите 5 чтобы вывести дерево симметричным обходом с права на лево" << '\n';
		std::cout << "Нажмите 6 чтобы вывести дерево прямым обходом" << '\n';
		std::cout << "Нажмите 7 чтобы вывести максимальное значение" << '\n';
		std::cout << "Нажмите 8 чтобы вывести минимальное значение" << '\n';
		std::cout << "Нажмите 9 чтобы проверить наличие элемента" << '\n';
		std::cout << "Нажмите esc чтобы закончить" << '\n';
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
		std::cout << "\nНашмите любую клавишу чтобы продолжить";
	}
	_getch();
	return 0;
} 
