
typedef struct s_Item {
	int val;
	int key;
	struct s_Item* Next;
	struct s_Item* Prev;
}t_Item;


typedef struct {
	int version;
	int serialNum;
	int ItemCount;
	char reserve[100];
	//char data[8]; if i wont to add date i neet to write char reserve[92];
}t_headerFile;



typedef struct s_Item2 {
	int val;
	int key;
	int id;
	struct s_Item* Next;
	struct s_Item* Prev;
}t_Item2;










struct item_big
{
	int a;
};
