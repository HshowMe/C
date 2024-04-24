#include<iostream>
//LinkedList

template<class T>
struct BiNode {
	T data;
	BiNode<T>* next;
	BiNode<T>* prev; //todo:implement
	BiNode(T data, BiNode<T>* next = nullptr, BiNode<T>* prev = nullptr) : data(data), next(next), prev(prev) {}
	friend std::ostream& operator<<(std::ostream& stream, BiNode<T>*& node)
	{
		if (node == nullptr)
		{
			stream << "EMPTY";
		}
		else
		{
			stream << node->data;
		}		
		return stream;
	}
};

template<class T>
class BiLinkedList {
public:
	BiLinkedList() : head(nullptr),tail(nullptr), length(0) {}
	BiLinkedList(const BiLinkedList& list) : head(nullptr),tail(nullptr), length(list.length)
	{
		head = copy(list.head);
	}
	BiLinkedList(BiLinkedList&& list) noexcept
	{
		length = list.length;
		head = list.head;
        tail = list.tail;
		list.length = 0;
		list.head = nullptr;
        list.tail = nullptr; 
	}

	~BiLinkedList() {
		dispose();
	}
	void PushHead(T data)
	{
		return InsertBiNode(0, new BiNode<T>(data));
	}
	void Insert(int index, T data)
	{
		return InsertBiNode(index, new BiNode<T>(data));
	}
	void PushTail(T data)
	{
		return InsertBiNode(Length(), new BiNode<T>(data));
	}
	T PopHead()
	{
		return PopBiNode(ExtractBiNode(0));
	}
	T Extract(int index)
	{
		return PopBiNode(ExtractBiNode(index));
	}
	T PopTail()
	{
		return PopBiNode(ExtractBiNode(Length() - 1));
	}

	friend std::ostream& operator<<(std::ostream& stream, BiLinkedList<T>& list)
	{
		BiNode<T>* temp = list.head;
		while (temp != nullptr)
		{
			stream << temp << " ";
			temp = temp->next;
		}
		return stream;
	}

	bool IsEmpty()
	{
		return head == nullptr;
	}

	int Length()
	{
		return length;
	}

	void swap(int ind1, int ind2)
	{
		if (!IndexValid(ind1) || !IndexValid(ind2) || ind1 == ind2)
		{
			return;
		}
		if (ind1 < ind2)
		{
			return swap(ind2, ind1);
		}

		BiNode<T>* BiNode1 = ExtractBiNode(ind1);
		BiNode<T>* BiNode2 = ExtractBiNode(ind2);

		InsertBiNode(ind2, BiNode1);
		InsertBiNode(ind1, BiNode2);
	}
	void sort()
	{
		int i = 0;
		for (BiNode<T>* iBiNode = head; iBiNode != nullptr; iBiNode = iBiNode->next, ++i) {
			int j = 0;
			for (BiNode<T>* jBiNode = i->next; jBiNode != nullptr; jBiNode = jBiNode->next, ++j) {
				if (iBiNode->data > jBiNode->data) {
					swap(i, j);
				}
			}
		}
	}
	void reverse() //todo: check if works
	{
		if (head == nullptr || head->next == nullptr)
		{
			return;
		}

		BiLinkedList<T> reversedList;

		while (!IsEmpty()) {
			BiNode<T>* node = ExtractBiNode(0);
			reversedList.InsertBiNode(0, node);
		}

		head = reversedList.head;
		reversedList.head = nullptr;
	}
	friend BiLinkedList& operator+(T data, BiLinkedList& list)
	{
		list.PushHead(data);
		return list;
	}
	friend BiLinkedList& operator+(BiLinkedList& list, T data)
	{
		list.PushTail(data);
		return list;
	}
	friend BiLinkedList& operator+(BiLinkedList& list, BiLinkedList& add) //todo:check and fix
	{
		BiNode<T>* tail = list.head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = copy(add.head);
		list.length += add.length;
		return list;
	}
	friend BiLinkedList& operator+=(BiLinkedList& list, T data)
	{
		list.PushTail(data);
		return list;
	}
	friend BiLinkedList& operator+=(BiLinkedList& list, BiLinkedList& add)  //todo:check and fix
	{
        BiNode<T>* tail = list.tail; // Changed from head to tail
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
        tail->next = copy(add.head);
        list.length += add.length;
        return list;
	}
	friend bool operator==(BiLinkedList& list1, BiLinkedList& list2)
	{
		if (list1.Length() != list2.Length())
		{
			return false;
		}

		BiNode<T>* temp1 = list1.head;
		BiNode<T>* temp2 = list2.head;

		while (temp1 != nullptr) {
			if (temp1->data != temp2->data)
			{
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}

		return true;
	}
	BiLinkedList& operator=(BiLinkedList& src)
	{
		if (this != &src)
		{
			dispose();
			head = copy(src.head);
			length = src.length;
		}
		return *this;
	}

private:
	BiNode<T>* head;
	BiNode<T>* tail; //todo: implement
	int length;
	bool IndexValid(int index)
	{
		return 0 <= index && index < Length();
	}
	void InsertBiNode(int index, BiNode<T>* node)  //todo:check and fix
	{
        /**/
		if (!IndexValid(index) && index != Length())
        {
          delete node;
          return;
        }
        ++length;
        if (index == 0)
        {
          if (head != nullptr) {
            node->next = head;
            head->prev = node; // Added
          } else {
            tail = node; // Added
          }
          head = node;
          return;
	    }
        BiNode<T>* temp = head;
        while (index > 1)
        {
          temp = temp->next;
          --index;
        }
        node->next = temp->next;
        if (temp->next != nullptr) {
          temp->next->prev = node; // Added
        }
        temp->next = node;
        node->prev = temp; // Added
    }
    BiNode<T>* ExtractBiNode(int index)
    {
        if (IsEmpty() || !IndexValid(index))
        {
            return nullptr;
        }
        --length;
        if (index == 0)
        {
            BiNode<T>* res = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            res->next = nullptr;
            return res;
        }

        BiNode<T>* temp = head;
        while (index > 1)
        {
            temp = temp->next;
            --index;
        }
        BiNode<T>* res = temp->next;
        temp->next = temp->next->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp;
        } else {
            tail = temp;
        }
        if (res != nullptr) {
            res->next = nullptr;
        }
        return res;
    }

