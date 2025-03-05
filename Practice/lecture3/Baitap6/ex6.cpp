#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *next;
};

typedef struct node node;

node *makeNode(int x){
	node *newNode = new node();
	newNode->data = x;
	newNode->next = NULL; 
	return newNode;
}

void push(node **top, int x){
	node *newNode = makeNode(x);
	newNode->next = *top;
	*top = newNode;
}

void pop(node **top){
	if((*top) != NULL){
		node *tmp = *top;
		(*top) = tmp->next;
		delete tmp;
	}
}

int Top(node *top){
	if(top != NULL)
		return top->data;
}

int size(node *top){
	int ans = 0;
	node *tmp = top;
	while(tmp != NULL){
		++ans;
		tmp = tmp->next;
	}
	return ans;
}

int main(){
	node *st = NULL;
	while(1){
		cout << "-------------------------------\n";
		cout << "1. push\n";
		cout << "2. pop\n";
		cout << "3. top\n";
		cout << "4. size\n";
		cout << "0. Thoat\n";
		cout << "-------------------------------\n";
		int lc; cin >> lc;
		if(lc == 1){
			int x; cout << "Nhap x :" ; cin >> x;
			push(&st, x);
		}
		else if(lc == 2){
			pop(&st);
		}
		else if(lc == 3){
			if(st == NULL) cout << "EMPTY\n";
			else
				cout << Top(st) << endl;
		}
		else if(lc == 4){
			cout << size(st) << endl;
		}
		else{
			break;
		}
	}
}

