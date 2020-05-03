template <class T>
class Node{				
	
	public:
		T value;		//wartosc wierzcholka, ktory jest tez wezlem
		Node *next;
		Node *prev;
		
		Node(){
			next = nullptr;
			prev = nullptr;
		}
		
		T GetValue(){
			return value;
		}
		
		T *GiveValue(){
			T *temp;
			temp = &value;
			return temp;
		}
};