	T PopBiNode(BiNode<T>* BiNode)
	{
		T data = T();
		if (BiNode != nullptr)
		{
			data = BiNode->data;
			delete BiNode;
		}
		return data;
	}
	void dispose()
	{
		while (!IsEmpty())
		{
			PopHead();
		}
	}
	BiNode<T>* copy(BiNode<T>* src)  //todo:check and fix
	{
		if (src == nullptr)
		{
			return nullptr;
		}

        BiNode<T>* dst = new BiNode<T>(src->data);
        BiNode<T>* srcTemp = src->next; // Added
        BiNode<T>* dstTemp = dst; // Added
        while (srcTemp != nullptr)
        {
        dstTemp->next = new BiNode<T>(srcTemp->data);
        dstTemp->next->prev = dstTemp; // Added
        dstTemp = dstTemp->next;
        srcTemp = srcTemp->next;
        }
        tail = dstTemp; // Added
        return dst;
	}
};



int main(int argc, char* argv[])
{
	BiLinkedList<int> v;
	v.PushHead(1);
	v.PushHead(2);
	v.PushHead(3);
	v.PushHead(4);
	v.PushHead(5);
	std::cout << v << std::endl;
	while (!v.IsEmpty())
	{
		std::cout << v.PopHead() << " ";
	}
	std::cout << std::endl;

	v.PushTail(1);
	v.PushTail(2);
	v.PushTail(3);
	v.PushTail(4);
	v.PushTail(5);
	std::cout << v << std::endl;
	while (!v.IsEmpty())
	{
		std::cout << v.PopTail() << " ";
	}
	std::cout << std::endl;

	v.PushTail(1);
	v.PushTail(2);
	v.PushTail(3);
	v.PushTail(4);
	v.PushTail(5);
	v.Insert(4, 14);
	v.Insert(5, 15);
	v.Insert(2, 12);
	v.Insert(0, 10);
	v.Insert(9, 17);
	std::cout << v << std::endl;
	std::cout << v.Extract(3) << " -> " << v << std::endl;
	std::cout << v.Extract(0) << " -> " << v << std::endl;
	std::cout << v.Extract(7) << " -> " << v << std::endl;
    v.reverse();
    std::cout << v << std::endl;
	BiLinkedList<std::string> strList;
	return EXIT_SUCCESS;
}