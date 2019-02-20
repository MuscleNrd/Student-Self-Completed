// UCIApp3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <class T>
class setList
{
private:
	struct setListNode
	{
		T info;
		setListNode* next;

		setListNode() : next(0) {}
		//setListNode(const T& newinfo) : info(newinfo), next(0) {}
		setListNode(T& newinfo, setListNode *newnext = 0)
			:info(newinfo), next(newnext) {}

		static void deleteSetList(setListNode *S)
		{
			if (S != NULL)
			{
				deleteSetList(S->next);

			}
		}
	};

	setListNode *buf;

	int itemCount;

	void init()
	{
		itemCount = 0;
		buf = new setListNode();
	}

public:
	setList() : buf(0), itemCount(0) {}
	//setList(initializer_list<T> s)
	//: buf(new setListNode) { uninitialized_copy(s.begin(), s.end(), buf);}

	setList(const setList<T>& aSet)
	{
		init();
		*this = aSet;
	}

	void insert(const T& newEntry)
	{
		setListNode* nextListNode = new setListNode();
		nextListNode->info = newEntry;
		nextListNode->next = buf;

		buf = nextListNode;
		itemCount++;
	}

	//int getSize() {return itemCount;}

	class setListIter
	{
		typedef setListIter iterator;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef T value_type;
		typedef T* ptr;
		typedef T& reference;

	private:
		setList ibuf;

	public:
		setListIter(setList p) : ibuf(p) {}
		// setListIter(const setList<T>& SL)


		setListIter& operator++()
		{
			ibuf.buf = ibuf.buf->next;
			return *this;
		}

		setListIter operator++(int postfix)
		{
			setListIter temp = ibuf;
			ibuf++;
			return temp;
		}

		setListIter operator=(const setListIter& rhs)
		{
			ibuf = rhs.ibuf;
			return *this;
		}

		bool operator==(const setListIter& rhs) { return ibuf->info == rhs.ibuf->info; }
		bool operator!=(const setListIter& rhs) { return ibuf.buf->info != rhs.ibuf.buf->info; }
		ptr operator->() { return ibuf; }
		reference operator*() { return ibuf.buf->info; }

	};

	setListIter find(const T& val) const;
	setListIter begin() { return setListIter(*this); }
	setListIter end() {
		while (buf->next != NULL)
		{
			buf++;
		}
		return *this;
	}

	~setList()
	{
		buf->deleteSetList(buf);
	}


};



using namespace std;
int main()
{
	setList<int> A;
	A.insert(1);
	A.insert(2);
	for (int i = 3; i <= 10; i++)
		A.insert(i);

	setList<int> B;
	for (int i = 20; i <= 40; i++)
		B.insert(i);

	setList<int> C(B);


	for (setList<int>::setListIter it = A.begin(); it != A.end(); ++it)
		cout << *it << endl;

    return 0;
}

