#include<stdio.h>
#include<stdlib.h>

// Dinh nghia cau truc Node
typedef struct Node{
	int data;
	struct Node* next;
} Node;

//Ham tao Node moi
Node* createNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode){
		printf("Khong the cap phat bo nho");
		exit(1);
	}else{
		newNode->data = value;
		newNode->next = NULL;
	}
	return newNode;
}

// 1. Them phan tu vao dau danh sach
void addAtHead(Node** head, int value){
	Node* newNode = createNode(value);
	newNode->next = *head;
	*head = newNode;
}

// 2. Them phan tu vao cuoi danh sach
void addAtTail(Node** head, int value){
	Node* newNode = createNode(value);
	if(*head == NULL){
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

// 3. Ham chen phan tu vao vi tri cu the
void insertAtPosition(Node** head, int value, int position){
	Node* newNode = createNode(value);
	if(position == -1){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	Node* temp = *head;
	for(int i = 1; i < position - 1 && temp != NULL; i++){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("Vi tri khong hop le! \n");
		free(newNode);
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

// 4. Xoa phan tu dau danh sach
void deleteAtHead(Node** head){
	if(*head == NULL){
		printf("Danh sach rong \n");
		return;
	}
	Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}

// 5. Xoa phan tu cuoi danh sach
void deleteAtTail(Node** head){
	if(*head == NULL){
		printf("Danh sach rong \n");
		return;
	}
	if((*head)->next == NULL){
		free(*head);
		*head = NULL;
		return;
	}
	Node* temp = *head;
	while (temp->next->next != NULL){
		temp = temp->next;
	}
	free(temp->next);
	temp->next = NULL;
}

// 8. In danh sach cac gia tri ra man hinh
void printList(Node* head){
	if(head == NULL){
		printf("Danh sach rong \n");
		return;
	}
	printf("Danh sach: ");
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(){
	Node* head = NULL;
	int value, position, choice;
	do{
		printf("==================MENU=================\n");
	printf("1. Them phan tu vao dau danh sach.\n");
	printf("2. Them phan tu vao cuoi danh sach.\n");
	printf("3. Chen phan tu vao vi tri cu the.\n");
	printf("4. Xoa phan tu dau danh sach.\n");
	printf("5. Xoa phan tu cuoi danh sach.\n");
	printf("6. Xoa phan tu theo gia tri.\n");
	printf("7. Tim kiem phan tu theo gia tri.\n");
	printf("8. In danh sach cac gia tri ra man hinh.\n");
	printf("9. Thoat.\n");
	printf("Lua chon cua ban: ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			printf("Nhap vao gia tri: ");
			scanf("%d", &value);
			addAtHead(&head, value);
			break;
		case 2:
			printf("Nhap vao gia tri: ");
			scanf("%d", &value);
			addAtTail(&head, value);
			break;
		case 3:
			printf("Nhap vao gia tri: ");
			scanf("%d", &value);
			printf("Nhap vi tri: ");
			scanf("%d", &position);
			insertAtPosition(&head, value, position);
			break;
		case 4:
			deleteAtHead(&head);
			break;
		case 5:
			deleteAtTail(&head);
			break;
		case 6:
			printf("Chua lam dc.\n");
			break;
		case 7:
			printf("Chua lam dc.\n");
			break;
		case 8:
			printList(head);
			break;
		case 9:
			printf("Thoat chuong trinh");
			break;
		default: 
			printf("Lua chon khong hop le!");	
		}
	}while(choice != 9);
	
	// Giai phong bo nho
    while (head != NULL) {
        deleteAtHead(&head);
    }
	
	return 0;
}
