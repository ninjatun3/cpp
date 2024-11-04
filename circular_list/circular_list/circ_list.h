// узел для списка
template <typename T>
struct Node {
	Node* next;
	T data;
	Node(T& _data) : data(_data) {}
};

// список
class CList {
private:
	Node* head;
	size_t capacity{0};
public:
	Clist();
	~CList();
	CList operator=(const CList& clist) const;
	bool operator==(const CList a, const CList b) const;
	void setCapacity(size_t& _c) : capacity(_c) {}
	
};